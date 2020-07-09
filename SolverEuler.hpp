/**
 * \file SolverEuler.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy SolverEuler.
*/
#pragma once
#include "Solver.hpp"
/**
 * \class SolverEuler
 * \brief Wyznaczanie kolejnych probek symulacji za pomoca row Eulera
 */
class SolverEuler : public Solver {
public:
    typedef std::shared_ptr<SolverEuler> Ptr;
    SolverEuler() {}
    virtual ~SolverEuler() {}
    //! @copydoc Solver::step
    virtual Vector step(ODE dx, Scalar t, const Vector& x, const Vector& u, double dt);
};
