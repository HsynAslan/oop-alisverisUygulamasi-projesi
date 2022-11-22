#include <fstream>
#include <iostream>
#include <cstring>  
#include <stdlib.h>
#include <string>
#include <string.h>
#include <conio.h>
using namespace std;

int txtDekiToplamSayi = 0;
bool boolIsimSoyisimSifreKontrol;
string uygDakiYoneticiIsmi;
string uygDakiYoneticiSoyIsmi;
string uygDakiYoneticiSifresi;


bool isimSoyisimSifreKontrol(string name, string lastName, string password) { // string name, string lastName, int password
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
        string txtDekiSoyIsim = tekBirSatir.substr(found + 1, found2 - found - 1); // soyismi cekme
        string txtDekiSifre = tekBirSatir.substr(found2 + 1); // sifreyi cekme
        if (txtDekiIsim == name && txtDekiSoyIsim == lastName && txtDekiSifre == password) {
            /*boolIsimSoyisimSifreKontrol = true;*/
            return true;
        }
    }
    return false;
    dosyaOkuma.close();
}


void yoneticiEkrani() {
    cout << "1.K�yafet �r�n Giri�i" << endl;
    cout << "2.Kurye Ekleme" << endl;
    cout << "3.�ikayet ve �neri Okuma" << endl;
    cout << "4.�ndirim Kodu Tan�mlama" << endl;
    cout << "5.Sipari� Faturalar�n�n G�r�nt�lenmesi" << endl;

    int yoneticiEkraniGirdi;
    cin >> yoneticiEkraniGirdi;

    switch (yoneticiEkraniGirdi)
    {
    case 1:
        // buras� yap�lacak ilk
        cout << "�r�n giri�i i�in" << endl;

        cout << "1.worked" << endl;
    case 2:
        cout << "2.worked" << endl;
    case 3:
        cout << "3.worked" << endl;
    case 4:
        cout << "4.worked" << endl;
    case 5:
        cout << "5.worked" << endl;
    }
}

void oneriSikayetYazma() {
    /*cout << "l�tfen yazmak istedi�iniz �neri veya �ikayeti yazd�ktan sonra enter'a bas�n�z.." << endl;
    char *onerigirdi;
    cin >> onerigirdi;
    cout << "oneri:" << onerigirdi << endl;*/


    // burda kald�m 13.10.2022

    /*ofstream sikayetDosyayaYazma;
    sikayetDosyayaYazma.open("oneri.txt", ios_base::app);
    sikayetDosyayaYazma << oneriGirdi;
    sikayetDosyayaYazma.close();*/
}

void musteriEkrani() {
    cout << "--- Do�ruland� ---" << endl;
    cout << "1.K�yafet kategorilerini g�ster" << endl;
    cout << "2.Sipari� takip" << endl;
    cout << "3.�ikayet/�neriler(Geri bildirimler)" << endl;
    cout << "4.�ifre De�i�tir" << endl;
    cout << "5.Geri D�n" << endl;
    int musteriEkraniGirdi;
    cin >> musteriEkraniGirdi;
    switch (musteriEkraniGirdi)
    {
    case 1:
        cout << "1.worked" << endl;
    case 2:
        cout << "2.worked" << endl;
    case 3:
        system("CLS");
        oneriSikayetYazma();
        break;
    case 4:
        cout << "4.worked" << endl;
    case 5:
        cout << "5.worked" << endl;
    }



}

void yoneticiMusteriGirisi() {
    cout << "1. Y�netici giri�i" << endl;
    cout << "2. M��teri giri�i" << endl;
    cout << "\n";

    int yoneticiMusteriGirisi;
    cin >> yoneticiMusteriGirisi;

    switch (yoneticiMusteriGirisi)
    {
    case 1:
        system("CLS");
        cout << "�sminizi Giriniz" << endl;
        cout << "E�er 2 isim sahibi iseniz bo�luk b�rakmayacak �ekilde giriniz.." << endl;
        cin >> uygDakiYoneticiIsmi;
        cout << "Soy �sminizi Giriniz.." << endl;
        cin >> uygDakiYoneticiSoyIsmi;
        system("CLS");
        cout << "Sifrenizi Giriniz" << endl;
        cout << "Maksimum 10 karakter girebilirsiniz.." << endl;
        cin >> uygDakiYoneticiSifresi;

        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1) {
            system("CLS");
            cout << "--- Do�ruland� ---\n" << endl;
            yoneticiEkrani();
            break;
        }
        else { cout << "Giri� Bilgileri Hatal�..\a\n" << endl; }


        break;
    case 2:
        system("CLS");
        cout << "�sminizi Giriniz" << endl;
        cout << "E�er 2 isim sahibi iseniz bo�luk b�rakmayacak �ekilde giriniz.." << endl;
        cin >> uygDakiYoneticiIsmi;
        cout << "Soy �sminizi Giriniz.." << endl;
        cin >> uygDakiYoneticiSoyIsmi;
        system("CLS");
        cout << "Sifrenizi Giriniz" << endl;
        cout << "Maksimum 10 karakter girebilirsiniz.." << endl;
        cin >> uygDakiYoneticiSifresi;

        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1) {
            system("CLS");
            cout << "--- Do�ruland� ---\n" << endl;
            musteriEkrani();
            break;
        }
        else { cout << "Giri� Bilgileri Hatal�..\a\n" << endl; }


        break;
    }
}

