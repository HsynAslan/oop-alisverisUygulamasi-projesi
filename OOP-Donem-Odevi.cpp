#include <fstream>
#include <iostream>
#include <cstring>  
#include <stdlib.h>
#include <string>
#include <string.h>
#include <conio.h>
#include "kisi.h"
using namespace std;
#define MAX_NAME_LEN 60

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



        size_t found3 = tekBirSatir.find(boslukArama, found2+1); // 3.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk3 = found3;
        string txtDekiSifre = tekBirSatir.substr(found2 + 1,(found3 - found2)-1); // sifreyi cekme // hata var




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
        system("CLS");
        cout << "Hangi Kategöriye Ekleme Yapmak İstiyorsunuz..\n" << endl;
        // Elbise, Tişört, Pantolon, Gömlek, Etek ve Ayakkabı
        cout << "1.Elbise\n2.Tişort\n3.Pantolon\n4.Gömlek\n5.Etek\n6.Ayakkabı" << endl;

        int kategoriGirdi;
        cin >> kategoriGirdi;

        if (kategoriGirdi == 1) {                                       // elbise
            system("CLS");
            string tekBirSatir1;
            ifstream dosyaOkuma("elbise.txt");

            //kaç satır olduğunu bilmeliyiz
            int güncelSatirSayisi = 1;
            while (getline(dosyaOkuma, tekBirSatir1)) {
                güncelSatirSayisi++;
            }
            dosyaOkuma.close();

            ofstream guncelSatirSayisiYazma;
            guncelSatirSayisiYazma.open("elbise.txt", ios_base::app);
            guncelSatirSayisiYazma << güncelSatirSayisi << "-";
            guncelSatirSayisiYazma.close();


            cout << "Lütfen Renk Bilgisini Giriniz.. (! Tek Karakter Giriniz M K B S !)\n" << endl;
            char eklenmekIstenenUrunRengi;
            cin >> eklenmekIstenenUrunRengi;

            ofstream renkYazma;
            renkYazma.open("elbise.txt", ios_base::app);
            renkYazma << eklenmekIstenenUrunRengi << "-";
            renkYazma.close();


            cout << "Ürününüzün İsmini Giriniz - (string !! tek kelime)\n" << endl;
            string eklenmekIstenenUrunIsmi;
            cin >> eklenmekIstenenUrunIsmi;

            ofstream isimYazma;
            isimYazma.open("elbise.txt", ios_base::app);
            isimYazma << eklenmekIstenenUrunIsmi;
            isimYazma.close();

            cout << "Lütfen Fiyat Giriniz..\n" << endl;
            double eklenmekIstenenUrunFiyati;
            cin >> eklenmekIstenenUrunFiyati;

            ofstream fiyatYazma;
            fiyatYazma.open("elbise.txt", ios_base::app);
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati << "\n";
            fiyatYazma.close();
        }
        else if (kategoriGirdi == 2) {
            system("CLS");
            string tekBirSatir1;
            ifstream dosyaOkuma("tisort.txt");

            //kaç satır olduğunu bilmeliyiz
            int güncelSatirSayisi = 1;
            while (getline(dosyaOkuma, tekBirSatir1)) {
                güncelSatirSayisi++;
            }
            dosyaOkuma.close();

            ofstream guncelSatirSayisiYazma;
            guncelSatirSayisiYazma.open("tisort.txt", ios_base::app);
            guncelSatirSayisiYazma << güncelSatirSayisi << "-";
            guncelSatirSayisiYazma.close();


            cout << "Lütfen Renk Bilgisini Giriniz.. (! Tek Karakter Giriniz M K B S !)\n" << endl;
            char eklenmekIstenenUrunRengi;
            cin >> eklenmekIstenenUrunRengi;

            ofstream renkYazma;
            renkYazma.open("tisort.txt", ios_base::app);
            renkYazma << eklenmekIstenenUrunRengi << "-";
            renkYazma.close();


            cout << "Ürününüzün İsmini Giriniz - (string !! tek kelime)\n" << endl;
            string eklenmekIstenenUrunIsmi;
            cin >> eklenmekIstenenUrunIsmi;

            ofstream isimYazma;
            isimYazma.open("tisort.txt", ios_base::app);
            isimYazma << eklenmekIstenenUrunIsmi;
            isimYazma.close();

            cout << "Lütfen Fiyat Giriniz..\n" << endl;
            double eklenmekIstenenUrunFiyati;
            cin >> eklenmekIstenenUrunFiyati;

            ofstream fiyatYazma;
            fiyatYazma.open("tisort.txt", ios_base::app);
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati << "\n";
            fiyatYazma.close();
        }
        else if (kategoriGirdi == 3) {
            system("CLS");
            string tekBirSatir1;
            ifstream dosyaOkuma("pantolon.txt");

            //kaç satır olduğunu bilmeliyiz
            int güncelSatirSayisi = 1;
            while (getline(dosyaOkuma, tekBirSatir1)) {
                güncelSatirSayisi++;
            }
            dosyaOkuma.close();

            ofstream guncelSatirSayisiYazma;
            guncelSatirSayisiYazma.open("pantolon.txt", ios_base::app);
            guncelSatirSayisiYazma << güncelSatirSayisi << "-";
            guncelSatirSayisiYazma.close();


            cout << "Lütfen Renk Bilgisini Giriniz.. (! Tek Karakter Giriniz M K B S !)\n" << endl;
            char eklenmekIstenenUrunRengi;
            cin >> eklenmekIstenenUrunRengi;

            ofstream renkYazma;
            renkYazma.open("pantolon.txt", ios_base::app);
            renkYazma << eklenmekIstenenUrunRengi << "-";
            renkYazma.close();


            cout << "Ürününüzün İsmini Giriniz - (string !! tek kelime)\n" << endl;
            string eklenmekIstenenUrunIsmi;
            cin >> eklenmekIstenenUrunIsmi;

            ofstream isimYazma;
            isimYazma.open("pantolon.txt", ios_base::app);
            isimYazma << eklenmekIstenenUrunIsmi;
            isimYazma.close();

            cout << "Lütfen Fiyat Giriniz..\n" << endl;
            double eklenmekIstenenUrunFiyati;
            cin >> eklenmekIstenenUrunFiyati;

            ofstream fiyatYazma;
            fiyatYazma.open("pantolon.txt", ios_base::app);
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati << "\n";
            fiyatYazma.close();
        }
        else if (kategoriGirdi == 4) {
            system("CLS");
            string tekBirSatir1;
            ifstream dosyaOkuma("gomlek.txt");

            //kaç satır olduğunu bilmeliyiz
            int güncelSatirSayisi = 1;
            while (getline(dosyaOkuma, tekBirSatir1)) {
                güncelSatirSayisi++;
            }
            dosyaOkuma.close();

            ofstream guncelSatirSayisiYazma;
            guncelSatirSayisiYazma.open("gomlek.txt", ios_base::app);
            guncelSatirSayisiYazma << güncelSatirSayisi << "-";
            guncelSatirSayisiYazma.close();


            cout << "Lütfen Renk Bilgisini Giriniz.. (! Tek Karakter Giriniz M K B S !)\n" << endl;
            char eklenmekIstenenUrunRengi;
            cin >> eklenmekIstenenUrunRengi;

            ofstream renkYazma;
            renkYazma.open("gomlek.txt", ios_base::app);
            renkYazma << eklenmekIstenenUrunRengi << "-";
            renkYazma.close();


            cout << "Ürününüzün İsmini Giriniz - (string !! tek kelime)\n" << endl;
            string eklenmekIstenenUrunIsmi;
            cin >> eklenmekIstenenUrunIsmi;

            ofstream isimYazma;
            isimYazma.open("gomlek.txt", ios_base::app);
            isimYazma << eklenmekIstenenUrunIsmi;
            isimYazma.close();

            cout << "Lütfen Fiyat Giriniz..\n" << endl;
            double eklenmekIstenenUrunFiyati;
            cin >> eklenmekIstenenUrunFiyati;

            ofstream fiyatYazma;
            fiyatYazma.open("gomlek.txt", ios_base::app);
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati << "\n";
            fiyatYazma.close();
        }
        else if (kategoriGirdi == 5) {
            system("CLS");
            string tekBirSatir1;
            ifstream dosyaOkuma("etek.txt");

            //kaç satır olduğunu bilmeliyiz
            int güncelSatirSayisi = 1;
            while (getline(dosyaOkuma, tekBirSatir1)) {
                güncelSatirSayisi++;
            }
            dosyaOkuma.close();

            ofstream guncelSatirSayisiYazma;
            guncelSatirSayisiYazma.open("etek.txt", ios_base::app);
            guncelSatirSayisiYazma << güncelSatirSayisi << "-";
            guncelSatirSayisiYazma.close();


            cout << "Lütfen Renk Bilgisini Giriniz.. (! Tek Karakter Giriniz M K B S !)\n" << endl;
            char eklenmekIstenenUrunRengi;
            cin >> eklenmekIstenenUrunRengi;

            ofstream renkYazma;
            renkYazma.open("etek.txt", ios_base::app);
            renkYazma << eklenmekIstenenUrunRengi << "-";
            renkYazma.close();


            cout << "Ürününüzün İsmini Giriniz - (string !! tek kelime)\n" << endl;
            string eklenmekIstenenUrunIsmi;
            cin >> eklenmekIstenenUrunIsmi;

            ofstream isimYazma;
            isimYazma.open("etek.txt", ios_base::app);
            isimYazma << eklenmekIstenenUrunIsmi;
            isimYazma.close();

            cout << "Lütfen Fiyat Giriniz..\n" << endl;
            double eklenmekIstenenUrunFiyati;
            cin >> eklenmekIstenenUrunFiyati;

            ofstream fiyatYazma;
            fiyatYazma.open("etek.txt", ios_base::app);
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati << "\n";
            fiyatYazma.close();
        }
        else if (kategoriGirdi == 6) {
            system("CLS");
            string tekBirSatir1;
            ifstream dosyaOkuma("ayakkabi.txt");

            //kaç satır olduğunu bilmeliyiz
            int güncelSatirSayisi = 1;
            while (getline(dosyaOkuma, tekBirSatir1)) {
                güncelSatirSayisi++;
            }
            dosyaOkuma.close();

            ofstream guncelSatirSayisiYazma;
            guncelSatirSayisiYazma.open("ayakkabi.txt", ios_base::app);
            guncelSatirSayisiYazma << güncelSatirSayisi << "-";
            guncelSatirSayisiYazma.close();


            cout << "Lütfen Renk Bilgisini Giriniz.. (! Tek Karakter Giriniz M K B S !)\n" << endl;
            char eklenmekIstenenUrunRengi;
            cin >> eklenmekIstenenUrunRengi;

            ofstream renkYazma;
            renkYazma.open("ayakkabi.txt", ios_base::app);
            renkYazma << eklenmekIstenenUrunRengi << "-";
            renkYazma.close();


            cout << "Ürününüzün İsmini Giriniz - (string !! tek kelime)\n" << endl;
            string eklenmekIstenenUrunIsmi;
            cin >> eklenmekIstenenUrunIsmi;

            ofstream isimYazma;
            isimYazma.open("ayakkabi.txt", ios_base::app);
            isimYazma << eklenmekIstenenUrunIsmi;
            isimYazma.close();

            cout << "Lütfen Fiyat Giriniz..\n" << endl;
            double eklenmekIstenenUrunFiyati;
            cin >> eklenmekIstenenUrunFiyati;

            ofstream fiyatYazma;
            fiyatYazma.open("ayakkabi.txt", ios_base::app);
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati << "\n";
            fiyatYazma.close();
        }
        else { cout << "Yanlış bir değer girdiniz 1 - 6 işaretlemelisiniz..\a\n"; }

    
    }
}

