#include "zahnrad.h"

/*
 * void ZahnRad::Getdk_aus_m_und_zx(void)
 * void ZahnRad::Get_m_aus_dk_und_zx(void)
 * void ZahnRad::Get_zx_aus_dk_und_m(void)
 * void ZahnRad::GetD0_aus_m_und_zx(void)
 * void ZahnRad::Getdf_aus_dk_c_m(void)
 * void ZahnRad::Get_a_aus_m_und_z(void)
 * void ZahnRad::Get_m_aus_dk_und_d0(void)
 * void ZahnRad::GetZahnzahl_beim_messen(void)
 * void ZahnRad::Get_WK_Wert(void)
 * int ZahnRad::GetAnzahlZahnraeder(void)
 * void ZahnRad::Zeige_Werte_aller_Zahnraeder(void)
 * void ZahnRad::Eingabe_Zaehnezahl_aller_Zahnräder(void)
 * void ZahnRad::Eingabe_Drehzahl_z1(void)
 * void ZahnRad::ZeigeZahnradwerte(void)
 * void ZahnRad::Info(void)
 * void ZahnRad::Hauptmenue(void)
 * void ZahnRad::Eingabe_Modul(void)
 * void ZahnRad::Eingabe_Zaehnezahl(void)
 * void ZahnRad::Eingabe_Kopfkreis(void)
 * void ZahnRad::Eingabe_Teilkreisdurchmesser(void)
 * void ZahnRad::Zahnradgroessen(void)
 * void ZahnRad::Berechnung_zwei_Zahnraeder(void)
 * void ZahnRad::Berechnung_mit_Drehmoment(void)
 * */



void ZahnRad::Getdk_aus_m_und_zx(void)
  { 
       std::cout << "\nKopfkreis aus Modul und Zaehnezahl" << std::endl; 
       Eingabe_Modul();
       Eingabe_Zaehnezahl();
       
       dk = m * (zx + 2);       // Kopfkreisdurchmesser
       d0 = m * zx;             // Teilkreisdurchmesser
       t = m * M_PI;            // Teilung
       ha = m;                  // Zahnkopfhoehe
       c *= m;                  // Kopfspiel
       df = d0 - (2 * (m + c)); // Fusskreisdurchmesser
       h = 2* m + c;            // Zahnhoehe
       hf = m + c;              // Zahnfusshoehe
 
       ZeigeZahnradwerte();
 
  }      
  
void ZahnRad::Get_m_aus_dk_und_zx(void)
    { 
       std::cout << "\nModul aus Kopfkreis und Zaehnezahl" << std::endl;
       Eingabe_Kopfkreis(); 
       Eingabe_Zaehnezahl();  
       
       m = dk / (zx + 2);       // Modul  
       t = m * M_PI;            // Teilung
       d0 = m * zx;             // Teilkreisdurchmesser   
       ha = m;                  // Zahnkopfhoehe
       c *= m;                  // Kopfspiel
       df = d0 - (2 * (m + c)); // Fusskreisdurchmesser
       h = 2* m + c;            // Zahnhoehe
       hf = m + c;              // Zahnfusshoehe
       
       ZeigeZahnradwerte();
    }     
    
void ZahnRad::Get_zx_aus_dk_und_m(void)
  {    
 
       std::cout << "\nZaehnezahl aus Kopfkreis und Modul" << std::endl; 
       Eingabe_Kopfkreis();       
       Eingabe_Modul();
              
       zx = (dk / m) - 2;       // Zaehnezahl
       t = m * M_PI;            // Teilung
       d0 = m * zx;             // Teilkreisdurchmesser
       ha = m;                  // Zahnkopfhoehe
       c *= m;                  // Kopfspiel
       df = d0 - (2 * (m + c)); // Fusskreisdurchmesser
       h = 2* m + c;            // Zahnhoehe
       hf = m + c;              // Zahnfusshoehe   
       
       ZeigeZahnradwerte();
  }       
  
