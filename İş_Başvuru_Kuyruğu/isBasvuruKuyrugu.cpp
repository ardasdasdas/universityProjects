#include<iostream>
#include<iomanip>
#include"isBasvuruKuyrugu.h"
int i = 0;
int erkek = 0, kadin = 0;
/**
* @brief	: Class yapisi icerisindeki ilk degerler atandi.
*/
Kuyruk::Kuyruk() {
	kuyruk_bas = 0;
	kuyruk_son = 0;
	elemanlar = 0;
}
/**
* @brief	: Class yapisi silindi.
*/
Kuyruk::~Kuyruk() {
}
/**
* @brief	: Gelen is basvurularini kuyruga ekler.
*/
void Kuyruk::isBasvurusuEkle() {
	cout << "İsim giriniz: ";
	cin >> basvuru[i].isim;
	cout << "Soy isim giriniz: ";
	cin >> basvuru[i].soyisim;
	cout << "E-Mail giriniz: ";
	cin >> basvuru[i].email;
	cout << "Yas giriniz: ";
	cin >> basvuru[i].yas;
	cout << "GNO giriniz: ";
	cin >> basvuru[i].GNO;
	cout << "Cinsiyet giriniz [E]?[K]: ";
	cin >> basvuru[i].cinsiyet;
	if (basvuru[i].cinsiyet == 'E' || basvuru[i].cinsiyet == 'e')
		erkek++;
	if(basvuru[i].cinsiyet == 'K' || basvuru[i].cinsiyet == 'k')
		kadin++;
	kuyruk_son++;
	elemanlar++;
	i++;
}
/**
* @brief	: Gelen is basvurularini kuyruktan siler.
*/
void Kuyruk::isBasvurusuSil() {
	int temp = -1;
	dizi tmp;
	temp = kuyruk_bas;
	kuyruk_bas++;
	if (kuyruk_bas == boyut)
		kuyruk_bas = 0;
	cout << basvuru[temp].isim << " " << basvuru[temp].soyisim << " silindi." << endl;

	for (int i = 0; i < elemanlar - 1; i++)
	{
		basvuru[i] = basvuru[i + 1];
	}
	if (basvuru[temp].cinsiyet == 'E' || basvuru[temp].cinsiyet == 'e')
		erkek--;
	else if (basvuru[temp].cinsiyet == 'K' || basvuru[temp].cinsiyet == 'k')
		kadin--;
	elemanlar--;
}
/**
* @brief	: Gelen is basvurularini ekrana listeler, herhangi bir deger degisitirilmedigi icin const tanimlanmıştır.
*/
void Kuyruk::isBasvurusuListele() const {
	cout << left << setw(30) << "İsim";
	cout << left << setw(30) << "Soyisim";
	cout << left << setw(30) << "Yas";
	cout << left << setw(30) << "GNO";
	cout << left << setw(30) << "E-Mail";
	cout << left << setw(30) << "Cinsiyet" << endl;
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	cout << left << setw(30) << "-----------";
	for (int i = 0; i < elemanlar; i++)
	{
		cout << endl;
		cout << left << setw(30) << basvuru[i].isim;
		cout << left << setw(30) << basvuru[i].soyisim;
		cout << left << setw(30) << basvuru[i].yas;
		cout << left << setw(30) << basvuru[i].GNO;
		cout << left << setw(30) << basvuru[i].email;
		cout << left << setw(30) << basvuru[i].cinsiyet;
	}
}
/**
* @brief	: Gelen is basvurularinin kac tane oldugunu ekrana bastirir, herhangi bir deger degisitirilmedigi icin const tanimlanmıştır.
*/
void Kuyruk::isBasvuruSayisi() const {
	cout << elemanlar << " kişi başvurmuştur." << endl;
}
/**
* @brief	: Basvuru yapanlarin yas ortalamasini hesaplar ve double deger olarak dondurur.
*/
double Kuyruk::isBasvurusuYasOrt()
{
	double toplam = 0;
	for (int i = 0; i < elemanlar; i++)
	{
		toplam += basvuru[i].yas;
	}
	return toplam / elemanlar;
}
/**
* @brief	: Gelen is basvurularinin cinsiyet oranini yuzde olarak hesaplar ve ekrana bastirir, herhangi bir deger degisitirilmedigi icin const tanimlanmıştır.
*/
void Kuyruk::isBasvurusuCinsiyetOrani() const {
	double yuzde;
	yuzde = 100.0 / elemanlar;
	yuzde *= erkek;
	cout << "Başvuru yapanların kadınlar %" << 100 - yuzde << " erkekler %" << yuzde << endl;
}
/**
* @brief	: Kuyrugun bos olup olmadigini kontrol eder, herhangi bir deger degisitirilmedigi icin const tanimlanmıştır.
*/
bool Kuyruk::bosMu() const {
	return (elemanlar == 0 && kuyruk_bas == i);
}
/**
* @brief	: Kuyrugun dolu olup olmadigini kontrol eder, herhangi bir deger degisitirilmedigi icin const tanimlanmıştır.
*/
bool Kuyruk::doluMu() const {
	return (elemanlar == boyut && kuyruk_son == i);
}