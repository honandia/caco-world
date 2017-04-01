#include "Animado.h"
//***********************CLASE ANIMADO***********************************************
//***********************************************************************************

Animado::Animado(int x=0, int y=0,BITMAP* imag1= NULL,BITMAP* imag2= NULL, int vel=0):Elemento(x,y),velocidad(vel)
{
   imagenes[0]= imag1;
   imagenes[1]= imag2;
   frame=0;
   direccion= false;// mirando a la derecha

}
Animado::~Animado()
{
   destroy_bitmap(imagenes[0]);
   destroy_bitmap(imagenes[1]);
}
void Animado::SetImagenes(BITMAP *imag1,BITMAP *imag2)
{
   clear(imagenes[0]);
   clear(imagenes[1]);
   imagenes[0]= imag1;
   imagenes[1]= imag2;
}
BITMAP* Animado::GetImagen(int pos)
{
   return imagenes[pos];
}
void Animado::SigFrame(void)
{
   frame = (frame==1)?0:1;// si frame es mayor q 1 se pone a 0 sino incrementa
}
int Animado::GetFrame(void)
{
   return frame;
}
void Animado::SetFrame(int fr)
{
   frame=fr;
}
void Animado::SetDir(bool dir)
{
   direccion= dir;
}
bool Animado::GetDir(void)
{
   return direccion;
}
void Animado::SetVel(int vel)
{
   velocidad = vel;
}
int Animado::GetVel(void)
{
   return velocidad;
}
int Animado::GetH(void)
{
   return imagenes[frame]->h;
}
int Animado::GetW(void)
{
   return imagenes[frame]->w;
}

//****************************CLASE PERSONAJE*********************************************
//****************************************************************************************

Personaje::Personaje(int x, int y,int xRel, BITMAP * imag1, BITMAP* imag2,int vel)
            :Animado(x, y,imag1, imag2, vel), xRelativa(xRel)
{
   // valores iniciales para los atributos
   status[0]=0;               // 0 vidas
   status[1]=3;               // 3 toques
   status[2]=0;               // 0 puntos
   status[3]=0;               // 0 estrellas
   status[4]=15;              // tope inicial del salto a 15
   status[5]=100;             // 100 de tiempo

   nadar = 3;
   muerto=false;
   pasada=false;
   saltando=false;
   bota=false;
   disparo= false;

}

Personaje::~Personaje()
{}

void Personaje::SetXRel(int xRel)
{xRelativa = xRel;}

int Personaje::GetXRel(void)
{return xRelativa;}
int Personaje::GetNanar(void)
{return nadar;}
void Personaje::SetNadar(int n)
{nadar= n;}
void Personaje::SetDisparo(bool d)
{disparo= d;}

bool Personaje::GetDisparo(void)
{return disparo;}

void Personaje::SetMuerto(bool m)
{muerto = m;}

bool Personaje::GetMuerto(void)
{return muerto;}

void Personaje::SetPasada(bool b)
{pasada= b;}

bool Personaje::GetPasada(void)
{return pasada;}

void Personaje::SetBota(bool b)
{bota = b;}
void Personaje::SetTiempo(int t)
{status[5]=t;}
void Personaje::SetSaltando(bool s)
{saltando= s;}
void Personaje::VerSiMuerto(BITMAP* durezas)
{
   if (getpixel(durezas,GetX(),GetY()+GetH()+1)== 0xff0000)
      status[1]=0;
   if (status[5]<0)
      Reset();
   if (status[1]==0)
      Reset();
   if(status[0]<0)
      muerto=true;
}

void Personaje::Reset(void)
{
   status[0]--;
   status[1]=3;
   status[5]=100;
   SetX(0);
   SetY(0);
   xRelativa=0;
}

void Personaje::VerSiPasada(BITMAP* durezas)
{
   pasada=((getpixel(durezas,GetX()+GetW()/2,GetY()+GetH()+1)== 0xffff00) && (status[3] ==5)); // si esta pisando la salida y ya ha cogido las cinco estrellas
}

int Personaje::GetStatus(int posicion)
{
   return status[posicion]; // retorna el valor de uno de los componentes del array status
}

void Personaje::SetStatus(int posicion, int cantidad)
{
   status[posicion]+= cantidad; // suma cantidad al valor de uno de los componentes de status
}

