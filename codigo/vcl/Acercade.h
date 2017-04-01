//---------------------------------------------------------------------------

#ifndef AcercadeH
#define AcercadeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "Truco.h"
//---------------------------------------------------------------------------
class TFormAcerca : public TForm
{
__published:	// IDE-managed Components
   TGroupBox *GroupBox1;
   TButton *Button1;
   TImage *Image1;
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TLabel *Label4;
   void __fastcall Image1Click(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall Button1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
public:		// User declarations
   __fastcall TFormAcerca(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAcerca *FormAcerca;
//---------------------------------------------------------------------------
#endif
