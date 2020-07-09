/**
* \file main.cpp
* \brief glowny plik programu
* \author piotr
* \date 2019-01-23
*
* zawiera wywolanie funkcji zamieszczonych w innych
* plikach oraz wypisanie w konsoli wynikow
*/
#include <iostream>
#include "Model.hpp"
#include "Sumator.hpp"
#include "ObiektFactory.hpp"
#include "SolverFactory.hpp"
#include "SymulinkException.hpp"
using namespace std;
using namespace std::placeholders;
int main()
{
  try { // sprobuj wykonac ponizszy kod...
    // utworz model
    Model model;
    // dodaj sygnaly
    model.addSygnal(make_shared<Sygnal>("a"));
    model.addSygnal(make_shared<Sygnal>("b"));
    model.addSygnal(make_shared<Sygnal>("u"));
    model.addSygnal(make_shared<Sygnal>("y"));
    model.addSygnal(make_shared<Sygnal>("c"));
    Vector wekt={1.0,-1.0};
    Vector wekt2={2.0};
    // dodaj obiekty
    model.addObiekt(ObiektFactory::makeStala("stala", 1.0), {}, "a");
   // model.addObiekt(ObiektFactory::makeCzlonInercyjny("int1", 1.0,1.0), {"a"}, "y");
   model.addObiekt(ObiektFactory::makeCzlonInercyjny("int1", 1.0,1.0), {"c"}, "y");
    model.addObiekt(ObiektFactory::makeCzlonPID("int1", 2.0,1.0,0.000001,10000.0), {"b"}, "c");
   model.addObiekt(make_shared<Sumator>("sum",wekt), {"a","y"} ,"b");
    model.addObiekt(ObiektFactory::makeScope("scope"), {"y"}, "");
    // symuluj model
    const double DT = 0.05;
    for (double t = 0.0; t < 10.0; t += DT) {
      model.update(t, DT);
    }
  } catch (SymulinkException& e) { // ... kiedy w powyzszym kodzie wystapi wyjatek naszej biblioteki, trafiamy tutaj
    cout << e.what() << endl; // wypisz komunikat bledu
  }
  return 0;
}
//sprawdz dzialanie sumatora w main