void oneriSikayetYazma() {
    cout << "Öneri ve Yorumunuzu yazabilirsiniz..\n" << endl;
    
    string onerigirdi;

    ofstream sikayetdosyayayazma;
    sikayetdosyayayazma.open("oneri.txt", ios_base::app);
    sikayetdosyayayazma << uygDakiYoneticiIsmi <<" "<<uygDakiYoneticiSoyIsmi<<": ";
    sikayetdosyayayazma.close();

    while (getline(cin,onerigirdi))
    {
        ofstream sikayetdosyayayazma;
        sikayetdosyayayazma.open("oneri.txt", ios_base::app);
        sikayetdosyayayazma << onerigirdi;
        sikayetdosyayayazma.close();
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
        system("CLS");
        oneriSikayetYazma();
        break;
    case 4:
        cout << "4.worked" << endl;
    case 5:
        cout << "5.worked" << endl;
    }
}

bool yoneticiMusteriCheck(string name, string lastName, string password) {
// yonetici ise 1 dondursun, değilse 0 dondursun
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



        size_t found3 = tekBirSatir.find(boslukArama, found2 + 1); // 3.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk3 = found3;
        string txtDekiSifre = tekBirSatir.substr(found2 + 1, found3 - found2); // sifreyi cekme // hata var


        if (txtDekiIsim == name && txtDekiSoyIsim == lastName && txtDekiSifre == password) {
            if (tekBirSatir.length() == txtDekiIsim.length() + txtDekiSoyIsim.length() + txtDekiSifre.length() + 2) {
                // burada ise yoneticidir

                return true;
            }
            /*boolIsimSoyisimSifreKontrol = true;*/
            // burada ise musteridir
            return false;
        }
    }// while bitişi
    dosyaOkuma.close();
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
        // yonetici ve musteri girisi kontrol
        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1 && yoneticiMusteriCheck(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi)==1) {
            
            kisi kisi1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
            yonetici yonetici1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi);
            


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

        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1 && yoneticiMusteriCheck(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 0) {
            
            // kisi kisi2(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
            // // kullanici(string isim, string soyisim, string sifre2, string dTarihi2, string ePosta2) : kisi(isim, soyisim)
            // kullanici kullanici1();

            kisi kisi2(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
            kullanici kullanici1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi);

            system("CLS");
            cout << "--- Doğrulandı ---\n" << endl;
            musteriEkrani();
            break;
        }
        else { cout << "Giriş Bilgileri Hatalı..\a\n" << endl; }


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
    while (uyeSifreCheck(uyeSifre) != 1) {
        cout << "Güçsüz şifre lütfen /, *, -, + karakterlerinden birini şifrenizde bulundurun.." << endl;
        cin >> uyeSifre;
    }
    cout << "Lütfen Dogum Tarihinizi Giriniz.." << endl;
    cin >> uyeDTarihi;
    while (uyeDTarihiCheck(uyeDTarihi) != 1) {
        cout << "Yanlış Tarih !!\a\n" << "Lütfen ay.gün.yıl formatında doldurunuz..\n" << endl;
        cin >> uyeDTarihi;
    }
    cout << "Lütfen E-Posta Adresinizi Giriniz.." << endl;
    cin >> uygEPosta;
    while (uyeEPostaCheck(uygEPosta) != 1) {
        cout << "Yanlış E-posta !!\a\n" << "Lütfen içinde @ geçen formatta giriniz..\n" << endl;
        cin >> uygEPosta;
    }

    //ofstream dosyaYaz("dosya.txt");
    //dosyaYaz << "C++ ile yaziliyorum.";
    //dosyaYaz.close();

    /*string uyeIsım;
    string uyeSoyIsım;
    string uyeSifre;
    string uyeDTarihi;
    string uygEPosta;*/



    ofstream dosyaYaz;
    dosyaYaz.open("yonetici.txt", ios_base::app);
    dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
    dosyaYaz.close();
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
        
        
        // burda uye kaydı ekranını çağırmak yerine .h dosyasındann yararlanmalıyız bence
        break;
    case 3:
        system("CLS");
        exit(0);
        break;
    default:
        cout << "3 Seçenekten birini seçip enter'a basın..\a\n" << endl;
        break;
    }
}




int main()
{

    setlocale(LC_ALL, "turkish");
    anaMenu();
    

   
    //isimSoyisimSifreKontrol("Huseyin", "Aslan", "456");
    //cout << boolIsimSoyisimSifreKontrol;
}

