#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

struct true_type {
    static constexpr bool value = true;
};

struct false_type {
    static constexpr bool value = false;
};

template <typename>
struct is_floating_point_helper : false_type{};

template <>
struct is_floating_point_helper<float> : true_type{};

template <>
struct is_floating_point_helper<const float> : true_type{};

template <>
struct is_floating_point_helper<double> : true_type{};

template <>
struct is_floating_point_helper<long double> :true_type{};

template <class T>
struct remove_const{
    using type = T;
};

template <class T> 
struct remove_const<const T> {
    using type = T;
};

template <class T>
struct remove_reference{
    using type = T;
}; 

template <class T>
struct remove_reference<T &> {
    using type = T;
};

template <class T>
struct remove_pointer {
    using type = T;
};

template <class T>
struct remove_pointer<T *> {
    using type = T;
};

template <typename T> 
struct is_floating_point : is_floating_point_helper<typename remove_const<typename remove_reference<T>::type>::type> {

};

template<bool judge, typename T1, typename T2> 
struct conditional {
    using type = T1;
};

template<typename T1, typename T2>
struct conditional <false, T1, T2>{
    using type = T2;
};


template<typename T1, typename T2> 
struct is_same : false_type{};

template<typename T>
struct is_same<T, T> : true_type{};

struct B{};
struct D : B{};
struct A {};

template<typename T1, typename T2>
struct is_base_of : conditional<__is_base_of(T1, T2), true_type, false_type>{};

template<typename T1, typename T2>
true_type test_is_base(T1 *);

template<typename T1, typename T2>
false_type test_is_base(void *);



int main() {
    using namespace std;
    char ch;
    int ct1 = 0;
    cin >> ch;
    while(ch != 'q') {
        ct1++;
        cin >> ch;
    }

    int ct2 = 0;
    cin.get(ch);
    while(ch != 'q') {
        cout << ch;
        ct2++;
        cin.get(ch);
    }
    cout << "ct1:" << ct1 << endl;
    cout << "ct2:" << ct2 << endl; 

    return 0;
}


int main() {
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;
    cout << setw(15) << "base ten" << setw(15) << "base sixteen" << setw(15) <<  "base eight" << "\n";
    cout.setf(ios::showbase);
    cout << setw(15) << n << hex << setw(15) << n << oct << setw(15) << n << "\n";

    return 0;
}