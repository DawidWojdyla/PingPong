//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;

const int wolno = -6, szybko = -8, srednio = -7;
int x, y, odbicia, punktyZielony, punktyCzerwony;
bool czyPunktZielonego;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
x = wolno; y = wolno;
czyPunktZielonego = false;
odbicia = 0; punktyZielony = 0; punktyCzerwony = 0;
poziomLatwy->Checked = true;
ustawPoleGry();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerPilkaTimer(TObject *Sender)
{
  pilka->Left += x;
  pilka->Top += y;

  if(pilka->Top - 5 <= tlo->Top)
  y = -y;

  if(pilka->Top + pilka->Height + 5 >= tlo->Height)
  y = -y;

  if(pilka->Left < paletka1->Left - 10)
  {
  czerwonyPunkt->Visible = true;
  punktyCzerwony++;
  czyPunktZielonego = false;
  zdobytyPunkt();

  }
  else if(pilka->Top + pilka->Height/2 >= paletka1->Top && pilka->Top + pilka->Height/2  <= paletka1->Top + paletka1->Height && pilka->Left <= paletka1->Left+paletka1->Width)
  {
  if(pilka->Top + pilka->Height/2 - paletka1->Top - paletka1->Height/2 < 12 && pilka->Top + pilka->Height/2 - paletka1->Top - paletka1->Height/2 > -12)
    {
     x = x * 1.6;
     pilka->Brush->Color = 0x0023B8F8;
     }
    else if (pilka->Top -7 < paletka1->Top || pilka->Top + pilka->Height + 7 > paletka1->Top + paletka1->Height)
        {
          y = y*1.25;
        }
     else
     {
     resetujPilke();
     }
  if(x<0)
   x = -x;
   odbicia++;
  }
  if(pilka->Left  > paletka2->Left + paletka2->Width/2 )
  {
  zielonyPunkt->Visible = true;
  punktyZielony++;
  czyPunktZielonego = true;
  zdobytyPunkt();
  }
  else if(pilka->Top + pilka->Height/2 >= paletka2->Top && pilka->Top + pilka->Height/2 <= paletka2->Top + paletka2->Height  && pilka->Left + pilka->Width >= paletka2->Left )
  {
  if(pilka->Top + pilka->Height/2 - paletka2->Top - paletka2->Height/2 < 12 && pilka->Top + pilka->Height/2 - paletka2->Top - paletka2->Height/2 > -12)
    {
     x = x * 1.6;
     pilka->Brush->Color = 0x0023B8F8;

     }
  else if (pilka->Top -7 < paletka2->Top || pilka->Top + pilka->Height +7 > paletka2->Top+paletka2->Height)
        {
          y = y*1.25;
        }
     else
     {
     resetujPilke();
     }
  if(x>0)
   x = -x;
   odbicia++;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerPaletka1GoraTimer(TObject *Sender)
{
if(paletka1->Top -5  > tlo->Top)
paletka1->Top -= 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerPaletka1DolTimer(TObject *Sender)
{
if(paletka1->Top + paletka1->Height + 5 < tlo->Height)
paletka1->Top += 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerPaletka2GoraTimer(TObject *Sender)
{
   if(paletka2->Top -5 > tlo->Top) paletka2->Top -= 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerPaletka2DolTimer(TObject *Sender)
{
if(paletka2->Top + paletka2->Height + 5 < tlo->Height)
paletka2->Top += 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_UP) timerPaletka2Gora->Enabled = true;
if(Key == VK_DOWN) timerPaletka2Dol->Enabled = true;

if(Key == 'A') timerPaletka1Gora->Enabled = true;
if(Key == 'Z') timerPaletka1Dol->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_UP) timerPaletka2Gora->Enabled = false;
if(Key == VK_DOWN) timerPaletka2Dol->Enabled = false;

if(Key == 'A') timerPaletka1Gora->Enabled = false;
if(Key == 'Z') timerPaletka1Dol->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::kontynuacjaClick(TObject *Sender)
{
 zaczynamyGre();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nowaGraClick(TObject *Sender)
{
 nowaGra->Visible = false;
 punktyZielony = 0;
 punktyCzerwony = 0;
 zaczynamyGre();

}
//---------------------------------------------------------------------------

void TForm1::zaczynamyGre()
{
ustawPoleGry();

resetujPilke();

if(czyPunktZielonego)
{
x = -x;
pilka->Left = paletka1->Left + paletka1->Width + 30;
}
else
pilka->Left = paletka2->Left - 30;
pilka->Top = tlo->Top + tlo->Height/3;

ustawWidocznoscElementowNaCzasGry();
timerPilka->Enabled = true;



odbicia = 0;
}
void TForm1::ustawWidocznoscElementowNaCzasGry()
{
 zielonyPunkt->Visible = false;
 czerwonyPunkt->Visible = false;
 poziomLatwy->Visible = false;
 poziomTrudny->Visible = false;
 poziomSredni->Visible = false;
 restart->Visible = false;
 kontynuacja->Visible = false;
 Punktacja->Visible = false;
 Odbicia->Visible = false;
 pilka->Visible = true;
 paletka1->Visible = true;
 paletka2->Visible = true;
 ShowCursor(false);
}
void TForm1::ustawWidocznoscElementowNaCzasPrzerwy()
{
  ShowCursor(true);
  pilka->Visible = false;
  Form1->kontynuacja->Visible = true;
  restart->Visible = true;
  Punktacja->Visible = true;
  poziomLatwy->Visible = true;
  poziomSredni->Visible = true;
  poziomTrudny->Visible = true;
  Odbicia->Visible = true;
}

void __fastcall TForm1::poziomLatwyClick(TObject *Sender)
{
paletka1->Height = 233;
paletka2->Height = 233;
x = wolno;
y = wolno;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::poziomSredniClick(TObject *Sender)
{
paletka1->Height = 173;
paletka2->Height = 173;
x = srednio;
y = srednio;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::poziomTrudnyClick(TObject *Sender)
{
paletka1->Height = 123;
paletka2->Height = 123;
x = szybko;
y = szybko;
}
//---------------------------------------------------------------------------

void TForm1::zdobytyPunkt()
{
   timerPilka->Enabled = false;
   Punktacja->Caption = IntToStr(punktyZielony) + " : " + IntToStr(punktyCzerwony);
   Odbicia->Caption =  "Odbicia: " + IntToStr(odbicia);
   ustawWidocznoscElementowNaCzasPrzerwy();
}

void TForm1::ustawPoleGry()
{
  paletka1->Left = tlo->Left + 20;
  paletka2->Left = tlo->Left + tlo->Width - paletka1->Width - 20;
  Punktacja->Left = tlo->Left + tlo->Width/2 - Punktacja->Width/2;
  Odbicia->Left =  tlo->Left + tlo->Width/2 - Punktacja->Width/2;
  poziomSredni->Left = tlo->Left + tlo->Width/2 - poziomSredni->Width/2;
  poziomLatwy->Left = poziomSredni->Left - poziomLatwy->Width -  15;
  poziomTrudny->Left = poziomSredni->Left + poziomSredni->Width + 15;
  zielonyPunkt->Left = paletka1->Left + paletka1->Width + 25;
  czerwonyPunkt->Left = paletka2->Left - 25 - czerwonyPunkt->Width;
  poziomLatwy->Top = tlo->Top + 25;
  poziomSredni->Top = poziomLatwy->Top;
  poziomTrudny->Top = poziomLatwy->Top;
  restart->Left = tlo->Left;
  restart->Top = tlo->Top;
  kontynuacja->Left = tlo->Left + tlo->Width/2 - kontynuacja->Width/2;
  paletka1->Top = tlo->Top + tlo->Height/2 - paletka1->Height/2;
  paletka2->Top = paletka1->Top;

}

void TForm1::resetujPilke()
{
  pilka->Brush->Style = bsSolid;
  pilka->Brush->Color = clHighlight;
    if(poziomLatwy->Checked)
    {
        x = wolno;
        x = wolno;
        if(y<0)
        y = wolno;
        else
        y = -wolno;
    }

    else if(poziomSredni->Checked)
    {
    x = srednio;
    if(y<0)
    y = srednio;
    else
    y = -srednio;
    }
    else
    {
    x = szybko;
    if(y<0)
    y = szybko;
    else
    y = -szybko;
    }
}


void __fastcall TForm1::restartClick(TObject *Sender)
{
if(Application->MessageBox ("Czy na pewno zacz¹æ nowa grê?", "PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDYES)
{
 punktyZielony = 0;
 punktyCzerwony = 0;
 zaczynamyGre();
} 
}
//---------------------------------------------------------------------------