void ZahnRad::GetD0_aus_m_und_zx(void)
 {  

       std::cout << "Teilkreisdmr aus Modul und Zaehnezahl....8" << std::endl; 
       Eingabe_Modul();
       Eingabe_Zaehnezahl();
       
       d0 = m * zx;             // Teilkreisdurchmesser
       t = m * M_PI;            // Teilung
       dk = m * (zx + 2);       // Kopfkreisdurchmesser
       ha = m;                  // Zahnkopfhoehe
       c *= m;                  // Kopfspiel
       df = d0 - (2 * (m + c)); // Fusskreisdurchmesser
       h = 2* m + c;            // Zahnhoehe
       hf = m + c;              // Zahnfusshoehe  
       
       ZeigeZahnradwerte();
 
 }   
 
void ZahnRad::Getdf_aus_dk_c_m(void)
   { 
      std::cout << "Fusskreisdmr aus TKdmr, Spiel und Modul" << std::endl;
      Eingabe_Modul();
      Eingabe_Teilkreisdurchmesser();

      std::cout << "KopfSpiel(0.1 * m bis 0.3 * m bzw. 0.167) in mm: ";
      std::cin >> c;
      
      df = d0 - (2 * (m + c)); // Fusskreisdurchmesser
      zx = d0 / m;             // Zaehnezahl
      t = m * M_PI;            // Teilung
      dk = m * (zx + 2);       // Kopfkreisdurchmesser
      d0 = m * zx;             // Teilkreisdurchmesser
      ha = m;                  // Zahnkopfhoehe
      hf = m + c;              // Zahnfusshoehe
      h = 2 * m + c;           // Zahnhoehe
      ZeigeZahnradwerte();
   } 
   
void ZahnRad::Get_a_aus_m_und_z(void)
 {

       std::cout << "Achsabstand Aussenzahnraeder aus Modul und Z-zahl" << std::endl;
       Eingabe_Modul();
       std::cout << "Zaehnezahl z1: ";
       std::cin >> z1;
       std::cout << "Zaehnezahl z2: ";
       std::cin >> z2;
       
       modulnr = Checkmodulgroesse(m);
       
       if(modulnr >= 0)
        {       
         a = (m * (z1 + z2)) / 2;
         d1 = m * z1;
         d2 = m * z2;
         std::cout << "Eingegebenes Modul: " << Modul[modulnr] << " mm" << std::endl;
         std::cout << "Teilkreisdmr z1: " << d1 << " mm" << std::endl;
         std::cout << "Teilkreisdmr z2: " << d2 << " mm" << std::endl;
         std::cout << "Achsabstand: " << a << " mm" << std::endl;
        }
        else
         std::cout << "Modulgroesse nicht in Liste!" << std::endl;  
         
 }    
 
void ZahnRad::Get_m_aus_dk_und_d0(void)
{

       std::cout << "Modul aus Kopfkreis und Teilkreisdurchmesser" << std::endl;
       Eingabe_Kopfkreis();
       Eingabe_Teilkreisdurchmesser();
      
       m = (dk - d0) / 2;       // Modul
       zx = d0 / m;             // Zaehnezahl
       c *= m;                  // Kopfspiel
       df = d0 - (2 * (m + c)); // Fusskreisdurchmesser
       t = m * M_PI;            // Teilung
       h = 2 * m + c;           // Zahnhoehe
       ha = m;                  // Zahnkopfhoehe
       hf = m + c;              // Zahnfusshoehe
       
       ZeigeZahnradwerte();
      
       
} 

