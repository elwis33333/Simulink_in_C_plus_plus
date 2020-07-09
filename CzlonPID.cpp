/**
 * \file CzlonPID.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie CzlonPID
*/
#include "CzlonPID.hpp"
using namespace std;
Vector CzlonPID::dx(Scalar t, const Vector& x, const Vector& u){
 Vector pochodna(2);
 pochodna[0]= u[0];
 pochodna[1]= -x[1]/_T+ u[0]/_T;
return pochodna;
}
