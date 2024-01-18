#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;

void show(const vint &v, int cols) {
    using std::cout;
    using std::endl;

    int lim = v.size();
    for (int i = 0; i < lim; i++) {
        cout.width(3);
        cout << v[i];
        if (i % cols == cols - 1) // minused by one because idx start from 0 
        {
            cout << endl;
        } else {
            cout << " ";
        }

        if (lim % cols != 0) {cout << endl;}
    }
}

int main()
{
    using std::cout;
    using std::slice;
    vint valint(SIZE);
    int i;
    for (i = 0; i < SIZE; i++)
    {
        valint[i] = std::rand() % 10;
    }

    cout << "Orignal array:\n";
    show(valint, 3);

    vint vcol(valint[slice(1, 4, 3)]);
    cout << "second column:\n";
    show(vcol,1);

    vint vrow(valint[slice(3, 3, 1)]);
    cout << "second row:\n";
    show(vrow,3);

    valint.operator[](slice(2, 4, 3)) = 10;
    // valint[slice(2, 4, 3)] = 10;
    cout << "Set last col to 10:\n";
    show(valint, 3);

    cout << "Set first col to sum of next two:\n";
    valint[slice(0, 4 ,3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
    show(valint, 3);

    return 0;
}