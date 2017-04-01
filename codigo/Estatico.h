#ifndef ESTATICO_H_
#define ESTATICO_H_

#include "Elemento.h"
#include "Animado.h"

//******************************************************************************
//****************** CLASE ESTATICO*********************************************
//*******clase abstracta de la que "cuelgan" todos los items del juego**********
//
//                                  Estatico
//                        /   |     |     |        |        |       |
//                      /     |     |      |         |       |       |
//               Puntos  Estrella   Bota   Tiempo    Corazon  Fuego   Vida
//******************************************************************************
class Estatico: public Elemento
{
protected:
   BITMAP * imagen;
public:
   Estatico(int, int,BITMAP *);
   virtual ~Estatico();
   void SetImagen(BITMAP*);
   BITMAP* GetImagen(void);
   int GetW(void);// para las colisiones bounding boxes
   int GetH(void);// para las colisiones bounding boxes
   bool Colision(Personaje*);
   BITMAP* Dibujar(BITMAP*,Personaje*);//para dibujar los items en el buffer
   virtual void GetAccion(Personaje * )=0;//funcion virtual para crear punteros a
                                        // la clase base, Estatico ,que apunten a objetos
                                        // de las clases hijas, (items), y dependiendo de que tipo
                                        // sean hagan una accion sobre el personaje u otra
};
//******************CLASE PUNTOS************************************************
//hereda de Estatico,esta pensada para items que sumen puntos al ser recogidos
// por el personaje.
//******************************************************************************
class Puntos: public Estatico
{
protected:
   int puntos;// puntos que tiene el objeto
public:
   Puntos(int,int, BITMAP*, int);
   ~Puntos();
   void SetPuntos(int);
   int GetPuntos(void);
   void GetAccion(Personaje*);// incrementa los puntos correspondientes al personaje
};
//********************CLASE ESTRELLA********************************************
//los objetos de esta clase son los items que el personaje debera recolectar a
//lo largo de la pantalla para poder acceder a la salida y completar el nivel
//******************************************************************************
class Estrella: public Estatico
{
public:
   Estrella(int,int,BITMAP*);
   ~Estrella();
   void GetAccion(Personaje*);// aumenta en uno el contador de estrellas del personaje
};
//********************CLASE BOTA************************************************
// al recoger este item el personaje saltara más
//******************************************************************************
class Bota: public Estatico
{
public:
   Bota(int,int,BITMAP*);
   ~Bota();
   void GetAccion(Personaje*);// aumenta la potencia de salto del personaje
};
//********************CLASE TIEMPO**********************************************
//da mas tiempo para acabar la pantalla
//******************************************************************************
class Tiempo: public Estatico
{
public:
   Tiempo(int, int,BITMAP*);
   ~Tiempo();
   void GetAccion(Personaje*);// aumenta el limite de tiempo para pasar la pantalla
};
//*******************CLASE CORAZON**********************************************
//item que incrementa los toque del personaje
//******************************************************************************
class Corazon: public Estatico
{
public:
   Corazon(int, int,BITMAP*);
   ~Corazon();
   void GetAccion(Personaje*); //Suma 1 toque al personaje
};
//******************CLASE FUEGO*************************************************
// cuando el personaje coja este item sera capaz de disparar
//******************************************************************************
class Fuego: public Estatico
{
public:
   Fuego(int, int,BITMAP*);
   ~Fuego();
   void GetAccion(Personaje*); //da la habilidad de disparar
};
//**********************CLASE VIDA**********************************************
// los objetos de esta clase representan una vida extra
//******************************************************************************
class Vida: public Estatico
{
public:
  Vida(int, int, BITMAP*);
  ~Vida();
  void GetAccion(Personaje*); //suma 1 al contador de vidas
};
#endif

