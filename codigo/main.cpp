#include "main.h"
#include "MenuPrincipal.h"


int Juego(bool modoGrafico, bool musica, int vidas)
{
   bool gOver= false;
   int puntos=0;
   Inicializar(modoGrafico, musica);
   BITMAP* mono1 = load_bitmap("imagenes/personaje/mono1.bmp", NULL);
   BITMAP* mono2 = load_bitmap("imagenes/personaje/mono2.bmp", NULL);
   Personaje* p1 = new Personaje(0,0,0,mono1,mono2,3);
   p1->SetStatus(0,vidas);
   puntos= Pantalla1(p1);
   if (p1->GetMuerto()&& !gOver)
   {
      GameOver();
      gOver=true;
   }
   if (p1->GetPasada())
   {
    p1->SetTiempo(100);
    p1->SetBota(false);
    p1->SetPasada(false);
    p1->SetStatus(3,-5);
    p1->SetXRel(300);
    p1->SetX(300);
    p1->SetY(0);
    puntos= Pantalla2(p1);
   }
  if (p1->GetMuerto()&& !gOver)
   {
      GameOver();
      gOver=true;
   }
   if (p1->GetPasada())
   {
    p1->SetTiempo(100);
    p1->SetBota(false);
    p1->SetPasada(false);
    p1->SetStatus(3,-5);
    p1->SetXRel(0);
    p1->SetX(0);
    p1->SetY(0);
    puntos= Pantalla3(p1);
   }
  if (p1->GetMuerto()&& !gOver)
   {
      GameOver();
      gOver=true;
   }
  if (p1->GetPasada())
   {
      p1->SetDisparo(false);
      p1->SetBota(false);
      p1->SetPasada(false);
      p1->SetStatus(3,-5);
      p1->SetXRel(600);
      p1->SetX(600);
      p1->SetY(0);
      puntos= PantallaFinal(p1);
      if (p1->GetPasada())
        Creditos();
   }
   if (p1->GetMuerto()&& !gOver)
   {
      GameOver();
      gOver=true;
   }  
   allegro_exit();
   return puntos;
}




