//
//  filtrowanie_obrazu.h
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 23.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#ifndef filtrowanie_obrazu_h
#define filtrowanie_obrazu_h

#include <stdio.h>

#define MAX 512            /* Maksymalny rozmiar wczytywanego obrazu */

void splot(int _obraz[][MAX],int *_wymx, int *_wymy, int _maska[3][3]);

void filtr_usredniajacy(int _obraz[][MAX],int *_wymx, int *_wymy);
void filtr_usredniajacy_ze_wzmocnieniem(int _obraz[][MAX],int *_wymx, int *_wymy);
void gradient_robertsa(int _obraz[][MAX],int *_wymx, int *_wymy);
void pozioma_maska_prewitta(int _obraz[][MAX],int *_wymx, int *_wymy);
void maska_sobela(int _obraz[][MAX],int *_wymx, int *_wymy);
void maska_wykrywajaca_narozniki(int _obraz[][MAX],int *_wymx, int *_wymy);
void laplasjan(int _obraz[][MAX],int *_wymx, int *_wymy);

#endif /* filtrowanie_obrazu_h */
