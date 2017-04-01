//---------------------------------------------------------------------------
#include "main.h"
#include <vcl.h>
#pragma hdrstop

#include "Nombre.h"
#include "MenuPrincipal.h"
#include "Configurar.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNombre *FormNombre;
//---------------------------------------------------------------------------
//Funcion de comparacion para ordenar el vector de puntos de mayor a menor
    bool CompararMayor(const RPuntos & r1, const RPuntos & r2)
    {
      return (r1.puntos > r2.puntos);
    }
//---------------------------------------------------------------------------
__fastcall TFormNombre::TFormNombre(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormNombre::BotonCancelarClick(TObject *Sender)
{
   AreaTexto->Text="JUGADOR1";
   FormNombre->ModalResult=2;
   FormNombre->Hide();

}
//---------------------------------------------------------------------------
void __fastcall TFormNombre::BotonAceptarClick(TObject *Sender)
{

   //*********************************************
   //**Cargar en un vector de FPuntos del fichero, crear un nuevo FPuntos con los nuevos datos
   //** meterlo en el vector, ordenar de mayor a menor, eliminar el ultimo del vector,
   //** meter el vector al fichero
   //*********************************************
   vector <RPuntos> vectorPuntos;
   vector <RPuntos>:: iterator i;
   RPuntos RAux;
   fstream fichPuntos;// fichero de e\s
   fichPuntos.open("Puntos.txt");// lo abro
   char buffer [50]; // buffer sobre el que se va a leer
   fichPuntos.getline(buffer,50);//leo la 1ª linea
   RAux.nombre = AnsiString (buffer);// hago un cast al buffer y lo pongo en el campo nombre de RAux
   fichPuntos.getline(buffer,50);// leo la siguiente linea
   RAux.puntos = atoi (buffer);// conviento a int y lo pongo en el campo puntos de RAux
   while (!(fichPuntos.eof()))// mientras que no sea el fin de fichero voy leyendo y metiendo en el vector
   {
      vectorPuntos.push_back(RAux);
      fichPuntos.getline(buffer,50);
      RAux.nombre = AnsiString (buffer);
      fichPuntos.getline(buffer,50);
      RAux.puntos = atoi (buffer);
   }
   fichPuntos.close(); //cierro el fichero

   RPuntos nuevoJ;  //creo un nuevo registro
   nuevoJ.nombre = AreaTexto->Text;//con el nombre que ha introducido el usuario
   AreaTexto->Text="Jugador1";
   FormNombre->ModalResult=2;
   FormNombre->Hide();
    //y los puntos que haya obtenido
    //llamo a la funcion Juego
   nuevoJ.puntos= Juego(FormConfigurar->RBPantalla->Checked
                       ,FormConfigurar->CBMusica->Checked
                       ,atoi(FormTruco->ENumero->Text.c_str()));


   vectorPuntos.push_back(nuevoJ);//inserto al final del vector el nuevo registro
   i=vectorPuntos.begin();
   sort(i,vectorPuntos.end(),CompararMayor);//ordeno de mayor a menor el vector
   vectorPuntos.pop_back();//saco el ultimo elemento, el menor
   //**************************************
   //**************************************
   fichPuntos.open("Puntos.txt");
   //fichPuntos.clear();
   for (int i=0;i < vectorPuntos.size();i++)
   {
      fichPuntos << vectorPuntos[i].nombre.c_str();
      fichPuntos << endl;
      fichPuntos << itoa(vectorPuntos[i].puntos," ",10);
      fichPuntos << endl;
   }
   fichPuntos.close(); //cierro el fichero
}
//---------------------------------------------------------------------------


void __fastcall TFormNombre::BotonAceptarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonAceptar->Font->Size=13;
BotonCancelar->Font->Size=9;
}
//---------------------------------------------------------------------------

void __fastcall TFormNombre::BotonCancelarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonAceptar->Font->Size=9;
BotonCancelar->Font->Size=13;
}
//---------------------------------------------------------------------------

void __fastcall TFormNombre::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonAceptar->Font->Size=9;
BotonCancelar->Font->Size=9;   
}
//---------------------------------------------------------------------------

