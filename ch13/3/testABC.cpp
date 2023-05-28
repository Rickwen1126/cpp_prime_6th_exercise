#include <iostream>
#include <string>
#include "dma.h"
const int DMA_NUM = 4;
const size_t DMA_LABEL_LEN = 50;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    abcDMA *p_dma[DMA_NUM];
    char tempLabel[DMA_LABEL_LEN];
    int tempRating;
    char kind;

    for (int i = 0; i < DMA_NUM; i++) {
        cout << "Enter DMA label: ";
        cin >> tempLabel;
        cout << "Enter DMA rating: ";
        cin >> tempRating;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA: ";
        while(cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
            cout << "Enter either 1 or 2 or 3"; 
        if (kind == '1') {
            p_dma[i] = new baseDMA(tempLabel, tempRating);
        } else if (kind == '2') {
            char lacksDMAColor[lacksDMA::COL_LEN];
            cout << "Please enter lacksDMA color: ";
            cin >> lacksDMAColor;
            p_dma[i] = new lacksDMA(lacksDMAColor, tempLabel, tempRating);
        } else {
            char style[DMA_LABEL_LEN];
            cout << "Please enter style: ";
            cin >> style;
            p_dma[i] = new hasDMA(style, tempLabel, tempRating);
        }
        while (cin.get() != '\n')
            continue;
    }

    cout << endl;

    for (int i = 0; i < DMA_NUM; i++) {
        p_dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < DMA_NUM; i++) {
        delete p_dma[i];
    }

    cout << "Done.\n";


    return 0;
}