void ZahnRad::GetZahnzahl_beim_messen(void)
 { 
       std::cout << "Zahl der Zaehne ueber die gemessen wird" << std::endl;
       Eingabe_Modul();;
       
       for (zx = 10; zx <= 225; zx++)
        { 
         k = GetkWert(zx);
         q = GetZahnkopfhoehe_q(zx, m, &d0, &dk);
         //s = ((dk-(q*2))/2)*get_tan((360/(zx*4)))*2;
         s= Getzahnstaerke(zx, m, q);
         std::cout << "zx = " << std::setw(3) << zx << "   k= " << std::setw(3) << k;
         std::cout << "   d0 = " << std::setw(12) << std::setprecision(10) << d0;
         std::cout << "   dk = " << std::setw(12) << std::setprecision(10) << dk;
         std::cout << "   q' = " << std::setw(12) << std::setprecision(10) << q;
         std::cout << "   s =  " << std::setw(12) << std::setprecision(10) << s; // << std::endl;   // std::setw(8) << std::setprecision(5) <<
         std::cout << "   s' neu = " <<  Getzahnstaerkeneu(zx, m) << std::endl;
        }
        
 }
 
void ZahnRad::Get_WK_Wert(void)
{

      std::cout << "Gemessene Distanz zwischen den Messflächen" << std::endl;
   //=$C$14*COS(20*PI()/180)*((B17-0,5)*PI()+(A17*(TAN(20*PI()/180)-(20*PI()/180))))+(2*$C$13*$C$14*SIN(20*PI()/180))
    
    //WENN((A18*20/180+0,5-(GANZZAHL(A18*20/180+0,5)))<=0,5;GANZZAHL(A18*20/180+0,5);RUNDEN(A18*20/180+0,5;0))
    //Wk
       Eingabe_Modul();
       Eingabe_Zaehnezahl();
       
       //std::cout << "Profilverschiebungsfaktor(bei kein 0 eingeben): ";
       //std::cin >> Profilverschiebungsfaktor;
       
              
       d0 = m * zx;
       dk = m * (zx + 2);
       Profilverschiebungsfaktor = 0.0;
       k = GetkWert(zx);
       //wk = m*get_cos(20)*((k-0.5)*M_PI+(zx*(get_tan(20)-(20*M_PI/180))))+(2* Profilverschiebungsfaktor* m * get_sin(20));  
       wk = calc_Wk_Wert(zx, m, Profilverschiebungsfaktor);
       std::cout << "Kopfkreisdurchmesser: " << dk << " mm" << std::endl;
       std::cout << "Teilkreisdmr........: " << d0 << " mm" << std::endl;
       std::cout << "wk = " << wk  << std::endl;
       
} 

int ZahnRad::GetAnzahlZahnraeder(void) 
{
 int radzahl = 2; 
     std::cout << "Anzahl der Zahnräder: ";
       std::cin >> radzahl;
    
       if ((radzahl < 2) || (radzahl > 20))
        {
         std::cout << "Falsche Anzahl der Zahnräder" << std::endl;  
         watu = 21; 
        }  
        
return radzahl;
}

void ZahnRad::Zeige_Werte_aller_Zahnraeder(void)
{
    int i;  
      std::cout << "Zeige Werte alle Zahnräder" << std::endl;
        for (i = 0; i < radzahl; i++)
         {
          std::cout << "z[" << i << "]=" << std::setw(8) << z[i];
          std::cout << "  n[" << i << "]=" << std::setw(8) << n[i];
          std::cout << "   nz=" << std::setw(8) << nz[i] << std::endl;  
         }   
         
}

void ZahnRad::Eingabe_Zaehnezahl_aller_Zahnräder(void) 
 {  
       std::cout << "Eingabe der Zähnezahl aller Zahnräder" << std::endl;
       for (i = 0; i < radzahl; i++)
        {
         std::cout << "Eingabe Zähnezahl Zahnrad[" << (i + 1) << "]=";  
         std::cin >> z[i];
         cpp_clpuf();
        }

        if(radzahl == 2)
         {
          iver[0] = (double)z[1] / (double)z[0];   
          std::cout << "Uebersetzungsverhaeltnis  i = z1 / z0 =" << iver[0] << std::endl;  
         }
 
 
 }

