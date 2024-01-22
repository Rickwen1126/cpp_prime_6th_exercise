#include <iostream>
int countStdInputCharVersion1() {
    int count = 0;
    char ch;
    while((ch = std::cin.get()) != '$') {
        count++;
    }

    std::cin.putback(ch);

    return count;
}

int countStdInputCharVersion2() {
    int count = 0;
    char ch;
    while (std::cin.peek() != '$')
    {
        std::cin.get(ch);
        count++;
    }
    
    return count;
}

void checkTheStdInBuffer() {
    char ch;
    while ((ch = std::cin.get()) != '\n') {
        std::cout << ch;
    }
}

int main() {
    int count = countStdInputCharVersion2();
    std::cout << "Totoal count (version1):"<< count << std::endl;
    std::cout << "StdIn buffer:";
    checkTheStdInBuffer();

    return 0;
}