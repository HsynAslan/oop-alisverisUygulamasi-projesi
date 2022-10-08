#include <fstream>
#include <iostream>
using namespace std;
#include "yonetici.h";
#include <stdlib.h>
#include <string>
int txtDekiToplamSayi=0;
bool boolIsimSoyisimSifreKontrol;
void anaMenu() {
    cout << "1. Sisteme giriş" << endl;
    cout << "2. Üye kaydı" << endl;
    cout << "3. Çıkış Menüsü" << endl;

    int anaMenuGirdi;
    cin >> anaMenuGirdi;

    switch (anaMenuGirdi) {
    case 1:
        system("CLS");
        
        break;
    case 2:
        system("CLS");
        cout << "2" << endl;
        break;
    case 3:
        system("CLS");
        cout << "3" << endl;
        break;
    }
}

void isimSoyisimSifreKontrol(string name, string lastName, string password) { // string name, string lastName, int password
    string tekBirSatir;
    string boslukArama = " ";
    ifstream dosyaOkuma("yonetici.txt");
    while (getline(dosyaOkuma, tekBirSatir)) {
        size_t found = tekBirSatir.find(boslukArama); // ilk bosluk bulma
        if (found != string::npos)
            int oAnkiBosluk = found;
        string txtDekiIsim = tekBirSatir.substr(0, found); // ilk kelimeyi cekme
        size_t found2 = tekBirSatir.find(boslukArama, found + 1); // 2.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk2 = found2;
        string txtDekiSoyIsim = tekBirSatir.substr(found + 1, found2 - found-1); // soyismi cekme
        string txtDekiSifre = tekBirSatir.substr(found2+1); // sifreyi cekme
        if (txtDekiIsim == name && txtDekiSoyIsim == lastName && txtDekiSifre == password) {  
            boolIsimSoyisimSifreKontrol = true;
            return;
            break;
        }  
    }  
    dosyaOkuma.close();
}



int main()
{

    setlocale(LC_ALL, "Turkish");
    // anaMenu();
    
   
    isimSoyisimSifreKontrol("Huseyin", "Aslan", "456");
    cout << boolIsimSoyisimSifreKontrol;
}

