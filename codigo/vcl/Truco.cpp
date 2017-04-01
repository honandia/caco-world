//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Truco.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTruco *FormTruco;
//---------------------------------------------------------------------------
__fastcall TFormTruco::TFormTruco(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormTruco::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
   if(Button == btNext)
      FormTruco->ENumero->Text=itoa((atoi(FormTruco->ENumero->Text.c_str()))+1," ",10);
   if(Button == btPrev)
      FormTruco->ENumero->Text=itoa((atoi(FormTruco->ENumero->Text.c_str()))-1," ",10);
}
//---------------------------------------------------------------------------

void __fastcall TFormTruco::Button1Click(TObject *Sender)
{
   FormTruco->ModalResult=2;
   FormTruco->Hide();
}
//---------------------------------------------------------------------------

