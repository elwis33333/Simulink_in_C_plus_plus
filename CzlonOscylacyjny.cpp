/**
 * \file CzlonOscylacyjny.cpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* zawiera algorytmy wykorzystywanych funkcji w klasie CzlonOscylacyjny
*/
#include "CzlonOscylacyjny.hpp"
#include<iostream>
using namespace std;
Vector CzlonOscylacyjny::dx(Scalar t, const Vector& x, const Vector& u){
 Vector pochodna(2);
 pochodna[0]= x[1];
 pochodna[1]= (u[0]*_k/(_T*_T))-(x[0]/(_T*_T))-(2.0*_zeta*x[1]/_T);
return pochodna;
}


