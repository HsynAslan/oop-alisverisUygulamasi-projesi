#include <iostream>
using namespace std;
#include <string>

class kiyafet {
public:
	kiyafet(string categories = "NULL", int nameID = -1, double price = -1, string size = "NULL", char color = 'X') {
		kategori = categories;
		kiyafet_adi = nameID;
		fiyat = price;
		boyut = size;
		renk = color;
	}
	string kategori;
	int kiyafet_adi;
	double fiyat;
	string boyut;
	char renk;
};