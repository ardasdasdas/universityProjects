/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com |
* @date		: 4 Kasim 2019 Pazartesi
* @brief	: Bu kod Veri Yapilari Lab 3 icin yazilmis bir koddur. Basit bir Is Basvurusu kodudur. Class yapisi ve class icerisinde struct kullanýlmýstýr. Dizi yapisindan kuyruk olusturulmustur.
*/
#include<iostream>
#include"isBasvuruKuyrugu.h"
#include<conio.h>
#include<iomanip>.
#include<locale.h>
#include<Windows.h>
using namespace std;
int count;
Kuyruk K;//Bir kuyruk oluþturuldu.
/**
* @brief	: Bu fonksiyon, oluþturulan liste uzerinde hangi iþlemi yapacagýmýza erismemizi saglar.
*/
void menu()
{
	int secim;
	do {
		cout << "\t MENÜ \n";
		cout << "\n\t[1] - Baþvuru Ekle";
		cout << "\n\t[2] - Baþvuru Sil";
		cout << "\n\t[3] - Baþvurularý Listele";
		cout << "\n\t[4] - Basvuru Sayýsý";
		cout << "\n\t[5] - Baþvuru Yaþ Ortalamasý";
		cout << "\n\t[6] - Baþvuru Cinsisiyet Oraný";
		cout << "\n\t[7] - Çýkýþ";
		cout << "\n\n Bir seçenek giriniz: ";
		cin >> secim;
		system("cls");
		if (secim <= 0 || secim > 9 || cin.fail())//Herhangi bir hatali giriste ana menüye geri gidilmesi icin yazýldý.
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
		else if (secim == 1)
		{
			if (K.doluMu())
				cout << "Kuyruk dolu." << endl;
			else
				K.isBasvurusuEkle();				
		}
		else if(secim == 2)
		{
			if (K.bosMu())
				cout << "Kuyruk boþ." << endl;
			else
				K.isBasvurusuSil();
		}
		else if (secim == 3)
		{
			if (K.bosMu())
				cout << "Kuyruk boþ." << endl;
			else
			{
				K.isBasvurusuListele();
			}
		
		}
		else if (secim == 4)
		{
			K.isBasvuruSayisi();
		}
		else if (secim == 5)
		{
			if (K.bosMu())
				cout << "Kuyruk boþ." << endl;
			else
				cout << "Baþvuranlarýn yaþ ortalamasý -> " << K.isBasvurusuYasOrt() << endl;
		}
		else if (secim == 6)
		{
			if (K.bosMu())
				cout << "Kuyruk boþ." << endl;
			else
				K.isBasvurusuCinsiyetOrani();
		}
		else if (secim == 7)
			exit(0);
		cout << endl << "Menüye dönmek için bir tuþa basýnýz." << endl;
		_getch();
		system("cls");
	} while (secim != 'Q' || secim != 'q');
}
int main()
{
	setlocale(LC_ALL, "Turkish");//Turkce karakterleri eklemek için eklendi.
	menu();
	system("pause");
}