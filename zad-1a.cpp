/*
Autor: Dominik Kaczmarek
Grupa: Pn/P 13:15
Temat: Laboratorium 4, zadanie: 1a
Data: 04.12.2023 r.
*/

#include <stdio.h>
#include <conio.h>

// Rozwiazywanie ukladu dwoch rownan metida Cramera (przez referencje)

void CzytajRownanie(float &a, float &b, float &c);
// funkcja wczytuje współczynniki jednego równania. a*x+b*y=c

void WypiszRozwiazanie( int N, float x, float y);
// funkcja wypisuje rozwiązanie układu równań lub inny komunikat

float ObliczWyznacznik(float p1, float p2, float p3,float p4);
// funkcja oblicza wyznacznik macierzy: p1 * p4 - p2 * p3

int ObliczRozwiazanie(float a1, float b1, float c1,
                      float a2, float b2, float c2,
                      float &x, float &y);
// funkcja oblicza rozwiązanie układu równań i zwraca:
//  2 – nieskończenie wiele rozwiązań
//  1 – jest jedno rozwiązanie
//  0 – brak rozwiązań (układ sprzeczny)


int main() {
    printf("Autor: Dominik Kaczmarek PnP 13:15\n\n");
    float A1, B1, C1; // pierwsze równanie
    float A2, B2, C2; // drugie równanie
    float X, Y; // rozwiązanie
    int N; // liczba rozwiazan
    printf("Program rozwiazuje uklad dwoch rownan liniowych metoda wspolczynnikow.\n\n");
    printf("Pierwsze rownanie: \n");
    CzytajRownanie(A1, B1, C1);
    printf("Drugie rownanie: \n");
    CzytajRownanie(A2, B2, C2);
    N = ObliczRozwiazanie(A1, B1, C1, A2, B2, C2, X, Y);
    WypiszRozwiazanie( N, X, Y);
    getch();
    return 0;
}


void CzytajRownanie(float &a, float &b, float &c)  {
    printf("\n    a * x + b * y = c    \n\n");
    printf("Podaj wspolczynniki a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Rownanie ma postac: %.2f*x%+.2f*y=%.2f\n\n", a, b, c);
}

void WypiszRozwiazanie( int N, float x, float y) {
    switch (N) {
        case 0: printf("Uklad jest sprzeczny. \n"); break;
        case 1: printf("Uklad ma jedno rozwiazanie. \nx = %.2f\ny = %.2f\n", x, y); break;
        case 2: printf("Uklad ma nieskonczenie wiele rozwiazan. \n"); break;
        default: printf("Blad w rozwiazaniu.\n");
    }
}

float ObliczWyznacznik(float p1, float p2, float p3, float p4) {
    return p1*p4 - p2*p3;
}

int ObliczRozwiazanie(float a1, float b1, float c1,
                      float a2, float b2, float c2,
                      float &x, float &y) {
    float wyznacznik;
    wyznacznik = ObliczWyznacznik(a1, b1, a2, b2);
    if (wyznacznik == 0) {
        x = NULL;
        y = NULL;
        if (ObliczWyznacznik(c1, b1, c2, b2) == 0 &&
        ObliczWyznacznik(a1, c1, a2, c2) == 0) {
            return 2;
        } else {
            return 0;
        }
    } else {
        x = (ObliczWyznacznik(c1, b1, c2, b2)/wyznacznik);
        y = (ObliczWyznacznik(a1, c1, a2, c2)/wyznacznik);
        return 1;
    }
}