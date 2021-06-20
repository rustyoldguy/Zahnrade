#ifndef ZAHNRAD_INC_
#define ZAHNRAD_INC_ 3

#include <iostream>
#include <iomanip>
#include <cmath>
#include "menuefrage.h"
#include "bomasincostan.h"
#include "cmpdouble.h"
#include "menues.h"

// hf Zahnfussshoehe
// h  Zahnhoehe
// a  Achsabstand 
// ha Zahnkopfhoehe
// q  Zahnkopfhoehe
// s  Zahnstaerke
// k = Anzahl der Zaehne uebr die gemessen wird

#define ENDOFCASE watu = 32; break; 

class ZahnRad{
 public:
     ZahnRad(); 
     ~ZahnRad();
     double Modul[52];
     double m, zx, dk, d0, t, ha, df, c, hf, h, a, cfaktor; //ha=Zahnkopfhoehe
     double z1, z2, d1, d2, q, s, Profilverschiebungsfaktor, wk;
     int modulnr, k, radzahl, i;
     int watu;
     int z[20] = {0};
     double n[20] = {0};
     double nz[20] = {0};
     double iver[20] = {0};   // Uebersetzungsverhaeltnis = z2 / z1
     double moment[20] = {0}; // Uebersetzungsverhaeltnis = z2 / z1
     double Fu[20] = {0};     // Umfangskraft = (2 * Drehmoment) / Teilkreisdurchmesser 
     std::string Versionsnummer;
    
     void ShowModulreihe(void); 
     int Checkmodulgroesse(double mx);
     void Getdk_aus_m_und_zx(void);
     void Get_m_aus_dk_und_zx(void);
     void Get_zx_aus_dk_und_m(void);
     void GetD0_aus_m_und_zx(void); 
     void Getdf_aus_dk_c_m(void); 
     void Get_a_aus_m_und_z(void);
     void Get_m_aus_dk_und_d0(void);
     void GetZahnzahl_beim_messen(void);
     void Get_WK_Wert(void); 
     int GetAnzahlZahnraeder(void);
     void Zeige_Werte_aller_Zahnraeder(void);
     void Eingabe_Zaehnezahl_aller_Zahnräder(void);
     void Eingabe_Drehzahl_z1(void);
     void ZeigeZahnradwerte(void);
     void Info(void);
     void Hauptmenue(void);
     void Eingabe_Modul(void);
     void Eingabe_Zaehnezahl(void);
     void Eingabe_Kopfkreis(void);
     void Eingabe_Teilkreisdurchmesser(void);
     void Zahnradgroessen(void);
     void Berechnung_zwei_Zahnraeder(void);
     void Berechnung_mit_Drehmoment(void);
  
};


int GANZZAHL(int zx);
double Bedingungszahl(int zx);
double Bedingung(int zx);
double RUNDEN(int zx);
int GetkWert(int zx);
double calc_Wk_Wert(int zx, double m, double Profilverschiebungsfaktor);
double GetZahnkopfhoehe_q(int zx, int m, double *d0, double *dk);
double Getzahnstaerke(int zx, int m, double q);
double Getzahnstaerkeneu(int zx, int m);
 


#endif