/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com
* @date		: 11 Ekim 2019 Cuma
* @brief	: Bu kod Veri Yapýlarý Lab 1 icin yazýlmýþ bir koddur. Basit bir ogrenci bilgi sistemi kodudur.
*/
#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>//_getch() fonksiyonunu kullanmak icin eklendi.
#include<iomanip>//setw() fonksiyonu ve left komutunu kullanmak icin eklendi.
#include<locale.h>//Koda Türkçe karakterleri eklemek icin eklendi.
using namespace std;
struct liste {
	int OgrNo;
	string isim;
	int Not;
};
int ogrenciSayisi, i, j, k, min, mak;
double ort = 0;
/**
* @brief	: Bu fonksiyon girilen ogrenci sayisi kadar rastgele isim, ogrenci numarasi ve not uretir.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void RastgeleOgrenci(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencileri duzgun bir sekilde ekrana yazdirir. Menu fonksiyonunun icerisinde calisir.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void listele(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden numarasi girilen ogrencinin notunu degistirmemizi saglar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void degistir(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini hesaplar.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini icerir.
*/
void min_mak_ort_Hesaplama(struct liste *ogrenci, int ogrenciSayisi, int &min, int &mak, double &ort);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini ekrana yazdirir.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini icerir.
*/
void min_mak_ort_Yazdýrma(struct liste *ogrenci, int &ogrenciSayisi, int &min, int &mak, double &ort);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerini notlarina gore buyukten kucuge dogru siralar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void kabarcik_siralama(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden, kullanicidan alinan k. en buyuk sayiyi hesaplar ve ekrana yazdirir. Ayrica bu fonksiyon icerisine buuble_sort() fonksiyonunu cagirir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void k_en_buyuk_hesaplama_ve_yazdirma(struct liste *ogrenci, int &ogrenciSayisi, int k);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerde en buyuk, en kucuk not alan(lar)i, not ortalamalarini ve k. en buyuk nota erismemizi saglar. Ayrica bu fonksiyon min_mak_ort_Yazdýrma() ve k_en_buyuk_hesaplama_ve_yazdirma() fonksiyonlarini icerir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void istatistik(struct liste *ogrenci, int &ogrenciSayisi);
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerin bilgileri uzerinde hangi islemi yapacagimiza erismemizi saglar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void menu(struct liste *ogrenci, int &ogrenciSayisi);
int main()
{
	system("color 30");//Ekraný açýk mavi yapmak için yazýldý.
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	cout << "Öðrenci sayýsýný giriniz: ";
	cin >> ogrenciSayisi;
	if (ogrenciSayisi == 0)//Öðrenci sayýsýnýn tam sayý bir deðer olmasý gerektiði icin yanlýþlýkla tam sayý dýþýnda bir girdi alýnmasý engellenmesi adýna if else yapýsý kullanýldý.
	{
		cout << "Hatalý giriþ." << endl;
		_getch();
		exit(0);
	}
	else
	{
		liste *ogrenci = new liste[ogrenciSayisi];//Mevcut öðrenci sayýsý bilinmediði icin hafýzada fazla yer tutumamak adýna struct dinamik olark oluþturuldu.
		RastgeleOgrenci(ogrenci, ogrenciSayisi);
		menu(ogrenci, ogrenciSayisi);
	}
	system("pause");
}
void RastgeleOgrenci(struct liste *ogrenci, int &ogrenciSayisi)
{
	static const string Alfabe = "abcdefgðhýijklmnopqrsþtuvüwxyz";//Rastgele harf alabilmek icin alfabe sabit bir stringe yazýldý.
	string rastgeleHarf = "", str;
	for (i = 0; i < ogrenciSayisi; i++)
	{
		for (j = 0; j < rand() % 25; j++)//Kac harfli isim olacaðý rastgele üretildi.
		{
			rastgeleHarf += Alfabe[rand() % Alfabe.size()];
		}
		ogrenci[i].isim = rastgeleHarf;

		if (ogrenci[i].isim == "")
			i--;
		rastgeleHarf = "";
	}
	ogrenci[0].OgrNo = rand() % 10000;
	for (i = 1; i < ogrenciSayisi; i++)
	{
		ogrenci[i].OgrNo = ogrenci[i - 1].OgrNo + 1;

	}
	for (i = 0; i < ogrenciSayisi; i++)
	{
		ogrenci[i].Not = rand() % 99 + 1;
	}
}
void listele(struct liste *ogrenci, int &ogrenciSayisi)
{
	cout << "\t******Öðrenci Listesi******\n\n";
	cout << left << setw(30) << "Ýsim";
	cout << left << setw(30) << "Öðrenci No";
	cout << left << setw(30) << "Not" << endl;
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";

	for (int i = 0; i < ogrenciSayisi; i++)
	{
		cout << endl;
		cout << left << setw(30) << ogrenci[i].isim;
		cout << left << setw(30) << ogrenci[i].OgrNo;
		cout << left << setw(30) << ogrenci[i].Not;
	}
	cout << endl;
}
void degistir(struct liste *ogrenci, int &ogrenciSayisi)
{
	cout << "\t******Deðiþtir Menüsü******\n\n";
	listele(ogrenci, ogrenciSayisi);
	int OgrenciNo, yeniNot;
	cout << "Ogrenci no giriniz: ";
	cin >> OgrenciNo;
	if (cin.fail())
	{
		cout << "Hatalý giriþ! Program sonlanýyor." << endl << endl;
		_getch();
		exit(0);

	}
	for (i = 0; i < ogrenciSayisi; i++)
	{
		if (ogrenci[i].OgrNo == OgrenciNo)
		{
			cout << ogrenci[i].OgrNo << "(" << ogrenci[i].isim << ")" << "öðrencisi için yeni notu (" << ogrenci[i].Not << ") giriniz: ";
			cin >> yeniNot;
			if (yeniNot > 100)
			{
				system("color A0");//Ekraný yeþil yapmak için yazýldý.
				cout << endl << "Bonusun sýnýrý yok :)" << endl;
			}
			if (yeniNot < 0)
			{
				system("color 40");//Ekraný kýrmýzý yapmak için yazýldý.
				cout << endl << "Puan kýrmanýn sýnýrý yok!" << endl;
			}
			ogrenci[i].Not = yeniNot;
			break;
		}
		else if (i == ogrenciSayisi - 1)
		{
			cout << "Hatalý numara girdiniz. Lütfen tekrar giriniz: " << endl;
			cin >> OgrenciNo;
			i = 0;
		}
	}
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini hesaplar.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini içerir.
*/
void min_mak_ort_Hesaplama(struct liste *ogrenci, int ogrenciSayisi, int &min, int &mak, double &ort)
{
	min = ogrenci[0].Not;
	mak = ogrenci[0].Not;

	for (i = 0; i < ogrenciSayisi; i++)
	{
		ort += ogrenci[i].Not;
		if (mak < ogrenci[i].Not)
		{
			mak = ogrenci[i].Not;
		}
		if (min > ogrenci[i].Not)
		{
			min = ogrenci[i].Not;
		}
	}
	ort /= float(ogrenciSayisi);
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden hangi ogrenci(ler)nin en yuksek ve en dusuk not aldigini bulur ve not ortalamasini ekrana yazdirir.
* @param	: Pointer struct, ogrenci sayisi, minimum, maksimum ve ortalama parametrelerini içerir.
*/
void min_mak_ort_Yazdýrma(struct liste *ogrenci, int &ogrenciSayisi, int &min, int &mak, double &ort)
{
	min_mak_ort_Hesaplama(ogrenci, ogrenciSayisi, min, mak, ort);
	cout << "***************************************************" << endl;
	for (i = 0; i < ogrenciSayisi; i++)
	{
		if (ogrenci[i].Not == min)
			cout << "min -> " << min << "(" << ogrenci[i].OgrNo << " numaralý " << ogrenci[i].isim << " isimli öðrenci)" << endl;
	}
	for (i = 0; i < ogrenciSayisi; i++)
	{
		if (ogrenci[i].Not == mak)
			cout << "mak -> " << mak << "(" << ogrenci[i].OgrNo << " numarali " << ogrenci[i].isim << " isimli öðrenci)" << endl;
	}
	cout << "ort -> " << ort << endl << endl;
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerini notlarina gore buyukten kucuge dogru siralar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void kabarcik_siralama(struct liste *ogrenci, int &ogrenciSayisi)
{
	liste temp;
	for (int i = 1; i < ogrenciSayisi; i++)
	{
		for (int j = 0; j < ogrenciSayisi - i; j++)
		{
			if (ogrenci[j].Not < ogrenci[j + 1].Not)
			{
				temp = ogrenci[j];
				ogrenci[j] = ogrenci[j + 1];
				ogrenci[j + 1] = temp;
			}
		}
	}
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerden, kullanicidan alinan k. en buyuk sayiyi hesaplar ve ekrana yazdirir. Ayrica bu fonksiyon icerisine buuble_sort() fonksiyonunu cagirir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void k_en_buyuk_hesaplama_ve_yazdirma(struct liste *ogrenci, int &ogrenciSayisi, int k)
{
	cout << "k deðerini giriniz: ";
	cin >> k;
	if (k > ogrenciSayisi || k < 0)
	{
		cout << endl << "Girdiðiniz sýrada bir öðrenci yoktur." << endl;
	}
	else
	{
		kabarcik_siralama(ogrenci, ogrenciSayisi);
		min_mak_ort_Hesaplama(ogrenci, ogrenciSayisi, min, mak, ort);
		cout << "Azalan sýralamadaki " << k << ". not ->" << ogrenci[k - 1].Not << "(" << ogrenci[k - 1].OgrNo << " numaralý " << ogrenci[k - 1].isim << "'li(ý) öðrenci)" << endl;
		cout << endl;
	}
}
/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerde en buyuk, en kucuk not alan(lar)i, not ortalamalarini ve k. en buyuk nota erismemizi saglar. Ayrica bu fonksiyon min_mak_ort_Yazdýrma() ve k_en_buyuk_hesaplama_ve_yazdirma() fonksiyonlarini icerir.
* @param	: Pointer struct, ogrenci sayisi ve k parametrelerini icerir.
*/
void istatistik(struct liste *ogrenci, int &ogrenciSayisi)
{
	char secim;
	cout << "\t******Ýstatistik Menusu******\n\n";
	cout << "[1]-Seçenek-1 (en küçük, en büyük ve ortalama): " << endl;
	cout << "[2]-Seçenek 2 (k. en büyük): " << endl;
	secim = _getch();
	if (secim == '1')
	{
		min_mak_ort_Yazdýrma(ogrenci, ogrenciSayisi, min, mak, ort);
		ort = 0;
	}
	else if (secim == '2')
	{
		k_en_buyuk_hesaplama_ve_yazdirma(ogrenci, ogrenciSayisi, k);
		ort = 0;
	}
	else
	{
		system("cls");
		cout << endl << "Girdiðiniz deðerde bir seçenek bulunamadý." << endl;
	}

}/**
* @brief	: Bu fonksiyon rastgele uretilen ogrencilerin bilgileri uzerinde hangi islemi yapacagimiza erismemizi saglar.
* @param	: Pointer struct ve ogrenci sayisi parametreleri icerir.
*/
void menu(struct liste *ogrenci, int &ogrenciSayisi)
{
	char secim;
	do {
		cout << "\t MENÜ \n";
		cout << "\n\tListele - [L]";
		cout << "\n\tDeðiþtir - [D]";
		cout << "\n\tÝstatistik - [I]";
		cout << "\n\tÇýkýþ - [Q]";
		cout << "\n\n Bir seçenek giriniz: ";
		secim = _getch();
		system("cls");
		if (secim == 'L' || secim == 'l')
			listele(ogrenci, ogrenciSayisi);
		else if (secim == 'D' || secim == 'd')
			degistir(ogrenci, ogrenciSayisi);
		else if (secim == 'I' || secim == 'i' || secim == 'Ý')
			istatistik(ogrenci, ogrenciSayisi);
		else if (secim == 'Q' || secim == 'q')
			exit(0);
		else
		{
			cout << "\n\n Hatalý giriþ!";
			secim = _getch();
			system("cls");
			menu(ogrenci, ogrenciSayisi);
		}
		cout << endl << "Menüye dönmek için bir tuþa basýnýz." << endl;
		_getch();
		system("cls");
	} while (secim != 'Q' || secim != 'q');
}