/**
 * \file ObiektCiagly.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie ObiektCiagly
*/
#include "ObiektCiagly.hpp"
using namespace std;
using namespace std::placeholders;
void ObiektCiagly::update(Scalar t, Scalar dt) {
  ODE fun = bind(&ObiektCiagly::dx, this, _1, _2, _3);
  _state = _solver->step(fun, t, _state, _inputs[0], dt);
  _output = _state;
}
