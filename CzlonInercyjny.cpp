/**
 * \file CzlonInercyjny.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie CzlonInercyjny
*/
#include "CzlonInercyjny.hpp"
using namespace std;
Vector CzlonInercyjny::dx(Scalar t, const Vector& x, const Vector& u){
Vector pochodna= _k/_T * u - 1/_T * x;
return pochodna;
}
