#include "bomasincostan.h"
/*
 * double bogenmass(double grad)
 * double get_cos(double winkel)
 * double get_tan(double winkel)
 * double get_sin(double winkel)
 */
// Wandelt grad in Bogenmass um
double bogenmass(double grad)
{
 double boma;

 boma = (grad * M_PI)  / 180;
 return boma;
}

double get_cos(double winkel)
{ 
 double boma = bogenmass(winkel);
 return cos(boma); 
}

double get_tan(double winkel)
{ 
 double boma = bogenmass(winkel);
 return tan(boma); 
}

double get_sin(double winkel)
{ 
 double boma = bogenmass(winkel);
 return sin(boma); 
}