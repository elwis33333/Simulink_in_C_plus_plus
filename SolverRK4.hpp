/**
 * \file SolverRK4.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy SolverRK4.
*/
#pragma once
#include "Solver.hpp"
/**
 * \class SolverRK4
 * \brief Wyznaczanie kolejnych probek symulacji za pomoca algorytmu RK4
 */
class SolverRK4 : public Solver {
public:
    typedef std::shared_ptr<SolverRK4> Ptr;
    SolverRK4() {}
    virtual ~SolverRK4() {}
    //! @copydoc Solver::step
    virtual Vector step(ODE dx, Scalar t, const Vector& x, const Vector& u, double dt);
};
