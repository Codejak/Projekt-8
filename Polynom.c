

// include Anweisungen
#include <iostream>         // Ein- und Ausgabeoperatoren
#include <iomanip>          // Formatierungsoperationen fuer die Ausgabe
#include <cstdlib> 

#include "Polynom.h"        // Funktionsprototypen fuer dieses Programmmodul

// Standardnamensraum verwenden
using namespace std;

Polynom::Polynom() {
  cout << "Grad deines Polynoms?" << flush;
  cin >> polynomGrad;

  double* polynomkoeff = new double[polynomGrad];

  for (int i = polynomGrad; i >= 0; --i) {
    cout << "Der Koeffizient" << i << "ten Grades bitte.." << endl;
    cin >> polynomkoeff[i];
  };

};

Polynom::~Polynom() {};

int Polynom::grad() {
return polynomGrad;
};

double Polynom::koeffizient(int i) {
  assert(i < 0);
  return *polynomkoeff[i];
};

double Polynom::berechneWert(double x) {
  for (int i = polynomGrad; i >= 0; --i) {
    double Wert = 0.0;
    Wert = Wert * x + polynomkoeff[i];
    return Wert;
  };
};

Polynom& Polynom::operator+=(Polynom& a) {
  
  if (grad() < a.grad()) {
    double* newpolynomkoeff = new double[a.grad()];
    for (int i = a.grad(); i >= 0; i--) {
      newpolynomkoeff[i] = polynomkoeff[i] + a.polynomkoeff[i];
    };
    delete[] polynomkoeff;
    polynomkoeff = newpolynomkoeff;
    polynomGrad = a.grad();

  };
  else {
    for (int i = 0; i <= grad(); i++) {
      polynomkoeff[i] += a.polynomkoeff[i];
      return *this;
    };
  };
  
};

Polynom& Polynom::operator*=(b) {
  polynomkoeff[i] *= b;
  return *this;
};

double Polynom::operator()(double x) {
  for (int i = grad(), i >= 0, i--) {
    double neuWert;
    neuWert = neuWert * x + polynomkoeff[i];
    return neuWert;
  };
};