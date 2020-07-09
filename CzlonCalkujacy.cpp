/**
 * \file CzlonCalkujacy.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie CzlonCalkujacy
*/
#include "CzlonCalkujacy.hpp"
using namespace std;
Vector CzlonCalkujacy::dx(Scalar t, const Vector& x, const Vector& u)
{
    return 1.0/_T * u;
}
