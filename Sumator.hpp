/**
 * \file Sumator.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Sumator.
*/
#pragma once
#include "Obiekt.hpp"
#include "SolverFactory.hpp"
/**
 * \class Sumator
 * \brief Klasa reprezentujaca obiekt sumatora o definiowanej liczbie wejsc i ich wzmocnien.
 */
class Sumator : public Obiekt {
public:
  typedef std::shared_ptr<Sumator> Ptr;
  Sumator(const std::string& name, Vector wagi = {1,1}) :
    Obiekt(name, 1, wagi.size()),
    _wagi(wagi)
  {}
  virtual ~Sumator() {}
  virtual void update(Scalar t, Scalar dt);
private:
 Vector _wagi;
};
