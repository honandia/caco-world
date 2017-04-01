#ifndef ANIMADO_H_
#define ANIMADO_H_
#include "Elemento.h"
#include <list>
using namespace std;


//****************************CLASE ANIMADO*************************************
//                            Animado
//                         |     |      |
//                  Personaje   Enemigo  Disparo
//                               |
//                              EnemigoD
//******************************************************************************
class Enemigo;
class EnemigoD;
class Personaje;

class Animado: public Elemento
{
protected:
   BITMAP* imagenes[2];
   int frame;
   bool direccion;// false--> mirando hacia la derecha; true--> mirando hacia la izquierda
   int velocidad;
public:
   Animado(int, int,BITMAP*,BITMAP*, int);
   ~Animado();
   void SetImagenes(BITMAP*,BITMAP*);
   BITMAP* GetImagen(int);
   void SigFrame(void);
   int GetFrame(void);
   void SetFrame(int);
   void SetDir(bool);
   bool GetDir(void);
   void SetVel(int);
   int GetVel(void);
   int GetH(void);
   int GetW(void);
};
//*****************CLASE DISPARO************************************************
class Disparo: public Animado
{
public:
   Disparo(int, int,BITMAP*,BITMAP*,int,bool);
   ~Disparo();
   void Mover();
   BITMAP* Dibujar(BITMAP*, Personaje*);
   bool Colision (Enemigo*);
   bool Colision (EnemigoD*);
   bool Colision (Personaje*);
};
//***************************CLASE PERSONAJE************************************
class Personaje: public Animado
{
protected:
   list<Disparo*> listaDisparos; // guarda los diaparo del personaje
   int xRelativa;// coordenada X relativa al buffer
   bool muerto; // false--> vivo, true--> muerto
   bool pasada; // true--> pantalla pasada, false--> pantalla no pasada
   bool saltando; // true-->esta saltando, false--> no esta saltando
   bool bota; // true-> si ha cogido bota
   bool disparo; // true-> si ha cogido el item disparo
   int nadar;// para contar las brazadas
   int status[6];//posiciones:
                  // 0-->vidas
                  // 1-->toques
                  // 2-->puntos
                  // 3-->estrellas
                  // 4-->tope para el salto
                  // 5-->tiempo

public:
   Personaje(int,int,int,BITMAP *,BITMAP *,int);
   ~Personaje();
   void SetXRel(int);
   int GetXRel(void);
   int GetNanar(void);
   void SetNadar(int);
   void SetDisparo(bool);
   bool GetDisparo(void);
   void SetMuerto(bool);
   bool GetMuerto(void);
   void SetPasada(bool);
   bool GetPasada(void);
   void SetBota(bool);
   void SetTiempo(int);
   void SetSaltando(bool);
   void VerSiMuerto(BITMAP*);
   void VerSiPasada(BITMAP*);
   void Reset(void);
   void SetStatus(int,int);
   int GetStatus(int);
   void SumarPuntos(int);
   void Avanzar(BITMAP*);
   void Retroceder(BITMAP*);
   void Saltar(BITMAP*);
   void Disparar(BITMAP*,BITMAP*);
   void MoverDisparos(BITMAP*,list<Enemigo*>&);
   void MoverDisparos(list<EnemigoD*> &);
   BITMAP* DibujarListaDisparos(BITMAP*);
   BITMAP* DibujarMarcador(BITMAP*,BITMAP*,BITMAP*,bool);
   BITMAP* DibujarPersonaje(BITMAP*,BITMAP*);
};
//*****************CLASE ENEMIGO************************************************
class Enemigo: public Animado
{
protected:
   int limite;  // limite del recorrido que hara el enemigo
   int recorrido; // espacio recorrido hasta el limite
   char tipo;     // 'H'--> Enemigo Horizontal
                  // 'V'--> Enemigo Vertical
public:
   Enemigo(int, int,BITMAP*,BITMAP*, int, int,char);
   ~Enemigo();
   void SetTipo(char);
   void Mover(void);
   void Atacar(Personaje*);
   bool Colision(Personaje*);
   BITMAP* Dibujar (BITMAP*,Personaje*);
};
//*****************CLASE ENEMIGOD***********************************************
// clase para los enemigos con disparo
//******************************************************************************
class EnemigoD: public Enemigo
{
protected:
   int toques; // los enemigos con disparo tienen toques
   int frecuencia;// frecuencia con la que se producen los disparos
   list <Disparo*> listaDisparos;// lista donde se guardan los diaparos
public:
   EnemigoD(int, int,BITMAP*,BITMAP*, int, int,char,int,int);
   ~EnemigoD();
   void SetFrecuencia(int);
   int GetToques(void);
   void SetToques(int);
   void Disparar(BITMAP*, BITMAP*, int, Personaje*) ;
   BITMAP* DibujarVida(BITMAP*,Personaje*);
   BITMAP* ActualizarDisparos(BITMAP*,Personaje*);

};       
#endif