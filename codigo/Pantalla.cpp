#include "Pantalla.h"
Pantalla::Pantalla(BITMAP* map, BITMAP* fond, BITMAP* dur, BITMAP* primer,BITMAP* aux)
   {
      fondo = fond;
      mapa = map;
      durezas = dur;
      primerPlano = primer;
      auxiliar= aux;
   }
Pantalla::~Pantalla()
{
  destroy_bitmap(fondo);
  destroy_bitmap(mapa);
  destroy_bitmap(durezas);
  destroy_bitmap(primerPlano);
  destroy_bitmap(auxiliar);
}
void Pantalla::SetFondo(BITMAP* fond)
{fondo = fond;}
BITMAP* Pantalla::GetFondo(void)
{return fondo;}
void Pantalla::SetMapa(BITMAP* map)
{mapa = map;}
BITMAP* Pantalla::GetMapa(void)
{return mapa;}
void Pantalla::SetDurezas(BITMAP* dur)
{durezas = dur;}
BITMAP* Pantalla::GetDurezas(void)
{return durezas;}
void Pantalla::SetPrimerPlano(BITMAP* primer)
{primerPlano = primer;}
BITMAP* Pantalla::GetPrimerPlano(void)
{return primerPlano;}
BITMAP* Pantalla::DibujarFondo(BITMAP* buffer,Personaje*p)
{
   if (key[KEY_RIGHT]&& p->GetX()>screen->w/2 && p->GetX()< mapa->w-screen->w/2)
   {
      blit(fondo,fondo,0,0,639,0,1,screen->h);
      blit(fondo,fondo,1,0,0,0,639,screen->h);
      if (auxiliar)
      {
        blit(auxiliar,auxiliar,0,0,638,0,2,screen->h);
        blit(auxiliar,auxiliar,2,0,0,0,638,screen->h);
      }
   }
   if (key[KEY_LEFT]&& p->GetX()>screen->w/2 && p->GetX()< mapa->w-screen->w/2)
   {
      blit(fondo,fondo,639,0,0,0,1,screen->h);
      blit(fondo,fondo,0,0,1,0,639,screen->h);
      if (auxiliar)
      {
        blit(auxiliar,auxiliar,638,0,0,0,2,screen->h);
        blit(auxiliar,auxiliar,0,0,2,0,638,screen->h);
      }
   }
   blit(fondo,buffer,0,0,0,0,screen->w,screen->h);
   if (auxiliar)
        masked_blit(auxiliar,buffer,0,0,0,0,screen->w,screen->h);
   return buffer;
}
BITMAP* Pantalla::DibujarMapa(BITMAP* buffer,Personaje* p1)
{
   masked_blit(mapa,buffer,p1->GetX()-p1->GetXRel(),0,0,0,buffer->w,buffer->h);
   return buffer;
}
BITMAP* Pantalla::DibujarPrimerPlano(BITMAP* buffer, Personaje* p1)
{
   masked_blit(primerPlano,buffer,p1->GetX()-p1->GetXRel(),0,0,0,buffer->w,buffer->h);
   return buffer;
}

