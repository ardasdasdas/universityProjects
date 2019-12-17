/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com
* @date		: 21 Ekim 2019 Cuma
* @brief	: Bu kod Veri Yapilari Lab 2 icin yazilmis bir koddur.
*/
#include<iostream>
#include<cctype>
#include<iomanip>//system("cls") fonksiyonunu kullanmak icin eklendi.
#include<conio.h>
#include<locale.h>//Koda Turkce karakterleri eklemek icin eklendi.
#include<Windows.h>//Sleep fonksiyonunu kullanmak icin eklendi.
using namespace std;
typedef struct liste {
	int value;
	struct liste *pnext;
}Element;
Element *head = NULL;
Element* temp;
int sayi;
/**
* @brief	: Bu fonksiyon, olusturulan liste uzerinde hangi islemi yapacagimiza erismemizi saglar.
*/
void menu();
/**
* @brief	: Bu fonksiyon, listeye eleman ekleme islemini yapar.
* @param	: Bu fonksiyon, eklenecek olan tam sayi parametresini icerir.
*/
void ekle(int);
/**
* @brief	: Bu fonksiyon, halihazirda olan listenin arasina eleman eklemek icin kullanilir.
* @param	: Bu fonksiyon, eklenecek olan tam sayiyi ve konum parametrelerini icerir.
*/
void araya_ekle(int, int);
/**
* @brief	: Bu fonksiyon, listeden eleman islemini yapar.
* @param	: Bu fonksiyon, silinecek olan tam sayi parametresini icerir.
*/
void sil(int);
/**
* @brief	: Bu fonksiyon, listenin belirli bir noktasindan itibaren kullanicidan girilen adet kadar silme islemini yapar.
* @param	: Bu fonksiyon, kacinci konumdan itibaren ve kac adet silme parametrelerini icerir.
*/
void belirli_noktadan_itibaren_coklu_sil(int, int);
/**
* @brief	: Bu fonksiyon, listeyi kullancidan alinan bag degerinden ikiye boler.
* @param	: Bu fonksiyon, bol parametresini icerir.
*/
void bol(int);
/**
* @brief	: Bu fonksiyon, olusturulan listeyi ekrana yazdirma islemini yapar.
*/
void listele();
/**
* @brief	: Bu fonksiyon, olusturulan listenin kac elemanli olduðunu hesaplar ve degeri integer olarak dondurur.
*/
int say();
int main()
{
	setlocale(LC_ALL, "Turkish");
	menu();
	system("pause");
}
void menu()
{
	int secim, count = 1;
	do {
		cout << "\t MENÜ \n";
		cout << "\n\t[1] - Ekle";
		cout << "\n\t[2] - Araya Ekle";
		cout << "\n\t[3] - Sil";
		cout << "\n\t[4] - Belirli Noktadan Ýtibaren Çoklu Sil";
		cout << "\n\t[5] - Böl";
		cout << "\n\t[6] - Listele";
		cout << "\n\t[7] - Say";
		cout << "\n\t[8] - Çýkýþ";
		cout << "\n\n Bir seçenek giriniz: ";
		cin >> secim;
		system("cls");
		if (secim <= 0 || secim > 8 || cin.fail())
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
			cout << "Kaç sayý girmek istiyorsunuz? ";
			cin >> count;
			if (cin.fail())
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
			else
			{
				for (int i = 0; i < count; i++)
				{
					cout << "Eklemek istediðiniz sayýyý girin: ";
					cin >> sayi;
					if (cin.fail())
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
					ekle(sayi);
				}
			}
		}
		else if (secim == 2)
		{
			int yeniSayi, konum;
			cout << "Eklemek istediðiniz sayýyý giriniz: ";
			cin >> yeniSayi;
			if (cin.fail())
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
			cout << endl << "Ekelemek istediðiniz konumu giriniz: ";
			cin >> konum;
			if (cin.fail())
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
			else
				araya_ekle(yeniSayi, konum);

		}
		else if (secim == 3)
		{
			int sayi;
			cout << "Silmek istediðiniz sayýyý giriniz: ";
			cin >> sayi;
			if (cin.fail())
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
			else
			{
				for (int i = 0; i < count; i++)
					sil(sayi);
			}
		}
		else if (secim == 4)
		{
			int eleman, adet;
			cout << "Kaçýncý elemandan itibaren silmek istiyorsunuz? ";
			cin >> eleman;
			if (cin.fail())
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
			cout << endl << "Kaç adet silmek istiyorsunuz? ";
			cin >> adet;
			if (cin.fail())
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
			else
				belirli_noktadan_itibaren_coklu_sil(eleman, adet);
		}
		else if (secim == 5)
		{
			int bag;
			cout << "Kaçýncý baðdan böleceksiniz? ";
			cin >> bag;
			if (cin.fail())
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
			else
				bol(bag);
		}
		else if (secim == 6)
			listele();
		else if (secim == 7)
			say();
		else if (secim == 8)
			exit(0);
		cout << endl << "Menüye dönmek için bir tuþa basýnýz." << endl;
		_getch();
		system("cls");
	} while (secim != 'Q' || secim != 'q');
}
void ekle(int sayi)
{
	liste* element = new liste();
	element->value = sayi;
	element->pnext = NULL;
	
	if (head == NULL)
		head = element;
	else
	{
		temp = head;
		while (temp->pnext != NULL)
			temp = temp->pnext;
		temp->pnext = element;
	}

}
void listele()
{
	if (head == NULL)
		cout << "Liste Boþ" << endl;
	else
	{
		cout << "-----------------" << endl;
		temp = head;
		while (temp->pnext != NULL)
		{
			cout << temp->value << "	";
			temp = temp->pnext;
		}
		cout << temp->value;
	}
}
void sil(int sayi)
{
	liste *p = head;
	temp = p;
	if (p == 0)
		cout << "listede eleman yok" << endl;
	else if (p->pnext == 0 && p->value == sayi)
	{
		delete p;
		head = 0;
	}
	else if (p == head && p->value == sayi)
	{
		head = p->pnext;
		delete p;
	}
	else
	{
		p = p->pnext;
		while (p)
		{
			if (p->value == sayi)
			{
				temp->pnext = p->pnext;
				break;
			}
			p = p->pnext;
			temp = temp->pnext;
		}
	}
}
void araya_ekle(int yeniSayi, int konum)
{
	int counter = 0;
	liste* temp1 = new liste();
	liste* temp2 = new liste();
	temp = head;
	temp1->value = yeniSayi;
	if (konum == 0)
	{
		temp1->value = yeniSayi;
		temp = head;
		temp1->pnext = temp;
		head = temp1;
	}
	else
	{
		while (temp != NULL)
		{
			if (counter + 1 == konum)
				break;
			temp = temp->pnext;
			counter++;
		}
		temp2 = temp->pnext;
		temp->pnext = temp1;
		temp1->pnext = temp2;
	}
}
int say()
{
	int sayac = 1;
	if (head == NULL)
		cout << "Liste boþ" << endl;
	else
	{
		temp = head;
		while (temp->pnext != NULL)
		{
			temp = temp->pnext;
			sayac++;
		}
		cout << "Listede " << sayac << " tane eleman vardýr." << endl;
	}
	return sayac;
}
void belirli_noktadan_itibaren_coklu_sil(int eleman, int adet)
{
	liste *p = head;
	liste *temp1, *temp2;
	for (int i = 1; i < eleman - 1; i++)
		p = p->pnext;
	if (p == NULL)
		return;
	temp1 = p->pnext;
	for (int i = 1; i <= adet; i++)
	{
		liste *temp = temp1;
		temp1 = temp1->pnext;
		free(temp);
	}
	p->pnext = temp1;
	p = temp1;
}
void bol(int bag)
{
	int count = say(), kisim;
	liste* ilkKýsým = new liste();
	liste* ikinciKýsým = new liste();
	liste* temp1 = new liste();
	temp1 = head;
	ilkKýsým = temp1;
	if (head == NULL)
		cout << "Liste Boþ" << endl;
	else
	{
		for (int i = 0; i < bag; i++)
		{
			ilkKýsým->pnext = temp1->pnext;
		}
		for (int i = 0; i < bag; i++)
		{
			temp1 = temp1->pnext;
		}
		ikinciKýsým = temp1;
		for (int i = bag - 1; i < count; i++)
		{
			ikinciKýsým->pnext = temp1->pnext;
		}
		cout << "Ýlk Kýsým" << endl;
		for (int i = 0; i < bag; i++)
		{
			cout << ilkKýsým->value << "	";
			ilkKýsým = ilkKýsým->pnext;
		}
		cout << endl;
		cout << "Ýkinci Kýsým" << endl;

		while (ikinciKýsým->pnext != NULL)
		{
			cout << ikinciKýsým->value << "	";
			ikinciKýsým = ikinciKýsým->pnext;
		}
		cout << ikinciKýsým->value;
		cout << endl;
		cout << "Hangi kýsmý kullanacaksýnýz? [1]?[2] ";
		cin >> kisim;
		if (kisim == 1)
		{
			belirli_noktadan_itibaren_coklu_sil(bag + 1, count - bag);
		}
		if (kisim == 2)
		{
			for (int i = 0; i < bag; i++)
			{
				liste *temp1 = head;
				head = head->pnext;
				free(temp1);
			}
		}
	}
}