void Personaje::SumarPuntos(int puntos)
{
   status[2]+=puntos;
}

void Personaje::Avanzar(BITMAP* durezas)
{
   if(!saltando)
   {
      if (getpixel(durezas,GetX(),GetY()+2 * GetH()/3)==0xff)
         SetVel(1);
      if (getpixel(durezas,GetX(),GetY()+2 * GetH()/3)==0)
         SetVel(3);
   }
   if (GetDir())     // si dir indica que esta mirando a la izquda se cambia a la dcha (false)
      SetDir(false);
   if (getpixel(durezas,GetX()+GetW()+5,GetY()+ 2 * GetH()/3)==0
   || getpixel(durezas,GetX()+GetW()+5,GetY()+2*GetH()/3)==0xff)
   {
      if (GetX()<(durezas->w-screen->w/2))
      {
         if (GetXRel() < screen->w/2)
         {
            SetX(GetX()+ GetVel());
            SetXRel(GetXRel()+ GetVel());
         }
         else
            SetX(GetX()+ GetVel());
      }
      else
      {
         SetX(GetX()+ GetVel());
         SetXRel(GetXRel()+ GetVel());
      }
      if (!(GetX()%5))
         SigFrame();
   }
}

void Personaje::Retroceder(BITMAP* durezas)
{
   if(!saltando)
   {
      if (getpixel(durezas,GetX(),GetY())==0xff)
         SetVel(1);
      if (getpixel(durezas,GetX(),GetY())==0)
         SetVel(3);
   }
   if (!GetDir())  // si dir indica que esta mirando a la derecha se cambia a la izqda (true)
      SetDir(true);
   if (getpixel(durezas,GetX()-5,GetY()+2*GetH()/3)==0
   ||getpixel(durezas,GetX()-5,GetY()+2*GetH()/3)==0xff)
   {
      if (GetX()>(screen->w/2))
      {
         if (GetXRel() > (screen->w/2))
         {
            SetX(GetX()-GetVel());
            SetXRel(GetXRel()-GetVel());
         }
         else
         SetX(GetX()-GetVel());
      }
      else
         {
         SetX(GetX()-GetVel());
         SetXRel(GetXRel()-GetVel());
         }
   if (!(GetX()%5))
      SigFrame();
   }
}

void Personaje::Saltar(BITMAP* durezas)
{
  if (( getpixel(durezas,GetX(),GetY()+GetH()+1)!=0
    || getpixel(durezas,GetX()+GetW(),GetY()+GetH()+1)!=0) && nadar >0)
   {
      saltando = true;
   }
  if (saltando && GetY()>0 && ( (getpixel(durezas,GetX(),GetY()-1)==0)
     || (getpixel(durezas,GetX(),GetY()-1)==0xff)))
   {
      SigFrame();
      SetY(GetY()-    2* status[4]);      /*(velocidad-3)*/
      if (status[4]!= 0)
         status[4]--;
      else
         {
            if (getpixel(durezas,GetX(),GetY()-1)==0xff) // para las zonas de agua
            {
               status[4]=9;
            }
            if (getpixel(durezas,GetX(),GetY())==0)
            {
               if (bota)
                  status[4]=18;
               else
                  status[4]=15;
            }
            saltando= false;
            nadar--;
         }
   }
  else
  {
   saltando=false;
   nadar--;
  }
}

void Personaje::Disparar(BITMAP* disp1,BITMAP* disp2)
{
   if (disparo)
      if (listaDisparos.size()< 3)
         listaDisparos.push_back(new Disparo(GetX()+GetW()/2,GetY()+GetH()/2,disp1,disp2,5,direccion));
}

