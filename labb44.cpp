#include <iostream>
#include <time.h>
#include <cstring>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;
class People {
protected:

	string name;
	int rost;

public:

	People() {
		this->rost = 0;
		this->name = "-";
	}

	People(int Rost, string Name) {
		this->rost = Rost;
		this->name = Name;
	}

	void setPeople() {
		bool a = true;
		cout << "Класс: People " << endl;
		cout << "Введите имя:" << endl;
		cin >> name;
		do
		{
			cout << "Введите рост: ";
			cin >> rost;
			if (cin.fail() || rost <= 0)
				cout << "Введите ещё раз" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);

	}

	~People()
	{

	}

	void printPeople() {
		cout << "Класс: People " << endl;
		cout << "Имя: " << name << endl;
		cout << "Рост: " << rost << endl;
	}

};


class Player : virtual public People {
protected:

	int startpos; // стартовая позиция

public:

	Player() {
		this->startpos = 0;
	}

	Player(int Startpos) {
		this->startpos = Startpos;
	}
	void setPlayer() {
		bool a = true;
		cout << "Класс: Player " << endl;
		do
		{
			cout << "Введите стартовую позицию: " << endl;
			cin >> startpos;
			if (cin.fail() || startpos <= 0 || startpos > 6)
				cout << "Введите ещё раз" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);
	}


	~Player()
	{

	}

	void printPlayer() {
		cout << "Класс: Player " << endl;
		cout << "Стартовая позиция: " << startpos << endl;
	}

};

class reservePlayer : virtual public Player {
protected:

	int timeonbench; // время на скамейке

public:

	reservePlayer() {
		this->timeonbench = 0;
	}

	reservePlayer(int Timeonbench) {
		this->timeonbench = Timeonbench;
	}
	void setreservePlayer() {
		bool a = true;

		cout << "Класс: reservePlayer " << endl;
		do
		{
			cout << "Введите время на скамейке(минут): " << endl;
			cin >> timeonbench;
			if (cin.fail() || timeonbench <= 0)
				cout << "Введите ещё раз" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);
	}


	~reservePlayer()
	{

	}

	void printreservePlayer() {
		cout << "Класс: reservePlayer " << endl;
		cout << "Время на скамейке(минут): " << timeonbench << endl;
	}

};


class sudiya : virtual public People { // судья
protected:

	string shapecolor; // цвет формы

public:

	sudiya() {
		this->shapecolor = "-";
	}

	sudiya(string shapecolor) {
		this->shapecolor = shapecolor;
	}
	void setSudiya() {
		cout << "Класс: Sudiya " << endl;
		cout << "Введите цвет формы:" << endl;
		cin >> shapecolor;
	}


	~sudiya()
	{

	}

	void printJudge() {
		cout << "Класс: Sudiya " << endl;
		cout << "Цвет формы: " << shapecolor << endl;;
	}

};

class MainSudiya : virtual public sudiya { // главный судья
protected:

	int numbsubor; // количество подчинённых 

public:

	MainSudiya() {
		this->numbsubor = 0;
	}

	MainSudiya(int Numbsubor) {
		this->numbsubor = Numbsubor;
	}
	void setMainJudge() {
		bool a = true;

		cout << "Класс: MainSudiya " << endl;
		do
		{
			cout << "Введите количество подчинённых:" << endl;
			cin >> numbsubor;
			if (cin.fail() || numbsubor <= 0)
				cout << "Введите ещё раз" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);
	}


	~MainSudiya()
	{

	}

	void printMainSudiya() {
		cout << "Класс: MainSudiya " << endl;
		cout << "Количество подчинённых: " << numbsubor << endl;;
	}

};



class Volleyball : virtual public MainSudiya, virtual public reservePlayer { // волейбол
protected:

	int numbplayers; // количество игроков

public:

	Volleyball() {
		this->numbplayers = 0;
	}

	Volleyball(int Numbplayers) {
		this->numbplayers = Numbplayers;
	}
	void setVolleyball() {
		bool a = true;

		cout << "Класс: Volleyball " << endl;
		do
		{
			cout << "Введите количество игроков:" << endl;
			cin >> numbplayers;
			if (cin.fail() || numbplayers <= 0)
				cout << "Введите ещё раз" << endl;
			else
				a = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		} while (a);
	}


	~Volleyball()
	{

	}

	void printVolleyball() {
		cout << "Класс: Volleyball " << endl;
		cout << "Количество игроков: " << numbplayers << endl;;
	}

};
