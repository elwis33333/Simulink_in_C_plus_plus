/**
 * \file CzlonOscylacyjny.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy CzlonOscylacyjny.
*/
#pragma once
#include "ObiektCiagly.hpp"
/**
 * \class CzlonOscylacyjny
 * \brief Klasa reprezentujaca obiekt bedacy czlonem oscylacyjnym o 1 wej. i 2 stanach.
 */
class CzlonOscylacyjny : public ObiektCiagly {
public:
    typedef std::shared_ptr<CzlonOscylacyjny> Ptr;
    CzlonOscylacyjny(const std::string& name, Scalar k, Scalar T, Scalar zeta, Solver::Ptr solver=SolverFactory::makeSolverEuler()) :
      ObiektCiagly(name, 2, 1, solver),
      _k(k),
      _T(T),
      _zeta(zeta)
    {
    }
protected:
  virtual Vector dx(Scalar t, const Vector& x, const Vector& u) override;
private:
    Scalar _k;
    Scalar _T;
    Scalar _zeta;
};