void Personaje::MoverDisparos(BITMAP* durezas,list<Enemigo*>& listaEnemigos)
{
   list <Disparo* > ::iterator i;
   list <Disparo* > ::iterator iborrar;
   list<Disparo*>  ::iterator iAux;
   list<Enemigo*>:: iterator i2;
   list<Enemigo*>:: iterator i2Aux;
   int encontrado ;

   iborrar = listaDisparos.end() ;

   for(i=listaDisparos.begin();i!= listaDisparos.end();i++)
   {

      i2= listaEnemigos.begin();
      encontrado  = 0 ;
      while( ( i2!=listaEnemigos.end() ) && (!encontrado ))
      {
         if ( iborrar != listaDisparos.end() )
         {
            listaDisparos.remove(*iborrar);
            iborrar  = listaDisparos.end();
            encontrado = 0;
         }
         if ((*i)->Colision(*i2))
         {
            SumarPuntos(100);
            i2Aux= i2;
            i2++;
            listaEnemigos.remove(*i2Aux);
            iborrar = i ;
            encontrado  =1 ;
         }
         else
         i2 ++ ;
      }


   }
   if  ( encontrado )
      listaDisparos.remove(*iborrar);
   for (i=listaDisparos.begin();i!=listaDisparos.end();i++)
   {
      if (getpixel(durezas,(*i)->GetX(),(*i)->GetY()) == 0 && (*i)->GetX()<GetX()+screen->w-GetXRel()
          && (*i)->GetX()>GetX()-screen->w-GetXRel())
         (*i) ->Mover();
      else
      {
         iAux= i;
         i++;
         listaDisparos.remove(*iAux);
      }
   }

}
void Personaje::MoverDisparos(list<EnemigoD*>& listaEnemigosD)
{
   list <Disparo* > ::iterator i;
   list <Disparo* > ::iterator iborrar;
   list<Disparo*>  ::iterator iAux;
   list<EnemigoD*>:: iterator i2;
   list<EnemigoD*>:: iterator i2Aux;
   int encontrado ;

   iborrar = listaDisparos.end() ;

   for(i=listaDisparos.begin();i!= listaDisparos.end();i++)
   {

      i2= listaEnemigosD.begin();
      encontrado  = 0 ;
      while( ( i2!=listaEnemigosD.end() ) && (!encontrado ))
      {
         if ( iborrar != listaDisparos.end() )
         {
            listaDisparos.remove(*iborrar);
            iborrar  = listaDisparos.end();
            encontrado = 0;
         }
         if ((*i)->Colision(*i2))
         {
            SumarPuntos(100);
            (*i2)->SetToques((*i2)->GetToques()-1);
            iborrar = i ;
            encontrado  =1 ;
         }
         else
         i2 ++ ;
      }
   }
   if  ( encontrado )
      listaDisparos.remove(*iborrar);
   for(i2=listaEnemigosD.begin(); i2!=listaEnemigosD.end(); i2++)
   {
      if ((*i2)->GetToques()<1)
      {
        i2Aux=i2;
        i2++;
        listaEnemigosD.remove(*i2Aux);
      }
   }
}


BITMAP* Personaje::DibujarListaDisparos(BITMAP* buffer)
{
   list<Disparo*>::iterator i;
   for (i=listaDisparos.begin();i!=listaDisparos.end();i++)
   {
      buffer=(*i)->Dibujar(buffer,this);
   }
   return buffer;
}

