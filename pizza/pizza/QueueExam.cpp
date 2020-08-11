#include<iostream>
#include<queue>

using namespace std;

template<typename t>
int main() {
	queue<int> q;
	q.push(4);
	q.push(3);
	q.push(2);
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.empty() << endl;
	cout << q.size() < endl;
}