#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "Elemento.h"
#include "Animado.h"
#include "Estatico.h"
#include "Pantalla.h"
#include <fstream.h>
#include <list>
using namespace std;
void CargarListaEstaticos(char* ,list<Estatico *>&);
BITMAP* DibujarListaEstaticos(list<Estatico*>& ,Personaje* ,BITMAP*,SAMPLE *);
void CargarListaEnemigos(char* ,list<Enemigo*>&);
BITMAP* DibujarListaEnemigos(list<Enemigo*>&, Personaje*, BITMAP*, SAMPLE *);
void ComprobarTeclas(Personaje*, Pantalla*, BITMAP*, BITMAP*, bool&);
void Inicializar(bool, bool);
int Pantalla1(Personaje*);
int Pantalla2(Personaje*);
int Pantalla3(Personaje*);
int PantallaFinal(Personaje*);
void Creditos(void);
void GameOver(void);
void Recuento(BITMAP*,Personaje*, Pantalla*);

#endif
 