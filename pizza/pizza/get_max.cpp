#include<iostream>
using namespace std;
//template <typename T>
//
//T get_max(T x, T y) {
//	if (x > y)
//		return x;
//	else
//		return y;
//}

template <typename T1, typename T2>
void ShowData(T1 t1, T2 t2) {
	cout << t1 << "+" << t2 << endl;
}
int main() {
	//int x, y;
	//float x1, y1;
	//cin >> x >> y;
	//cout << "����" << get_max(x, y) << endl;
	//cin >> x1 >> y1;
	//cout << "�Ǽ� :" << get_max(x1, y1) << endl;

	char c;
	int a;
	float b;
	cin >> a >> b >> c;
	ShowData(a, b);
	ShowData(b, c);
	ShowData(a, c);
}