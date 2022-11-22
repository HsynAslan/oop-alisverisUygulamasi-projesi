#include <iostream>
using namespace std;
#include <string>

class kisi {
public:
	kisi(string isim, string soyisim) {
		ad = isim;
		soyad = soyisim;
	}
	string ad;
	string soyad;
	string telNo;
};

class kullanici : public kisi {
public:
	kullanici(string isim, string soyisim, string sifre2, string dTarihi2, string ePosta2) : kisi(isim, soyisim) {
		sifre = sifre2;
		dTarihi = dTarihi2;
		ePosta = ePosta2;
	}
	string kullanici_adi;
	string ePosta;
	string adres_ilce;
	string sifre;
	string indirim_kodu;
	string dTarihi;
};

class yonetici : public kisi {
public:
	yonetici(string isim, string soyisim, string sifre2) :kisi(isim, soyisim) {
		sifre = sifre2;
	}
	string sifre;
};

class kurye : public kisi {
public:
	string dagitim_bitisler;
	string siparis_numaralari;
};