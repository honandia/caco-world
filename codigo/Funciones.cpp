#include "Funciones.h"
void Inicializar(bool modo, bool musica)
{
   allegro_init();
   install_keyboard();
   text_mode(-1);
   set_color_depth(32);
   install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);

   (musica)
      ? set_volume(0xC0,0xC0)
      : set_volume(0x00,0x00);

   (modo)
      ? set_gfx_mode(GFX_AUTODETECT, 640,480, 0, 0)
      : set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640,480, 0, 0);
   extern FONT * font; // varariable tipo FONT* para escribir el marcador
}

void CargarListaEstaticos(char * ruta, list<Estatico *>& lista)
{
   //cargo los bitmaps para los objetos
   BITMAP* bota = load_bitmap("imagenes/estaticos/bota.bmp", NULL);
   BITMAP* corazon = load_bitmap("imagenes/estaticos/corazon.bmp", NULL);
   BITMAP* estrella = load_bitmap("imagenes/estaticos/estrella.bmp", NULL);
   BITMAP* tiempo = load_bitmap("imagenes/estaticos/tiempo.bmp", NULL);
   BITMAP* diamante = load_bitmap("imagenes/estaticos/diamante.bmp", NULL);
   BITMAP* hamburguesa = load_bitmap("imagenes/estaticos/hamburguesa.bmp", NULL);
   BITMAP* sandia = load_bitmap("imagenes/estaticos/sandia.bmp", NULL);
   BITMAP* pimiento = load_bitmap("imagenes/estaticos/pimiento.bmp", NULL);
   BITMAP* manzana = load_bitmap("imagenes/estaticos/manzana.bmp", NULL);
   BITMAP* fuego = load_bitmap("imagenes/estaticos/fuego.bmp",NULL);
   BITMAP* vida = load_bitmap("imagenes/estaticos/vida.bmp",NULL);
   int x=0;
   int y=0;
   char* tipo;
   char buffer [50];
   fstream fichCoord;
   fichCoord.open(ruta);// lo abro
   fichCoord.getline(buffer,50);//leo la 1ª linea
   x=atoi(buffer);
   fichCoord.getline(buffer,50);
   y=atoi(buffer);
   fichCoord.getline(buffer,50);
   tipo=buffer;
   while (!(fichCoord.eof()))
   {
      switch (*tipo)
      {
         case 'e': lista.push_back(new Estrella(x,y,estrella));break;
         case 'c': lista.push_back(new Corazon(x,y,corazon));break;
         case 'b': lista.push_back(new Bota(x,y,bota));break;
         case 'f': lista.push_back(new Fuego(x,y,fuego));break;
         case 't': lista.push_back(new Tiempo(x,y,tiempo));break;
         case 'm': lista.push_back(new Puntos(x,y,manzana,20));break;
         case 'p': lista.push_back(new Puntos(x,y,pimiento,50));break;
         case 's': lista.push_back(new Puntos(x,y,sandia,100));break;
         case 'h': lista.push_back(new Puntos(x,y,hamburguesa,150));break;
         case 'd': lista.push_back(new Puntos(x,y,diamante,300));break;
         case 'v': lista.push_back(new Vida(x,y,vida));
      }
      fichCoord.getline(buffer,50);//leo la 1ª linea
      x=atoi(buffer);
      fichCoord.getline(buffer,50);
      y=atoi(buffer);
      fichCoord.getline(buffer,50);
      tipo=buffer;
   }
   fichCoord.close(); //cierro el fichero
}

