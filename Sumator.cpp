/**
 * \file Sumator.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie Sumator
*/
#include "Sumator.hpp"
using namespace std;
using namespace std::placeholders;
void Sumator::update(Scalar t, Scalar dt){
      int wielkosc = 0;
      for(int i=0; i<_wagi.size(); i++){
        if (_inputs[i].size() > wielkosc){ wielkosc = _inputs[i].size();}
      }
      Vector wyjscie(0.0,wielkosc);
       for(int j=0;j<_wagi.size(); j++){
        wyjscie+= _wagi[j]*_inputs[j];
      }
  _output=wyjscie;
  }
