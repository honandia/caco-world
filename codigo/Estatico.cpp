#include"Estatico.h"
//***************CLASE ESTATICO*************************************************
//******************************************************************************
Estatico::Estatico(int x=0, int y=0, BITMAP* imag=NULL): Elemento(x,y),imagen(imag)
{}

Estatico::~Estatico()
{
   destroy_bitmap(imagen);
}

void Estatico::SetImagen(BITMAP* imag)
{
   clear(imagen);
   imagen = imag;
}
BITMAP* Estatico::GetImagen(void)
{
   return imagen;
}
int Estatico::GetW(void)
{
   return imagen->w;
}
int Estatico::GetH(void)
{
   return imagen->h;
}
bool Estatico::Colision(Personaje* p)
{
   return(p->GetX()+p->GetW()/2 > GetX() && p->GetX()+p->GetW()/2<GetX()+GetW()
          && p->GetY()+p->GetH()/2 > GetY() && p->GetY()+p->GetH()/2<GetY()+GetH()/2 );
}
BITMAP* Estatico::Dibujar(BITMAP* buffer,Personaje * p)
{
   draw_sprite(buffer, imagen, GetX()-p->GetX()+p->GetXRel(), GetY());
   return buffer;
}
void Estatico::GetAccion(Personaje*)
{}
//**********************CLASE PUNTOS********************************************
//******************************************************************************
Puntos::Puntos(int x =0,int y=0, BITMAP* imag = NULL, int punt=0):Estatico(x,y,imag),puntos(punt)
{}
Puntos::~Puntos()
{}
void Puntos::SetPuntos(int punt)
{puntos = punt;}
int Puntos::GetPuntos(void)
{return puntos;}
void Puntos::GetAccion(Personaje* p)
{
   p->SumarPuntos(puntos);
}
//**********************CLASE ESTRELLA******************************************
//******************************************************************************
Estrella::Estrella(int x=0, int y=0, BITMAP* imag = NULL):Estatico(x,y,imag)
{}
Estrella::~Estrella()
{}
void Estrella::GetAccion(Personaje* p)
{
   p->SetStatus(3,1); 
}
//********************CLASE BOTA************************************************
//******************************************************************************
Bota::Bota(int x=0, int y=0, BITMAP* imag= NULL):Estatico(x,y,imag)
{}
Bota::~Bota()
{}
void  Bota::GetAccion(Personaje* p)
{
   p->SetBota(true);
}
//*****************CLASE TIEMPO*************************************************
//******************************************************************************
Tiempo::Tiempo(int x=0, int y=0,BITMAP* imag=NULL):Estatico(x,y,imag)
{}
Tiempo::~Tiempo()
{}
void Tiempo::GetAccion(Personaje* p)
{
   p->SetStatus(5,50);
}
//***************CLASE CORAZON**************************************************
//******************************************************************************
Corazon::Corazon(int x=0, int y=0, BITMAP* imag=NULL):Estatico(x,y,imag)
{}
Corazon::~Corazon()
{}
void Corazon::GetAccion(Personaje* p)
{
   p->SetStatus(1,1);
}
//*********************CLASE FUEGO**********************************************
//******************************************************************************
Fuego::Fuego(int x=0, int y=0,BITMAP* imag=NULL):Estatico(x,y,imag)
{}
Fuego::~Fuego()
{}
void Fuego::GetAccion(Personaje* p)
{
   p->SetDisparo(true);
}
//********************CLASE VIDA************************************************
//******************************************************************************
Vida::Vida(int x, int y, BITMAP* imag):Estatico(x,y,imag)
{}
Vida::~Vida()
{}
void Vida::GetAccion(Personaje* p)
{
  p->SetStatus(0,1);// suma 1 vida
}

