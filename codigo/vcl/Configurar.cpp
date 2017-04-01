//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Configurar.h"
#include "MenuPrincipal.h"
#include "Nombre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConfigurar *FormConfigurar;
//---------------------------------------------------------------------------
__fastcall TFormConfigurar::TFormConfigurar(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigurar::Button2Click(TObject *Sender)
{
   FormConfigurar->ModalResult=2;
   FormConfigurar->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigurar::Button1Click(TObject *Sender)
{
   FormConfigurar->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TFormConfigurar::Button2MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
Button2->Font->Size=13;
}
//---------------------------------------------------------------------------



void __fastcall TFormConfigurar::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
Button2->Font->Size=9;      
}
//---------------------------------------------------------------------------

