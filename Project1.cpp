//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->MessageBoxA("Witaj w Grze Ping Pong,\n\n Zielon� paletk� steruje si� za pomoc� klawiszy A oraz Z, natomiast czerwon� za pomoc� strza�ki w g�r� i d�.\n\nGdy odbijesz pi�k� na skraju paletki to zmieni k�t odbicia. \nGdy odbijesz pi�k� �rodkiem paletki to zmieni k�t odbicia oraz przy�pieszy.\nGdy odbijesz pi�k� przy�pieszon� �rodkiem paletki, pi�ka dodatkowo przy�pieszy lub gdy odbijesz j� na skraju paletki dodatkowo zmieni k�t odbicia.\n\nMasz do wyboru 3 poziomy trudno�ci, kt�re mo�esz zmienia� tak�e w trakcie trwania rozgrywki.\n\nMo�esz dowolnie zmienia� pole gry.\n\nEnojoy the game! ;)", "Ping Pong", MB_OK);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
