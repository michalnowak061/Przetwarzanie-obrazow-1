//
//  przetwarzanie_obrazu.h
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 22.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef przetwarzanie_obrazu_h
#define przetwarzanie_obrazu_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 512            /* Maksymalny rozmiar wczytywanego obrazu */

void negatyw(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci);
void progowanie(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _prog);
void progowanie_czerni(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _prog);
void progowanie_bieli(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _prog);
void korekcja_gamma(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, float _gamma);
void zmiana_poziomow(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _czern, int _biel);
void konturowanie(int _obraz[][MAX], int *_wymx,int *_wymy);
void rozmywanie_poziome(int _obraz[][MAX], int *_wymx,int *_wymy);
void rozmywanie_pionowe(int _obraz[][MAX], int *_wymx,int *_wymy);
void rozciaganie_histogramu(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci);

#endif /* przetwarzanie_obrazu_h */
