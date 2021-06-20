#include "zahnrad.h"

/*
 * ZahnRad::ZahnRad()
 * ZahnRad::~ZahnRad()
 * void ZahnRad::ShowModulreihe(void)
 * int ZahnRad::Checkmodulgroesse( double mx)
 * int GANZZAHL(int zx)
 * double Bedingungszahl(int zx)
 * double Bedingung(int zx)
 * double RUNDEN(int zx)
 * int GetkWert(int zx)
 * double calc_Wk_Wert(int zx, double m, double Profilverschiebungsfaktor)
 * double GetZahnkopfhoehe_q(int zx, int m, double *d0, double *dk)
 * double Getzahnstaerke(int zx, int m, double q)
 * double Getzahnstaerkeneu(int zx, int m)
 * 
 * */


ZahnRad::ZahnRad()
{
 int slei;
 double zahni[52] = { 0.3, 0.7, 1.25, 2.25, 3.25, 4.5, 6.5, 10, 14, 20, 30, 42, 60,
                      0.4, 0.8, 1.5,  2.5,  3.5,  5,   7,   11, 15, 22, 33, 45, 65,
                      0.5, 0.9, 1.75, 2.75, 3.75, 5.5, 8,   12, 16, 24, 36, 50, 70,
                      0.6, 1,   2,    3,    4,    6,   9,   13, 18, 27, 39, 55, 75};    
 for (slei = 0; slei < 52; slei++)
  Modul[slei] = zahni[slei];  

 watu = 21;
 radzahl = 2;
 m = 2;
 cfaktor = 0.166667;
 c = cfaktor * m;
 Versionsnummer = " V0.08";                   
}

ZahnRad::~ZahnRad()
{}
      
void ZahnRad::ShowModulreihe(void)
{
 int i, j = 0;

 for (i = 0; i < 52; i++) 
  {
   if (j > 12)
    {
     j = 0;
     std::cout << std::endl;
    }
    std::cout << std::setw(7) << std::setprecision(3) << Modul[i];  
   j++;
  }

 std::cout << std::endl;
}

int ZahnRad::Checkmodulgroesse( double mx)
{
 int rewer = -1, i, erge;
 int vorkommamx, vorkommaModul;
 
 for (i = 0; i < 52; i++)
  {
   vorkommamx = (int)mx;
   vorkommaModul = (int)Modul[i];
   if(vorkommamx == vorkommaModul)
      erge = compdouble(Modul[i], mx, 3);   
   if (erge >= 3)
    {
     rewer = i; 
     break;
    }
  }

 return rewer;
}

/* Formel fuer Zaehnezahl ueber die gemessen wird
//WENN((A18*20/180+0,5-(GANZZAHL(A18*20/180+0,5)))<=0,5;GANZZAHL(A18*20/180+0,5);RUNDEN(A18*20/180+0,5;0))
//WENN(
       (zx8*20/180+0,5- ( 
                         GANZZAHL(zx)
                         ))<=0,5
                                                       ;GANZZAHL(zx);
                                                        RUNDEN(zx)
      )
      
*/

int GANZZAHL(int zx)
{
 int rewer = -1;
 double erge, zaehler, nenner;
 zaehler = (double)(zx * 20);
 nenner = 180;
 
 erge = (zaehler / nenner) + 0.5; //GANZZAHL(A18*20/180+0,5)
 rewer = (int)erge;
 
 return rewer;
}

double Bedingungszahl(int zx)
{
 
 double erge, zaehler, nenner;
 zaehler = (double)(zx * 20);
 nenner = 180;
 
 erge = (zaehler / nenner) + 0.5; //GANZZAHL(A18*20/180+0,5)
  
 return erge;
}

double Bedingung(int zx)
{
 
 double erge, a, b;
 a = Bedingungszahl(zx);
 b = GANZZAHL(zx);
 erge = a - b;
 
 
 return erge;
}

double RUNDEN(int zx)
{
 double erge, a, b;
 a = (double)(zx * 20);
 b = (a / 180.0) +0.5;
 erge = round(b);

 return erge;   
}

// Errechnet ueber wie viele Zaehne der Wk-Wert gemessen wird
int GetkWert(int zx)
{
 int k = -1;  

 if((Bedingung(zx)) <=0.5)
         k = GANZZAHL(zx);
           else k = RUNDEN(zx);

 return k; 
}

// errechnet wie gross der Wk-Wert ist
double calc_Wk_Wert(int zx, double m, double Profilverschiebungsfaktor)
{
 double wk, tanwert, sinwert, coswert, k;
 
 tanwert = get_tan(20);
 sinwert = get_sin(20);
 coswert = get_cos(20);
 k = GetkWert(zx);
 
 wk = m*coswert*((k-0.5)*M_PI+(zx*(tanwert-(20*M_PI/180))))+(2* Profilverschiebungsfaktor* m * sinwert);     

 return wk;
}

double GetZahnkopfhoehe_q(int zx, int m, double *d0, double *dk)
{
 double dummy, dummyb, q;
 double dmrteilkreis, dmrkopfkreis;
 double teiler; // toboma
 
 //toboma = M_PI / 180;
 dmrteilkreis = (double)m * (double)zx; 
 dmrkopfkreis = dmrteilkreis + (2 * m);
 teiler = (double)zx * 4;
 dummy = 360 / teiler;
 dummyb = get_cos(dummy) * dmrteilkreis;
 
 *d0 = dmrteilkreis;
 *dk = dmrkopfkreis;
 //q =(dk-(get_cos((360/(zx * 4))*M_PI/180)*d0))/2;
 
 
//((std::cout << "z =" << zx << "  m= " << m << "   d0 = " << dmrteilkreis << "\n";
     
  //q = (dmrkopfkreis - (get_cos((360/(zx * 4))*M_PI/180) * dmrteilkreis))/2; 
  
  //q = (dmrkopfkreis-(get_cos((360/(zx*4)))*dmrteilkreis))/2;
  q = (dmrkopfkreis - dummyb) /2;
  return q;
}

//Zahnstaerke s:
       // s =((E17-(F17*2))/2)*TAN((360/(A17*4))*PI()/180)*2
       // s =((dk-(q*2))/2)*get_tan((360/(A17*4)))*2
double Getzahnstaerke(int zx, int m, double q)
{
 double dk, d0, s;
 double da, db, winkel, tanwert;
 double teiler;

 d0 = zx * m;        // Teilkreisdmr
 dk = d0 + (2 * m);  // Kopfkreisdmr
 da = dk - (q * 2);  // q ist die Kopfhoehe
 db = da / 2;
 teiler = (double)zx * 4;
 winkel = 360 / teiler; // genau Breite Haelfte Zahn
 tanwert = get_tan(winkel);

 s = db * tanwert * 2;   

 return s;
}
double Getzahnstaerkeneu(int zx, int m)
{
 double d0, s;
 double winkel, sinwert;
 double teiler;

 d0 = zx * m;        // Teilkreisdmr
 teiler = (double)zx * 4;
 winkel = 360 / teiler; // genau Breite Haelfte Zahn
 sinwert = get_sin(winkel);

 s = d0 * sinwert;   

 return s;
}