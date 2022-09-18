#include "PlikTekstowy.h"

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy::czyPlikJestPusty()
{
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }
    plikTekstowy.close();
    return pusty;
}

void PlikTekstowy::usunPlik()
{
    if (remove(NAZWA_PLIKU.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << NAZWA_PLIKU << endl;
}

void PlikTekstowy::zmienNazwePliku(string nazwaTymczasowa)
{
    if (rename(nazwaTymczasowa.c_str(), NAZWA_PLIKU.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << nazwaTymczasowa << endl;
}
