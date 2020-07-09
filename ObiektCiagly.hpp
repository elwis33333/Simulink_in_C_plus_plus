/**
 * \file ObiektCiagly.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy ObiektCiagly.
*/
#pragma once
#include "Obiekt.hpp"
#include "SolverFactory.hpp"
/**
 * \class ObiektCiagly
 * \brief Klasa dziedziczaca po klasie Obiekt, dziedzicza po niej klasy konkretnych obiektow
 */
class ObiektCiagly : public Obiekt {
public:
  typedef std::shared_ptr<ObiektCiagly> Ptr;
  ObiektCiagly(const std::string& name, unsigned nStates=1, unsigned nInputs=1, Solver::Ptr solver=SolverFactory::makeSolverEuler()) :
    Obiekt(name, nStates, nInputs),
    _solver(solver)
  {}
  virtual ~ObiektCiagly() {}
  virtual void update(Scalar t, Scalar dt);
protected:
  virtual Vector dx(Scalar t, const Vector& x, const Vector& u) = 0;
private:
  Solver::Ptr _solver;
};
