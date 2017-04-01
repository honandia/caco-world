#ifndef ELEMENTO_H_
#define ELEMENTO_H_

#include <stdlib.h>
#include "allegro/include/allegro.h"
#include "allegro/include/winalleg.h"
//**************************CLASE ELEMENTO**************************************
//La clase Elemento es la clase base , guarda las coordenadas
//x y de cualquier elemento de la jerarquia.
//******************************************************************************
//                                    Elemento
//                                  |          |
//                                |               |
//                             |                      |
//                   Estatico                            Animado
//******************************************************************************
class Elemento
{
protected:
   int cordX;
   int cordY;
public:
   Elemento(int, int);
   ~Elemento();
   void SetX(int);
   int GetX(void);
   void SetY(int);
   int GetY(void);

};

#endif
