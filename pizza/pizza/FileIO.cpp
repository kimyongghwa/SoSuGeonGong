#include <iostream>
#include <fstream>
#include<string>
using namespace std;

void SaveFile() {
	string s;
	cout << "���Ͽ� �Է��� ������ �־��ּ���.";
	ofstream o("abc.txt");
	cin >> s;
	for (int i = 0; i < 3; i++)
	{
		o << s<<endl;
	}
	o.close();
}
void ReadFile() {
	string s;
	ifstream i("abc.txt");
	if(i.is_open())
		while (getline(i, s)) {
			cout << s << endl;
		}
	i.close();
}

int main() {
	ReadFile();
	return 0;
}