#include <iostream>
using namespace std;
#include <string>

class kisi {
public:
	kisi(string isim = "NULL", string soyisim = "NULL") {
		ad = isim;
		soyad = soyisim;
	}
	string ad;
	string soyad;
	string telNo;
	
};

class kullanici : public kisi {
public:
	kullanici(string isim = "NULL", string soyisim = "NULL", string sifre2 = "NULL", string dTarihi2 = "NULL", string ePosta2 = "NULL") : kisi(isim, soyisim) {
		// þifre dTarihi ePosta okeyse 
		sifre = sifre2;
		dTarihi = dTarihi2;
		ePosta = ePosta2;
		
		
		
		



		// txtye yazalým burda

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