/**
 * \file ObiektFactory.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie ObiektFactory
*/
#include "ObiektFactory.hpp"
#include <iostream>
#include <fstream>
#include "CzlonCalkujacy.hpp"
#include "CzlonInercyjny.hpp"
#include "CzlonOscylacyjny.hpp"
#include "CzlonPID.hpp"
#include "Stala.hpp"
#include "Scope.hpp"
#include "SymulinkException.hpp"
using namespace std;
Obiekt::Ptr ObiektFactory::makeCzlonCalkujacy(const std::string& name, Scalar T)
{
  return Obiekt::Ptr(new CzlonCalkujacy(name, T));
}
Obiekt::Ptr ObiektFactory::makeCzlonInercyjny(const std::string& name, Scalar k, Scalar T)
{
  return Obiekt::Ptr(new CzlonInercyjny(name, k, T));
}
Obiekt::Ptr ObiektFactory::makeCzlonOscylacyjny(const std::string& name, Scalar k, Scalar T, Scalar zeta)
{
    return Obiekt::Ptr(new CzlonOscylacyjny(name, k, T, zeta));
}
Obiekt::Ptr ObiektFactory::makeCzlonPID(const std::string& name, Scalar k, Scalar Ti, Scalar Td, Scalar T)
{
    return Obiekt::Ptr(new CzlonPID(name, k, Ti, Td, T));
}
Obiekt::Ptr ObiektFactory::makeStala(const std::string& name, Scalar value)
{
  return Obiekt::Ptr(new Stala(name, value));
}
Obiekt::Ptr ObiektFactory::makeScope(const std::string& name) {
  return Obiekt::Ptr(new Scope(name));
}
Obiekt::Ptr ObiektFactory::makeObiekt(const std::string& name, const std::string& type, const std::vector<double>& params)
{
  if (type == "czlon_calkujacy") {
    return makeCzlonCalkujacy(name, params[0]);
  }
  else if (type == "czlon_inercyjny") {
        return makeCzlonInercyjny(name, params[0],params[1]);
    }
  else if (type == "czlon_oscylacyjny") {
        return makeCzlonOscylacyjny(name, params[0],params[1],params[2]);
    }
  else if (type == "czlon_pid") {
        return makeCzlonPID(name, params[0],params[1],params[2],params[3]);
    }
  else if (type == "stala") {
    return makeStala(name, params[0]);
  }
  else if (type == "scope") {
    return makeScope(name);
  }
  else {
  throw SymulinkException("Nieznany typ obiektu!");
  }
}
