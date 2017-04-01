//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MenuPrincipal.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Tmenu *menu;

//---------------------------------------------------------------------------
__fastcall Tmenu::Tmenu(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonJugarClick(TObject *Sender)
{
   FormNombre->ShowModal(); 
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonSalirClick(TObject *Sender)
{
   exit(0);   
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonConfigurarClick(TObject *Sender)
{
 FormConfigurar->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonScoresClick(TObject *Sender)
{

 FormScores->TextoPuntos->Lines->LoadFromFile("Puntos.txt");
 FormScores->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonAyudaClick(TObject *Sender)
{
   FormAcerca->ShowModal();   
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BAyudaClick(TObject *Sender)
{
   Application->HelpFile = ".\\ayuda\\AYUDA.HLP";
   Application->HelpCommand(HELP_CONTENTS, 0);
}
//---------------------------------------------------------------------------




void __fastcall Tmenu::BotonJugarEnter(TObject *Sender)
{
  BotonJugar->Font->Size=13;
   //
}
//---------------------------------------------------------------------------







void __fastcall Tmenu::BotonJugarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonJugar->Font->Color=clYellow	;
BotonJugar->Font->Size=13;
BotonConfigurar->Font->Size=9;
BotonScores->Font->Size=9;
BAyuda->Font->Size=9;
BotonAyuda->Font->Size=9;
BotonSalir->Font->Size=9;

}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonConfigurarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonJugar->Font->Size=9;
BotonConfigurar->Font->Size=13;
BotonScores->Font->Size=9;
BAyuda->Font->Size=9;
BotonAyuda->Font->Size=9;
BotonSalir->Font->Size=9;
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonScoresMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonJugar->Font->Size=9;
BotonConfigurar->Font->Size=9;
BotonScores->Font->Size=13;
BAyuda->Font->Size=9;
BotonAyuda->Font->Size=9;
BotonSalir->Font->Size=9;
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BAyudaMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
BotonJugar->Font->Size=9;
BotonConfigurar->Font->Size=9;
BotonScores->Font->Size=9;
BAyuda->Font->Size=13;
BotonAyuda->Font->Size=9;
BotonSalir->Font->Size=9;
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonAyudaMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonJugar->Font->Size=9;
BotonConfigurar->Font->Size=9;
BotonScores->Font->Size=9;
BAyuda->Font->Size=9;
BotonAyuda->Font->Size=13;
BotonSalir->Font->Size=9;
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::BotonSalirMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonJugar->Font->Size=9;
BotonConfigurar->Font->Size=9;
BotonScores->Font->Size=9;
BAyuda->Font->Size=9;
BotonAyuda->Font->Size=9;
BotonSalir->Font->Size=13;
}
//---------------------------------------------------------------------------

void __fastcall Tmenu::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
BotonJugar->Font->Size=9;
BotonConfigurar->Font->Size=9;
BotonScores->Font->Size=9;
BAyuda->Font->Size=9;
BotonAyuda->Font->Size=9;
BotonSalir->Font->Size=9;

}
//---------------------------------------------------------------------------

