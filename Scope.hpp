/**
 * \file Scope.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Scope.
*/
#pragma once
#include "Types.hpp"
#include <iostream>
/**
 * \class Scope
 * \brief Klasa wyswietlajacy dany sygnal na konsoli.
 */
class Scope : public Obiekt {
public:
  typedef std::shared_ptr<Stala> Ptr;
  Scope(const std::string name) :
    Obiekt(name, 1) {
  }

  virtual ~Scope() {}
  virtual void update(Scalar t, Scalar dt) {
    std::cout << t << "\t ,";
    std::cout << _inputs[0];
    std::cout << std::endl;
  }
};