void CargarListaEnemigos(char* ruta,list<Enemigo*> & lista)
{
   BITMAP* aranya1 = load_bitmap("imagenes/enemigos/aranya1.bmp", NULL);
   BITMAP* aranya2 = load_bitmap("imagenes/enemigos/aranya2.bmp", NULL);
   BITMAP* cangrejo1 = load_bitmap("imagenes/enemigos/cangrejo1.bmp", NULL);
   BITMAP* cangrejo2 = load_bitmap("imagenes/enemigos/cangrejo2.bmp", NULL);
   BITMAP* mosquito1 = load_bitmap("imagenes/enemigos/mosquito1.bmp", NULL);
   BITMAP* mosquito2 = load_bitmap("imagenes/enemigos/mosquito2.bmp", NULL);
   BITMAP* tio1 = load_bitmap("imagenes/enemigos/tio1.bmp", NULL);
   BITMAP* tio2 = load_bitmap("imagenes/enemigos/tio2.bmp", NULL);
   BITMAP* pez1 = load_bitmap("imagenes/enemigos/pez1.bmp", NULL);
   BITMAP* pez2 = load_bitmap("imagenes/enemigos/pez2.bmp", NULL);
   BITMAP* jibion1 = load_bitmap("imagenes/enemigos/jibion1.bmp", NULL);
   BITMAP* jibion2 = load_bitmap("imagenes/enemigos/jibion2.bmp", NULL);
   int x=0;
   int y=0;
   char* tipo;
   int vel=0;
   int lim=0;
   char buffer [50];
   fstream fichCoord;
   fichCoord.open(ruta);// lo abro
   fichCoord.getline(buffer,50);//leo la 1ª linea
   x=atoi(buffer);
   fichCoord.getline(buffer,50);
   y=atoi(buffer);
   fichCoord.getline(buffer,50);
   vel=atoi(buffer);
   fichCoord.getline(buffer,50);
   lim= atoi(buffer);
   fichCoord.getline(buffer,50);
   tipo=buffer;
   while (!(fichCoord.eof()))
   {
      switch (*tipo)
      {
         case 'a': lista.push_back(new Enemigo(x,y,aranya1,aranya2,vel,lim,'V'));break;
         case 'j': lista.push_back(new Enemigo(x,y,jibion1,jibion2,vel,lim,'V'));break;
         case 'c': lista.push_back(new Enemigo(x,y,cangrejo1,cangrejo2,vel,lim,'H'));break;
         case 'm': lista.push_back(new Enemigo(x,y,mosquito1,mosquito2,vel,lim,'H'));break;
         case 'p': lista.push_back(new Enemigo(x,y,pez1,pez2,vel,lim,'H'));break;
         case 't': lista.push_back(new Enemigo(x,y,tio1,tio2,vel,lim,'H'));
      }
      fichCoord.getline(buffer,50);//leo la 1ª linea
      x=atoi(buffer);
      fichCoord.getline(buffer,50);
      y=atoi(buffer);
      fichCoord.getline(buffer,50);
      vel=atoi(buffer);
      fichCoord.getline(buffer,50);
      lim= atoi(buffer);
      fichCoord.getline(buffer,50);
      tipo=buffer;
   }
   fichCoord.close(); //cierro el fichero
}

BITMAP* DibujarListaEstaticos(list<Estatico*>& listaEstaticos,Personaje* p1,BITMAP* buffer, SAMPLE * item)
{
   list <Estatico* >:: iterator i; //iterador para la lista de Estatico*
   list<Estatico*>::iterator iAux;
   for(i=listaEstaticos.begin(); i != listaEstaticos.end(); i++)
   {
      buffer= (*i)->Dibujar(buffer,p1);
      if ((*i)->Colision(p1))
      {
         play_sample(item, 0xC0,0xC0, 1000, 0);
         iAux=i;
         i++;
         (*iAux)->GetAccion(p1);
         listaEstaticos.remove(*iAux);
      }
   }
   return buffer;
}

BITMAP* DibujarListaEnemigos(list<Enemigo*>& listaEnemigos,Personaje* p1,BITMAP* buffer, SAMPLE * muerto)
{
   list <Enemigo *>:: iterator i2; //iterador para la lista de Enemigo*
   for(i2=listaEnemigos.begin(); i2 != listaEnemigos.end(); i2++)
   {
      (*i2)->Mover();
      buffer=(*i2)->Dibujar(buffer,p1);
      if ((*i2)->Colision(p1))
      {
         play_sample(muerto, 0xC0,0xC0, 1000, 0);
         (*i2)->Atacar(p1);
      }
   }
   return buffer;
}

BITMAP* DibujarListaEnemigosD(list<EnemigoD*>& listaEnemigosD,Personaje* p1,BITMAP* buffer, SAMPLE * muerto,BITMAP*disp1,BITMAP*disp2)
{
   list <EnemigoD *>:: iterator i2; //iterador para la lista de Enemigo*
   for(i2=listaEnemigosD.begin(); i2 != listaEnemigosD.end(); i2++)
   {
      (*i2)->Mover();
      (*i2)->Disparar(disp1,disp2,3,p1);

      buffer= (*i2)->ActualizarDisparos(buffer, p1);
      buffer=(*i2)->Dibujar(buffer,p1);
      if ((*i2)->GetToques()>0)
        buffer= (*i2)->DibujarVida(buffer,p1);
      if ((*i2)->Colision(p1))
      {
         play_sample(muerto, 0xC0,0xC0, 1000, 0);
         (*i2)->Atacar(p1);
      }
   }
   return buffer;
}


