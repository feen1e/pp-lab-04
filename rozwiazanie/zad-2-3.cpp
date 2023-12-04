/*
Autor: Dominik Kaczmarek
Grupa: Pn/P 13:15
Temat: Laboratorium 4, zadania: 2, 3
Data: 04.12.2023 r.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ROZMIAR 100

void wczytanieLancucha(char lancuchZnakow[]);
// funkcja wczytuje lancuch znakow

void wypisanieLancucha(char lancuchZnakow[]);
// funkcja wypisuje elementy lancucha

int usuwanieCyfr(char lancuchZnakow[]);
// funkcja usuwa z lancucha znakow wszystkie cyfry oraz zwraca ich liczbe

char * usuwanieKomentarzy(char lancuchZnakow[]);
// funkcja usuwa z lancucha znakow wszystkie komentarze oraz zwraca adres poczatku lancucha

//void zadanie4();

//char zmienna1 = 'A';
//int zmienna2 = 123;
//float zmienna3 = 45.67;
//double zmienna4 = 89.1023;

int main() {
    //char lancuch[] = "ab1c/*123*/d2e12//3";
    //zadanie4();
    char lancuch[ROZMIAR+1];
    char *adres;
    int usunieteCyfry, wybranaOpcja;
    do {
        printf("Autor: Dominik Kaczmarek PnP 13:15\n\n");
        printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("||                  Wybierz funkcje do uruchomienia                      ||\n");
        printf("|| *1* Wczytanie lancucha znakow                                         ||\n");
        printf("|| *2* Wypisanie lancucha                                                ||\n");
        printf("|| *3* Usuniecie cyfr z lancucha                                         ||\n");
        printf("|| *4* Usuniecie komentarzy z lancucha i wypisanie adresu                ||\n");
        printf("|| *5* Zakoncz dzialanie programu                                        ||\n");
        printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("Wprowadz numer wybranej opcji: ");
        scanf("%i", &wybranaOpcja);
        system("cls");
        switch (wybranaOpcja) {
            case 1:
                wczytanieLancucha(lancuch);
                fflush(stdin);
                printf("\nKliknij Enter aby kontynuowac...");
                getchar();
                system("cls");
                break;
            case 2:
                wypisanieLancucha(lancuch);
                fflush(stdin);
                printf("\nKliknij Enter aby kontynuowac...");
                getchar();
                system("cls");
                break;
            case 3:
                usunieteCyfry = usuwanieCyfr(lancuch);
                printf("Usunieto %d cyfr.\n", usunieteCyfry);
                fflush(stdin);
                printf("\nKliknij Enter aby kontynuowac...");
                getchar();
                system("cls");
                break;
            case 4:
                adres = usuwanieKomentarzy(lancuch);
                printf("Adres poczatku lancucha to %d.\n", adres);
                fflush(stdin);
                printf("\nKliknij Enter aby kontynuowac...");
                getchar();
                system("cls");
                break;
            case 5:
                break;
            default:
                printf("Wprowadzono nieprawidlowa cyfre.");
                break;
        }
    }   while (wybranaOpcja != 5);
    return 0;
}

void wczytanieLancucha(char lancuchZnakow[]) {
    char podanyZnak;
    printf("Podaj lancuch znakow. Maksymalna dlugosc to %d.\n", ROZMIAR);
    {
        int znak = 0;
        do {
            podanyZnak = getch();
            printf("%c", podanyZnak);
            lancuchZnakow[znak] = podanyZnak;
            if (podanyZnak == 13) lancuchZnakow[znak] = '\0';
            znak++;
        } while (podanyZnak != 13 and znak <= ROZMIAR-1);
        if (znak >= ROZMIAR-1) lancuchZnakow[ROZMIAR] = '\0';
    }
}

void wypisanieLancucha(char lancuchZnakow[]) {
    int ile_znakow = 0;
    for (int i = 0; lancuchZnakow[i] != '\0'; i++) ile_znakow++;
    for (int i = 0; i < ile_znakow; i ++) printf("%c", lancuchZnakow[i]);
}

int usuwanieCyfr(char lancuchZnakow[]) {
    int znak = 0, ile_usunietych = 0;
    for (int i = 0; lancuchZnakow[znak] != '\0'; i++) {
        //printf("%c\n", lancuchZnakow[i]);
        if (lancuchZnakow[i] < '0' || lancuchZnakow[i] > '9') {
            lancuchZnakow[znak] = lancuchZnakow[i];
            //printf("    %c\n", lancuchZnakow[znak]);
            znak++;
        } else ile_usunietych++;
    }
    lancuchZnakow[znak] = '\0';
    return ile_usunietych;
}

char * usuwanieKomentarzy(char lancuchZnakow[]) {
    int znak = 0;
    bool komentarz = false;
    for (int i = 0; lancuchZnakow[znak] != '\0'; i++) {
        if (lancuchZnakow[i] == '/' and lancuchZnakow[i+1] == '*') komentarz = true;
        if (lancuchZnakow[i-2] == '*' and lancuchZnakow[i-1] == '/') komentarz = false;
        if (lancuchZnakow[i] == '/' and lancuchZnakow[i+1] == '/') {
            lancuchZnakow[znak] = '\0';
            break;
        }
        if (not komentarz) {
            lancuchZnakow[znak] = lancuchZnakow[i];
            //printf("    %c\n", lancuchZnakow[znak]);
            znak++;
        }
    }
    return lancuchZnakow;
}

//void zadanie4() {
//    char zmienna5 = 'Z';
//    float zmienna6 = 321.54;
//    int zmienna7 = 98;
//    printf("Adresy:\n1: %d, 2: %d, 3: %d, 4: %d, 5: %d, 6: %d, 7: %d\n",
//           &zmienna1, &zmienna2, &zmienna3, &zmienna4, &zmienna5, &zmienna6, &zmienna7);
//    printf("Wartosci: \n1: %c, 2: %d, 3: %f, 4: %lf, 5: %c, 6: %f, 7: %d\n",
//           zmienna1, zmienna2, zmienna3, zmienna4, zmienna5, zmienna6, zmienna7);
//    printf("%llu", sizeof(zmienna4));
//}
