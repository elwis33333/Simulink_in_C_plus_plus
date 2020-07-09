/**
 * \file CzlonCalkujacy.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy CzlonCalkujacy.
*/
#pragma once
#include "ObiektCiagly.hpp"
/**
 * \class CzlonCalkujacy
 * \brief Klasa reprezentujaca obiekt bedacy czlonem calkujacym o 1 wej. i 1 wyj.
 */
class CzlonCalkujacy : public ObiektCiagly {
public:
    typedef std::shared_ptr<CzlonCalkujacy> Ptr;

    CzlonCalkujacy(const std::string& name, Scalar T, Solver::Ptr solver=SolverFactory::makeSolverEuler()) :
      ObiektCiagly(name, 1, 1, solver),
      _T(T)
    {}
protected:
  virtual Vector dx(Scalar t, const Vector& x, const Vector& u);

private:
    Scalar _T;
};
