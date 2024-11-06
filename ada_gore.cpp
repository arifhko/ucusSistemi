#include "ucus.h"

void ucusFonksiyonlari::setVarisYeriListele(string varisYeri)
{
    bool sorgu=false;

    ucuslar.sort([](const ucus& u1, const ucus& u2)
    {
        return u1.kalkisYeri < u2.kalkisYeri || (u1.kalkisYeri == u2.kalkisYeri && u1.kalkisSaati < u2.kalkisSaati) || (u1.kalkisYeri == u2.kalkisYeri && u1.kalkisSaati == u2.kalkisSaati && u1.kalkisDakikasi < u2.kalkisDakikasi);
    });

    list<ucus>::iterator it;
    
    system("cls");
    cout << Color::Yellow << "Numara     Kalkis Yeri     Varis Yeri      Kalkis Zamani       Kapasite        Luks Koltuk Sayisi" << endl;
    cout << "------     -----------     ----------      -------------       --------        ------------------" << Color::Reset << endl;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if (varisYeri == (*it).varisYeri)
        {
            cout << setw(6) << (*it).ucusNumarasi << setw(16) << (*it).kalkisYeri << Color::Green << setw(15) << (*it).varisYeri << Color::Reset << setw(16) << (*it).kalkisSaati << ":" << (*it).kalkisDakikasi << setw(15) << (*it).koltukKapasitesi << setw(26) << (*it).luksKoltukKapasitesi << endl;
            sorgu=true;
        }
    }
    if (sorgu==false)
    {
        system("cls");
        cout << Color::Cyan << varisYeri << Color::Reset << " sehrine giden ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
}

void ucusFonksiyonlari::getVarisYeriListele()
{
    ucus ucusVaris;
    system("cls");
    cout << "Varis yeri giriniz: ";
    cin >> ucusVaris.varisYeri;
    while (harfKontrol(ucusVaris.varisYeri)==false)
    {
        system("cls");
        cout << "Varis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
        cin >> ucusVaris.varisYeri;
    }
    for (int i = 0; i < ucusVaris.varisYeri.length(); i++)
    {
        ucusVaris.varisYeri[i] = toupper(ucusVaris.varisYeri[i], locale());
    }
    setVarisYeriListele(ucusVaris.varisYeri);
}

void ucusFonksiyonlari::setKalkisYeriListele(string kalkisYeri)
{
    bool sorgu=false;

    ucuslar.sort([](const ucus& u1, const ucus& u2)
    {
        return u1.kalkisSaati < u2.kalkisSaati || (u1.kalkisSaati == u2.kalkisSaati && u1.kalkisDakikasi < u2.kalkisDakikasi);
    });

    list<ucus>::iterator it;
    
    system("cls");
    cout << Color::Yellow << "Numara     Kalkis Yeri     Varis Yeri      Kalkis Zamani       Kapasite        Luks Koltuk Sayisi" << endl;
    cout << "------     -----------     ----------      -------------       --------        ------------------" << Color::Reset << endl;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if (kalkisYeri == (*it).kalkisYeri)
        {
            cout << setw(6) << (*it).ucusNumarasi << Color::Green << setw(16) << (*it).kalkisYeri << Color::Reset << setw(15) << (*it).varisYeri << setw(16) << (*it).kalkisSaati << ":" << (*it).kalkisDakikasi << setw(15) << (*it).koltukKapasitesi << setw(26) << (*it).luksKoltukKapasitesi << endl;
            sorgu=true;
        }
    }
    if (sorgu==false)
    {
        system("cls");
        cout << Color::Cyan << kalkisYeri << Color::Reset << " sehrinden kalkan ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
}

void ucusFonksiyonlari::getKalkisYeriListele()
{
    ucus ucusKalkis;
    system("cls");
    cout << "Kalkis yeri giriniz: ";
    cin >> ucusKalkis.kalkisYeri;
    while (harfKontrol(ucusKalkis.kalkisYeri)==false)
    {
        system("cls");
        cout << "Kalkis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
        cin >> ucusKalkis.kalkisYeri;
    }
    for (int i = 0; i < ucusKalkis.kalkisYeri.length(); i++)
    {
        ucusKalkis.kalkisYeri[i] = toupper(ucusKalkis.kalkisYeri[i], locale());
    }
    setKalkisYeriListele(ucusKalkis.kalkisYeri);
}

void ucusFonksiyonlari::setKalkisVarisYeriListele(string kalkisYeri, string varisYeri)
{
    bool sorgu=false;

    ucuslar.sort([](const ucus& u1, const ucus& u2)
    {
        return u1.kalkisSaati > u2.kalkisSaati || (u1.kalkisSaati == u2.kalkisSaati && u1.kalkisDakikasi > u2.kalkisDakikasi);
    });

    list<ucus>::iterator it;
    
    system("cls");
    cout << Color::Yellow << "Numara     Kalkis Yeri     Varis Yeri      Kalkis Zamani       Kapasite        Luks Koltuk Sayisi" << endl;
    cout << "------     -----------     ----------      -------------       --------        ------------------" << Color::Reset << endl;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if (kalkisYeri == (*it).kalkisYeri && varisYeri == (*it).varisYeri)
        {
            cout << setw(6) << (*it).ucusNumarasi << Color::Green << setw(16) << (*it).kalkisYeri << setw(15) << (*it).varisYeri << Color::Reset << setw(16) << (*it).kalkisSaati << ":" << (*it).kalkisDakikasi << setw(15) << (*it).koltukKapasitesi << setw(26) << (*it).luksKoltukKapasitesi << endl;
            sorgu=true;
        }
    }
    if (sorgu==false)
    {
        system("cls");
        cout << Color::Cyan << kalkisYeri << Color::Reset << " sehrinden kalkip " << Color::Cyan << varisYeri << Color::Reset << " sehrine giden ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
}

void ucusFonksiyonlari::getKalkisVarisYeriListele()
{
    ucus ucusKalkisVaris;
    system("cls");
    cout << "Kalkis yeri giriniz: ";
    cin >> ucusKalkisVaris.kalkisYeri;
    while (harfKontrol(ucusKalkisVaris.kalkisYeri)==false)
    {
        system("cls");
        cout << "Kalkis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
        cin >> ucusKalkisVaris.kalkisYeri;
    }
    for (int i = 0; i < ucusKalkisVaris.kalkisYeri.length(); i++)
    {
        ucusKalkisVaris.kalkisYeri[i] = toupper(ucusKalkisVaris.kalkisYeri[i], locale());
    }
    system("cls");
    cout << "Varis yeri giriniz: ";
    cin >> ucusKalkisVaris.varisYeri;
    while (harfKontrol(ucusKalkisVaris.varisYeri)==false)
    {
        system("cls");
        cout << "Varis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
        cin >> ucusKalkisVaris.varisYeri;
    }
    for (int i = 0; i < ucusKalkisVaris.varisYeri.length(); i++)
    {
        ucusKalkisVaris.varisYeri[i] = toupper(ucusKalkisVaris.varisYeri[i], locale());
    }
    setKalkisVarisYeriListele(ucusKalkisVaris.kalkisYeri, ucusKalkisVaris.varisYeri);
}
