#include <fstream>
#include <iostream>
using namespace std;

#include <stdlib.h>
#include <string>
#include <conio.h>



int txtDekiToplamSayi=0;
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
    cout << "1.Kıyafet Ürün Girişi" << endl;
    cout << "2.Kurye Ekleme" << endl;
    cout << "3.Şikayet ve Öneri Okuma" << endl;
    cout << "4.İndirim Kodu Tanımlama" << endl;
    cout << "5.Sipariş Faturalarının Görüntülenmesi" << endl;

    int yoneticiEkraniGirdi;
    cin >> yoneticiEkraniGirdi;

    switch (yoneticiEkraniGirdi)
    {
    case 1:
        // burası yapılacak ilk
        cout << "Ürün girişi için" << endl;
        
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



void musteriEkrani() {
    cout << "--- Doğrulandı ---" << endl;
    cout << "1.Kıyafet kategorilerini göster" << endl;
    cout << "2.Sipariş takip" << endl;
    cout << "3.Şikayet/Öneriler(Geri bildirimler)" << endl;
    cout << "4.Şifre Değiştir" << endl;
    cout << "5.Geri Dön" << endl;
    int musteriEkraniGirdi;
    cin >> musteriEkraniGirdi;
    switch (musteriEkraniGirdi)
    {
    case 1:
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

void yoneticiMusteriGirisi() {
    cout << "1. Yönetici girişi" << endl;
    cout << "2. Müşteri girişi" << endl;
    cout << "\n";

    int yoneticiMusteriGirisi;
    cin >> yoneticiMusteriGirisi;

    switch (yoneticiMusteriGirisi)
    {
    case 1:
        system("CLS");
        cout << "İsminizi Giriniz" << endl;
        cout << "Eğer 2 isim sahibi iseniz boşluk bırakmayacak şekilde giriniz.." << endl;
        cin >> uygDakiYoneticiIsmi;
        cout << "Soy İsminizi Giriniz.." << endl;
        cin >> uygDakiYoneticiSoyIsmi;
        system("CLS");
        cout << "Sifrenizi Giriniz" << endl;
        cout << "Maksimum 10 karakter girebilirsiniz.." << endl;
        cin >> uygDakiYoneticiSifresi;
        
        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1) {
            system("CLS");
            cout << "--- Doğrulandı ---\n" << endl;
            yoneticiEkrani();
            break;
        }
        else { cout << "Giriş Bilgileri Hatalı..\a\n" << endl; }

        
        break;
    case 2:
        system("CLS");
        cout << "İsminizi Giriniz" << endl;
        cout << "Eğer 2 isim sahibi iseniz boşluk bırakmayacak şekilde giriniz.." << endl;
        cin >> uygDakiYoneticiIsmi;
        cout << "Soy İsminizi Giriniz.." << endl;
        cin >> uygDakiYoneticiSoyIsmi;
        system("CLS");
        cout << "Sifrenizi Giriniz" << endl;
        cout << "Maksimum 10 karakter girebilirsiniz.." << endl;
        cin >> uygDakiYoneticiSifresi;

        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1) {
            system("CLS");
            cout << "--- Doğrulandı ---\n" << endl;
            // müşteri ekranları
            break;
        }
        else { cout << "Giriş Bilgileri Hatalı..\a\n" << endl; }


        break;
    }
}

bool uyeSifreCheck(string name) {
    for (size_t i = 0; i < sizeof(name)-1; i++)
    {
        if (name[i] == '*' | '+' | '-' | '/'  ){
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
//bool uyeEPosta(string ePosta) {
//
//}


void uyeKaydiEkrani() {
    string uyeIsım;
    string uyeSoyIsım;
    string uyeSifre;
    string uyeDTarihi;
    string uygEPosta;
    cout << "Lütfen isminizi giriniz.." << endl;
    cin >> uyeIsım;
    cout << "Lütfen Soyisminizi giriniz.." << endl;
    cin >> uyeSoyIsım;
    cout << "Lütfen Şifrenizi Giriniz.." << endl;
    cin >> uyeSifre;
    cout << "Lütfen Dogum Tarihinizi Giriniz.." << endl;
    cin >> uyeDTarihi;
    uyeDTarihiCheck(uyeDTarihi);
    cout << "Lütfen E-Posta Adresinizi Giriniz.." << endl;
    cin >> uygEPosta;
    
    
}

void anaMenu() {
    cout << "1. Sisteme giriş" << endl;
    cout << "2. Üye kaydı" << endl;
    cout << "3. Çıkış Menüsü" << endl;
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
        cout << "3 Seçenekten birini seçip enter'a basın..\a\n" << endl;
        break;
    }
}




int main()
{

    setlocale(LC_ALL, "Turkish");
    anaMenu();
    
   
    //isimSoyisimSifreKontrol("Huseyin", "Aslan", "456");
    //cout << boolIsimSoyisimSifreKontrol;
}

