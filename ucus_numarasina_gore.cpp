#include "ucus.h"

void ucusFonksiyonlari::setUcusBilgileri(int ucusNumarasi)
{
    list<ucus>::iterator it;

    system("cls");
    cout << Color::Yellow << "Numara     Kalkis Yeri     Varis Yeri      Kalkis Zamani       Kapasite        Luks Koltuk Sayisi" << endl;
    cout << "------     -----------     ----------      -------------       --------        ------------------" << Color::Reset << endl;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if ((*it).ucusNumarasi == ucusNumarasi)
        {
            cout << Color::Green << setw(6) << (*it).ucusNumarasi << Color::Reset << setw(16) << (*it).kalkisYeri << setw(15) << (*it).varisYeri << setw(16) << (*it).kalkisSaati << ":" << (*it).kalkisDakikasi << setw(15) << (*it).koltukKapasitesi << setw(26) << (*it).luksKoltukKapasitesi << endl;
            return;
        }
    }
    system("cls");
    cout << "Boyle bir ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
}

void ucusFonksiyonlari::setUcusBilgileriSade(int ucusNumarasi)
{
    list<ucus>::iterator it;

    system("cls");
    cout << Color::Yellow << "Numara     Kalkis Yeri     Varis Yeri      Kalkis Zamani       Kapasite        Luks Koltuk Sayisi" << endl;
    cout << "------     -----------     ----------      -------------       --------        ------------------" << Color::Reset << endl;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if ((*it).ucusNumarasi == ucusNumarasi)
        {
            cout << setw(6) << (*it).ucusNumarasi << setw(16) << (*it).kalkisYeri << setw(15) << (*it).varisYeri << setw(16) << (*it).kalkisSaati << ":" << (*it).kalkisDakikasi << setw(15) << (*it).koltukKapasitesi << setw(26) << (*it).luksKoltukKapasitesi << endl;
            return;
        }
    }
    system("cls");
    cout << "Boyle bir ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
}

void ucusFonksiyonlari::getUcusBilgileri()
{
    ucus ucusBilgi;

    system("cls");
    cout << "Ucus numarasi giriniz: ";
    cin >> ucusBilgi.ucusNumarasi;
    if (ucusKontrol(ucusBilgi.ucusNumarasi)==false)
    {
        system("cls");
        cout << Color::Cyan << ucusBilgi.ucusNumarasi << Color::Reset << " numarali ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
    else
    {
        setUcusBilgileri(ucusBilgi.ucusNumarasi);
    }
}
