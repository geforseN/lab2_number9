#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

//Фамилия, дата поступления, дата отчисления.
/*
·        ввод записи таблицы с клавиатуры;
·        загрузка и сохранение  таблицы в текстовом файле;
·        просмотр таблицы;
·        сортировка таблицы в порядке возрастания заданного поля;
·        поиск в таблице элемента с заданным значением поля или с наиболее близким к нему по значению;
·        удаление записи;
·        изменение(редактирование) записи;
·        вычисление с проверкой и использованием всех записей по заданному условию и формуле(например, общая сумма на всех счетах).
*/

struct date
{
	//инициализация дня, месяца, года
	int day = 0;
	int month = 0;
	int year = 0;	

	//методы для дня  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++  DAY	
	void showDay(){
		std::cout << "Нынешний день: " << day << "\n";
		//printf_s("Нынешний день: %d\n", day);
	}

	void getDay() {
		std::cout << "Введите день: " ;
		std::cin >> day;
		std::cout << "//День введён" << "\n";
	}

	void setDay(int input_day)
	{
		std::cout << "День изменён с " << day << " на " << input_day << "\n";
		day = input_day;
	}

	void showDay_tableVersion() {
		std::cout << day / 10 << day % 10 << "\n";
	}

	//методы для месяца  ++++++++++++++++++++++++++++++++++++++++++++++++++++++  MONTH 
	void showMonth(){
		std::cout << "Нынешний месяц: " << month << "\n";
		//printf_s("Нынешний месяц: %d\n", month);
	} 

	void getMonth() {
		std::cout << "Введите месяц: ";
		std::cin >> month;
		std::cout << "//Месяц введён" << "\n";
	}

	void setMonth(int input_month){
		std::cout << "Месяц изменён с " << month << " на " << input_month << "\n";
		month = input_month;
	}

	void showMonth_tableVersion() {
		std::cout << month / 10 << month % 10 << "\n";
	}

	//методы для года  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++  YEAR																					YEAR
	void showYear(){
		std::cout << "Нынешний год: " << year << "\n";
		//printf_s("Нынешний год: %d\n", year);
	}

	void getYear() {
		std::cout << "Введите год: ";
		std::cin >> year;
		std::cout << "//Год введён" << "\n";
	}

	void setYear(int input_year){
		std::cout << "Год изменён с " << year << " на " << input_year << "\n";
		year = input_year;
	}
	void showYear_tableVersion() {
		//           1 число         2 число			  3 число			 4 число
		std::cout << year / 1000 << (year / 100) % 10 << (year / 10) % 10 << year % 10 <<"\n";
	}
	//методы для всей даты  +++++++++++++++++++++++++++++++++++++++++++++++++++  DATE
	void showFullDate(){
		showDay();
		showMonth();
		showYear();
	}

	void showFullDate_tableVersionZXC() {
		showDay_tableVersion();
		std::cout << ".";
		showMonth_tableVersion();
		std::cout << ".";
		showYear_tableVersion();
	}
	void recordFullDate() {
		std::ofstream file;
		file.open("students.txt");
		
		file << day / 10 << day % 10;
		file << ".";
		file << month / 10 << month % 10;
		file << ".";
		file << year / 1000 << (year / 100) % 10 << (year / 10) % 10 << year % 10;

		file.close();
	}
	
	//file << zet.enroll.showFullDate_tableVersion();
};

struct student
{
	//инициализация фамилии, даты зачисления (enroll) и даты отчисления (dismiss)
	std::string surname;
	date enroll;
	date dismiss;

	//методы для фамилии
	void showSurname()
	{
		std::cout << "Нынешняя фамилия: " << surname << "\n";
	}
	void getSurname()
	{
		std::cout << "Введите фамилию" << "\n";
		std::cin >> surname;
		std::cout << "//Фамилия введена" << "\n";
	}
	void setSurname(std::string input_surname)
	{
		std::cout << "Фамилия изменена с " << surname << " на "<< input_surname << "\n";	
		surname = input_surname;
	}

};

int main()
{
	//     Проблемы
	//  1. tableVersion некоректно работает с отрицательными значениями дат 
	//	решение: (добавить в вычислениях модуль)
	//  2. проблемы с "разтроением" кода методов для дней, месяцев, лет
	// 	решение: (создать в вводе функции параметр, который будет спрашивать тип даты???? так себе)
	// 	3. проблема с нужностью/ненужностью перевода строки
	//	решение: (создать в вводе функции параметр, который будет отвечать за перевод строки)
	//	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	student zet;
	zet.enroll.day = 1;
	zet.enroll.month = 9;
	zet.enroll.year = 2020;

	//zet.getsurname();
	//zet.showsurname();
	//zet.setsurname("Набоков");
	//zet.showsurname();

	//zet.enroll.showFullDate();
	//zet.enroll.getDay();
	//zet.enroll.showFullDate();

	//zet.enroll.showDay_tableVersion();
	//zet.enroll.showMonth_tableVersion();
	//zet.enroll.showYear_tableVersion();

	zet.enroll.recordFullDate_tableVersion();
	
	return 0;
}
