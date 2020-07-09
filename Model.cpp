/**
 * \file Model.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie Model
*/
#include "Model.hpp"
#include <algorithm>
#include <iostream>
using namespace std;
void Model::update(Scalar t, Scalar dt) {
  for (ObiektInfo& oi : _obiekty) {
    // znajdz sygnaly wejsciowe
    for (unsigned i = 0; i < oi.inputs.size(); ++i) {
      oi.obiekt->setInput(i, oi.inputs[i]->getValue());
    }
    oi.obiekt->update(t, dt);
    if (oi.output != NULL) oi.output->setValue(oi.obiekt->getOutput());
  }
}
void Model::addSygnal(Sygnal::Ptr s) {
  _sygnaly.insert(make_pair(s->getName(), s));
}
void Model::addObiekt(Obiekt::Ptr o, const std::vector<std::string> inputs, const std::string& output) {
  ObiektInfo oi;
  // znajdz wejscia
  for (const auto& in : inputs) {
    oi.inputs.push_back(_sygnaly[in]);
  }
  // znajdz wyjscia
  if (output != "") {
    oi.output = _sygnaly[output];
  } else {
    oi.output = NULL;
  }
  oi.obiekt = o;
  _obiekty.push_back(oi);
}