void ZahnRad::Eingabe_Drehzahl_z1(void)    
{      std::cout << "Eingabe der Drehzahl von z1" << std::endl;
       std::cout << "Eingabe Drehzahl von z1: ";  
       std::cin >> n[0];
       cpp_clpuf();
       
       nz[0] = n[0] * z[0];
       
       for (i = 1; i < radzahl; i++)
        {
         nz[i] = nz[0]; 
        }
       for (i = 1; i < radzahl; i++)
        {
         n[i] = nz[i] / z[i]; 
        } 
        
         
        iver[0] = (double)z[1] / (double)z[0]; 
              
        if(radzahl == 2)
         {
          std::cout << "Uebersetzungsverhaeltnis  i = z1 / z0 =" << iver[0] << std::endl;  
         }
        
        
        if(radzahl >= 3)
         {
          for (i = 1; i < radzahl - 1; i++)
           {
            iver[i] = (double)z[i + 1] / (double)z[i]; 
           } 
          std::cout << "Uebersetzungsverhaeltnisse" << std::endl; 
          for (i = 0; i < radzahl - 1; i++)
           {
            std::cout << "i" << i << "=" << iver[0] << std::endl; 
           } 
 

          } 


}   

void ZahnRad::ZeigeZahnradwerte(void)
{      
       std::cout << "Zaehnezahl....: " << zx << std::endl;
       std::cout << "Kopfkreis.....: " << dk << " mm" << std::endl; 
       std::cout << "Teilkreisdmr..: " << d0 << " mm" << std::endl;
       std::cout << "Fusskreisdmr..: " << df << " mm" << std::endl;
       std::cout << "Modul.........: " << m <<  " mm" << std::endl;
       std::cout << "Kopfspiel = " << cfaktor << " * " << m << " = " << c << " mm" << std::endl;
       std::cout << "Teilung t.....: " << t << std::endl; 
       std::cout << "Zahnkopfhoehe.: " << ha << " mm" << std::endl;
       std::cout << "Zahnfusshoehe.: " << hf << " mm" << std::endl;
       std::cout << "Zahnhoehe.....: " << h << " mm" << std::endl;
  
}


void ZahnRad::Info(void)
{
 std::cout << "Info" << std::endl;
 std::cout << "Version " << Versionsnummer << std::endl;
 std::cout << "Autor" << std::endl;
 std::cout << "Josef Franz Wismeth" << std::endl;
}

void ZahnRad::Hauptmenue(void)
   {
         std::cout << std::endl << "Zahnrad " << Versionsnummer  << std::endl;
         std::cout << "Programm beenden....................................0" << std::endl;
         std::cout << "Eingabe der Anzahl der Zahnräder....................1" << std::endl;
         std::cout << "Eingabe der Zähnezahl aller Zahnräder...............2" << std::endl;
         std::cout << "Eingabe Drehzahl z1.................................3" << std::endl;
         std::cout << "Zeige Module........................................4" << std::endl;
         std::cout << "Zahnradgroessen m z dk df d0........................5" << std::endl;
         std::cout << "Berechnung_zwei_Zahnraeder..........................6" << std::endl;
         std::cout << "Berechnung_mit_Drehmoment...........................7" << std::endl;
         std::cout << "Zeige Werte alle Zahnräder..........................24" << std::endl;
         std::cout << "Info................................................25" << std::endl;
         
   }

void ZahnRad::Eingabe_Modul(void)
{
       std::cout << "Eingabe Modul: ";  
       std::cin >> m;
       
}

void ZahnRad::Eingabe_Zaehnezahl(void) 
{  
  std::cout << "Zaehnezahl: ";
  std::cin >> zx;  
}

void ZahnRad::Eingabe_Kopfkreis(void)
{
       std::cout << "Kopfkreisdurchmesser in mm: ";  
       std::cin >> dk;
}  

