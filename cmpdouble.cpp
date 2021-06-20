#include "cmpdouble.h"
/*
 * int compdouble(double da, double db, int stellen) 
 * int compdoubleb(double da, double db, int stellen)
 * double TrenneVorkommmaNachkomma(double floatzahl, double *vorkomma)
 */


int compdouble(double da, double db, int stellen)
{
 int rewer = -1, nachint_a = 0, nachint_b = 0, i, faktor = 1, vka, vkb;
 double nachkomma_a, vorkomma_a;
 double nachkomma_b, vorkomma_b;
 
  
 nachkomma_a = std::modf(da, &vorkomma_a);
 nachkomma_b = std::modf(db, &vorkomma_b);
 
 vka = vorkomma_a;
 vkb = vorkomma_b;
 
 //std::cout << "Nachkomma_a: " << nachkomma_a << std::endl;
 //std::cout << "Nachkomma_b: " << nachkomma_b << std::endl;
 
 if(vka == vkb)
 for (i = 0; i <= stellen; i++)
  {
   faktor *= 10;
   nachint_a = nachkomma_a * faktor;
   nachint_b = nachkomma_b * faktor;
   //std::cout <<"nachint_a: " << std::setw(8) << nachint_a<< "   nachint_b: " << std::setw(8) <<  nachint_b << "   i:" << i << std::endl;
   if(nachint_a != nachint_b) break;
  }
 
  rewer = i;  // Gibt an, bis zu welcher Nachkommastelle die Zahlen gleich sind
 
 return rewer;	
}

// Vergleicht double-Zahl da mit double-Zahl db auf stellen(Parameter 3) genau
// Rueckgabewet ist, auf wie viele Nachkommastellen die Zahlen gleich sind.
// Dezimalstellen kleiner als 'stellen'(Parameter 3) werden nicht beruecksichtigt.
int compdoubleb(double da, double db, int stellen)
{
 int rewer = -1, nachint_a = 0, nachint_b = 0, i, faktor = 1, vka, vkb;
 int vorkommastellena = -1, vorkommastellenb = -1; 
 double nachkomma_a, vorkomma_a;
 double nachkomma_b, vorkomma_b;
 
 vorkommastellena = (int)log10(da) + 1;
 vorkommastellenb  = (int)log10(da) + 1;
 
 if (stellen >= 1)
  { 
   /*
   // Vorkomma- und Nachkommastellen separieren 
   nachkomma_a = std::modf(da, &vorkomma_a);
   nachkomma_b = std::modf(db, &vorkomma_b);
 
   // Gleitkomma in int umwandlen
   vka = vorkomma_a;     
   vkb = vorkomma_b;     
   */
   
   // Vorkomma- und Nachkommastellen separieren 
   nachkomma_a = TrenneVorkommmaNachkomma(da, &vorkomma_a);
   nachkomma_b = TrenneVorkommmaNachkomma(db, &vorkomma_b);
 
   vka = vorkomma_a;     
   vkb = vorkomma_b;     
 
   std::cout << "Vorkommastellen da: " << vorkommastellena << std::endl;
   std::cout << "Vorkommastellen bb: " << vorkommastellenb << std::endl;
   std::cout << "Nachkomma_a: " << nachkomma_a << std::endl;
   std::cout << "Nachkomma_b: " << nachkomma_b << std::endl;
 
   if(vka == vkb)
   for (i = 0; i <= stellen; i++)
    {
     faktor *= 10; 
     nachint_a = nachkomma_a * faktor;
     nachint_b = nachkomma_b * faktor;
     std::cout <<"nachint_a: " << std::setw(8) << nachint_a<< "   nachint_b: " << std::setw(8) <<  nachint_b << "   i:" << i << std::endl;
     if(nachint_a != nachint_b)
	  {
	   rewer = i;  // Gibt an, bis zu welcher Nachkommastelle die Zahlen gleich sind
       break;
	  }
	}
   	else 
	 {
	  for (i = vorkommastellena - 1; i >= 0; i--)	
	   {
		faktor = pow(10, i);
		vka = vorkomma_a / faktor;
        vkb = vorkomma_b / faktor;
	    // Format der Auswertungsstellen:  -3-2-1.12345 
		rewer =  i * -1;  // Gibt an, bis zu welcher Nachkommastelle die Zahlen gleich sind; Vorkommastelle -1 = Einer, -2=Zehner usw
		std::cout <<"vka: " << std::setw(8) << vka << "   vka: " << std::setw(8) <<  vkb << "   rewer: " << rewer << "   faktor: " << faktor << std::endl;  
	    return rewer;
	   }
     }
  }
 else rewer = -111; // Wenn Stellen kleiner 1
 
 return rewer;	
}



double TrenneVorkommmaNachkomma(double floatzahl, double *vorkomma)
{
 double nachkomma;
 int intvorkomma = (int)floatzahl; 
  
 nachkomma = floatzahl -(double)intvorkomma; 
 *vorkomma = (double)intvorkomma;
 
 return nachkomma; 
} 