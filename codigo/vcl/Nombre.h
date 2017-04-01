//---------------------------------------------------------------------------

#ifndef NombreH
#define NombreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>

#include <vector>
using namespace std;

struct RPuntos
{
   AnsiString nombre;
   int puntos;
};
//---------------------------------------------------------------------------
class TFormNombre : public TForm
{
__published:	// IDE-managed Components
   TEdit *AreaTexto;
   TButton *BotonCancelar;
   TButton *BotonAceptar;
   TLabel *Label1;
   void __fastcall BotonCancelarClick(TObject *Sender);
   void __fastcall BotonAceptarClick(TObject *Sender);
   void __fastcall BotonAceptarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
   void __fastcall BotonCancelarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
   void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
public:		// User declarations
   __fastcall TFormNombre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNombre *FormNombre;
//---------------------------------------------------------------------------

#endif
