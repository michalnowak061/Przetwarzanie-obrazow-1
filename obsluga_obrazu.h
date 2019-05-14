//
//  obsluga_obrazu.h
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 22.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef obsluga_obrazu_h
#define obsluga_obrazu_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 512            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */

int czytaj(FILE *_plik,int _obraz[MAX][MAX],int *_wymx,int *_wymy, int *_szarosci,char _komentarze[DL_LINII][DL_LINII]);
void wyswietl(char *_nazwa_pliku);
int zapisz(FILE *_plik,int _obraz[MAX][MAX],int *_wymx,int *_wymy, int *_szarosci,char _komentarze[DL_LINII][DL_LINII]);
void dodaj_komentarz(char _komentarze[DL_LINII][DL_LINII],char *_komentarz);

#endif /* obsluga_obrazu_h */