void ZahnRad::Eingabe_Teilkreisdurchmesser(void)
{
      std::cout << "Teilkreisdmr in mm: ";
      std::cin >> d0; 
}

void ZahnRad::Zahnradgroessen(void)
{
  int wastu = 21;

  do 
  switch(wastu)
  {
  default:
         std::cout << std::endl << "Zahnradgroessen" << std::endl;   
         std::cout << "Zurueck zum Hauptmenue..............................0" << std::endl;
         std::cout << "Kopfkreis aus Modul und Zaehnezahl..................1" << std::endl;
         std::cout << "Modul aus Kopfkreis und Zaehnezahl..................2" << std::endl; 
         std::cout << "Zaehnezahl aus Kopfkreis und Modul..................3" << std::endl; 
         std::cout << "Teilkreisdmr aus Modul und Zaehnezahl...............4" << std::endl; 
         std::cout << "Fusskreisdmr aus TKdmr, Spiel und Modul.............5" << std::endl;
         std::cout << "Achsabstand Aussenzahnraeder aus Modul und Z-zahl...6" << std::endl;
         std::cout << "Modul aus Kopfkreis und Teilkreisdurchmesser........7" << std::endl;
         std::cout << "Zahl der Zaehne ueber die gemessen wird.............8" << std::endl;
         std::cout << "Gemessene Distanz zwischen den Messflächen..........9" << std::endl;
         std::cout << "Eingabe des Kopfspiels c............................10" << std::endl;
         wastu = MenueFrage();
        break; 
         
   case 0: 
         return;        
         wastu = 21;
     break;    
         
   case 1:
         Getdk_aus_m_und_zx();       
         wastu = 21;
     break;    
   
   case 2:
       Getdk_aus_m_und_zx();
       wastu = 21;
     break;       
       
   case 3:
       Get_zx_aus_dk_und_m();
       wastu = 21;
     break;     
  
   case 4:
       GetD0_aus_m_und_zx();
       wastu = 21;
     break;     

   case 5:
       Getdf_aus_dk_c_m();
       wastu = 21;
     break; 
   
   case 6:  
       Get_a_aus_m_und_z();
       wastu = 21;
     break;    
     
   case 7: 
       Get_m_aus_dk_und_d0();
        wastu = 21;
     break;
     
   case 8:
       GetZahnzahl_beim_messen();
        wastu = 21;
     break;
     
   case 9:
       Get_WK_Wert();  
        wastu = 21;
     break;   
     
   case 10:
       std::cout << "Eingabe des Kopfspiels c" << std::endl;
       std::cout << "Momentane Werte" << std::endl;
       std::cout << "Modul.........: " << m <<  " mm" << std::endl;
       std::cout << "Kopfspiel = cfaktor * m = " << cfaktor << " * " << m << " = " << c << " mm" << std::endl;
       std::cout << "Eingabe cfaktor(0.1 bis 0.3): ";
       std::cin >> cfaktor;
       if (cfaktor < 0.1)
        {
         cfaktor = 0.167;
         std::cout << "Eingabe cfaktor kleiner 0.1 nicht erlaubt" << std::endl;  
        }   
       if (cfaktor > 0.3)
        {
         cfaktor = 0.167;
         std::cout << "Eingabe cfaktor groesser 0.3 nicht erlaubt" << std::endl;  
        }
       c = cfaktor * m;
       std::cout << "Neue Werte" << std::endl;
       std::cout << "Modul.........: " << m <<  " mm" << std::endl;
       std::cout << "Kopfspiel = cfaktor * m = " << cfaktor << " * " << m << " = " << c << " mm" << std::endl;
       wastu = 21;
     break;   
      
  }while(wastu != 0);
}


