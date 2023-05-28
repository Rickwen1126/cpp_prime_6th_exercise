#include <iostream>
#include <string>
using namespace std;
// template <class U>
// class T {
//     private:
//         U val;
//     public:
//         T(U u) : val(u) {
//         }

//         void show() {
//             cout << val;
//         }
// };

// // template class T<double>;
// class T<double>;

// template <>
// class T<string> {
//     private:
//         string val;
//     public:
//         T(string v) : val(v) {
            
//         }

//         void show() {
//             cout << val;
//         }
// };

// template <typename T> void counts();
// template <typename T> void report(T &);

// template <typename TT>
// class HasFriendT {
//     private:
//         TT item;
//         static int ct;
//     public:
//         HasFriendT(const TT &i) : item(i) {ct++;}
//         ~HasFriendT() {ct--;}
//         friend void counts<HasFriendT<TT>>();
//         friend void report<>(HasFriendT<TT> &);
// };

// template <typename T>
// int HasFriendT<T>::ct = 0;

// template <typename T>
// void counts() {
//     cout << "template size: " << sizeof(T) << "; ";
//     cout << "template counts(): " << T::ct << endl;
// }

// template <typename T> 
// void report(T &t) {
//     cout << t.item << endl;
// }

// template <typename T>
// class My {
// 	private :
// 		T val;
// 	public:
//         My(T t):val(t){} 
// 		template<class C, class D>
// 		friend void show(C &, D &);
// };

// template<class C, class D>
// void show(C &c, D &d) {
// 	cout << c.val << endl;
// 	cout << d.val << endl;
// }

// int main (int argc, char *argv[]) {
//     {
//         My<int> m1(1);
//         My<double> m2(2.2);
//         show(m1, m2);

//     }
    
//     // system("pause");
    
//     // counts<HasFriendT<int>>();
//     // HasFriendT<int> hfi1(10);
//     // HasFriendT<int> hfi2(20);
//     // HasFriendT<double> hfdb(10.5);
//     // report(hfi1);
//     // report(hfi2);
//     // report(hfdb);
//     // cout << "counts<int>() output:\n";
//     // counts<HasFriendT<int>>();
//     // cout << "counts<double>() output:\n";
//     // counts<HasFriendT<double>>();
    
//     return 0;
// }


template <class T>
class Gala{
		private:
			T val;
			static int ct;
		public:
            Gala(T t) : val(t) {ct++;}
            ~Gala() {ct--;}
			friend void counts();// no member parameter, it can only access global Gala obj or static member
			friend void report(const Gala<T> &); 
};

template<class T>
int Gala<T>::ct = 0;

// it is normal funciton with tmeplate 
void counts() {
		cout << Gala<int>::ct << endl;
		cout << Gala<double>::ct << endl;
		// Gala<int>::ct & Gala<double>::ct are different value because they are independent class
}

void report(const Gala<int> &g) {
	cout << g.val << endl;
}

void report(const Gala<double> &g) {
	cout << g.val << endl;
}

int main() {
	counts();
    Gala<int> g1(12);
    Gala<double> g2(3.33);
    report(g1);
    report(g2);
    counts();

	return 0 ;
}