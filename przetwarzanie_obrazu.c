//
//  przetwarzanie_obrazu.c
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 22.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "przetwarzanie_obrazu.h"

//--------------------------------------------------------------------------------------------------
void negatyw(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci){
    for (int i = 0; i < *_wymy; ++i){
        for(int j = 0; j < *_wymx; ++j){
            _obraz[i][j] = *_szarosci - _obraz[i][j];
        }
    }
}
//--------------------------------------------------------------------------------------------------
void progowanie(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _prog){
    int PROG = (_prog) * (*_szarosci) / 100;
    
    for (int i = 0; i < *_wymy; ++i){
        for (int j = 0; j < *_wymx; ++j){
            if(_obraz[i][j] <= PROG) _obraz[i][j] = 0;
            else if(_obraz[i][j] > PROG) _obraz[i][j] = *_szarosci;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void progowanie_czerni(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _prog){
    int PROG = (_prog) * (*_szarosci) / 100;;
    
    for (int i = 0; i < *_wymy; ++i){
        for (int j = 0; j < *_wymx; ++j){
            if(_obraz[i][j] <= PROG) _obraz[i][j] = 0;
            else if(_obraz[i][j] > PROG) _obraz[i][j] = _obraz[i][j];
        }
    }
}
//--------------------------------------------------------------------------------------------------
void progowanie_bieli(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _prog){
    int PROG = (_prog) * (*_szarosci) / 100;;
    
    for (int i = 0; i < *_wymy; ++i){
        for (int j = 0; j < *_wymx; ++j){
            if(_obraz[i][j] <= PROG) _obraz[i][j] = _obraz[i][j];
            else if(_obraz[i][j] > PROG) _obraz[i][j] = *_szarosci;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void korekcja_gamma(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, float _gamma){

    for (int i = 0; i < *_wymy; ++i){
        for(int j = 0; j < *_wymx; ++j){
            _obraz[i][j] = pow((float)_obraz[i][j] / (float)*_szarosci,1 / _gamma) * (*_szarosci);
        }
    }
}
//--------------------------------------------------------------------------------------------------
void zmiana_poziomow(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci, int _czern, int _biel){
    int CZERN = *_szarosci - (( (1 - (float)_czern / 100) ) * (float)*_szarosci ) ;
    int BIEL = _biel * *_szarosci / 100;
    
    for (int i = 0; i < *_wymy; ++i){
        for(int j = 0; j < *_wymx; ++j){
            if(_obraz[i][j] <= CZERN) _obraz[i][j] = 0;
            else if(_obraz[i][j] > CZERN && _obraz[i][j] < BIEL){
                _obraz[i][j] = (_obraz[i][j] - CZERN) * (*_szarosci / (BIEL - CZERN));
            }
            else if(_obraz[i][j] >= BIEL) _obraz[i][j] = *_szarosci;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void konturowanie(int _obraz[][MAX], int *_wymx,int *_wymy){
    for(int i = 0; i < *_wymy; ++i){
        for(int j = 0; j < *_wymx; ++j){
            _obraz[i][j] = abs(_obraz[i+1][j] - _obraz[i][j]) + abs(_obraz[i][j+1] - _obraz[i][j]) ;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void rozmywanie_poziome(int _obraz[][MAX], int *_wymx,int *_wymy){
    for(int i = 1; i < *_wymy - 1; ++i){
        for(int j = 0; j < *_wymx; ++j){
            _obraz[i][j] = (_obraz[i-1][j] + _obraz[i][j] + _obraz[i+1][j]) / 3;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void rozmywanie_pionowe(int _obraz[][MAX], int *_wymx,int *_wymy){
    for(int i = 0; i < *_wymy; ++i){
        for(int j = 1; j < *_wymx - 1; ++j){
            _obraz[i][j] = (_obraz[i][j-1] + _obraz[i][j] + _obraz[i][j+1]) / 3;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void rozciaganie_histogramu(int _obraz[][MAX], int *_wymx,int *_wymy, int *_szarosci){
    int Lmin = *_szarosci; int Lmax = 0;
    
    for (int i = 0; i < *_wymy; ++i){
        for (int j = 0; j < *_wymx; ++j){
            if(_obraz[i][j] > Lmax) Lmax = _obraz[i][j];
            else if(_obraz[i][j] < Lmin) Lmin = _obraz[i][j];
        }
    }
    
    for (int i = 0; i < *_wymy; ++i){
        for (int j = 0; j < *_wymx; ++j){
            _obraz[i][j] = (_obraz[i][j] - Lmin) * (float)((float)*_szarosci / (float)(Lmax - Lmin));
        }
    }
}
//--------------------------------------------------------------------------------------------------
