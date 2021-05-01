#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <locale>
#include <iostream>
using namespace std;


#define ENG 26
#define RUS 32

struct userlp
{
	int number;
	string login;
	string pasword;
};

// УПРАВЛЕНИЕ ПРОИСХОДИТ С ПОМОЩЬЮ СЛЕДУЮЩИХ КЛАВИШ:
//	Стрелка вверх 
//	Стрелка вниз 
//  ESC (назад)
//	ENTER (выбор пункта меню)

int keybHit(int num) { // Функция по считыванию нажатия клавиши


	// У каждой клавиши есть свой код в таблице символов ASCII
	char button = _getch();
	// Функция _getch получает данные о нажатой клавише и они заносятся в переменную button

	if (button == 27) { // КОД 27 соответствует ESC
		if (num > 0 && num < 3) num = 69; // если мы находимся в главном меню во время нажатия ESC, то переменной задаётся значение, которое сразу выключит программу
		//else if (num > 10 && num < 1000000) num /= 10; // если мы находимся в побочных меню, то задаётся значение переменной, которое выведет главное меню
		else if (num == 11) num = 1;
		else if (num == 21) num = 11;	// 11 -> 21
		else if (num == 2) num = 31;	// 2  -> 31
		else if (num == 31) num = 41;	// 31 -> 41
		else if (num == 21) num = 111;	// 21 -> 111
		else if (num == 22) num = 121;	// 22 -> 121
		else if (num == 23) num = 131;	// 23 -> 131
		else if (num == 24) num = 141;	// 24 -> 141
		else if (num == 25) num = 151;	// 25 -> 151
		else if (num == 26) num = 161;	// 26 -> 161
		else if (num == 161) num = 171;	// 161 -> 171
	}
	else if (button == 72) num -= 1; // КОД 72 соответсвует Стрелке вверх
	else if (button == 80) num += 1; // КОД 80 соответсвует Стрелке вниз
	else if (button == 13) { // КОД 13 соответсвует ENTER
		// Если при нажатии ENTER, переменная num, которая передается в эту функцию, принадлежит промежутку [1; 3]
		// то она изменяется на то значение, которое позволит вывести следующий уровень меню
		if (num == 1) num = 11;			// 1  -> 11
		else if (num == 11) num = 21;	// 11 -> 21
		else if (num == 2) num = 31;	// 2  -> 31
		else if (num == 31) num = 41;	// 31 -> 41
		else if (num == 21) num = 111;	// 21 -> 111
		else if (num == 22) num = 121;	// 22 -> 121
		else if (num == 23) num = 131;	// 23 -> 131
		else if (num == 24) num = 141;	// 24 -> 141
		else if (num == 25) num = 151;	// 25 -> 151
		else if (num == 26) num = 161;	// 26 -> 161
		else if (num == 161) num = 171;	// 161 -> 171
	}

	// Если переменная num выходит за рамки пунктов меню, то он изменяется на крайнее значение с другой стороны
	// чтобы сделать эффект бесконечной прокрутки меню
	if (num == 0) num = 2;
	else if (num == 3) num = 1;

	if (num == 10) num = 11;
	else if (num == 12) num = 11;

	if (num == 20) num = 26;
	else if (num == 27) num = 21;

	if (num == 30) num = 31;
	else if (num == 32) num = 31;

	if (num == 40) num = 43;
	else if (num == 44) num = 41;

	if (num == 160) num = 163;
	else if (num == 164) num = 161;

	// И после всех изменений переменная возвращается, чтобы с её помощью отрисовать нужный шаблон меню
	return num;
}

