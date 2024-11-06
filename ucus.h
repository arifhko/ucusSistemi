#include <iostream>
#include <string>
#include <list>
#include <iomanip>

#pragma once

using namespace std;

struct ucus
{
    int ucusNumarasi;
    string kalkisYeri;
    string varisYeri;
    string kalkisSaati;
    string kalkisDakikasi;
    int koltukKapasitesi;
    int ekonomikKoltukKapasitesi;
    int luksKoltukKapasitesi;
};

class ucusFonksiyonlari
{
private:
    bool ucusKontrol(int ucusNumarasi);
    void setUcus(int ucusNumarasi, string kalkisYeri, string varisYeri, string kalkisSaati, string kalkisDakikasi, int koltukKapasitesi, int ekonomikKoltukKapasitesi);
    void setLuksKoltukSayisi(int ucusNumarasi, int yeniLuksKoltukKapasitesi);
    void setUcusBilgileri(int ucusNumarasi);
    void setUcusBilgileriSade(int ucusNumarasi);
    void setIptal(int ucusNumarasi);
    void setVarisYeriListele(string varisYeri);
    void setKalkisYeriListele(string kalkisYeri);
    void setKalkisVarisYeriListele(string kalkisYeri, string varisYeri);
public:
    list<ucus> ucuslar;
    void getUcusEko();
    void getUcusLuks();
    void getLuksKoltukSayisi();
    void getUcusBilgileri();
    void getIptal();
    void getluksKoltukListele();
    void getVarisYeriListele();
    void getKalkisYeriListele();
    void getKalkisVarisYeriListele();
};
