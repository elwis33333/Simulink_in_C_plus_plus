/**
 * \file Obiekt.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy CzlonCalkujacy.
*/
#pragma once
#include "Types.hpp"
/**
 * \class Obiekt
 * \brief Klasa podstawowa zawierajaca nazwe, wejscia, wyjscia i stany
 */
class Obiekt {
public:
  typedef std::shared_ptr<Obiekt> Ptr;
  Obiekt(const std::string name, unsigned nStates=1, unsigned nInputs=1) :
    _name(name),
    _inputs(nInputs, Vector(0.0, 1)),
    _state(0.0, nStates),
    _output(0.0, 1) {
  }
  virtual ~Obiekt() {}
  std::string getName() const { return _name; }
  virtual void update(Scalar t, Scalar dt) {
    _state = _inputs[0];
    _output = _state;
  }
  void setInput(unsigned n, const Vector& u) {
    _inputs[n] = u;
  }
  Vector getState() const { return _state; }
  Vector getOutput() const { return _output; }
protected:
  std::vector<Vector> _inputs;
  Vector _state;
  Vector _output;
private:
  std::string _name;
};
