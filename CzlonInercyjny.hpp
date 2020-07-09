/**
 * \file CzlonInercyjny.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy CzlonInercyjny.
*/
#pragma once
#include "ObiektCiagly.hpp"
/**
 * \class CzlonInercyjny
 * \brief Klasa reprezentujaca obiekt bedacy czlonem inercyjnym o 1 wej. i 1 wyj.
 */
class CzlonInercyjny : public ObiektCiagly {
public:
    typedef std::shared_ptr<CzlonInercyjny> Ptr;
    CzlonInercyjny(const std::string& name, Scalar k, Scalar T, Solver::Ptr solver=SolverFactory::makeSolverEuler()) :
      ObiektCiagly(name, 1, 1, solver),
      _k(k),
      _T(T)
    {}
protected:
  virtual Vector dx(Scalar t, const Vector& x, const Vector& u);
private:
    Scalar _k;
    Scalar _T;
};
