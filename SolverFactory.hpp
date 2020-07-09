/**
 * \file SolverFactory.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy SolverFactory.
*/
#pragma once
#include <string>
#include "Solver.hpp"
/**
 * \class SolverFactory
 * \brief Klasa tworzaca nowe solwery dla nowych obiektow
 */
class SolverFactory {
public:
    /**
     * @brief Tworzy i zwraca solver Eulera.
     */
    static Solver::Ptr makeSolverEuler();
     /**
     * @brief Tworzy i zwraca solver RK4.
     */
    static Solver::Ptr makeSolverRK4();
    // tutaj dodaj metody zwracajace inne zaimplementowane solvery
    /**
     * @brief Tworzy i zwraca solver wedlug argumentu.
     *
     * Dla somyslnego argumentu zwracany jest solver domyslny (Eulera).
     *
     * @param type [in] rodzaj solvera (euler, rk4, ...)
     * @return Solver.
     */
    static Solver::Ptr makeSolver(const std::string& type);
};
