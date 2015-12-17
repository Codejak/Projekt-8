#include <cstdlib>
#include <iostream>         // Ein- und Ausgabeoperatoren
#include <iomanip>          // Formatierungsoperationen fuer die Ausgabe
#include "Polynom.h"        // Funktionsprototypen fuer dieses Programmmodul
// Standardnamensraum verwenden
using namespace std;

// machst was
void schreibWertetabelle(Polynom* p) {
  // Grad der erzeugten Polyonme ausgeben
  cout << "Der Grad des Polynoms ist " << p->grad() << endl;

  // gibt eine Wertetabelle fuer das Polynom p aus
  cout << endl;
  cout.setf(ios::fixed); // Zahlen in Dezimaldarstellung ausgeben
  cout.precision(5); // und auf 5 Stellen hinter dem Komma genau

  // Tabellenueberschrift ausgeben
  cout << setw(11) << "x" << " " << setw(11) << "p(x)" << endl;

  // Argumente und Polynomwerte ausgeben
  for (double x = -1; x < 1; x += 0.1) {
    cout << setw(11) << x << "  " << setw(11) << p->berechneWert(x) << endl;
  }
}

// Hauptprogramm
int main() {
  Polynom* p;      // Polynomzeiger p
  Polynom* q;      // Polynomzeiger q

  p = new Polynom; // Erzeugung eines neues Polynoms
  q = new Polynom; // Erzeugung eines neues Polynoms

  schreibWertetabelle(p); // Wertetabelle fuer p
  schreibWertetabelle(q); // Wertetabelle fuer q

  delete p; // Freigabe des dynamischen Koeffizientenfeldes
  delete q; // Freigabe des dynamischen Koeffizientenfeldes

  return EXIT_SUCCESS;
}