#include <iostream>
#include <initializer_list>

template <class T>
T average_list(std::initializer_list<T> list)
{
	if (list.size() == 0)
	{
		return T{};
	}

	T t{};
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		t += *iter;
	}
	return t / list.size();
}

int main() {
	using namespace std;
	auto q = average_list({15.4, 10.7, 9.0});
	cout << q << endl;
	return 0;
}