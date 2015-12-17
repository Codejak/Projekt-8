

// include-Anweisungen
#include <iostream> // Schnittstelle der Ein-/Ausgabeobjekte und Operationen
#include <iomanip>  // enthaelt die Schnittstelle der Funktion
					// setprecision(int)
#include <cmath>    // Schnittstelle von Funktionen wie sin(double)
#include <cassert>  // enthaelt die Schnittstelle der Funktion assert()
#include <cstdlib>
#include "polynom.h"

using namespace std;


double eps = 1E-7;           // geforderte Genauigkeit
double fabs (double);




double findeNullStelleRekursiv(double a, double b) {
  
  
  double xn;

  assert((p(a)*p(b)) < 0);   // FIXME Hier die richtige Vorbedingung einfuegen.


  xn =  a - p(a) * ((b-a) / ( p(b) - p(a) ));

  if(fabs(p(xn)) <= eps)
    return xn;

  if(p(xn)*p(a) < 0)
    // b = xn;
    return findeNullStelleRekursiv(a, xn);
  else
    // a = xn;
    return findeNullStelleRekursiv(xn, b);

}





double findeNullStelleIterativ(double a, double b){
  double h;
  
  assert((p(a)*p(b)) < 0);

  
  do {
    h = (a - p(a) * ((b-a) / ( p(b) - p(a) )));
    if (p(h) == 0) 
      return h;

    if (p(h)*p(a) < 0) 
      b = h;
    else 
      a = h;

  } while (fabs(p(h)) > eps);


  return h;
}

