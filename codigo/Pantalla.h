#ifndef PANTALLA_H_
#define PANTALLA_H_
#include "Animado.h"
class Pantalla
{
private:
   BITMAP* fondo;
   BITMAP* mapa;
   BITMAP* durezas;
   BITMAP* primerPlano;
   BITMAP* auxiliar;
public:
   Pantalla(BITMAP*,BITMAP*,BITMAP*,BITMAP*, BITMAP*);
   ~Pantalla();
   void SetFondo(BITMAP*);
   BITMAP* GetFondo(void);
   void SetMapa(BITMAP*);
   BITMAP* GetMapa(void);
   void SetDurezas(BITMAP*);
   BITMAP* GetDurezas(void);
   void SetPrimerPlano(BITMAP*);
   BITMAP* GetPrimerPlano(void);
   BITMAP* DibujarFondo(BITMAP*, Personaje*);
   BITMAP* DibujarMapa(BITMAP*, Personaje*);
   BITMAP* DibujarPrimerPlano(BITMAP*, Personaje*);
};
#endif
 