void encrypt(int n)
{
	FILE* fp1, * fp2;
	fopen_s(&fp1, "input.txt", "r");
	fopen_s(&fp2, "output.txt", "w");
	int flag;
	char c;
	c = getc(fp1);
	while (!feof(fp1))
	{
		flag = 0; //обработан ли текущий символ
		if (c >= 'A' && c <= 'Z')
		{
			c = c + (n % ENG);
			if (c > 'Z') c = 'A' + (c - 'Z') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c + (n % ENG);
			if (c > 'z') c = 'a' + (c - 'z') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'А' && c <= 'Я')
		{
			c = c + (n % RUS);
			if (c > 'Я') c = 'А' + (c - 'Я') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'а' && c <= 'я')
		{
			c = c + (n % RUS);
			if (c > 'я') c = 'а' + (c - 'я') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(fp2, "%c", c);
		c = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
}

void decipher(int n)
{
	FILE* fp1, * fp2;
	fopen_s(&fp1, "input.txt", "r");
	fopen_s(&fp2, "output.txt", "w");
	int flag;
	char c;
	c = getc(fp1);
	while (!feof(fp1))
	{
		flag = 0;
		if (c >= 'A' && c <= 'Z')
		{
			c = c - (n % ENG);
			if (c < 'A') c = 'Z' - ('A' - c) + 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c - (n % ENG);
			if (c < 'a') c = 'z' - ('a' - c) + 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'А' && c <= 'Я')
		{
			c = c - (n % RUS);
			if (c < 'А') c = 'Я' - ('А' - c) + 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'а' && c <= 'я')
		{
			c = c - (n % RUS);
			if (c < 'а') c = 'я' - ('а' - c) + 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(fp2, "%c", c);
		c = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
}

void main_menu(int num)
{
	system("cls");
	(num == 1) ? printf(">Admin<\n") : printf("Admin\n");
	(num == 2) ? printf(">User<\n") : printf("User\n");
}

void adminreg(int num)
{
	string login;
	string pasword;
	string rlogin = "1234";
	string rpasword = "1234";
	int prov;

	do
	{
		system("cls");
		printf("Enter Login:");
		cin >> login;
		printf("Enter Pasword:");
		cin >> pasword;

		if (rlogin == login && rpasword == pasword)
		{
			(num == 11) ? printf(">Login<\n") : printf("Login\n");
			prov = 1;
		}
		else
		{
			prov = 0;
		}
	} 	while (prov != 1);
}

void adminmenu(int num)
{
	system("cls");
	printf("Admin panel\n");
	(num == 21) ? printf(">Adding a record<\n") : printf("Adding a record\n");
	(num == 22) ? printf(">Edit a record<\n") : printf("Edit a record\n");
	(num == 23) ? printf(">Deleting a record<\n") : printf("Deleting a record\n");
	(num == 24) ? printf(">View all data in tabular form<\n") : printf("View all data in tabular form\n");
	(num == 25) ? printf(">Various data search and filtering procedures<\n") : printf("Various data search and filtering procedures\n");
	(num == 26) ? printf(">User management<\n") : printf("User management\n");
}

void adminuserad(int num)
{
	system("cls");
	printf("User management\n");
	(num == 161) ? printf(">Add user<\n") : printf("Add user\n");
	(num == 162) ? printf(">Delete user<\n") : printf("Delete user\n");
	(num == 163) ? printf(">View all users<\n") : printf("View all users\n");
}

void useradd(int num)
{
	char cbuffer[20];
	//int ibuffer;

	FILE* file;
	setlocale(LC_ALL, "Russian");

	system("cls");
	fopen_s(&file, "users.txt", "a+");

	printf("User login:");
	gets_s(cbuffer);
	while (getchar() != '\n') {
		continue;
	}
	fprintf(file, "%s ", cbuffer);
	*cbuffer = '\0';

	printf("User password:");
	gets_s(cbuffer);
	fprintf(file, "%s ", cbuffer);
	*cbuffer = '\0';

	fclose(file);
}

void userreg(int num)
{
	string login;
	string pasword;
	string rlogin = "1234";
	string rpasword = "1234";
	int prov;

	do
	{
		system("cls");
		printf("Enter Login:");
		cin >> login;
		printf("Enter Pasword:");
		cin >> pasword;

		if (rlogin == login && rpasword == pasword)
		{
			(num == 31) ? printf(">Login<\n") : printf("Login\n");
			prov = 1;
		}
		else
		{
			prov = 0;
		}
	} while (prov != 1);
}

void usermenu(int num)
{
	system("cls");
	printf("User panel\n");
	(num == 41) ? printf(">View all data in tabular form<\n") : printf("View all data in tabular form\n");
	(num == 42) ? printf(">Completing the task<\n") : printf("Completing the task\n");
	(num == 43) ? printf(">Various data search and filtering procedures<\n") : printf("Various data search and filtering procedures\n");
}

int main()
{
	bool running = true;
	int pressed = 1;

	while (running)
	{
		if (pressed > 0 && pressed < 3)                       //Меню первого уровня
		{
			main_menu(pressed);
			pressed = keybHit(pressed);
		}

		else if (pressed > 10 && pressed < 12)               //Меню админа   
		{
			adminreg(pressed);
			pressed = keybHit(pressed);
		}
		else if (pressed > 20 && pressed < 27)
		{
			adminmenu(pressed);
			pressed = keybHit(pressed);
		}
		else if (pressed > 160 && pressed < 164)
		{
			adminuserad(pressed);
			pressed = keybHit(pressed);
		}
		else if (pressed > 170 && pressed < 172)
		{
			cin.clear();
			while (cin.get() != '\n');
			cin.get();
			useradd(pressed);
			pressed = keybHit(pressed);
		}




		else if (pressed > 30 && pressed < 32)
		{
			userreg(pressed);
			pressed = keybHit(pressed);
		}
		else if (pressed > 40 && pressed < 44)
		{
			usermenu(pressed);
			pressed = keybHit(pressed);
		}
		else if (pressed == 69) running = false;
	}
}
