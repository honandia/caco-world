//---------------------------------------------------------------------------

#ifndef TrucoH
#define TrucoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormTruco : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TUpDown *UpDown1;
   TButton *Button1;
   TEdit *ENumero;
   void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
   void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TFormTruco(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTruco *FormTruco;
//---------------------------------------------------------------------------
#endif
