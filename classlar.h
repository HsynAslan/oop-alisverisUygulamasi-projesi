#include <iostream>
using namespace std;
#include <string>
class kisi {
public:
	string ad_soyad;
	string telNo;
};

class kiyafet {
public:
	string kategori;
	int kiyafet_adi;
	double fiyat;
	string boyut;
	string renk;
};

class zaman {
public:
	int saat;
	int dakika;
};

class siparis :public kiyafet {
public:
	int siparis_no;
	double siparis_fiyat;
	zaman siparis_baslangic;
	zaman siparis_ulasim;
};

class kullanici :public kisi {
public:
	string kullanici_adi;
	string ePosta;
	string adres_ilce;
	string sifre;
	string indirimKodu;
	string dogumTarihi;
};

class yonetici :public kisi {
public:
	string sifre;
};

class kurye : public kisi {
public:
	zaman dagitim_bitisler;
	int siparis_numaralari;
};