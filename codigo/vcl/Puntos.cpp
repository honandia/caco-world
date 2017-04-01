//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Puntos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormScores *FormScores;
//---------------------------------------------------------------------------
__fastcall TFormScores::TFormScores(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TFormScores::BotonAceptarClick(TObject *Sender)
{
   FormScores->ModalResult=2;
   FormScores->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFormScores::BotonAceptarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonAceptar->Font->Size= 13;
}
//---------------------------------------------------------------------------

void __fastcall TFormScores::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
BotonAceptar->Font->Size= 9;   
}
//---------------------------------------------------------------------------

