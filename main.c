//
//  main.cpp
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 22.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include <time.h>
#include <string.h>
#include "obsluga_obrazu.h"
#include "przetwarzanie_obrazu.h"
#include "filtrowanie_obrazu.h"

int main(void){
    
    int obraz[MAX][MAX];
    char komentarze[DL_LINII][DL_LINII];
    char nazwa_pliku[20] = "brak";
    int wymx = 0, wymy = 0, szarosci = 0;
    
    int prog = 0;
    int czern = 0;
    int biel = 0;
    float gamma = 0;

    FILE *plik = NULL;
    char nazwa[20] = "brak";
    
    int wybor = 0;
    
    while(wybor != 99){
        printf("----- Przetwarzanie obrazow 1 -----\n\n");
        printf("Wczytany obraz: %s \n",nazwa_pliku);
        printf("Rozmiar obrazu: %d x %d \n",wymx,wymy);
        printf("Maksymalny odcien szarosci: %d \n",szarosci);
        printf("\n---------- Opcje programu ---------\n\n");
        printf("1. Wczytaj obraz \n");
        printf("2. Zapisz obraz do pliku \n");
        printf("3. Wyswietl obraz \n\n");
        printf("4.  -> Negatyw \n");
        printf("5.  -> Progowanie \n");
        printf("6.  -> Progowanie czerni \n");
        printf("7.  -> Progowanie bieli \n");
        printf("8.  -> Korekcja gamma \n");
        printf("9.  -> Zmiana poziomow \n");
        printf("10. -> Konturowanie \n");
        printf("11. -> Rozmywanie poziome \n");
        printf("12. -> Rozmywanie pionowe \n");
        printf("13. -> Rozciaganie histogramu \n\n");
        printf("14. -> Filtr usredniajacy \n");
        printf("15. -> Filtr usredniajacy ze wzmocnieniem \n");
        printf("16. -> Gradient Robertsa \n");
        printf("17. -> Pozioma maska Prewitta \n");
        printf("18. -> Maska Sobela \n");
        printf("19. -> Maska wykrywajaca narozniki \n");
        printf("20. -> Laplasjan \n\n");
        printf("99. Zakoncz ");
        printf("\n-----------------------------------\n");
        printf("Twoj wybor > ");
        scanf("%d",&wybor);
        
        time_t czas;
        struct tm * ptr;
        time( & czas );
        ptr = localtime( & czas );
        char * data = asctime( ptr );
        
        switch(wybor){
            case 1:
                printf("Podaj nazwe pliku: ");
                scanf("%s",nazwa);
                plik = fopen(nazwa,"r");
                
                if (plik != NULL) { 
                    if(czytaj(plik,obraz,&wymx,&wymy,&szarosci,komentarze) == 1){
                        strcpy(nazwa_pliku,nazwa);
                    }
                    fclose(plik);
                }
                break;
                
            case 2:
                printf("Podaj nazwe pliku: ");
                scanf("%s",nazwa);
                plik = fopen(nazwa,"w");
                
                if (plik != NULL) {
                    zapisz(plik,obraz,&wymx,&wymy,&szarosci,komentarze);
                    fclose(plik);
                }
                break;
                
            case 3:
                wyswietl(nazwa);
                break;
                
            case 4:
                negatyw(obraz,&wymx,&wymy,&szarosci);
                char komentarz1[50] = " Negatyw ";
                strcat(komentarz1,data);
                dodaj_komentarz(komentarze,komentarz1);
                break;
                
            case 5:
                printf("Podaj wartosc progu: ");
                scanf("%d",&prog);
                progowanie(obraz,&wymx,&wymy,&szarosci,prog);
                char komentarz2[50] = " Progowanie ";
                strcat(komentarz2,data);
                dodaj_komentarz(komentarze,komentarz2);
                break;
                
            case 6:
                printf("Podaj wartosc progu: ");
                scanf("%d",&prog);
                progowanie_czerni(obraz,&wymx,&wymy,&szarosci,prog);
                char komentarz3[50] = " Progowanie czerni ";
                strcat(komentarz3,data);
                dodaj_komentarz(komentarze,komentarz3);
                break;
                
            case 7:
                printf("Podaj wartosc progu: ");
                scanf("%d",&prog);
                progowanie_bieli(obraz,&wymx,&wymy,&szarosci,prog);
                char komentarz4[50] = " Progowanie bieli ";
                strcat(komentarz4,data);
                dodaj_komentarz(komentarze,komentarz4);
                break;
                
            case 8:
                printf("Podaj wspolczynnik gamma: ");
                scanf("%f",&gamma);
                korekcja_gamma(obraz,&wymx,&wymy,&szarosci,gamma);
                char komentarz5[50] = " Korekcja gamma ";
                strcat(komentarz5,data);
                dodaj_komentarz(komentarze,komentarz5);
                break;
                
            case 9:
                printf("Podaj wartosc poziomu czerni: ");
                scanf("%d",&czern);
                printf("Podaj wartosc poziomu bieli: ");
                scanf("%d",&biel);
                zmiana_poziomow(obraz,&wymx,&wymy,&szarosci,czern,biel);
                char komentarz6[50] = " Zmiana poziomow ";
                strcat(komentarz6,data);
                dodaj_komentarz(komentarze,komentarz6);
                break;
                
            case 10:
                konturowanie(obraz,&wymx,&wymy);
                char komentarz7[50] = " Konturowanie ";
                strcat(komentarz7,data);
                dodaj_komentarz(komentarze,komentarz7);
                break;
                
            case 11:
                rozmywanie_poziome(obraz,&wymx,&wymy);
                char komentarz8[50] = " Rozmywanie poziome ";
                strcat(komentarz8,data);
                dodaj_komentarz(komentarze,komentarz8);
                break;
                
            case 12:
                rozmywanie_pionowe(obraz,&wymx,&wymy);
                char komentarz9[50] = " Rozmywanie pionowe ";
                strcat(komentarz9,data);
                dodaj_komentarz(komentarze,komentarz9);
                break;
                
            case 13:
                rozciaganie_histogramu(obraz,&wymx,&wymy,&szarosci);
                char komentarz10[50] = " Rozciaganie histogramu ";
                strcat(komentarz10,data);
                dodaj_komentarz(komentarze,komentarz10);
                break;
                
            case 14:
                filtr_usredniajacy(obraz,&wymx,&wymy);
                char komentarz11[50] = " Filtr usredniajacy ";
                strcat(komentarz11,data);
                dodaj_komentarz(komentarze,komentarz11);
                break;
                
            case 15:
                filtr_usredniajacy_ze_wzmocnieniem(obraz,&wymx,&wymy);
                char komentarz12[50] = " Filtr usredniajacy ze wzmocnieniem ";
                strcat(komentarz12,data);
                dodaj_komentarz(komentarze,komentarz12);
                break;
                
            case 16:
                gradient_robertsa(obraz,&wymx,&wymy);
                char komentarz13[50] = " Gradient Robertsa ";
                strcat(komentarz13,data);
                dodaj_komentarz(komentarze,komentarz13);
                break;
                
            case 17:
                pozioma_maska_prewitta(obraz,&wymx,&wymy);
                char komentarz14[50] = " Pozioma maska Prewitta ";
                strcat(komentarz14,data);
                dodaj_komentarz(komentarze,komentarz14);
                break;
                
            case 18:
                maska_sobela(obraz,&wymx,&wymy);
                char komentarz15[50] = " Maska Sobela ";
                strcat(komentarz15,data);
                dodaj_komentarz(komentarze,komentarz15);
                break;
                
            case 19:
                maska_wykrywajaca_narozniki(obraz,&wymx,&wymy);
                char komentarz16[50] = " Maska wykrywajaca narozniki ";
                strcat(komentarz16,data);
                dodaj_komentarz(komentarze,komentarz16);
                break;
                
            case 20:
                laplasjan(obraz,&wymx,&wymy);
                char komentarz17[50] = " Laplasjan ";
                strcat(komentarz17,data);
                dodaj_komentarz(komentarze,komentarz17);
                break;
        }
        
        system("clear");
    }
    
    printf("Program zakonczyl dzialanie\n");
    return 0;
}
