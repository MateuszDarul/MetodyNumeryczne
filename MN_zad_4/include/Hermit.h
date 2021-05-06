#ifndef HERMIT_H
#define HERMIT_H

#include "Funkcje.h"
#include "Define.h"
#include "Wykres.h"

#define wezel 0
#define waga 1

class Hermit
{
private:
    static double kwadratura[4][5][2];

public:
    static int ilosc_iteracji;
    static double ObliczINF(funkcja f, int ilosc_wezlow);
    static void wczytajKwadratury();
};

#endif // HERMIT_H
