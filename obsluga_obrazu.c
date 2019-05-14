//
//  obsluga_obrazu.c
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 22.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "obsluga_obrazu.h"

//--------------------------------------------------------------------------------------------------
int czytaj(FILE *_plik,int _obraz[MAX][MAX],int *_wymx,int *_wymy, int *_szarosci,char _komentarze[DL_LINII][DL_LINII]){
    char buf[DL_LINII];     /* <- bufor pomocniczy do czytania naglowka i komentarzy */
    int znak = '#';         /* <- zmienna pomocnicza do czytania komentarzy */
    int koniec=0;           /* <- czy napotkano koniec danych w pliku */
                             
    /* Sprawdzenie czy podano prawidłowy uchwyt pliku */
    if (_plik==NULL) {
        fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
        return 0;
    }
    
    /* Sprawdzenie "numeru magicznego" - powinien być P2 */
    if (fgets(buf,DL_LINII,_plik)==NULL)       /* Wczytanie pierwszej linii pliku do bufora */
        koniec=1;                              /* Nie udalo sie? Koniec danych! */
    
    if ( (buf[0]!='P') || (buf[1]!='2') || koniec) {  /* Czy jest magiczne "P2"? */
        fprintf(stderr,"Blad: To nie jest plik PGM\n");
        return 0;
    }
    
    /* Pominiecie komentarzy */
    int i = 0;
    do{
        if((znak = fgetc(_plik)) == '#') {
            if (fgets(buf,DL_LINII,_plik)==NULL){
                koniec=1;
            }
            //przekopiowanie komentarzy do tablicy komentarzy
            for (int j = 0; j < strlen(buf); ++j){
                _komentarze[i][j] = buf[j];
            }
            ++i;
            
        }else ungetc(znak,_plik);
    }while (znak=='#' && !koniec);
    
    /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
    if (fscanf(_plik,"%d %d %d",_wymx,_wymy,_szarosci)!=3) {
        fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
        return 0;
    }
    
    /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
    for (int i=0;i<*_wymy;i++) {
        for (int j=0;j<*_wymx;j++) {
            if (fscanf(_plik,"%d",&(_obraz[i][j]))!=1) {
                fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
                return 0;
            }
        }
    }
    
    return 1;   /* Czytanie zakonczone sukcesem */
}
//--------------------------------------------------------------------------------------------------
void wyswietl(char *_nazwa_pliku) {
    
    char polecenie[DL_LINII];
    
    strcpy(polecenie,"open ");
    strcat(polecenie,_nazwa_pliku);
    
    printf("%s\n",polecenie);
    system(polecenie);
}
//--------------------------------------------------------------------------------------------------
int zapisz(FILE *_plik,int _obraz[MAX][MAX],int *_wymx,int *_wymy, int *_szarosci,char _komentarze[DL_LINII][DL_LINII]){
    /* wpisanie na poczatek pliku "numeru magicznego" */
    fprintf(_plik,"P2\n");
    
    /* wpisanie do pliku komentarzy */
    for(int i = 0; i < DL_LINII; ++i){
        fprintf(_plik,"#");
        for(int j = 0; j < DL_LINII; ++j){
            fprintf(_plik,"%c",_komentarze[i][j]);
            if(_komentarze[i][j] == '\n') break;
        }
        if(_komentarze[i+1][0] == 0) break;
    }
    
    /* wpisanie do pliku wymiarow obrazu */
    fprintf(_plik,"%d %d \n",*_wymx,*_wymy);
    /* wpisanie do pliku maksymalnego stopnia szarosci */
    fprintf(_plik,"%d \n",*_szarosci);
    
    /* wpisanie do pliku pikseli */
    for(int i = 0; i < *_wymy; i++) {
        for(int j = 0; j < *_wymx; j++) {
            fprintf(_plik,"%d ",_obraz[i][j]);
        }
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------
void dodaj_komentarz(char _komentarze[DL_LINII][DL_LINII],char *_komentarz){
    
    /* dodanie na koniec tablicy komentarzy nowego komentarza */
    for(int i = 0; i < DL_LINII; ++i){
        if(_komentarze[i][0] == '\0'){
            for (int j = 0; j < strlen(_komentarz); ++j) {
                _komentarze[i][j] = _komentarz[j];
            }
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------
