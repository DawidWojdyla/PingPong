//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *timerPilka;
        TShape *tlo;
        TTimer *timerPaletka1Gora;
        TTimer *timerPaletka1Dol;
        TTimer *timerPaletka2Gora;
        TTimer *timerPaletka2Dol;
        TButton *kontynuacja;
        TLabel *Punktacja;
        TButton *nowaGra;
        TRadioButton *poziomLatwy;
        TRadioButton *poziomSredni;
        TRadioButton *poziomTrudny;
        TStaticText *Odbicia;
        TShape *pilka;
        TLabel *zielonyPunkt;
        TLabel *czerwonyPunkt;
        TButton *restart;
        TShape *paletka1;
        TShape *paletka2;
        void __fastcall timerPilkaTimer(TObject *Sender);
        void __fastcall timerPaletka1GoraTimer(TObject *Sender);
        void __fastcall timerPaletka1DolTimer(TObject *Sender);
        void __fastcall timerPaletka2GoraTimer(TObject *Sender);
        void __fastcall timerPaletka2DolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall kontynuacjaClick(TObject *Sender);
        void __fastcall nowaGraClick(TObject *Sender);
        void __fastcall poziomLatwyClick(TObject *Sender);
        void __fastcall poziomSredniClick(TObject *Sender);
        void __fastcall poziomTrudnyClick(TObject *Sender);
        void __fastcall restartClick(TObject *Sender);
private:
        void zdobytyPunkt();
        void zaczynamyGre();
        void resetujPilke();
        void ustawPoleGry();
        void ustawWidocznoscElementowNaCzasGry();
        void ustawWidocznoscElementowNaCzasPrzerwy();
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
