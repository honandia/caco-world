//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("caco.res");
USEFORM("codigo\vcl\MenuPrincipal.cpp", menu);
USEUNIT("codigo\Elemento.cpp");
USEUNIT("codigo\Estatico.cpp");
USEUNIT("codigo\Funciones.cpp");
USEUNIT("codigo\main.cpp");
USEUNIT("codigo\Pantalla.cpp");
USEUNIT("codigo\Animado.cpp");
USELIB("allegro\lib\bcc32\alleg.lib");
USEFORM("codigo\vcl\Nombre.cpp", FormNombre);
USEFORM("codigo\vcl\Configurar.cpp", FormConfigurar);
USEFORM("codigo\vcl\Puntos.cpp", FormScores);
USEFORM("codigo\vcl\Acercade.cpp", FormAcerca);
USEFORM("codigo\vcl\Truco.cpp", FormTruco);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
       Application->Initialize();
       Application->HelpFile = "";
       Application->CreateForm(__classid(Tmenu), &menu);
       Application->CreateForm(__classid(TFormNombre), &FormNombre);
       Application->CreateForm(__classid(TFormConfigurar), &FormConfigurar);
       Application->CreateForm(__classid(TFormScores), &FormScores);
       Application->CreateForm(__classid(TFormAcerca), &FormAcerca);
       Application->CreateForm(__classid(TFormTruco), &FormTruco);
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
   return 0;
}
//---------------------------------------------------------------------------
