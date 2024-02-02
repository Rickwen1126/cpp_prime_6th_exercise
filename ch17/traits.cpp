#include <iostream>

template <class T>
struct MyIter {
    typedef T value_type;
    T *ptr;
    MyIter(T *p = 0) : ptr(p) {}
    T& operator*() const {return *ptr;}
};

template <class T>
struct Traits{
    typedef typename T::value_type value_type;
};

template <class T>
struct Traits<T*> {
    typedef T value_type;
};

template <class T>
struct Traits<const T*>{
    typedef const T value_type;
};

template <class I> 
typename Traits<I>::value_type
func(I ite) {
    std::cout << "class version" << std::endl;
    return *ite;
}


int main() {
    MyIter iter(new int(8));
    std::cout << func(iter) << std::endl;

    const int *p = new int(100);

    std::cout << func(p) << std::endl;

    return 0;
}