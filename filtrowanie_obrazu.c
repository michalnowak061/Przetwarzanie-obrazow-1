//
//  filtrowanie_obrazu.c
//  Przetwarzanie_obrazów_1
//
//  Created by Michał on 23.06.2018.
//  Copyright © 2018 Michał. All rights reserved.
//

#include "filtrowanie_obrazu.h"

//--------------------------------------------------------------------------------------------------
void splot(int _obraz[][MAX],int *_wymx, int *_wymy, int _maska[3][3]){
    int bitmapa[*_wymy][*_wymx]; // <- tymczasowa bitmapa do przechowania pikseli po splocie
    
    //wykonanie splotu maski z obrazem
    for(int i = 1; i < *_wymy - 1; ++i){
        for(int j = 1; j < *_wymx - 1; ++j){
            bitmapa[i][j] = (_maska[0][0] * _obraz[i-1][j-1]) + (_maska[0][1] * _obraz[i-1][j]) + (_maska[0][2] * _obraz[i-1][j+1])
                          + (_maska[1][0] * _obraz[i][j-1])   + (_maska[1][1] * _obraz[i][j])   + (_maska[1][2] * _obraz[i][j+1])
                          + (_maska[2][0] * _obraz[i+1][j-1]) + (_maska[2][1] * _obraz[i+1][j]) + (_maska[2][2] * _obraz[i+1][j+1]);
        }
    }
    //przekopiowanie zawartosci bitmapy do obrazu
    for(int i = 1; i < *_wymy - 1; ++i){
        for(int j = 1; j < *_wymx - 1; ++j){
            _obraz[i][j] = bitmapa[i][j];
        }
    }
    //sprawdzenie czy wszystkie wspolczynniki maski sa dodatnie
    int dodatnie = 1;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(_maska[i][j] < 0){
                dodatnie = 0; break;
            }
        }
    }
    //normalizacja
    int Lmin = 255; int Lmax = 0;
    
    switch(dodatnie){
        //normalizacja dla dodatnich i ujemnych wspolczynnikow maski
        case 0:
            for (int i = 1; i < *_wymy - 1; ++i){
                for (int j = 1; j < *_wymx - 1; ++j){
                    if(_obraz[i][j] > Lmax) Lmax = _obraz[i][j];
                    else if(_obraz[i][j] < Lmin) Lmin = _obraz[i][j];
                }
            }
            
            for(int i = 1; i < *_wymy - 1; ++i){
                for(int j = 1; j < *_wymx - 1; ++j){
                    _obraz[i][j] = ( (float)(_obraz[i][j] - Lmin) / (float)(Lmax - Lmin) ) * 255;
                }
            }
            break;
        //normalizacja dla dodatnich wspolczynnikow maski
        case 1:
            for(int i = 1; i < *_wymy - 1; ++i){
                for(int j = 1; j < *_wymx - 1; ++j){
                    _obraz[i][j] = _obraz[i][j] / (_maska[0][0] + _maska[0][1] + _maska[0][2]
                                                  +_maska[1][0] + _maska[1][1] + _maska[1][2]
                                                  +_maska[2][0] + _maska[2][1] + _maska[2][2]);
                }
            }
            break;
    }
}
//--------------------------------------------------------------------------------------------------
void filtr_usredniajacy(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = 1; W[0][1] = 1; W[0][2] = 1;
    W[1][0] = 1; W[1][1] = 1; W[1][2] = 1;
    W[2][0] = 1; W[2][1] = 1; W[2][2] = 1;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
void filtr_usredniajacy_ze_wzmocnieniem(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = 1; W[0][1] = 1; W[0][2] = 1;
    W[1][0] = 1; W[1][1] = 2; W[1][2] = 1;
    W[2][0] = 1; W[2][1] = 1; W[2][2] = 1;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
void gradient_robertsa(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = 0;  W[0][1] = 0; W[0][2] = 0;
    W[1][0] = -1; W[1][1] = 0; W[1][2] = 0;
    W[2][0] = 0;  W[2][1] = 1; W[2][2] = 0;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
void pozioma_maska_prewitta(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = -1;  W[0][1] = -1; W[0][2] = -1;
    W[1][0] = 0;   W[1][1] = 0;  W[1][2] = 0;
    W[2][0] = 1;   W[2][1] = 1;  W[2][2] = 1;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
void maska_sobela(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = -1;  W[0][1] = -2; W[0][2] = -1;
    W[1][0] = 0;   W[1][1] = 0;  W[1][2] = 0;
    W[2][0] = 1;   W[2][1] = 2;  W[2][2] = 1;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
void maska_wykrywajaca_narozniki(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = 1;  W[0][1] = 1;  W[0][2] = 1;
    W[1][0] = -1; W[1][1] = -2; W[1][2] = 1;
    W[2][0] = -1; W[2][1] = -1; W[2][2] = 1;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
void laplasjan(int _obraz[][MAX],int *_wymx, int *_wymy){
    int W[3][3];
    
    W[0][0] = -1; W[0][1] = -1; W[0][2] = -1;
    W[1][0] = -1; W[1][1] = -8; W[1][2] = -1;
    W[2][0] = -1; W[2][1] = -1; W[2][2] = -1;
    
    splot(_obraz,_wymx,_wymy,W);
}
//--------------------------------------------------------------------------------------------------
