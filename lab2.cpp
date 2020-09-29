#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;
class motocycle {
private:
	int id;
	string name;
	int mile;
public:
	motocycle() {
		this->id = 0;
		this->name = ' ';
		this->mile = 0;
	}
	motocycle(int ID, string fio) {
		this->id = ID;
		this->name = fio;
		this->mile = 0;
	}
	~motocycle() {};
	friend void print(motocycle& moto);
	friend class STO;
	friend void input_id(motocycle& mot);
	friend void set_id(int ID, string fio, motocycle& moto) {
		moto.id = ID;
		moto.name = fio;
	};
};
void print(motocycle& moto) {
	cout << "Уникальный номер мотоцикла - " << moto.id << endl;
	cout << "ФИО владельца мотоцикла - " << moto.name << endl;
	cout << "Пробег мотоцикла - " << moto.mile << endl;
}
void input_id(motocycle& moto) {
	int ID;
	string fio;
	bool a = true;
	do
	{
		cout << "Введите id: ";
		cin >> ID;
		if (cin.fail())
			cout << "Повторите попытку" << endl;
		else
			a = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (a);
	cout << "Введите ФИО владельца - ";
	cin >> fio;
	set_id(ID, fio, moto);
};
class STO {
private:
	int Mile;
public:
	STO() {
		this->Mile = 0;
	}
	STO(int Mil) {
		this->Mile = Mil;
	}
	~STO() {};
	void input_mile() {
		bool a = true;
		do
		{
			cout << "Введите пробег - ";
			cin >> Mile;
			if (cin.fail())
				cout << "Повторите попытку" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);
		STO m(Mile);
	};
	void install_mileage(motocycle& avto) {
		avto.mile = Mile;
	}
};

int main() {
	system("chcp 1251>null");
	STO m1;
	motocycle Moto[10];
	int i = 0, answ = 0, count = 0;
	do {
		cout << "Добавить мотоцикл в базу?(1)" << endl;
		int answer = 0;
		answ = 0;
		cin >> answer;
		if (answer == 1)
		{
			input_id(Moto[i]);
			cout << "========================================" << endl;
			print(Moto[i]);
			cout << "========================================" << endl;
			m1.input_mile();
			m1.install_mileage(Moto[i]);
			cout << "========================================" << endl;
			print(Moto[i]);
			i++;
			count++;
		}
		cout << "========================================" << endl;
		cout << "Хотите прродолжить работу? (1)" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> answ;
	} while (answ == 1 && i != 10);
	cout << "Хотите вывести информацию о всех мотоциклах? 1";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	int answ1;
	cin >> answ1;
	if (answ1 == 1) {
		system("CLS");
		for (int j = 0; j < count; j++)
		{
			cout << "Мотоцикл № " << j + 1 << endl;
			print(Moto[j]);
			cout << "========================================" << endl;
		}
	}
	return 0;
}  