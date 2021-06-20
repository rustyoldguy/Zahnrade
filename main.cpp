#include "zahnrad.h"


int main(int argc, char **argv)
{
 ZahnRad gear;
 int watu = 32; 
 
 do
 switch(watu) 
 { 
   default: 
      gear.Hauptmenue();
          watu = MenueFrage();
       break;


  case 0:
        std::cout << "Programm beendet" << std::endl;
        return 0;
      break;  
      
         
  case 1:  
       gear.radzahl = gear.GetAnzahlZahnraeder();
       ENDOFCASE
    
  case 2:
       gear.Eingabe_Zaehnezahl_aller_Zahnräder();
       ENDOFCASE
     
        
    case 3:
       gear.Eingabe_Drehzahl_z1(); 
       ENDOFCASE   
  
   case 4:
       gear.ShowModulreihe();
       ENDOFCASE 
     
   case 5:
       gear.Zahnradgroessen();
       ENDOFCASE

   case 6:
       gear.Berechnung_zwei_Zahnraeder();
       ENDOFCASE

   case 7:
       gear.Berechnung_mit_Drehmoment();
       ENDOFCASE  
       
        
   case 24:   
       gear.Zeige_Werte_aller_Zahnraeder();
       ENDOFCASE    
   
   case 25:   
       gear.Info();
       ENDOFCASE    
     
 }while(watu != 0);
  
   std::cout << "Programm beendet" << std::endl; 
   return 0;
}