bool uyeSifreCheck(string name) {
    for (size_t i = 0; i < sizeof(name) - 1; i++)
    {
        if (name[i] == '*' | name[i] == '+' | name[i] == '-' | name[i] == '/') {
            return true;
        }
    }
    return false;
}
bool uyeDTarihiCheck(string tarih) {
    if (sizeof(tarih) == 10 && tarih[2], tarih[5] == '.') {
        int gun = stoi(tarih.substr(0, 2)); // stoi string to int
        int ay = stoi(tarih.substr(3, 2));
        int yil = stoi(tarih.substr(6, 4));
        if ((gun <= 31 && gun > 0) && (ay >= 1 && ay <= 12) && (yil >= 1900 && yil <= 2021))
            return true;
    }
    return false;

}
bool uyeEPostaCheck(string ePosta) {
    for (int i = 0; i < sizeof(ePosta); i++)
    {
        if (ePosta[i] == '@') {
            return true;
        }
    }
    return false;
}


void uyeKaydiEkrani() {
    string uyeIs�m;
    string uyeSoyIs�m;
    string uyeSifre;
    string uyeDTarihi;
    string uygEPosta;
    cout << "L�tfen isminizi giriniz.." << endl;
    cin >> uyeIs�m;
    cout << "L�tfen Soyisminizi giriniz.." << endl;
    cin >> uyeSoyIs�m;
    cout << "L�tfen �ifrenizi Giriniz.." << endl;
    cin >> uyeSifre;
    while (uyeSifreCheck(uyeSifre) != 1) {
        cout << "G��s�z �ifre l�tfen /, *, -, + karakterlerinden birini �ifrenizde bulundurun.." << endl;
        cin >> uyeSifre;
    }
    cout << "L�tfen Dogum Tarihinizi Giriniz.." << endl;
    cin >> uyeDTarihi;
    while (uyeDTarihiCheck(uyeDTarihi) != 1) {
        cout << "Yanl�� Tarih !!\a\n" << "L�tfen ay.g�n.y�l format�nda doldurunuz..\n" << endl;
        cin >> uyeDTarihi;
    }
    cout << "L�tfen E-Posta Adresinizi Giriniz.." << endl;
    cin >> uygEPosta;
    while (uyeEPostaCheck(uygEPosta) != 1) {
        cout << "Yanl�� E-posta !!\a\n" << "L�tfen i�inde @ ge�en formatta giriniz..\n" << endl;
        cin >> uygEPosta;
    }

    //ofstream dosyaYaz("dosya.txt");
    //dosyaYaz << "C++ ile yaziliyorum.";
    //dosyaYaz.close();

    /*string uyeIs�m;
    string uyeSoyIs�m;
    string uyeSifre;
    string uyeDTarihi;
    string uygEPosta;*/



    ofstream dosyaYaz;
    dosyaYaz.open("yonetici.txt", ios_base::app);
    dosyaYaz << uyeIs�m << " " << uyeSoyIs�m << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
    dosyaYaz.close();
}

void anaMenu() {
    cout << "1. Sisteme giri�" << endl;
    cout << "2. �ye kayd�" << endl;
    cout << "3. ��k�� Men�s�" << endl;
    cout << "\n";

    int anaMenuGirdi;
    cin >> anaMenuGirdi;

    switch (anaMenuGirdi) {
    case 1:
        system("CLS");
        yoneticiMusteriGirisi();
        break;
    case 2:
        system("CLS");
        uyeKaydiEkrani();
        break;
    case 3:
        system("CLS");
        cout << "3" << endl;
        break;
    default:
        cout << "3 Se�enekten birini se�ip enter'a bas�n..\a\n" << endl;
        break;
    }
}

