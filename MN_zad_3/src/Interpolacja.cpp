#include "Interpolacja.h"

double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Newton(std::vector<Punkt<double>> wezly, double x)
{
    double wynik = 0, tmp;
    for(int k = 0; k < wezly.size(); k++)
    {
        tmp = wezly[k].y;
        for(int j=0; j<wezly.size(); j++)
        {
            if (k != j)
            {
                tmp *= (x - j)/(k-j);
            }
        }
        wynik += tmp;
    }

    return wynik;
}

std::vector<Punkt<double>> Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami)
{
    std::vector<Punkt<double>> wynik;

    for(double x=przedzial.x; x<=przedzial.y; x+=odleglosc_miedy_punktami)
    {
        wynik.push_back( Punkt<double>(x, obliczWartoscFunkcjiInterpolowanej_Newton(wezly, x)) );
    }

    return wynik;
}



double Interpolacja::obliczWartoscFunkcjiInterpolowanej_Lagrange(std::vector<Punkt<double>> wezly, double x)
{
    double wynik = 0, tmp;
    for(int i=0; i<wezly.size(); i++)
    {
        tmp = wezly[i].y;
        for(int j=0; j<wezly.size(); j++)
        {
            if(i != j)
            {
                tmp *= ((x - wezly[j].x) / (wezly[i].x - wezly[j].x));
            }
        }
        wynik += tmp;
    }
    return wynik;
}

std::vector<Punkt<double>> Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(Punkt<double> przedzial, std::vector<Punkt<double>> wezly, double odleglosc_miedy_punktami)
{
    std::vector<Punkt<double>> wynik;

    for(double x=przedzial.x; x<=przedzial.y; x+=odleglosc_miedy_punktami)
    {
        wynik.push_back( Punkt<double>(x, obliczWartoscFunkcjiInterpolowanej_Lagrange(wezly, x)) );
    }

    return wynik;
}
