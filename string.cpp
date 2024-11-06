#include <iostream>
#include "color.h"

using namespace std;

void menu()
{
    cout << Color::Cyan << "********************************************************" << endl;
    cout << Color::Cyan << "*                                                      *" << endl;
    cout << Color::Cyan << "*" << Color::Blue << "                     UCUS SISTEMI                     " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "1-" << Color::Reset << " Ucus Ekleme (Sadece Ekonomi)                  " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "2-" << Color::Reset << " Ucus Ekleme (Ekonomi + Luks)                  " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "3-" << Color::Reset << " Luks Koltuk Guncelleme                        " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "4-" << Color::Reset << " Ucus Iptal Etme                               " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "5-" << Color::Reset << " Ucus Goruntuleme                              " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "6-" << Color::Reset << " Luks Koltuk Iceren Ucuslari Goruntule         " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "7-" << Color::Reset << " Varis Yerine Gore Ucus Goruntule              " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "8-" << Color::Reset << " Kalkis Yerine Gore Ucus Goruntule             " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*     " << Color::Magenta << "9-" << Color::Reset << " Kalkis ve Varis Yerine Gore Ucus Goruntule    " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*" << Color::Magenta << "               Cikis icin '-1' giriniz                " << Color::Cyan << "*" << endl;
    cout << Color::Cyan << "*                                                      *" << endl;
    cout << Color::Cyan << "********************************************************" << Color::Reset << endl;
}

bool harfKontrol(string str)
{
    bool kontrol=true;

    for (char c : str)
    {
        if (!isalpha(c) || (c < 'A' || c > 'z'))
        {
            kontrol = false;
            break;
        }
    }

    if (kontrol==true)
    {
        return true;
    } 
    else
    {
        return false;
    }
}
