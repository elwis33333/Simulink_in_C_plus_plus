/**
 * \file Solver.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Solver.
*/
#pragma once
#include "Obiekt.hpp"
/**
 * \class Solver
 * \brief Klasa odpowiedzialna za obliczanie i zwracanie nowych stanow obiektu.
 */
class Solver {
public:
    typedef std::shared_ptr<Solver> Ptr;
    virtual ~Solver() {}
    /**
     * @brief Oblicza i zwraca nowy stan obiektu.
     *
     * @param dx [in] rownanie rozniczkowe dx = f(x, u)
     * @param t [in] czas
     * @param x [in] poprzedni stan
     * @param u [in] wejscie
     * @param dt [in] krok czasu
     */
    virtual Vector step(ODE dx, Scalar t, const Vector& x, const Vector& u, double dt) = 0;
};
