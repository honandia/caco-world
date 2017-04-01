//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Acercade.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAcerca *FormAcerca;
//---------------------------------------------------------------------------
__fastcall TFormAcerca::TFormAcerca(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAcerca::Image1Click(TObject *Sender)
{
   FormTruco->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormAcerca::Button1Click(TObject *Sender)
{
   FormAcerca->ModalResult=2;
   FormAcerca->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFormAcerca::Button1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
Button1->Font->Size= 13;   
}
//---------------------------------------------------------------------------

void __fastcall TFormAcerca::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
Button1->Font->Size= 9;   
}
//---------------------------------------------------------------------------

