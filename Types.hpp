/**
 * \file Types.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Types.
*/
#pragma once
#include <string>
#include <map>
#include <valarray>
#include <functional>
#include <memory>
#include <ostream>
/**
 * \class Types
 * \brief Klasa zawierajaca wlasne "zmienne"
 */
typedef double Scalar;
typedef std::valarray<Scalar> Vector;
typedef std::function<Vector(Scalar, const Vector&, const Vector&)> ODE; // dx = f(t, x, u)
std::ostream& operator<<(std::ostream& str, const Vector& v);
