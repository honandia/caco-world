//---------------------------------------------------------------------------

#ifndef ConfigurarH
#define ConfigurarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TFormConfigurar : public TForm
{
__published:	// IDE-managed Components
   TRadioGroup *RadioGroup1;
   TRadioButton *RBPantalla;
   TRadioButton *RBVentana;
   TButton *Button2;
   TGroupBox *GBMusica;
   TCheckBox *CBMusica;
   void __fastcall Button2Click(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall Button2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
public:		// User declarations
   __fastcall TFormConfigurar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConfigurar *FormConfigurar;
//---------------------------------------------------------------------------
#endif