void ComprobarTeclas(Personaje* p, Pantalla* pant, BITMAP* disp1, BITMAP* disp2, bool & pulsado)
{
   if (key[KEY_X] && !pulsado)
   {
      p->Disparar(disp1,disp2);
      pulsado=true ;
   }
   if (!key[KEY_X])
      pulsado=false;
   if (key[KEY_SPACE] )
      {
         p->Saltar(pant->GetDurezas());
         p->SetVel(5);
      }
   else
      p->SetSaltando(false);
   if (key[KEY_RIGHT])
      p->Avanzar(pant->GetDurezas());
   else
   if (key[KEY_LEFT])
      p->Retroceder(pant->GetDurezas());
   else
      p->SetFrame(0);
}

int Pantalla1(Personaje* p1)
{
   bool pulsado=false;
   BITMAP* buffer; // Bitmap sobre el que iremos pintando todo
   buffer= create_bitmap(screen->w,screen->h);
   int tiempoAux=0;
   SAMPLE * item = load_wav("sonido/item.wav");
   SAMPLE * muerto = load_wav("sonido/muerto.wav");
   MIDI * musica= load_midi("sonido/musica.mid");
   play_midi(musica, TRUE);
   BITMAP* disp1 = load_bitmap("imagenes/disparos/disparo3.bmp",NULL);
   BITMAP* disp2 = load_bitmap("imagenes/disparos/disparo4.bmp",NULL);
   BITMAP* fuego = load_bitmap("imagenes/estaticos/fuego.bmp",NULL);
   BITMAP* bota = load_bitmap("imagenes/estaticos/bota.bmp", NULL);
   BITMAP* fondo = load_bitmap("imagenes/pantalla/fondo.bmp", NULL);
   BITMAP* mapa = load_bitmap("imagenes/pantalla/mapa.bmp", NULL);
   BITMAP* durezas = load_bitmap("imagenes/pantalla/durezas.bmp", NULL);
   BITMAP* primer = load_bitmap("imagenes/pantalla/primerplano.bmp", NULL);
   Pantalla* pant1=new Pantalla(mapa,fondo,durezas,primer, NULL);
   list <Estatico *> listaEstaticos;
   CargarListaEstaticos("ficheros/objetosp1.txt",listaEstaticos);
   list <Enemigo *> listaEnemigos;
   CargarListaEnemigos("ficheros/enemigosp1.txt",listaEnemigos);
//bucle del juego
   do
   {

      buffer=pant1->DibujarFondo(buffer, p1);
      buffer=pant1->DibujarMapa(buffer, p1);
      buffer = DibujarListaEstaticos(listaEstaticos,p1,buffer,item);
      buffer = DibujarListaEnemigos(listaEnemigos,p1,buffer,muerto);
      buffer=p1->DibujarPersonaje(buffer,pant1->GetDurezas());
      buffer=pant1->DibujarPrimerPlano(buffer,p1);
      buffer=p1->DibujarMarcador(buffer,bota,fuego, true);
      p1->VerSiMuerto(pant1->GetDurezas());
      p1->VerSiPasada(pant1->GetDurezas());
      ComprobarTeclas(p1, pant1, disp1, disp2, pulsado);
      tiempoAux++;
      if (!(tiempoAux % 100))
         p1->SetStatus(5,-1);
      blit(buffer,screen,0,0,0,0,screen->w,screen->h);
      clear(buffer);
   }
   while (!(key[KEY_ESC]) && !(p1->GetMuerto()) && !(p1->GetPasada()));
   if (p1->GetPasada())
    Recuento(buffer,p1,pant1);
   listaEstaticos.clear();
   listaEnemigos.clear();
   destroy_midi(musica);
   return p1->GetStatus(2);// retorna los puntos
}
int Pantalla2(Personaje* p1)
{

   bool pulsado=false;
   BITMAP* buffer; // Bitmap sobre el que iremos pintando todo
   buffer= create_bitmap(screen->w,screen->h);
   int tiempoAux=0;
   SAMPLE * item = load_wav("sonido/item.wav");
   SAMPLE * muerto = load_wav("sonido/muerto.wav");
   MIDI * musica= load_midi("sonido/agua.mid");
   play_midi(musica, TRUE);
   BITMAP* disp1 = load_bitmap("imagenes/disparos/disparo3.bmp",NULL);
   BITMAP* disp2 = load_bitmap("imagenes/disparos/disparo4.bmp",NULL);
   BITMAP* fuego = load_bitmap("imagenes/estaticos/fuego.bmp",NULL);
   BITMAP* bota = load_bitmap("imagenes/estaticos/bota.bmp", NULL);
   BITMAP* fondo = load_bitmap("imagenes/pantalla/fondoCreditos.bmp", NULL);
   BITMAP* mapa = load_bitmap("imagenes/pantalla/mapaagua.bmp", NULL);
   BITMAP* durezas = load_bitmap("imagenes/pantalla/durezasagua.bmp", NULL);
   BITMAP* primer = load_bitmap("imagenes/pantalla/primerplanoagua.bmp", NULL);
   Pantalla* pant2=new Pantalla(mapa,fondo,durezas,primer, NULL);
   list <Estatico *> listaEstaticos;
   CargarListaEstaticos("ficheros/objetosp2.txt",listaEstaticos);
   list <Enemigo *> listaEnemigos;
   CargarListaEnemigos("ficheros/enemigosp2.txt",listaEnemigos);
//bucle del juego
   do
   {
      buffer=pant2->DibujarFondo(buffer, p1);
      buffer=pant2->DibujarMapa(buffer, p1);
      buffer = DibujarListaEstaticos(listaEstaticos,p1,buffer,item);
      buffer = DibujarListaEnemigos(listaEnemigos,p1,buffer,muerto);
      buffer=p1->DibujarPersonaje(buffer,pant2->GetDurezas());
      buffer=pant2->DibujarPrimerPlano(buffer,p1);
      buffer=p1->DibujarMarcador(buffer,bota,fuego, true);
      p1->VerSiMuerto(pant2->GetDurezas());
      p1->VerSiPasada(pant2->GetDurezas());
      ComprobarTeclas(p1, pant2, disp1, disp2, pulsado);
      tiempoAux++;
      if (!(tiempoAux % 100))
         p1->SetStatus(5,-1);
      blit(buffer,screen,0,0,0,0,screen->w,screen->h);
      clear(buffer);
   }
   while (!(key[KEY_ESC]) && !(p1->GetMuerto()) && !(p1->GetPasada()));
   if (p1->GetPasada())
   Recuento(buffer,p1,pant2);
   destroy_midi(musica);
   listaEstaticos.clear();
   listaEnemigos.clear();
   return p1->GetStatus(2);// retorna los puntos
}
int Pantalla3(Personaje* p1)
{
   bool pulsado=false;
   BITMAP* buffer; // Bitmap sobre el que iremos pintando todo
   buffer= create_bitmap(screen->w,screen->h);
   int tiempoAux=0;
   SAMPLE * item = load_wav("sonido/item.wav");
   SAMPLE * muerto = load_wav("sonido/muerto.wav");
   MIDI * musica= load_midi("sonido/cueva.mid");
   play_midi(musica, TRUE);
   BITMAP* disp1 = load_bitmap("imagenes/disparos/disparo3.bmp",NULL);
   BITMAP* disp2 = load_bitmap("imagenes/disparos/disparo4.bmp",NULL);
   BITMAP* fuego = load_bitmap("imagenes/estaticos/fuego.bmp",NULL);
   BITMAP* bota = load_bitmap("imagenes/estaticos/bota.bmp", NULL);
   BITMAP* fondo = load_bitmap("imagenes/pantalla/fondofin.bmp", NULL);
   BITMAP* aux = load_bitmap("imagenes/pantalla/fondo2.bmp", NULL);
   BITMAP* mapa = load_bitmap("imagenes/pantalla/mapa2.bmp", NULL);
   BITMAP* durezas = load_bitmap("imagenes/pantalla/durezas2.bmp", NULL);
   BITMAP* primer = load_bitmap("imagenes/pantalla/primerplano2.bmp", NULL);
   Pantalla* pant2=new Pantalla(mapa,fondo,durezas,primer,aux);
   list <Estatico *> listaEstaticos;
   CargarListaEstaticos("ficheros/objetosp3.txt",listaEstaticos);
   list <Enemigo *> listaEnemigos;
   CargarListaEnemigos("ficheros/enemigosp3.txt",listaEnemigos);
   BITMAP* viejo1= load_bitmap("imagenes/enemigos/viejo1.bmp",NULL);
   BITMAP* viejo2= load_bitmap("imagenes/enemigos/viejo2.bmp",NULL);
   list<EnemigoD*> listaED;
   EnemigoD* eDisp = new EnemigoD(1029, 329,viejo1,viejo2,1, 70,'H',3,60);
   listaED.push_back(eDisp);
   eDisp = new EnemigoD(1094,215,viejo1,viejo2,1, 240,'H',6,60);
   listaED.push_back(eDisp);
   eDisp = new EnemigoD(4454,281,viejo1,viejo2,1, 70,'H',12,30);
   listaED.push_back(eDisp);

//bucle del juego
   do
   {
      buffer=pant2->DibujarFondo(buffer, p1);
      buffer=pant2->DibujarMapa(buffer, p1);
      p1->MoverDisparos(pant2->GetDurezas(),listaEnemigos);
      buffer = DibujarListaEstaticos(listaEstaticos,p1,buffer,item);
      buffer = DibujarListaEnemigos(listaEnemigos,p1,buffer,muerto);
      buffer= DibujarListaEnemigosD(listaED,p1, buffer, muerto,disp1,disp2);
      p1->MoverDisparos(listaED);
      buffer=p1->DibujarPersonaje(buffer,pant2->GetDurezas());
      buffer=p1->DibujarListaDisparos(buffer);
      buffer=pant2->DibujarPrimerPlano(buffer,p1);
      buffer=p1->DibujarMarcador(buffer,bota,fuego, true);
      p1->VerSiMuerto(pant2->GetDurezas());
      p1->VerSiPasada(pant2->GetDurezas());
      ComprobarTeclas(p1, pant2, disp1, disp2, pulsado);
      tiempoAux++;
      if (!(tiempoAux % 100))
         p1->SetStatus(5,-1);
      blit(buffer,screen,0,0,0,0,screen->w,screen->h);
      clear(buffer);
   }
   while (!(key[KEY_ESC]) && !(p1->GetMuerto()) && !(p1->GetPasada()));
   if (p1->GetPasada())
      Recuento(buffer,p1,pant2);
   destroy_midi(musica);
   listaEstaticos.clear();
   listaEnemigos.clear();
   listaED.clear();
   return p1->GetStatus(2);// retorna los puntos
}
int PantallaFinal(Personaje* p)
{
   BITMAP* buffer;
   buffer= create_bitmap(screen->w,screen->h);
   BITMAP* fondo = load_bitmap("imagenes/pantalla/fondofin.bmp",NULL);
   BITMAP* mapa = load_bitmap("imagenes/pantalla/mapafin.bmp",NULL);
   BITMAP* primer= load_bitmap("imagenes/pantalla/primerplanofin.bmp",NULL);
   BITMAP* durezas = load_bitmap("imagenes/pantalla/durezasfin.bmp",NULL);
   Pantalla* pant = new Pantalla(mapa,fondo,durezas,primer,NULL);
   BITMAP* bota = load_bitmap("imagenes/estaticos/bota.bmp", NULL);
   BITMAP* fuego = load_bitmap("imagenes/estaticos/fuego.bmp", NULL);
   BITMAP* dino1 = load_bitmap("imagenes/enemigos/dino1.bmp",NULL);
   BITMAP* dino2 = load_bitmap("imagenes/enemigos/dino2.bmp",NULL);
   BITMAP* bola1 = load_bitmap("imagenes/enemigos/bola1.bmp",NULL);
   BITMAP* disp1= load_bitmap("imagenes/disparos/disparo1.bmp",NULL);
   BITMAP* disp2= load_bitmap("imagenes/disparos/disparo2.bmp",NULL);
   BITMAP* disp3= load_bitmap("imagenes/disparos/disparo3.bmp",NULL);
   BITMAP* disp4= load_bitmap("imagenes/disparos/disparo4.bmp",NULL);
   BITMAP* disp5= load_bitmap("imagenes/disparos/disparo5.bmp",NULL);
   BITMAP* disp6= load_bitmap("imagenes/disparos/disparo6.bmp",NULL);
   list<Enemigo*> listaAux;
   list<EnemigoD*> listaCabezas;
   list<Estatico*> listaEstaticos;
   CargarListaEstaticos("ficheros/objetospfinal.txt",listaEstaticos);
   EnemigoD* cabeza= new EnemigoD(500,270,dino1,dino2,2,50,'V',100,70);
   listaCabezas.push_front(cabeza);
   Enemigo* cuello1=new Enemigo(570,240,bola1,bola1,0,0,'V');
   Enemigo* cuello2=new Enemigo(590,240,bola1,bola1,0,0,'V');
   Enemigo* cuello3=new Enemigo(610,240,bola1,bola1,0,0,'V');
   EnemigoD* cabeza2= new EnemigoD(400,270,dino1,dino2,1,70,'V',100,70);
   listaCabezas.push_back(cabeza2);
   Enemigo* cuello4=new Enemigo(470,300,bola1,bola1,0,0,'V');
   Enemigo* cuello5=new Enemigo(490,300,bola1,bola1,0,0,'V');
   Enemigo* cuello6=new Enemigo(510,300,bola1,bola1,0,0,'V');
   Enemigo* cuello7=new Enemigo(530,300,bola1,bola1,0,0,'V');
   Enemigo* cuello8=new Enemigo(550,300,bola1,bola1,0,0,'V');
   Enemigo* cuello9=new Enemigo(570,300,bola1,bola1,0,0,'V');
   Enemigo* cuello10=new Enemigo(590,300,bola1,bola1,0,0,'V');
   Enemigo* cuello11=new Enemigo(610,300,bola1,bola1,0,0,'V');
   bool pulsado=false;
   SAMPLE * item = load_wav("sonido/item.wav");
   SAMPLE* muerto= load_wav("sonido/muerto.wav");
   MIDI * musica= load_midi("sonido/final.mid");
   play_midi(musica, TRUE);
   do
   {

      if (cabeza->GetToques()<50 && cabeza->GetToques()>25)
         cabeza->SetFrecuencia(50);
      if (cabeza2->GetToques()<50 && cabeza2->GetToques()>25)
         cabeza2->SetFrecuencia(50);
      if (cabeza->GetToques()<25 && cabeza->GetToques()>10)
         cabeza->SetFrecuencia(40);
      if (cabeza2->GetToques()<25 && cabeza2->GetToques()>10)
         cabeza2->SetFrecuencia(40);
      if (cabeza->GetDir())
      {
         cuello1->SetY(cabeza->GetY()+5);
         cuello2->SetY(cuello1->GetY()+5);
         cuello3->SetY(cuello2->GetY()+5);
      }
      else
      {
         cuello1->SetY(cabeza->GetY()-5);
         cuello2->SetY(cuello1->GetY()-5);
         cuello3->SetY(cuello2->GetY()-5);
      }
      if (cabeza2->GetDir())
      {
         cuello4->SetY(cabeza2->GetY()+2);
         cuello5->SetY(cuello4->GetY()+2);
         cuello6->SetY(cuello5->GetY()+2);
         cuello7->SetY(cuello6->GetY()+2);
         cuello8->SetY(cuello7->GetY()+2);
         cuello9->SetY(cuello8->GetY()+2);
         cuello10->SetY(cuello9->GetY()+2);
         cuello11->SetY(cuello10->GetY()+2);
      }
      else
      {
         cuello4->SetY(cabeza2->GetY()-2);
         cuello5->SetY(cuello4->GetY()-2);
         cuello6->SetY(cuello5->GetY()-2);
         cuello7->SetY(cuello6->GetY()-2);
         cuello8->SetY(cuello7->GetY()-2);
         cuello9->SetY(cuello8->GetY()-2);
         cuello10->SetY(cuello9->GetY()-2);
         cuello11->SetY(cuello10->GetY()-2);
      }
      p->MoverDisparos(pant->GetDurezas(),listaAux);
      blit(fondo,buffer,0,0,0,0,screen->w,screen->h);
      masked_blit(mapa,buffer,0,0,0,0,screen->w,screen->h);
      buffer=DibujarListaEstaticos(listaEstaticos,p,buffer,item);
      buffer=p->DibujarPersonaje(buffer,durezas);
      buffer=p->DibujarListaDisparos(buffer);
      p->MoverDisparos(listaCabezas);
      p->VerSiMuerto(durezas);
      ComprobarTeclas(p,pant,disp3,disp4,pulsado);
       if (cabeza->GetToques()>1)
      {
         buffer=cuello3->Dibujar(buffer,p);
         buffer=cuello2->Dibujar(buffer,p);
         buffer=cuello1->Dibujar(buffer,p);
      }
      if (listaCabezas.size()==2)
         buffer=DibujarListaEnemigosD(listaCabezas,p,buffer,muerto,disp1,disp2);
      else
         buffer=DibujarListaEnemigosD(listaCabezas,p,buffer,muerto,disp5,disp6);
      if (cabeza2->GetToques()>1)
      {
         buffer=cuello11->Dibujar(buffer,p);
         buffer=cuello10->Dibujar(buffer,p);
         buffer=cuello9->Dibujar(buffer,p);
         buffer=cuello8->Dibujar(buffer,p);
         buffer=cuello7->Dibujar(buffer,p);
         buffer=cuello6->Dibujar(buffer,p);
         buffer=cuello5->Dibujar(buffer,p);
         buffer=cuello4->Dibujar(buffer,p);
         buffer=cabeza2->Dibujar(buffer,p);
      }
      masked_blit(primer,buffer,0,0,0,0,screen->w,screen->h);
      buffer=p->DibujarMarcador(buffer,bota,fuego, false);
      blit(buffer,screen,0,0,0,0,screen->w,screen->h);
      clear(buffer);
      if (listaCabezas.size()==0)
         p->SetPasada(true);
   }
   while(!key[KEY_ESC]&& !(p->GetMuerto()) && !(p->GetPasada()));
   destroy_midi(musica);
   listaAux.clear();
   listaEstaticos.clear();
   listaCabezas.clear();
   return p->GetStatus(2);
}
void Creditos(void)
{
   BITMAP* buffer;
   buffer= create_bitmap(screen->w,screen->h);
   BITMAP* fondo = load_bitmap("imagenes/pantalla/fondoCreditos.bmp", NULL);
   BITMAP* creditos = load_bitmap("imagenes/pantalla/creditos.bmp", NULL);
   int y;
   int temp;
   BITMAP* final = load_bitmap("imagenes/pantalla/final.bmp",NULL);
   MIDI * musica= load_midi("sonido/creditos.mid");
   play_midi(musica, FALSE);
   do
   {
      blit(fondo,buffer,0,0,0,0,screen->w,screen->h);
      masked_blit(creditos,buffer,0,y,0,0,screen->w,screen->h);
      masked_blit(final,buffer,0,0,0,0,screen->w,screen->h);
      blit(buffer,screen,0,0,0,0,screen->w,screen->h);
      clear(buffer);
      temp++;
      if (!(temp % 4))
         if (y < creditos->h - screen->h)
            y++;
   }
   while(!key[KEY_ESC]);
   destroy_midi(musica);
}
void GameOver(void)
{
   MIDI * musica= load_midi("sonido/gameover.mid");
   play_midi(musica, FALSE);
   BITMAP* buffer;
   buffer= create_bitmap(screen->w,screen->h);
   BITMAP* fondo = load_bitmap("imagenes/pantalla/fondoCreditos.bmp", NULL);
   BITMAP* gOver = load_bitmap("imagenes/pantalla/gameover.bmp", NULL);
   int y;
   int temp;
   do
   {
      blit(fondo,buffer,0,0,0,0,screen->w,screen->h);
      masked_blit(gOver,buffer,0,y,0,0,screen->w,screen->h);
      blit(buffer,screen,0,0,0,0,screen->w,screen->h);
      clear(buffer);
      temp++;
      if (!(temp % 2))
         if (y < gOver->h - screen->h)
         y+=2;
   }
   while(!key[KEY_ESC]);
   destroy_midi(musica);
}
void Recuento(BITMAP* buffer,Personaje* p, Pantalla* pant)
{
  int puntos = p->GetStatus(2);
  SAMPLE * aplauso = load_wav("sonido/aplauso.wav");
  play_sample(aplauso, 0xC0,0xC0, 1000, 0);
  do
  {
    p->SetStatus(2,20);
    p->SetStatus(5,-1);
    puntos--;
    buffer= pant->DibujarFondo(buffer,p);
    buffer= pant->DibujarMapa(buffer,p);
    buffer= p->DibujarPersonaje(buffer,pant->GetDurezas());
    buffer= pant->DibujarPrimerPlano(buffer,p);
    buffer= p->DibujarMarcador(buffer,NULL,NULL,true);
    blit(buffer,screen,0,0,0,0,screen->w,screen->h);
  }
  while(p->GetStatus(5)>0);
}
