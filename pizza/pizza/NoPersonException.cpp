#include "NoPersonException.h"
#include<iostream>
using namespace std;

int main() {
	int pizzaSlices = 12;
	int persons = 0;
	int slicesPerPerson = 0;

	try {
		cout << "사람수를 입력하시오";
		cin >> persons;
		if (persons <= 0)
			throw NoPersonException(persons);
		slicesPerPerson = pizzaSlices / persons;
			cout << "한사람당 피자는" <<
			slicesPerPerson << "입니다" << endl;
	}
	catch (NoPersonException e) {
		cout << "오류 01 사람이 " <<
			e.getPersons() << "명입니다." << endl;
	}
}