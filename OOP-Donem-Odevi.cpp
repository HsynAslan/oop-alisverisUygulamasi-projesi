#include <fstream>
#include <iostream>
#include <cstring>  
#include <stdlib.h>
#include <string>
#include <string.h>
#include <conio.h>
#include "kisi.h"
#include "zaman.h"
#include <ctime>
#include <cmath>
#include <chrono>
#include <Windows.h>
#include<conio.h>
using namespace std;
#define MAX_NAME_LEN 60

int txtDekiToplamSayi = 0;
bool boolIsimSoyisimSifreKontrol;
string uygDakiYoneticiIsmi;
string uygDakiYoneticiSoyIsmi;
string uygDakiYoneticiSifresi;
string bulunanDTarihi;
string bulunanEPosta;



bool uyeSifreCheck(string name) {
    for (size_t i = 0; i < sizeof(name) - 1; i++)
    {
        if (name[i] == '*' | name[i] == '+' | name[i] == '-' | name[i] == '/') {
            return true;
        }
    }
    return false;
}
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
    yoneticiekraninaDon:
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
        yoneticiEkraniGirdiGeriDonme:
        system("CLS");
        cout << "Hangi Kategöriye Ekleme Yapmak İstiyorsunuz..\n" << endl;
        // Elbise, Tişört, Pantolon, Gömlek, Etek ve Ayakkabı
        cout << "1.Elbise\n2.Tişort\n3.Pantolon\n4.Gömlek\n5.Etek\n6.Ayakkabı\n\n-1.Geri Dön\n" << endl;

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
            if (güncelSatirSayisi != 1) { // NULL değil ise
                ofstream altSatiraGecme;
                altSatiraGecme.open("elbise.txt", ios_base::app);
                altSatiraGecme << "\n";
                altSatiraGecme.close();
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
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati;
            fiyatYazma.close();

            cout << "Eklendi.." << endl;
            int geriDonn;
            do
            {
                cout << "Geriye Dönmek için -1 tuşlayınız.." << endl;
                cin >> geriDonn;
            } while (geriDonn!=-1);

            goto yoneticiEkraniGirdiGeriDonme;
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
            if (güncelSatirSayisi != 1) { // NULL değil ise
                ofstream altSatiraGecme;
                altSatiraGecme.open("tisort.txt", ios_base::app);
                altSatiraGecme << "\n";
                altSatiraGecme.close();
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
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati;
            fiyatYazma.close();

            cout << "Eklendi.." << endl;
            int geriDonn;
            do
            {
                cout << "Geriye Dönmek için -1 tuşlayınız.." << endl;
                cin >> geriDonn;
            } while (geriDonn != -1);

            goto yoneticiEkraniGirdiGeriDonme;
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
            if (güncelSatirSayisi != 1) { // NULL değil ise
                ofstream altSatiraGecme;
                altSatiraGecme.open("pantolon.txt", ios_base::app);
                altSatiraGecme << "\n";
                altSatiraGecme.close();
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
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati;
            fiyatYazma.close();

            cout << "Eklendi.." << endl;
            int geriDonn;
            do
            {
                cout << "Geriye Dönmek için -1 tuşlayınız.." << endl;
                cin >> geriDonn;
            } while (geriDonn != -1);

            goto yoneticiEkraniGirdiGeriDonme;
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
            if (güncelSatirSayisi != 1) { // NULL değil ise
                ofstream altSatiraGecme;
                altSatiraGecme.open("gomlek.txt", ios_base::app);
                altSatiraGecme << "\n";
                altSatiraGecme.close();
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
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati;
            fiyatYazma.close();

            cout << "Eklendi.." << endl;
            int geriDonn;
            do
            {
                cout << "Geriye Dönmek için -1 tuşlayınız.." << endl;
                cin >> geriDonn;
            } while (geriDonn != -1);

            goto yoneticiEkraniGirdiGeriDonme;
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
            if (güncelSatirSayisi != 1) { // NULL değil ise
                ofstream altSatiraGecme;
                altSatiraGecme.open("etek.txt", ios_base::app);
                altSatiraGecme << "\n";
                altSatiraGecme.close();
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
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati;
            fiyatYazma.close();

            cout << "Eklendi.." << endl;
            int geriDonn;
            do
            {
                cout << "Geriye Dönmek için -1 tuşlayınız.." << endl;
                cin >> geriDonn;
            } while (geriDonn != -1);

            goto yoneticiEkraniGirdiGeriDonme;
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
            if (güncelSatirSayisi != 1) { // NULL değil ise
                ofstream altSatiraGecme;
                altSatiraGecme.open("ayakkabi.txt", ios_base::app);
                altSatiraGecme << "\n";
                altSatiraGecme.close();
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
            fiyatYazma << "-" << eklenmekIstenenUrunFiyati;
            fiyatYazma.close();

            cout << "Eklendi.." << endl;
            int geriDonn;
            do
            {
                cout << "Geriye Dönmek için -1 tuşlayınız.." << endl;
                cin >> geriDonn;
            } while (geriDonn != -1);

            goto yoneticiEkraniGirdiGeriDonme;
        }
        else if (kategoriGirdi == -1) {
            goto yoneticiekraninaDon;
        }
        else { cout << "Yanlış bir değer girdiniz 1 - 6 işaretlemelisiniz..\a\n"; }

    case 5: // faturaların görüntülenmesi
        ifstream dosyaOkuma("fatura.txt");
        string tekbirsatirr;
        system("CLS");
        while (getline(dosyaOkuma, tekbirsatirr)) {
            cout << tekbirsatirr << endl;
        }
        dosyaOkuma.close();
        
        int geriyeeDon;
        
        do
        {
            
            cout << "\n Geriye Dönmek İçin -1 Tuşlayınız.." << endl;
            cin >> geriyeeDon;
        } while (geriyeeDon!=-1);
        goto yoneticiekraninaDon;
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
bool numaraCheck(string numara) {
    string tekBirSatir;
    string kisaCizgiArama = "-";
    ifstream dosyaOkuma("elbise.txt");
    while (getline(dosyaOkuma, tekBirSatir))
    {
        size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
        if (found != string::npos)
            int oAnkiCizgi = found;
        string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
        if (txtdekiNumara == numara) {
            return true;
            break;
        }
    }
    return false;
    dosyaOkuma.close();
}
void kiyafetKategorileriGoster() {
kiyafetKategorilerineGeriDon:
    fflush(stdin); // sonsuz döngüye girmesin buffer temizlemek için
    system("CLS");
    cout << "1.Elbise\n2.Tişort\n3.Pantolon\n4.Gömlek\n5.Etek\n6.Ayakkabı\n-1.Geri Dön\n" << endl;
    int kiyafetKategoriGirdi;
    yanlışSecimBasaDon:
    fflush(stdin); // sonsuz döngüye girmesin buffer temizlemek için
    cin >> kiyafetKategoriGirdi;
    system("CLS");
    if(kiyafetKategoriGirdi==1){

        ifstream dosyaOkuma("elbise.txt");
        string tekbirsatirr;
        while (getline(dosyaOkuma, tekbirsatirr)) {
            cout << tekbirsatirr << endl;
        }
        dosyaOkuma.close();
        string cikisİcinGirdi;

        cout << "Sepetinize Eklemek İstediğiniz Ürünün Numarasını Tuşlayınız.." << endl;
        cout << "Eğer Geri Dönmek İstiyorsanız -1 tuşlayın" << endl;
        cin >> cikisİcinGirdi;
        // elbiseden istediği numara kontrol edilip ürün bilgileri fatura adlı txtye atılmalı
        if (cikisİcinGirdi == "-1") {
            // geri dönüşüm yapılmalı
            goto kiyafetKategorilerineGeriDon;
            cout << "geri dön " << endl;
        }
        else
        {
            if (numaraCheck(cikisİcinGirdi) == true) { // öyle bir numara var ise
                // o numarayı fatura txtye atmak lazım

                string tekBirSatir;
                string kisaCizgiArama = "-";
                ifstream dosyaOkuma("elbise.txt");
                while (getline(dosyaOkuma, tekBirSatir))
                {
                    size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
                    if (found != string::npos)
                        int oAnkiCizgi = found;
                    string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
                    if (txtdekiNumara == cikisİcinGirdi) {
                        // o satiri başka bir txtye yazma

                        /*ofstream dosyaYaz;
                        dosyaYaz.open("yonetici.txt", ios_base::app);
                        dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
                        dosyaYaz.close();*/

                        ofstream faturayaYazma;
                        faturayaYazma.open("fatura.txt", ios_base::app);

                        cout << "Beden Bilgisi Giriniz.. (S, M, L, XL, XXL vs..)" << endl;
                        string bedenBilgisi;
                        cin >> bedenBilgisi;
                        faturayaYazma << uygDakiYoneticiIsmi << " " << uygDakiYoneticiSoyIsmi << "/" << "ZAMAN" << "/";//zaman gelcek buraya




                        faturayaYazma << tekBirSatir << "/" << bedenBilgisi << "\n";
                        cout << "Ürün Faturaya Geçildi" << endl;
                        cout << "Devam etmek için -1 tuşlayınız.." << endl;
                        int geridon = 0;
                        while (geridon != -1)
                        {
                            cin >> geridon;
                        }
                        goto kiyafetKategorilerineGeriDon;
                    }
                }
                dosyaOkuma.close();
            }
            else
            {
                cout << "Yanlış Tuşlama Yaptınız.." << endl;
            }

        }

    }
    // else if ler
    else if (kiyafetKategoriGirdi == 2) {
        {

            ifstream dosyaOkuma("tisort.txt");
            string tekbirsatirr;
            while (getline(dosyaOkuma, tekbirsatirr)) {
                cout << tekbirsatirr << endl;
            }
            dosyaOkuma.close();
            string cikisİcinGirdi;

            cout << "Sepetinize Eklemek İstediğiniz Ürünün Numarasını Tuşlayınız.." << endl;
            cout << "Eğer Geri Dönmek İstiyorsanız -1 tuşlayın" << endl;
            cin >> cikisİcinGirdi;
            // elbiseden istediği numara kontrol edilip ürün bilgileri fatura adlı txtye atılmalı
            if (cikisİcinGirdi == "-1") {
                // geri dönüşüm yapılmalı
                goto kiyafetKategorilerineGeriDon;
                cout << "geri dön " << endl;
            }
            else
            {
                if (numaraCheck(cikisİcinGirdi) == true) { // öyle bir numara var ise
                    // o numarayı fatura txtye atmak lazım

                    string tekBirSatir;
                    string kisaCizgiArama = "-";
                    ifstream dosyaOkuma("tisort.txt");
                    while (getline(dosyaOkuma, tekBirSatir))
                    {
                        size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
                        if (found != string::npos)
                            int oAnkiCizgi = found;
                        string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
                        if (txtdekiNumara == cikisİcinGirdi) {
                            // o satiri başka bir txtye yazma

                            /*ofstream dosyaYaz;
                            dosyaYaz.open("yonetici.txt", ios_base::app);
                            dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
                            dosyaYaz.close();*/

                            ofstream faturayaYazma;
                            faturayaYazma.open("fatura.txt", ios_base::app);

                            cout << "Beden Bilgisi Giriniz.. (S, M, L, XL, XXL vs..)" << endl;
                            string bedenBilgisi;
                            cin >> bedenBilgisi;
                            faturayaYazma << uygDakiYoneticiIsmi << " " << uygDakiYoneticiSoyIsmi << "/" << "ZAMAN" << "/";//zaman gelcek buraya




                            faturayaYazma << tekBirSatir << "/" << bedenBilgisi << "\n";
                            cout << "Ürün Faturaya Geçildi" << endl;
                            cout << "Devam etmek için -1 tuşlayınız.." << endl;
                            int geridon = 0;
                            while (geridon != -1)
                            {
                                cin >> geridon;
                            }
                            goto kiyafetKategorilerineGeriDon;
                        }
                    }
                    dosyaOkuma.close();
                }
                else
                {
                    cout << "Yanlış Tuşlama Yaptınız.." << endl;
                }

            }

        }
    }
    else if(kiyafetKategoriGirdi == 3){
        {

            ifstream dosyaOkuma("pantolon.txt");
            string tekbirsatirr;
            while (getline(dosyaOkuma, tekbirsatirr)) {
                cout << tekbirsatirr << endl;
            }
            dosyaOkuma.close();
            string cikisİcinGirdi;

            cout << "Sepetinize Eklemek İstediğiniz Ürünün Numarasını Tuşlayınız.." << endl;
            cout << "Eğer Geri Dönmek İstiyorsanız -1 tuşlayın" << endl;
            cin >> cikisİcinGirdi;
            // elbiseden istediği numara kontrol edilip ürün bilgileri fatura adlı txtye atılmalı
            if (cikisİcinGirdi == "-1") {
                // geri dönüşüm yapılmalı
                goto kiyafetKategorilerineGeriDon;
                cout << "geri dön " << endl;
            }
            else
            {
                if (numaraCheck(cikisİcinGirdi) == true) { // öyle bir numara var ise
                    // o numarayı fatura txtye atmak lazım

                    string tekBirSatir;
                    string kisaCizgiArama = "-";
                    ifstream dosyaOkuma("pantolon.txt");
                    while (getline(dosyaOkuma, tekBirSatir))
                    {
                        size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
                        if (found != string::npos)
                            int oAnkiCizgi = found;
                        string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
                        if (txtdekiNumara == cikisİcinGirdi) {
                            // o satiri başka bir txtye yazma

                            /*ofstream dosyaYaz;
                            dosyaYaz.open("yonetici.txt", ios_base::app);
                            dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
                            dosyaYaz.close();*/

                            ofstream faturayaYazma;
                            faturayaYazma.open("fatura.txt", ios_base::app);

                            cout << "Beden Bilgisi Giriniz.. (S, M, L, XL, XXL vs..)" << endl;
                            string bedenBilgisi;
                            cin >> bedenBilgisi;
                            faturayaYazma << uygDakiYoneticiIsmi << " " << uygDakiYoneticiSoyIsmi << "/" << "ZAMAN" << "/";//zaman gelcek buraya




                            faturayaYazma << tekBirSatir << "/" << bedenBilgisi << "\n";
                            cout << "Ürün Faturaya Geçildi" << endl;
                            cout << "Devam etmek için -1 tuşlayınız.." << endl;
                            int geridon = 0;
                            while (geridon != -1)
                            {
                                cin >> geridon;
                            }
                            goto kiyafetKategorilerineGeriDon;
                        }
                    }
                    dosyaOkuma.close();
                }
                else
                {
                    cout << "Yanlış Tuşlama Yaptınız.." << endl;
                }

            }

        }
    }
    else if (kiyafetKategoriGirdi == 4) {
        {

            ifstream dosyaOkuma("gomlek.txt");
            string tekbirsatirr;
            while (getline(dosyaOkuma, tekbirsatirr)) {
                cout << tekbirsatirr << endl;
            }
            dosyaOkuma.close();
            string cikisİcinGirdi;

            cout << "Sepetinize Eklemek İstediğiniz Ürünün Numarasını Tuşlayınız.." << endl;
            cout << "Eğer Geri Dönmek İstiyorsanız -1 tuşlayın" << endl;
            cin >> cikisİcinGirdi;
            // elbiseden istediği numara kontrol edilip ürün bilgileri fatura adlı txtye atılmalı
            if (cikisİcinGirdi == "-1") {
                // geri dönüşüm yapılmalı
                goto kiyafetKategorilerineGeriDon;
                cout << "geri dön " << endl;
            }
            else
            {
                if (numaraCheck(cikisİcinGirdi) == true) { // öyle bir numara var ise
                    // o numarayı fatura txtye atmak lazım

                    string tekBirSatir;
                    string kisaCizgiArama = "-";
                    ifstream dosyaOkuma("gomlek.txt");
                    while (getline(dosyaOkuma, tekBirSatir))
                    {
                        size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
                        if (found != string::npos)
                            int oAnkiCizgi = found;
                        string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
                        if (txtdekiNumara == cikisİcinGirdi) {
                            // o satiri başka bir txtye yazma

                            /*ofstream dosyaYaz;
                            dosyaYaz.open("yonetici.txt", ios_base::app);
                            dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
                            dosyaYaz.close();*/

                            ofstream faturayaYazma;
                            faturayaYazma.open("fatura.txt", ios_base::app);

                            cout << "Beden Bilgisi Giriniz.. (S, M, L, XL, XXL vs..)" << endl;
                            string bedenBilgisi;
                            cin >> bedenBilgisi;
                            faturayaYazma << uygDakiYoneticiIsmi << " " << uygDakiYoneticiSoyIsmi << "/" << "ZAMAN" << "/";//zaman gelcek buraya




                            faturayaYazma << tekBirSatir << "/" << bedenBilgisi << "\n";
                            cout << "Ürün Faturaya Geçildi" << endl;
                            cout << "Devam etmek için -1 tuşlayınız.." << endl;
                            int geridon = 0;
                            while (geridon != -1)
                            {
                                cin >> geridon;
                            }
                            goto kiyafetKategorilerineGeriDon;
                        }
                    }
                    dosyaOkuma.close();
                }
                else
                {
                    cout << "Yanlış Tuşlama Yaptınız.." << endl;
                }

            }

        }
    }
    else if (kiyafetKategoriGirdi == 5) {
        {

            ifstream dosyaOkuma("etek.txt");
            string tekbirsatirr;
            while (getline(dosyaOkuma, tekbirsatirr)) {
                cout << tekbirsatirr << endl;
            }
            dosyaOkuma.close();
            string cikisİcinGirdi;

            cout << "Sepetinize Eklemek İstediğiniz Ürünün Numarasını Tuşlayınız.." << endl;
            cout << "Eğer Geri Dönmek İstiyorsanız -1 tuşlayın" << endl;
            cin >> cikisİcinGirdi;
            // elbiseden istediği numara kontrol edilip ürün bilgileri fatura adlı txtye atılmalı
            if (cikisİcinGirdi == "-1") {
                // geri dönüşüm yapılmalı
                goto kiyafetKategorilerineGeriDon;
                cout << "geri dön " << endl;
            }
            else
            {
                if (numaraCheck(cikisİcinGirdi) == true) { // öyle bir numara var ise
                    // o numarayı fatura txtye atmak lazım

                    string tekBirSatir;
                    string kisaCizgiArama = "-";
                    ifstream dosyaOkuma("etek.txt");
                    while (getline(dosyaOkuma, tekBirSatir))
                    {
                        size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
                        if (found != string::npos)
                            int oAnkiCizgi = found;
                        string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
                        if (txtdekiNumara == cikisİcinGirdi) {
                            // o satiri başka bir txtye yazma

                            /*ofstream dosyaYaz;
                            dosyaYaz.open("yonetici.txt", ios_base::app);
                            dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
                            dosyaYaz.close();*/

                            ofstream faturayaYazma;
                            faturayaYazma.open("fatura.txt", ios_base::app);

                            cout << "Beden Bilgisi Giriniz.. (S, M, L, XL, XXL vs..)" << endl;
                            string bedenBilgisi;
                            cin >> bedenBilgisi;
                            faturayaYazma << uygDakiYoneticiIsmi << " " << uygDakiYoneticiSoyIsmi << "/" << "ZAMAN" << "/";//zaman gelcek buraya




                            faturayaYazma << tekBirSatir << "/" << bedenBilgisi << "\n";
                            cout << "Ürün Faturaya Geçildi" << endl;
                            cout << "Devam etmek için -1 tuşlayınız.." << endl;
                            int geridon = 0;
                            while (geridon != -1)
                            {
                                cin >> geridon;
                            }
                            goto kiyafetKategorilerineGeriDon;
                        }
                    }
                    dosyaOkuma.close();
                }
                else
                {
                    cout << "Yanlış Tuşlama Yaptınız.." << endl;
                }

            }

        }
    }
    else if (kiyafetKategoriGirdi == 6) {
        {

            ifstream dosyaOkuma("ayakkabi.txt");
            string tekbirsatirr;
            while (getline(dosyaOkuma, tekbirsatirr)) {
                cout << tekbirsatirr << endl;
            }
            dosyaOkuma.close();
            string cikisİcinGirdi;

            cout << "Sepetinize Eklemek İstediğiniz Ürünün Numarasını Tuşlayınız.." << endl;
            cout << "Eğer Geri Dönmek İstiyorsanız -1 tuşlayın" << endl;
            cin >> cikisİcinGirdi;
            // elbiseden istediği numara kontrol edilip ürün bilgileri fatura adlı txtye atılmalı
            if (cikisİcinGirdi == "-1") {
                // geri dönüşüm yapılmalı
                goto kiyafetKategorilerineGeriDon;
                cout << "geri dön " << endl;
            }
            else
            {
                if (numaraCheck(cikisİcinGirdi) == true) { // öyle bir numara var ise
                    // o numarayı fatura txtye atmak lazım

                    string tekBirSatir;
                    string kisaCizgiArama = "-";
                    ifstream dosyaOkuma("ayakkabi.txt");
                    while (getline(dosyaOkuma, tekBirSatir))
                    {
                        size_t found = tekBirSatir.find(kisaCizgiArama); // ilk cizgi bulma
                        if (found != string::npos)
                            int oAnkiCizgi = found;
                        string txtdekiNumara = tekBirSatir.substr(0, found); // ilk cizgi cekme
                        if (txtdekiNumara == cikisİcinGirdi) {
                            // o satiri başka bir txtye yazma

                            /*ofstream dosyaYaz;
                            dosyaYaz.open("yonetici.txt", ios_base::app);
                            dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta << "\n";
                            dosyaYaz.close();*/

                            ofstream faturayaYazma;
                            faturayaYazma.open("fatura.txt", ios_base::app);

                            cout << "Beden Bilgisi Giriniz.. (S, M, L, XL, XXL vs..)" << endl;
                            string bedenBilgisi;
                            cin >> bedenBilgisi;
                            faturayaYazma << uygDakiYoneticiIsmi << " " << uygDakiYoneticiSoyIsmi << "/" << "ZAMAN" << "/";//zaman gelcek buraya




                            faturayaYazma << tekBirSatir << "/" << bedenBilgisi << "\n";
                            cout << "Ürün Faturaya Geçildi" << endl;
                            cout << "Devam etmek için -1 tuşlayınız.." << endl;
                            int geridon = 0;
                            while (geridon != -1)
                            {
                                cin >> geridon;
                            }
                            goto kiyafetKategorilerineGeriDon;
                        }
                    }
                    dosyaOkuma.close();
                }
                else
                {
                    cout << "Yanlış Tuşlama Yaptınız.." << endl;
                }

            }

        }
    }
    else {
        cout << "Lütfen 1..6 veya -1 sayılarını tuşlayınız..\a" << endl;
        goto yanlışSecimBasaDon;
    }
}

void sifreDegistirme(string name, string  lastName, string  password, string  newPassword, string dTarihi, string ePosta) {
    string tekBirSatir;
    string boslukArama = " ";
    ifstream dosyaOkuma("yonetici.txt");
    int sayici = 1;
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
        string txtDekiSifre = tekBirSatir.substr(found2 + 1, (found3 - found2) - 1); // sifreyi cekme // hata var



        size_t found4 = tekBirSatir.find(boslukArama, found3 + 1); // 4.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk4 = found4;
        string txtDekiDTarihi = tekBirSatir.substr(found3 + 1, (found4 - found3) - 1); // DTarihi cekme
        


        size_t found5 = tekBirSatir.find(boslukArama, found4 + 1); // 4.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk5 = found5;
        string txtDekiEPosta = tekBirSatir.substr(found4 + 1, (found5 - found4) - 1); // ePosta cekme


        if (txtDekiIsim == name && txtDekiSoyIsim == lastName && txtDekiSifre == password && txtDekiDTarihi == dTarihi && txtDekiEPosta==ePosta) {
            /*boolIsimSoyisimSifreKontrol = true;*/

            // şifre değişikliği olucak
            

             
            //cout << "Şifreniz Değişti Tekrardan Giriş Yapmak için Program Kapanıyor";

           
            
           // yeni satiri temp e yaz
            
            ofstream dosyaYazmaTempp;
            dosyaYazmaTempp.open("yonetici_temp.txt");
            dosyaYazmaTempp << name << " " << lastName << " " << newPassword << " " << dTarihi << " " << ePosta << "\n";
            dosyaYazmaTempp.close();

        }
        else
        {
            // aradığımız adam değil burası
            // 
            // copy to temp
            ofstream dosyaYazmaTemp;
            dosyaYazmaTemp.open("yonetici_temp.txt");
            dosyaYazmaTemp <<tekBirSatir << endl; // sürekli huseyin basıyopr
            dosyaYazmaTemp.close();
        }
        sayici++;
    }
    
    dosyaOkuma.close();

}
void tarihveEPostaBulma(string name, string lastName, string password) {
    string tekBirSatir;
    string boslukArama = " ";
    ifstream dosyaOkuma("yonetici.txt");
    
    int sayici = 1;
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
        string txtDekiSifre = tekBirSatir.substr(found2 + 1, (found3 - found2) - 1); // sifreyi cekme // hata var



        size_t found4 = tekBirSatir.find(boslukArama, found3 + 1); // 4.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk4 = found4;
        string txtDekiDTarihi = tekBirSatir.substr(found3 + 1, (found4 - found3) - 1); // DTarihi cekme



        size_t found5 = tekBirSatir.find(boslukArama, found4 + 1); // 4.boslugu bulma
        if (found != string::npos) // found2 ?
            int oAnkiBosluk5 = found5;
        string txtDekiEPosta = tekBirSatir.substr(found4 + 1, (found5 - found4) - 1); // ePosta cekme

        if (txtDekiIsim == name && txtDekiSoyIsim == lastName && txtDekiSifre == password) {
            bulunanDTarihi = txtDekiDTarihi;
            bulunanEPosta = txtDekiEPosta;

        }
    }
}
void musteriEkrani() {
    cout << "1.Kıyafet kategorilerini göster" << endl;
    cout << "2.Sipariş takip" << endl;
    cout << "3.Şikayet/Öneriler(Geri bildirimler)" << endl;
    cout << "4.Şifre Değiştir" << endl;
    cout << "5.Geri Dön" << endl;
    int musteriEkraniGirdi;
    cin >> musteriEkraniGirdi;
    if (musteriEkraniGirdi == 1) {
        kiyafetKategorileriGoster();
    }
    else if(musteriEkraniGirdi==3){ oneriSikayetYazma(); }
    else if (musteriEkraniGirdi==4){
        cout << "Yeni Şifrenizi Giriniz.. " << endl;;
        string yeniSifre;

        do
        {
            system("CLS");
            cout << "(içinde /, *, -, + olmalı)" << endl;


            //cout << "Please enter login password:";
            char s[10] = { 0 };
            int i;
            for (i = 0; i < 10; i++) {
                s[i] = _getch();
                if (s[i] == 13) {
                    break;
                }
                else {
                    _putch('*');
                }
            };
            //printf("\nYour pass is %s", s);
            getchar();

            yeniSifre = s;
            yeniSifre.pop_back();




            // cin >> yeniSifre;
        } while (uyeSifreCheck(yeniSifre) != 1);

        //kisi kisi2(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
        //kullanici kullanici1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi); // bunun şifresi değişecek

        //txtden bulup şifreyi de değiştirmeliyiz
        tarihveEPostaBulma(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi);
        sifreDegistirme(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi, yeniSifre ,bulunanDTarihi, bulunanEPosta); // çalışmıyor
       
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
        string txtDekiSifre = tekBirSatir.substr(found2 + 1, found3 - found2-1); // sifreyi cekme // hata var


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


    if (yoneticiMusteriGirisi == 1) {
        system("CLS");
        cout << "İsminizi Giriniz" << endl;
        cout << "Eğer 2 isim sahibi iseniz boşluk bırakmayacak şekilde giriniz.." << endl;
        cin >> uygDakiYoneticiIsmi;
        cout << "Soy İsminizi Giriniz.." << endl;
        cin >> uygDakiYoneticiSoyIsmi;
        system("CLS");
        cout << "Sifrenizi Giriniz" << endl;
        cout << "Maksimum 10 karakter girebilirsiniz.." << endl;



        //cout << "Please enter login password:";
        char s[10] = { 0 };
        int i;
        for (i = 0; i < 10; i++) {
            s[i] = _getch();
            if (s[i] == 13) {
                break;
            }
            else {
                _putch('*');
            }
        };
        //printf("\nYour pass is %s", s);
        getchar();
        
        uygDakiYoneticiSifresi = s;
        uygDakiYoneticiSifresi.pop_back();


        // cin >> uygDakiYoneticiSifresi;
        // yonetici ve musteri girisi kontrol
        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1 && yoneticiMusteriCheck(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1) {

            kisi kisi1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
            yonetici yonetici1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi);



            system("CLS");
            cout << "--- Doğrulandı ---\n" << endl;
            yoneticiEkrani();
            
        }
        else { cout << "Giriş Bilgileri Hatalı..\a\n" << endl; }


        
    }
    else if (yoneticiMusteriGirisi == 2) {
        system("CLS");
        cout << "İsminizi Giriniz" << endl;
        cout << "Eğer 2 isim sahibi iseniz boşluk bırakmayacak şekilde giriniz.." << endl;
        cin >> uygDakiYoneticiIsmi;
        cout << "Soy İsminizi Giriniz.." << endl;
        cin >> uygDakiYoneticiSoyIsmi;
        system("CLS");
        cout << "Sifrenizi Giriniz" << endl;
        cout << "Maksimum 10 karakter girebilirsiniz.." << endl;


        //cout << "Please enter login password:";
        char s[10] = { 0 };
        int i;
        for (i = 0; i < 10; i++) {
            s[i] = _getch();
            if (s[i] == 13) {
                break;
            }
            else {
                _putch('*');
            }
        };
        //printf("\nYour pass is %s", s);
        getchar();

        uygDakiYoneticiSifresi = s;
        uygDakiYoneticiSifresi.pop_back();


        // cin >> uygDakiYoneticiSifresi;

        if (isimSoyisimSifreKontrol(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 1 && yoneticiMusteriCheck(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi) == 0) {

            // kisi kisi2(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
            // // kullanici(string isim, string soyisim, string sifre2, string dTarihi2, string ePosta2) : kisi(isim, soyisim)
            // kullanici kullanici1();

            kisi kisi2(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi);
            kullanici kullanici1(uygDakiYoneticiIsmi, uygDakiYoneticiSoyIsmi, uygDakiYoneticiSifresi); // bunun şifresi değişecek

            system("CLS");
            cout << "--- Doğrulandı ---\n" << endl;
            musteriEkrani();
            
        }
        else { cout << "Giriş Bilgileri Hatalı..\a\n" << endl; }


        
    }
    
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
    cout << "Lütfen isminizi giriniz.. (string)" << endl;
    cin >> uyeIsım;
    cout << "Lütfen Soyisminizi giriniz.. (string)" << endl;
    cin >> uyeSoyIsım;
    cout << "Lütfen Şifrenizi Giriniz.. (içinde +, -, *, / bulunmak zorunda yoksa hata verir)" << endl;


    //cout << "Please enter login password:";
    char s[10] = { 0 };
    int i;
    for (i = 0; i < 10; i++) {
        s[i] = _getch();
        if (s[i] == 13) {
            break;
        }
        else {
            _putch('*');
        }
    };
    //printf("\nYour pass is %s", s);
    getchar();

    uyeSifre = s;
    uyeSifre.pop_back();



    // cin >> uyeSifre;
    while (uyeSifreCheck(uyeSifre) != 1) {
        cout << "Güçsüz şifre lütfen /, *, -, + karakterlerinden birini şifrenizde bulundurun.." << endl;
        
        cin >> uyeSifre;
    }
    cout << "Lütfen Dogum Tarihinizi Giriniz.. ( 06.06.2001 formatında yoksa hata verir)" << endl;
    cin >> uyeDTarihi;
    while (uyeDTarihiCheck(uyeDTarihi) != 1) {
        cout << "Yanlış Tarih !!\a\n" << "Lütfen ay.gün.yıl formatında doldurunuz..\n" << endl;
        cin >> uyeDTarihi;
    }
    cout << "Lütfen E-Posta Adresinizi Giriniz.. (icinde @ olmalk zorunda yoksa hata verir)" << endl;
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
    dosyaYaz << uyeIsım << " " << uyeSoyIsım << " " << uyeSifre << " " << uyeDTarihi << " " << uygEPosta <<"\n";
    dosyaYaz.close();
}




void faturaTemizleme() {
    ofstream ofs;
    ofs.open("fatura.txt", ofstream::out | ofstream::trunc);
    ofs.close();
    }


void anaMenu() {
anaMenuyeGeriDon:
    system("CLS");
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
        // burda uye kaydı ekranını çağırmak yerine .h dosyasındann yararlanmalıyız bence
        system("CLS");
        cout << "Kaydınız Tamamlandı.." << endl;
        cout << "Geriye Dönmek İçin -1 Tuşlayınız.." << endl;
        int geriDonme;
        cin >> geriDonme;

        while (geriDonme != -1) {
            cout << "Yanlış bir değer girdiniz Lütfen -1 tuşlayınız..\a" << endl;
            cin >> geriDonme;
        }
        fflush(stdin); // sonsuz döngüye girmesin buffer temizlemek için
        goto anaMenuyeGeriDon;
        break;
    case 3:
        system("CLS");
        // fatura temizlenmeli

        faturaTemizleme();

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

