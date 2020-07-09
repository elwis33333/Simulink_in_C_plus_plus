/**
 * \file Stala.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Stala.
*/
#pragma once
#include "Types.hpp"
#include <iostream>
/**
 * \class Stala
 * \brief Klasa reprezentujaca wymuszenie bedace stala wartoscia
 */
class Stala : public Obiekt {
public:
  typedef std::shared_ptr<Stala> Ptr;

  Stala(const std::string name, Scalar value=0.0) :
    Obiekt(name, 0),
    _value(value) {
  }
  virtual ~Stala() {}

  virtual void update(Scalar t, Scalar dt) {
    _output = Vector(_value, 1);
  }
private:
  Scalar _value;
};
