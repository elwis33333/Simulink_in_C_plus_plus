/**
 * \file CzlonPID.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy CzlonPID.
*/
#pragma once
#include "ObiektCiagly.hpp"
/**
 * \class CzlonPID
 * \brief Klasa reprezentujaca obiekt bedacy regulatorem PID o 1 wej. i 2 stanach.
 */
class CzlonPID : public ObiektCiagly {
public:
    typedef std::shared_ptr<CzlonPID> Ptr;
    CzlonPID(const std::string& name, Scalar k, Scalar Ti, Scalar Td, Scalar T, Solver::Ptr solver=SolverFactory::makeSolverEuler()) :
      ObiektCiagly(name, 2, 1, solver),
      _k(k),
      _Ti(Ti),
      _Td(Td),
      _T(T)
    {}
virtual void update(Scalar t, Scalar dt) {
    ObiektCiagly::update(t, dt);
    _output = { _state[0]/_Ti+_state[1]*_Td/_T+(_k-_Td/_T)*_inputs[0][0], _state[0], _state[1] } ;
}
protected:
  virtual Vector dx(Scalar t, const Vector& x, const Vector& u);
private:
    Scalar _k;
    Scalar _Ti;
    Scalar _Td;
    Scalar _T;
};
