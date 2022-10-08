#include <iostream>
using namespace std;
#include <fstream>
class yonetici {
private:
	string isim;
	string soyIsim;
	int Sifre;
public:
	void setName(string name);
	void setLName(string lName);
	void setSifre(int password);

	string getName()const;
	string getLName()const;
	int getSifre()const;

	yonetici(string, string, int);
	yonetici(string, string, string, int);
};

void yonetici::setName(string name) {
	isim = name;
}

void yonetici::setLName(string lName) {
	soyIsim = lName;
}

void yonetici::setSifre(int password) {
	Sifre = password;
}

string yonetici::getName()const {
	return isim;
}

string yonetici::getLName()const {
	return soyIsim;
}

int yonetici::getSifre()const {
	return Sifre;
}

yonetici::yonetici(string name, string lName, int sifre) {
	cout << "Constructor Worked" << endl;
	// dosyaya yazma yeri

	// yeni yonetici girisi
	// belki isim soyIsim kontolu yapýlabilir
}

yonetici::yonetici(string, string, string,int) {
	cout << "Lütfen 2. Ýsminizi 1.isminizden sonra boþluk olmicak þekilde giriniz..\a\n" << endl;
}

