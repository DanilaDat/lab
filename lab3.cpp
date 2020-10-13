#include <iostream>
#include <windows.h>
#include <iomanip>
class String {
private:
	int size;
	char* string;
public:
	String() {
		size = 1;
		string = new char[size];
		for (int i = 0; i < size; i++)
			string[i] = 0;
	};
	String(int size) {
		this->size = size;
		this->string = new char[size];
		std::cout << "Введите строку\n";
		for (int i = 0; i < size; i++)
			std::cin >> this->string[i];
	}
	String(String& Str) {
		this->size = Str.size;
		this->string = new char[Str.size];
		for (int i = 0; i < Str.size; i++) {
			this->string[i] = Str.string[i];
		}
	}
	~String() {
		delete[size]string;
	}
	friend void output(String& Str);
	friend void input_str(String& Str);
	friend void buble_sort(String& Str);
	friend void operator-- (String& Str);
	friend bool operator< (String& Str1, String& Str2);
	friend bool operator> (String& Str1, String& Str2);
	friend void operator+=(String& Str, String& object);
	friend void operator+=(String& Str, char object);
	friend void edit_element(String& Str);
	friend char get_element(String& Str);
};
void operator-- (String& Str) {
	for (int i = 0; i < Str.size; i++)
		Str.string[i]--;
}
bool operator< (String& Str1, String& Str2) {
	return (Str1.size < Str2.size);
}
bool operator> (String& Str1, String& Str2) {
	return (Str1.size > Str2.size);
}
void operator+=(String& Str, String& object) {
	for (int i = Str.size, j = 0; i < Str.size + object.size; i++, j++)
		Str.string[i] = object.string[j];
	Str.size = Str.size + object.size;
};
void operator+=(String& Str, char object) {
	Str.string[Str.size] = object;
	Str.size += 1;
}
int input_int(int min, int max);
int main() {
	system("chcp 1251>null");
	String Str1;
	std::cout << "Введите длину строки \n";
	int s = input_int(0, 200);
	String Str2(s);
	String Str3(Str2);
	output(Str1);
	output(Str2);
	output(Str3);

	String* Str4 = new String();
	input_str(*Str4);
	String* Str5 = new String();
	*Str5 = *Str4;
	buble_sort(*Str4);
	output(*Str4);
	output(*Str5);
	delete Str4, Str5;
	system("pause");
	system("CLS");
	String* Array = new String[20];
	int flag = 1, count = -1;
	while (flag != 0) {
		std::cout << "Выберите действие\n1)Добавить строку\n2)Изменить определённый символ в строке\n3)Вывести определенный символ в строке\n4)Вывести определенную строку\n5)Вывести все строки\n";
		std::cout << "6)Сравнить строки\n7)Сортировать строку по убыванию\n8)Уменьшить строку на 1\n9)Добавить символ к определенной строке\n10)Добавить строку к строке\n11)Выход\n";
		int answer = input_int(0, 12);
		int number = 0; char get_el = 0, symbol = 0;
		int first = 0, second = 0;
		switch (answer) {
		case 1:
			count++;
			input_str(Array[count]);
			system("pause");
			system("CLS");
			break;
		case 2:
			std::cout << "Введите номер строки,в которой хотите изменить элемент\n";
			number = input_int(0, count + 1);
			std::cout << "Строка " << number << " до изменений \n";
			output(Array[number - 1]);
			edit_element(Array[number - 1]);
			std::cout << "Строка после изменения \n";
			output(Array[number - 1]);
			system("pause");
			system("CLS");
			break;
		case 3:
			std::cout << "Введите номер строки, из которой хотите получить элемент\n";
			number = input_int(0, count + 1);
			std::cout << "Строка " << number << " \n";
			output(Array[number - 1]);
			get_el = get_element(Array[number - 1]);
			std::cout << "Полученный элемент - " << get_el;
			system("pause");
			system("CLS");
			break;
		case 4:
			std::cout << "Введите номер строки, которую хотите вывести \n";
			number = input_int(0, count + 1);
			std::cout << "Строка " << number << " \n";
			output(Array[number - 1]);
			system("pause");
			system("CLS");
			break;
		case 5:
			for (int i = 0; i < count + 1; i++) {
				std::cout << "Строка " << i + 1 << "\n";
				output(Array[i]);
			}
			system("pause");
			system("CLS");
			break;
		case 6:
			std::cout << "Введите номера строк,которые хотите сравнить\nПервая - ";

			first = input_int(0, count + 1);
			std::cout << "Вторая - ";
			second = input_int(0, count + 1);
			if (first == second)
			{
				std::cout << "Нельзя провести сравнение,потому что вы выбрали одну и туже строку";
				break;
			}
			if (operator<(Array[first - 1], Array[second - 1]))
				std::cout << "Строка " << first << " меньше строки " << second << "\n";
			else std::cout << "Строка " << first << " больше строки " << second << "\n";
			output(Array[first - 1]); output(Array[second - 1]);
			system("pause");
			system("CLS");
			break;
		case 7:
			std::cout << "Введите номер строки, которую хотите сортировать \n";
			number = input_int(0, count + 1);
			std::cout << "Строка " << number << " до сортировки\n";
			output(Array[number - 1]);
			buble_sort(Array[number - 1]);
			std::cout << "Строка " << number << " после сортировки\n";
			output(Array[number - 1]);
			system("pause");
			system("CLS");
			break;
		case 8:
			std::cout << "Введите номер строки, которую хотите уменьшить на 1 \n";
			number = input_int(0, count + 1);
			std::cout << "Строка " << number << " до уменьшения\n";
			output(Array[number - 1]);
			operator--(Array[number - 1]);
			std::cout << "Строка " << number << " после уменьшения\n";
			output(Array[number - 1]);
			system("pause");
			system("CLS");
			break;
		case 9:
			std::cout << "Введите номер строки, к которой хотите добавить элемент \n";
			number = input_int(0, count + 1);
			std::cout << "Строка " << number << " до добавления\n";
			output(Array[number - 1]);
			std::cout << "Введите элемент,который хотите добавить ";
			std::cin >> symbol;
			operator+=(Array[number - 1], symbol);
			std::cout << "Строка " << number << " после добавления\n";
			output(Array[number - 1]);
			system("pause");
			system("CLS");
			break;
		case 10:
			std::cout << "Введите номер строки, к которой хотите добавить другую строку \n";
			first = input_int(0, count + 1);
			std::cout << "Введите номер строки, которую хотите добавить \n";
			second = input_int(0, count + 1);
			std::cout << "Строка " << first << " до добавления\n";
			output(Array[first - 1]);
			operator+=(Array[first - 1], Array[second - 1]);
			std::cout << "Строка " << first << " после добавления\n";
			output(Array[first - 1]);
			system("pause");
			system("CLS");
			break;
		case 11:
			exit(0);
			break;
		}
	}
	delete[20]Array;
}
void output(String& Str) {
	for (int i = 0; i < Str.size; i++)
		std::cout << Str.string[i];
	std::cout << "\n";
	std::cout << "---------------------------------------------------------------------\n";
}
int input_int(int min, int max) {
	int a = 0;
	while (!(std::cin >> a) || a > max || a < min) {
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Повторите ввод\n";
	}
	return a;
}
void input_str(String& Str) {
	Str.string = new char[100];
	int index(0);
	char symbol;
	std::cout << "Введите строку (Чтобы закончить ввод, введите 0)\n";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	while (true) {
		std::cin >> symbol;
		if (symbol == '0')
			break;
		Str.string[index] = symbol;
		index++;
	}
	Str.size = index;
}
void buble_sort(String& Str) {
	char temp;
	for (int i = 0; i < Str.size - 1; i++) {
		for (int j = 0; j < Str.size - i - 1; j++) {
			if (Str.string[j] < Str.string[j + 1]) {
				temp = Str.string[j];
				Str.string[j] = Str.string[j + 1];
				Str.string[j + 1] = temp;
			}
		}
	}
}
void edit_element(String& Str) {
	std::cout << "Введите индекс символа который хотите поменять\n";
	int index = input_int(0, Str.size - 1);
	char symbol;
	std::cout << "Введите новый символ ";
	std::cin >> symbol;
	Str.string[index - 1] = symbol;
}
char get_element(String& Str) {
	std::cout << "Введите индекс символа,которы хотите вывести\n";
	int index = input_int(0, Str.size - 1);
	return Str.string[index - 1];
}