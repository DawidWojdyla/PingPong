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
                 Application->MessageBoxA("Witaj w Grze Ping Pong,\n\n Zielon¹ paletk¹ steruje siê za pomoc¹ klawiszy A oraz Z, natomiast czerwon¹ za pomoc¹ strza³ki w górê i dó³.\n\nGdy odbijesz pi³kê na skraju paletki to zmieni k¹t odbicia. \nGdy odbijesz pi³kê œrodkiem paletki to zmieni k¹t odbicia oraz przyœpieszy.\nGdy odbijesz pi³kê przyœpieszon¹ œrodkiem paletki, pi³ka dodatkowo przyœpieszy lub gdy odbijesz j¹ na skraju paletki dodatkowo zmieni k¹t odbicia.\n\nMasz do wyboru 3 poziomy trudnoœci, które mo¿esz zmieniaæ tak¿e w trakcie trwania rozgrywki.\n\nMo¿esz dowolnie zmieniaæ pole gry.\n\nEnojoy the game! ;)", "Ping Pong", MB_OK);
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