void ZahnRad::Berechnung_zwei_Zahnraeder(void)
{
  int wastu = 21;

  do 
  switch(wastu)
  {
  default:
         std::cout << "Zurueck zum Hauptmenue..............................0" << std::endl; 
         std::cout << "z2 aus n1, n2, und z1...............................1" << std::endl;
         std::cout << "n2 aus n1, z1, und z2...............................2" << std::endl;
         std::cout << "n2 aus iver und n1..................................3" << std::endl;
         std::cout << "n1 aus iver und n2..................................4" << std::endl;
         std::cout << "z2 aus iver und z1..................................5" << std::endl;
         std::cout << "z1 aus iver und z2..................................6" << std::endl; 
         wastu = MenueFrage();
        break; 
     
  case 0: 
         return;        
         wastu = 21;
     break;     
      
        
 case 1:   
       std::cout << "z2 aus n1, n2, und z1" << std::endl;
       
       std::cout << "Eingabe z1: ";
       std::cin >> z[0];
       
       std::cout << "Eingabe n1: ";
       std::cin >> n[0];
       
       std::cout << "Eingabe n2: ";
       std::cin >> n[1];
       
       z[1] = z[0] * n[0] / n[1];
       std::cout << "z2: " << z[1] << std::endl;
       
       wastu = 21;
     break;
       
   case 2:   
       std::cout << "n2 aus n1, z1, und z2" << std::endl;
       
       std::cout << "Eingabe n1: ";
       std::cin >> n[0];
       
       std::cout << "Eingabe z1: ";
       std::cin >> z[0];
       
       std::cout << "Eingabe z2: ";
       std::cin >> z[1];
       
       n[1] = z[0] * n[0] / z[1];
       std::cout << "n2: " << n[1] << std::endl;
       
       wastu = 21;
     break;

   case 3:   
       std::cout << "n2 aus iver und n1" << std::endl;
       
       std::cout << "Eingabe Uebersetzungsverhaeltnis(z.B. 0.4): ";
       std::cin >> iver[0];
       
       std::cout << "Eingabe n1: ";
       std::cin >> n[0];
                    
       n[1] = n[0] / iver[0];
       std::cout << "n2: " << n[1] << std::endl;
       
       wastu = 21;
     break; 

  case 4:   
       std::cout << "n1 aus iver und n2" << std::endl;
       
       std::cout << "Eingabe Uebersetzungsverhaeltnis(z.B. 0.4): ";
       std::cin >> iver[0];
       
       std::cout << "Eingabe n2: ";
       std::cin >> n[1];
                    
       n[0] = n[1] * iver[0];
       std::cout << "n1: " << n[0] << std::endl;
       
       wastu = 21;
     break;  

  case 5:   
       std::cout << "z2 aus iver und z1" << std::endl;
       
       std::cout << "Eingabe Uebersetzungsverhaeltnis(z.B. 0.4): ";
       std::cin >> iver[0];
       
       std::cout << "Eingabe z1: ";
       std::cin >> z[0];
                    
       z[1] = z[0] * iver[0];
       std::cout << "z2: " << z[1] << std::endl;
       
       wastu = 21;
     break;    
       
   case 6:   
       std::cout << "z1 aus iver und z2" << std::endl;
       
       std::cout << "Eingabe Uebersetzungsverhaeltnis(z.B. 0.4): ";
       std::cin >> iver[0];
       
       std::cout << "Eingabe z2: ";
       std::cin >> z[1];
                    
       z[0] = z[1] / iver[0];
       std::cout << "z2: " << z[0] << std::endl;
       
       wastu = 21;
     break;           
      
  }while(wastu != 0);   
}

