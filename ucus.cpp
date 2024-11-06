#include "ucus.h"

bool ucusFonksiyonlari::ucusKontrol(int ucusNumarasi)
{
    list<ucus>::iterator it;
    for (it = ucuslar.begin(); it != ucuslar.end(); ++it) {
        if ((*it).ucusNumarasi == ucusNumarasi) {
            return true;
        }
    }
    return false;
}

void ucusFonksiyonlari::setUcus(int ucusNumarasi, string kalkisYeri, string varisYeri, string kalkisSaati, string kalkisDakikasi, int koltukKapasitesi, int ekonomikKoltukKapasitesi)
{
    ucus yeniUcus;
    yeniUcus.ucusNumarasi = ucusNumarasi;
    yeniUcus.kalkisYeri = kalkisYeri;
    yeniUcus.varisYeri = varisYeri;
    yeniUcus.kalkisSaati = kalkisSaati;
    yeniUcus.kalkisDakikasi = kalkisDakikasi;
    yeniUcus.koltukKapasitesi = koltukKapasitesi;
    yeniUcus.ekonomikKoltukKapasitesi = ekonomikKoltukKapasitesi;
    yeniUcus.luksKoltukKapasitesi = koltukKapasitesi-ekonomikKoltukKapasitesi;
    ucuslar.push_back(yeniUcus);
    system("cls");
    setUcusBilgileriSade(ucusNumarasi);
    cout << endl << endl << endl << endl << endl << "Yeni ucus " << Color::Green << "basariyla " << Color::Reset << "eklendi" << endl;
}

void ucusFonksiyonlari::setLuksKoltukSayisi(int ucusNumarasi, int yeniLuksKoltukKapasitesi)
{
    list<ucus>::iterator it;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if ((*it).ucusNumarasi == ucusNumarasi)
        {
            if (yeniLuksKoltukKapasitesi <= (*it).koltukKapasitesi)
            {
                (*it).luksKoltukKapasitesi = yeniLuksKoltukKapasitesi;
                system("cls");
                cout << "Ucusun luks koltuk sayisi " << Color::Green << "guncellendi" << Color::Reset << endl;
            }
            else if (yeniLuksKoltukKapasitesi > (*it).koltukKapasitesi)
            {
                system("cls");
                cout << "Ucusun toplam kapasitesi '" << Color::Cyan << (*it).koltukKapasitesi << Color::Reset << "'. Ucusun luks koltuk sayisi toplam koltuk kapasitesinden " << Color::Red << "buyuk olamaz" << Color::Reset << endl;
            }
            return;
        }
    }
    system("cls");
    cout << "Boyle bir ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
}

void ucusFonksiyonlari::setIptal(int ucusNumarasi)
{
    list<ucus>::iterator it;
    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if ((*it).ucusNumarasi == ucusNumarasi)
        {
            ucuslar.erase(it);
            system("cls");
            cout << "Ucus " << Color::Red << "iptal" << Color::Reset << " edildi" << endl;
            return;
        }
    }
}

void ucusFonksiyonlari::getUcusEko()
{
    ucus ucusEkle;

    system("cls");
    cout << "Ucus numarasi giriniz: ";
    cin >> ucusEkle.ucusNumarasi;
    if (ucusKontrol(ucusEkle.ucusNumarasi)==true)
    {
        system("cls");
        cout << Color::Cyan << ucusEkle.ucusNumarasi << Color::Reset << " numarali ucus " << Color::Red << "zaten" << Color::Reset << " mevcut" << endl;
    }
    else
    {
        system("cls");
        cout << "Kalkis yeri giriniz: ";
        cin >> ucusEkle.kalkisYeri;
        while (harfKontrol(ucusEkle.kalkisYeri)==false)
        {
            system("cls");
            cout << "Kalkis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
            cin >> ucusEkle.kalkisYeri;
        }
        for (int i = 0; i < ucusEkle.kalkisYeri.length(); i++)
        {
            ucusEkle.kalkisYeri[i] = toupper(ucusEkle.kalkisYeri[i], locale());
        }
        system("cls");
        cout << "Varis yeri giriniz: ";
        cin >> ucusEkle.varisYeri;
        while (harfKontrol(ucusEkle.varisYeri)==false)
        {
            system("cls");
            cout << "Varis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
            cin >> ucusEkle.varisYeri;
        }
        for (int i = 0; i < ucusEkle.varisYeri.length(); i++)
        {
            ucusEkle.varisYeri[i] = toupper(ucusEkle.varisYeri[i], locale());
        }
        system("cls");
        cout << "Kalkis saati giriniz: ";
        cin >> ucusEkle.kalkisSaati;
        system("cls");
        cout << "Kalkis dakikasi giriniz: ";
        cin >> ucusEkle.kalkisDakikasi;
        system("cls");
        cout << "Yolcu kapasitesi giriniz: ";
        cin >> ucusEkle.koltukKapasitesi;
        ucusEkle.ekonomikKoltukKapasitesi=ucusEkle.koltukKapasitesi;
        setUcus(ucusEkle.ucusNumarasi, ucusEkle.kalkisYeri, ucusEkle.varisYeri, ucusEkle.kalkisSaati, ucusEkle.kalkisDakikasi, ucusEkle.koltukKapasitesi, ucusEkle.ekonomikKoltukKapasitesi);
    }
}

