#include <iostream>
#include "string.h"
#include "ucus.h"
#include "string.cpp"
#include "ada_gore.cpp"
#include "ucus_numarasina_gore.cpp"
#include "ucus.cpp"

int main()
{
    ucusFonksiyonlari fonksiyon;

    string sorgulama="h";
    while (sorgulama=="h" || sorgulama=="H")
    {
        int secim;
        system("cls");
        menu();
        cout << "Seciminizi giriniz: ";
        cin >> secim;
        while (secim<1 || secim>9)
        {
            if (secim==-1)
            {
                return 0;
            }
            system("cls");
            menu();
            cout << Color::Red <<"Hatali" << Color::Reset << " giris yaptiniz. Seciminizi giriniz: ";
            cin >> secim;
        }
        switch (secim)
        {
        case 1:
            fonksiyon.getUcusEko();
            break;
        case 2:
            fonksiyon.getUcusLuks();
            break;
        case 3:
            fonksiyon.getLuksKoltukSayisi();
            break;
        case 4:
            fonksiyon.getIptal();
            break;
        case 5:
            fonksiyon.getUcusBilgileri();
            break;
        case 6:
            fonksiyon.getluksKoltukListele();
            break;
        case 7:
            fonksiyon.getVarisYeriListele();
            break;
        case 8:
            fonksiyon.getKalkisYeriListele();
            break;
        case 9:
            fonksiyon.getKalkisVarisYeriListele();
            break;
        }
        cout << Color::Yellow << endl << endl << "Uygulamadan cikmak istiyor musunuz?" << endl << endl << "(E/e) " << endl << "(H/h)" << endl << ":";
        cin >> sorgulama;
        while (sorgulama!="E" && sorgulama!="e" && sorgulama!="H" && sorgulama!="h")
        {
            cout << endl << Color::Red << "Hatali" << Color::Yellow << " giris yaptiniz, tekrar deneyin: ";
            cin >> sorgulama;
        }
        cout << Color::Reset;
    }
    return 0;
}