BITMAP* Personaje::DibujarMarcador(BITMAP* buffer,BITMAP* b,BITMAP* d, bool tiempo)
{
   textout(buffer, font, "Vidas:",2,5,0xffff00);
   textout(buffer, font, "Toques:",2,15,0xffff00);
   textout(buffer, font, "Estrellas:",120,5,0xffff00);
   if (tiempo)
      textout(buffer, font, "Tiempo:",500,5,0xffff00);
   textout(buffer, font, "Puntos:", 120, 15, 0xffff00);
   if ( bota)
      if (b)
        draw_sprite(buffer,b,2,30);
   if (disparo)
      if (d)
        draw_sprite(buffer,d,34,30);
   if (status[3]>4)
      textout(buffer, font, "La salida esta abierta ahora!!",220,5,-1);
   if (status[5]<50 && status[5] %2)
      textout(buffer, font, "Date prisa!!",500,15,-1);
   textout(buffer, font,itoa(GetStatus(0)," ",10),60,5,-1);
   textout(buffer, font,itoa(GetStatus(1)," ",10),60,15,-1);
   textout(buffer, font,itoa(GetStatus(2)," ",10),200,15,-1);
   textout(buffer, font,itoa(GetStatus(3)," ",10),200,5,-1);
   if (tiempo)
      textout(buffer, font,itoa(GetStatus(5)," ",10),570,5,-1);

   return buffer;
}
BITMAP* Personaje::DibujarPersonaje(BITMAP* buffer,BITMAP* durezas)
{
   if ((getpixel(durezas,GetX(),GetY()+GetH())==0) &&
   (getpixel(durezas,GetX()+GetW(),GetY()+GetH())==0)
   ||( getpixel(durezas,GetX(),GetY()+GetH())== 0xff)&&
   (getpixel(durezas,GetX()+GetW(),GetY()+GetH())==0xff))
   {
      if((getpixel(durezas,GetX(),GetY()+GetH())==0) &&
      (getpixel(durezas,GetX()+GetW(),GetY()+GetH())==0))
         SetY(GetY()+10);//para que parezca que hay gravedad.

      if (( getpixel(durezas,GetX(),GetY()+GetH())== 0xff)&&
      (getpixel(durezas,GetX()+GetW(),GetY()+GetH())==0xff))
         {
         SetY(GetY()+2);// gravedad para el agua
         }
   }
   else
      if(getpixel(durezas,GetX(),GetY()+GetH()-1)==0xffffff
      ||getpixel(durezas,GetX()+GetW(),GetY()+GetH()-1)==0xffffff
      ||(getpixel(durezas,GetX(),GetY()+GetH()-1)==0xffff00)
      ||(getpixel(durezas,GetX()+GetW(),GetY()+GetH()-1)==0xffff00))
      {
         SetY(GetY()-1);//corrige lo que se haya pasado del borde real

      }
   if((getpixel(durezas,GetX(),GetY()+GetH()+1)==0xffffff)
   ||(getpixel(durezas,GetX()+GetW(),GetY()+GetH()+1)==0xffffff)
   ||(getpixel(durezas,GetX(),GetY()+GetH()+1)==0xffff00)
   ||(getpixel(durezas,GetX()+GetW(),GetY()+GetH()+1)==0xffff00))
   {
      nadar= 3;
   }
   (direccion)
   ? draw_sprite_h_flip(buffer, imagenes[frame], GetXRel(),GetY()) // dibujar mirando hacia la izqda
   : draw_sprite(buffer, imagenes[frame], GetXRel(), GetY());   //dibujar mirando hacia la dcha
   return buffer;
}

//****************************CLASE ENEMIGO*************************************

Enemigo::Enemigo(int x=0, int y=0, BITMAP* imag1= NULL, BITMAP* imag2=NULL, int vel=0, int lim=0 ,char tip=' ')
                :Animado(x, y,imag1, imag2, vel), limite(lim),tipo(tip)
{
   recorrido =0;
}

Enemigo::~Enemigo()
{}

void Enemigo::Mover(void)
{
   if(direccion)
   {
      if(recorrido < limite)
      {
         recorrido++;
         switch (tipo)
         {
         case 'H': cordX+=velocidad; if(!(GetX()%10)) SigFrame(); break;//avanza hacia la dcha
         case 'V': cordY-=velocidad; //sube
         }
      }
      else
      {
         recorrido=0;
         direccion=false;
      }
   }
   else
   {
      if(recorrido < limite)
      {
         recorrido++;
         switch (tipo)
         {
         case 'H': cordX-=velocidad; if(!(GetX()%10)) SigFrame(); break;//avanza hacia la izquierda
         case 'V': cordY+=velocidad; if(!(GetY()%10)) SigFrame();//baja
         }
      }
      else
      {
         recorrido=0;
         direccion=true;
      }
   }
}
//************************************************
void Enemigo::Atacar(Personaje* p)
{
   if (GetX() < p->GetX())
   {
      p->SetStatus(1,-1);
      p->SetX(p->GetX()+20);
   }
   else
   {
      p->SetStatus(1,-1);
      p->SetX(p->GetX()-20);
   }
}
bool Enemigo::Colision(Personaje * p)
{
   return(p->GetX()+p->GetW() > GetX() && p->GetX()<GetX()+GetW()
          && p->GetY()+p->GetH() > GetY() && p->GetY()<GetY()+GetH());
}
//****************************************************
void Enemigo::SetTipo(char tip)
{
   tipo = tip;
}
BITMAP* Enemigo::Dibujar (BITMAP* buffer,Personaje* p)
{
   if (tipo=='H')
      if (!direccion)
         draw_sprite(buffer, imagenes[frame], GetX() - p->GetX()+p->GetXRel(), GetY());
      else
         draw_sprite_h_flip(buffer, imagenes[frame], GetX() - p->GetX()+p->GetXRel(), GetY());
   else
      draw_sprite(buffer, imagenes[frame], GetX() - p->GetX()+p->GetXRel(), GetY());
   return buffer;
}
//***********************CLASE ENEMIGOD*****************************************
EnemigoD::EnemigoD(int x=0, int y=0,BITMAP* imag1=NULL,BITMAP* imag2=NULL, int vel=0, int lim=0,char tip= ' ',int toq=0,int frec=0)
:Enemigo(x,y,imag1,imag2,vel,lim,tip),toques(toq),frecuencia(frec)
{}