void ucusFonksiyonlari::getUcusLuks()
{
    ucus ucusEkle;

    system("cls");
    cout << "Ucus numarasi giriniz: ";
    cin >> ucusEkle.ucusNumarasi;
    if (ucusKontrol(ucusEkle.ucusNumarasi)==true)
    {
        system("cls");
        cout << Color::Cyan << ucusEkle.ucusNumarasi << Color::Reset << " numarali ucus " << Color::Red << "zaten" << Color::Reset << " mevcut" << endl;
    }
    else
    {
        system("cls");
        cout << "Kalkis yeri giriniz: ";
        cin >> ucusEkle.kalkisYeri;
        while (harfKontrol(ucusEkle.kalkisYeri)==false)
        {
            system("cls");
            cout << "Kalkis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
            cin >> ucusEkle.kalkisYeri;
        }
        for (int i = 0; i < ucusEkle.kalkisYeri.length(); i++)
        {
            ucusEkle.kalkisYeri[i] = toupper(ucusEkle.kalkisYeri[i], locale());
        }
        system("cls");
        cout << "Varis yeri giriniz: ";
        cin >> ucusEkle.varisYeri;
        while (harfKontrol(ucusEkle.varisYeri)==false)
        {
            system("cls");
            cout << "Varis yeri giriniz (sadece " << Color::Red << "latin" << Color::Reset << " harfler): ";
            cin >> ucusEkle.varisYeri;
        }
        for (int i = 0; i < ucusEkle.varisYeri.length(); i++)
        {
            ucusEkle.varisYeri[i] = toupper(ucusEkle.varisYeri[i], locale());
        }
        system("cls");
        cout << "Kalkis saati giriniz: ";
        cin >> ucusEkle.kalkisSaati;
        system("cls");
        cout << "Kalkis dakikasi giriniz: ";
        cin >> ucusEkle.kalkisDakikasi;
        system("cls");
        cout << "Yolcu kapasitesi giriniz: ";
        cin >> ucusEkle.koltukKapasitesi;
        system("cls");
        cout << "Ekonomik yolcu sayisi giriniz: ";
        cin >> ucusEkle.ekonomikKoltukKapasitesi;
        while (ucusEkle.ekonomikKoltukKapasitesi > ucusEkle.koltukKapasitesi)
        {
            system("cls");
            cout << "Ekonomik yolcu sayisi giriniz (toplam yolcu kapasitesinden[" << Color::Cyan << ucusEkle.koltukKapasitesi << Color::Reset << "] " << Color::Red << "buyuk olamaz" << Color::Reset << "): ";
            cin >> ucusEkle.ekonomikKoltukKapasitesi;
        }
        setUcus(ucusEkle.ucusNumarasi, ucusEkle.kalkisYeri, ucusEkle.varisYeri, ucusEkle.kalkisSaati, ucusEkle.kalkisDakikasi, ucusEkle.koltukKapasitesi, ucusEkle.ekonomikKoltukKapasitesi);
    }
}

void ucusFonksiyonlari::getLuksKoltukSayisi()
{
    ucus luksGuncelle;

    system("cls");
    cout << "Ucus numarasi giriniz: ";
    cin >> luksGuncelle.ucusNumarasi;
    if (ucusKontrol(luksGuncelle.ucusNumarasi)==false)
    {
        system("cls");
        cout << Color::Cyan << luksGuncelle.ucusNumarasi << Color::Reset << " numarali ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
    else
    {
        system("cls");
        cout << "Yeni luks koltuk kapasitesi giriniz: ";
        cin >> luksGuncelle.luksKoltukKapasitesi;
        setLuksKoltukSayisi(luksGuncelle.ucusNumarasi, luksGuncelle.luksKoltukKapasitesi);
    }
}

void ucusFonksiyonlari::getIptal()
{
    ucus ucusIptal;
    system("cls");
    cout << "Ucus numarasi giriniz: ";
    cin >> ucusIptal.ucusNumarasi;
    if (ucusKontrol(ucusIptal.ucusNumarasi)==false)
    {
        system("cls");
        cout << Color::Cyan << ucusIptal.ucusNumarasi << Color::Reset << " numarali ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
    else
    {
        setIptal(ucusIptal.ucusNumarasi);
    }
}

void ucusFonksiyonlari::getluksKoltukListele()
{
    bool sorgu=false;

    ucuslar.sort([](const ucus& u1, const ucus& u2)
    {
        return u1.ucusNumarasi < u2.ucusNumarasi;
    });

    list<ucus>::iterator it;

    system("cls");
    cout << Color::Yellow << "Numara     Kalkis Yeri     Varis Yeri      Kalkis Zamani       Kapasite        Luks Koltuk Sayisi" << endl;
    cout << "------     -----------     ----------      -------------       --------        ------------------" << Color::Reset << endl;

    for (it = ucuslar.begin(); it != ucuslar.end(); ++it)
    {
        if ((*it).luksKoltukKapasitesi > 0)
        {
            cout << setw(6) << (*it).ucusNumarasi << setw(16) << (*it).kalkisYeri << setw(15) << (*it).varisYeri << setw(16) << (*it).kalkisSaati << ":" << (*it).kalkisDakikasi << setw(15) << (*it).koltukKapasitesi << Color::Green << setw(26) << (*it).luksKoltukKapasitesi << Color::Reset << endl;
            sorgu=true;
        }
    }
    if (sorgu==false)
    {
        system("cls");
        cout << "Listelenecek bir ucus " << Color::Red << "bulunamadi" << Color::Reset << endl;
    }
}
