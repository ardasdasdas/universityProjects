#include "postFix_preFix.h"
#include"Stack.h"
#include<iostream>
#include<string>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<cmath>
int ust, alt;
int i = 0;
stack s1;
/**
* @brief	: Constructor fonksiyonu.
*/
postFix_preFix::postFix_preFix()
{
}
/**
* @brief	: Destructor fonksiyonu.
*/
postFix_preFix::~postFix_preFix()
{
}
/**
* @brief	: Bu fonksiyon, kullanicidan string olarak problemin alinmasini saglar.
*/
void postFix_preFix::getProblem() {
	getline(cin, str);
}
/**
* @brief	: Bu fonksiyon, postfix tarzinde kullanicidan string olarak alinan problemin sonucunu stack veri yapisini kullanarak hesaplar.
*/
void postFix_preFix::postfixCalculate() {
	while (i < str.length())
	{
		if (str[i] < 58 && str[i]>47)
		{
			s1.push(str[i] - 48);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (str[i] == '+')
				s1.push(s1.pop() + s1.pop());
			else if (str[i] == '-')
				s1.push(s1.pop() - s1.pop());
			else if (str[i] == '*')
				s1.push(s1.pop() * s1.pop());
			else if (str[i] == '/')
			{
				ust = s1.pop();
				alt = s1.pop();
				s1.push(alt / ust);
			}
			else if (str[i] == '^')
			{
				ust = s1.pop();
				alt = s1.pop();
				s1.push(pow(alt, ust));
			}
		}
		i++;
	}
	i = 0;
}
/**
* @brief	: Bu fonksiyon, prefix tarzinde kullanicidan string olarak alinan problemin sonucunu stack veri yapisini kullanarak hesaplar.
*/
void postFix_preFix::prefixCalculate() {
	int i = str.length() - 1;

	while (i >= 0)
	{
		if (str[i] < 58 && str[i] > 47)
		{
			s1.push(str[i] - 48);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (str[i] == '+')
				s1.push(s1.pop() + s1.pop());
			else if (str[i] == '-')
				s1.push(s1.pop() - s1.pop());
			else if (str[i] == '*')
				s1.push(s1.pop() * s1.pop());
			else if (str[i] == '/')
			{
				ust = s1.pop();
				alt = s1.pop();
				s1.push(alt / ust);
			}
			else if (str[i] == '^')
			{
				ust = s1.pop();
				alt = s1.pop();
				s1.push(pow(alt, ust));
			}
		}
		i--;
	}
}
/**
* @brief	: Bu fonksiyon, postfix veya prefix tarzinde kullanicidan string olarak alinan problemin sonucunu stack veri yapisini kullanarak hesaplanan sonucunu ekrana yazdirir.
*/
void postFix_preFix::display() {
	cout << endl << endl << "Sonuc -> " << s1.pop() << endl << endl << endl;
}
/**
* @brief	: String tipinde oluþturulan bu fonksiyon, postfix olarak girilen soruyu prefix hale getirir, prefix olarak girilen soruyu postfix hale getirir.
* @return	: Yeni oluþturulan str return edilir.
*/
string postFix_preFix::prefix_to_postfix() {
	string str1;
	int size = str.length();
	str1.resize(size);
	for (int i = 0; i < size; i++)
	{
		str1[i] = str[size - i - 1];
	}
	return str1;
}
/**
* @brief	: Bu fonksiyon, kullanicinin yapmak istedigi islemi secebilmesi icin yazilmistir.
*/
void postFix_preFix::menu() {
	int secim;
	postFix_preFix test;
	do {
		cout << "\t MENÜ \n";
		cout << "\n\t Hangi türde iþlem yapmak istediðnizi seçiniz.";
		cout << "\n\t[1] - Postfix";
		cout << "\n\t[2] - Prefix";
		cout << "\n\t[3] - Çýkýþ";
		cout << endl;
		cin >> secim;
		system("cls");
		if (secim <= 0 || secim > 4 || cin.fail())//Herhangi bir hatali giriste ana menüye geri gidilmesi icin yazýldý.
		{
			cout << "Hatalý giriþ! Menüye yönlendiriliyorsunuz..." << endl;
			Sleep(600);
			cout << "3" << endl;
			Sleep(600);
			cout << "2" << endl;
			Sleep(600);
			cout << "1" << endl;
			Sleep(600);
			system("cls");
			cin.clear();
			cin.ignore();
			menu();
		}
		if (secim == 1) {
			cout << "Postfix ifade giriniz:";
			cin.ignore();
			test.getProblem();
			test.postfixCalculate();
			cout << "Hesaplanýyor..." << endl;
			Sleep(400);
			cout << "3" << endl;
			Sleep(300);
			cout << "2" << endl;
			Sleep(200);
			cout << "1" << endl;
			Sleep(200);
			test.display();
			int secim2;
			cout << "Girilen deðerin postfix gösterimini görmek için [1], menüye dönmek herhangi baþka bir tuþa basýnýz.";
			cin >> secim2;
			if (secim2 == 1)
			{
				system("cls");
				cout << test.prefix_to_postfix() << endl;
				_getch();
				system("cls");
			}
			else if (secim2 == 2) {
				system("cls");
			}
		}
		else if (secim == 2) {
			cout << "Prefix ifade giriniz:";
			cin.ignore();
			test.getProblem();
			test.prefixCalculate();
			cout << "Hesaplanýyor..." << endl;
			Sleep(400);
			cout << "3" << endl;
			Sleep(300);
			cout << "2" << endl;
			Sleep(200);
			cout << "1" << endl;
			Sleep(200);
			test.display();
			int secim2;
			cout << "Girilen deðerin prefix gösterimini görmek için [1], menüye dönmek için [2].";
			cin >> secim2;
			if (secim2 == 1)
			{
				system("cls");
				cout << test.prefix_to_postfix() << endl;
				_getch();
				system("cls");
			}
			else if (secim2 == 2) {
				system("cls");
			}
		}
		else if (secim == 3)
			exit(0);
	} while (secim != 4);
}