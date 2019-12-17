#pragma once
#include<string>
using namespace std;
/**
* @brief	: Bir class yapisi olusturuldu, classin icine struct yapisi kuruldu. Bu struct sayesinde kuyruk olusturuldu.
*/
class Kuyruk {
	public:
		Kuyruk();
		~Kuyruk();
		void isBasvurusuEkle();
		void isBasvurusuSil();
		void isBasvurusuListele() const;
		void isBasvuruSayisi() const;
		double isBasvurusuYasOrt();
		void isBasvurusuCinsiyetOrani() const;
		bool bosMu() const;
		bool doluMu() const;
	private:
		struct dizi {
			string isim;
			string soyisim;
			string email;
			int yas;
			string GNO;
			char cinsiyet;
		};
		int boyut = 10;
		dizi *basvuru = new dizi[boyut];
		int kuyruk_bas;
		int kuyruk_son;
		int elemanlar;
};
