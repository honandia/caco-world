//---------------------------------------------------------------------------

#ifndef MenuPrincipalH
#define MenuPrincipalH
//---------------------------------------------------------------------------


#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "Nombre.h"
#include "Configurar.h"
#include "Puntos.h"
#include "Acercade.h"



//---------------------------------------------------------------------------
class Tmenu : public TForm
{
__published:	// IDE-managed Components
   TButton *BotonJugar;
   TButton *BotonConfigurar;
   TButton *BotonScores;
   TButton *BotonAyuda;
   TButton *BotonSalir;
   TImage *Image1;
   TButton *BAyuda;
   void __fastcall BotonJugarClick(TObject *Sender);
   void __fastcall BotonSalirClick(TObject *Sender);
   void __fastcall BotonConfigurarClick(TObject *Sender);
   void __fastcall BotonScoresClick(TObject *Sender);
   void __fastcall BotonAyudaClick(TObject *Sender);
   void __fastcall BAyudaClick(TObject *Sender);
   void __fastcall BotonJugarEnter(TObject *Sender);
   void __fastcall BotonJugarMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall BotonConfigurarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
   void __fastcall BotonScoresMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall BAyudaMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall BotonAyudaMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall BotonSalirMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
   void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
public:		// User declarations
   __fastcall Tmenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tmenu *menu;
//---------------------------------------------------------------------------
#endif