EnemigoD::~EnemigoD()
{}
void EnemigoD::SetFrecuencia(int f)
{
   frecuencia= f;
}
int EnemigoD::GetToques(void)
{
  return toques;
}
void EnemigoD::SetToques(int t)
{
  toques = t;
}
void EnemigoD::Disparar(BITMAP* disp1, BITMAP* disp2, int vel, Personaje* p)
{
   if (GetX()<(p->GetX()+screen->w-p->GetXRel()) && (GetX()>p->GetX()- p->GetXRel()))
   {
    switch(tipo)
    {
      case 'H':
            if (!(GetX() % frecuencia))
               listaDisparos.push_back(new Disparo(GetX(),GetY()+GetH()/3,disp1,disp2,vel,!GetDir()));break;
      case 'V':
           if(!GetDir())
            if (!(GetY() % frecuencia))
               listaDisparos.push_back(new Disparo(GetX(),GetY()+GetH()/3,disp1,disp2,vel,!GetDir()));
    }
   }
}
BITMAP* EnemigoD::DibujarVida(BITMAP* buffer,Personaje* p)
{
  textout(buffer,font,itoa(toques," ",10),GetX()-p->GetX()+p->GetXRel()+GetW()/2,GetY()-10,-1);
  return buffer;

}
BITMAP* EnemigoD::ActualizarDisparos(BITMAP* buffer,Personaje* p)
{
  list<Disparo*>::iterator i;
  list<Disparo*>::iterator iAux;
  for(i= listaDisparos.begin();i!=listaDisparos.end();i++)
  {
    (*i)->Mover();
    if((*i)->Colision(p))
      {
        iAux=i;
        i++;
        listaDisparos.remove(*iAux);
        p->SetStatus(1,-1);
      }
  }
  for (i= listaDisparos.begin();i!=listaDisparos.end();i++)
    buffer= (*i)->Dibujar(buffer,p);
  return buffer;

}
//************************CLASE DISPARO*****************************************

Disparo::Disparo(int x, int y,BITMAP* imag1,BITMAP*imag2,int vel,bool dir)
:Animado(x,y,imag1,imag2,vel)
{
   direccion = dir;
}

Disparo::~Disparo()
{}

void Disparo::Mover()
{
   (direccion)
   ? SetX(GetX() - GetVel())
   : SetX(GetX() + GetVel());

   if (!(GetX() % 10))
      SigFrame();
}

BITMAP* Disparo::Dibujar(BITMAP* buffer,Personaje * p)
{
   draw_sprite(buffer, imagenes[frame],GetX() - p->GetX()+p->GetXRel(), GetY());
   return buffer;
}
bool Disparo::Colision (Enemigo* e)
{
  return(GetX() > e->GetX() && GetX()< e->GetX()+e->GetW()
  && GetY()+e->GetH() > e->GetY() && GetY()< e->GetY()+e->GetH());
}
bool Disparo::Colision (EnemigoD* eD)
{
  return(GetX() > eD->GetX() && GetX()< eD->GetX()+eD->GetW()
  && GetY()+eD->GetH() > eD->GetY() && GetY()< eD->GetY()+eD->GetH());
}
bool Disparo::Colision (Personaje* p)
{
  return(GetX() > p->GetX() && GetX()< p->GetX()+p->GetW()
  && GetY() > p->GetY() && GetY()< p->GetY()+p->GetH());
}
