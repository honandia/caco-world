//---------------------------------------------------------------------------

#ifndef PuntosH
#define PuntosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormScores : public TForm
{
__published:	// IDE-managed Components
   TButton *BotonAceptar;
   TLabel *Label1;
   TMemo *TextoPuntos;
   void __fastcall BotonAceptarClick(TObject *Sender);
   void __fastcall BotonAceptarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
   void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
public:		// User declarations
   __fastcall TFormScores(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormScores *FormScores;
//---------------------------------------------------------------------------
#endif