void ZahnRad::Berechnung_mit_Drehmoment(void)
{
  int wastu = 21;

  do 
  switch(wastu)
  {
  default:
       std::cout << "Zurueck zum Hauptmenue..............................0" << std::endl;
       std::cout << "Drehmoment M2 aus iver und M1.......................1" << std::endl;
       std::cout << "Drehmoment M1 aus iver und M2.......................2" << std::endl;
       std::cout << "Uebersetzungsverhaeltnis aus M1 und M2..............3" << std::endl;
       std::cout << "Drehmoment M1 aus Fu1 und Teilkreisdurchmesser......4" << std::endl;
       std::cout << "Drehmoment Fu1 aus M1 und Teilkreisdurchmesser......5" << std::endl;
       std::cout << "Teilkreisdmr aus Drehmoment und Umfangskraft........6" << std::endl;
       wastu = MenueFrage();
     break;   

  case 0: 
         return;        
         wastu = 21;
     break;
     
  case 1:   
       std::cout << "Drehmoment M2 aus iver und M1" << std::endl;
       
       std::cout << "Eingabe Uebersetzungsverhaeltnis(z.B. 0.4): ";
       std::cin >> iver[0];
       
       std::cout << "Eingabe Drehmoment M1 in Nm: ";
       std::cin >> moment[0];
                    
       moment[1] = moment[0] * iver[0]; // M2 = i * M1
       std::cout << "Drehmoment M2 in Nm: " << moment[1] << std::endl;
       
       wastu = 21;
     break;


   case 2:   
       std::cout << "Drehmoment M1 aus iver und M2" << std::endl;
       
       std::cout << "Eingabe Uebersetzungsverhaeltnis(z.B. 0.4): ";
       std::cin >> iver[0];
       
       std::cout << "Eingabe Drehmoment M2 in Nm: ";
       std::cin >> moment[1];
                    
       moment[0] = moment[1] / iver[0];
       std::cout << "Drehmoment M1 in Nm: " << moment[0] << std::endl;
       
       wastu = 21;
     break;   

   case 3:   
       std::cout << "Uebersetzungsverhaeltnis aus M1 und M2" << std::endl;
       
       std::cout << "Eingabe Drehmoment M1 in Nm: ";
       std::cin >> moment[0];
       
       std::cout << "Eingabe Drehmoment M2 in Nm: ";
       std::cin >> moment[1];
                    
       iver[0] = moment[1] / moment[0];
       std::cout << "Eingabe Uebersetzungsverhaeltnis: "  <<  iver[0] << std::endl;
       
       wastu = 21;
     break;    
     
     
  case 4:
       std::cout << "Drehmoment M1 aus Fu1 und Teilkreisdurchmesser" << std::endl;
       
       std::cout << "Umfangskraft Fu1: ";
       std::cin >> Fu[0]; 

       Eingabe_Teilkreisdurchmesser();

       moment[0] = (Fu[0] * d0) / 2;
       std::cout << "Drehmoment M1 = " << Fu[0] <<" * " << d0 << " / 2 = " << moment[0] << std::endl;
 
       wastu = 21;
     break;    

 case 5:
       std::cout << "Drehmoment Fu1 aus M1 und Teilkreisdurchmesser" << std::endl;
       
       std::cout << "Drehmoment M1 in Nm: ";
       std::cin >> moment[0]; 

       Eingabe_Teilkreisdurchmesser();

       Fu[0] = (moment[0] * 2) / d0;
       std::cout << "Umfangskraft Fu1 = (" << moment[0] <<" * 2 ) / " << d0 << " = " << Fu[0] << " N " << std::endl;
 
       wastu = 21;
     break;

  case 6:
       std::cout << "Teilkreisdurchmesser aus Drehmoment und Umfangskraft" << std::endl;
       
       std::cout << "Drehmoment M1 in Nm: ";
       std::cin >> moment[0]; 
       
       std::cout << "Umfangskraft Fu1 in N ";
       std::cin >> Fu[0];

       d0 = (moment[0] * 2) / Fu[0];
       std::cout << "Teilkreisdurchmesser D0 = (" << moment[0] <<" * 2 ) / " << Fu[0] << " = " << d0 << " mm" << std::endl;
 
       wastu = 21;
     break;


  }while(wastu != 0);
  
}