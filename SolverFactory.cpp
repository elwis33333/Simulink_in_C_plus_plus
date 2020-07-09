#include "SolverFactory.hpp"
#include "SolverEuler.hpp"
#include "SolverRK4.hpp"
#include "SymulinkException.hpp"
// tutaj zalacz pozostale wykorzystywane solvery
using namespace std;
Solver::Ptr SolverFactory::makeSolverEuler()
{
    return Solver::Ptr(new SolverEuler);
}
Solver::Ptr SolverFactory::makeSolverRK4()
{
    return Solver::Ptr(new SolverRK4);
}
Solver::Ptr SolverFactory::makeSolver(const std::string& type)
{
    if (type == "" || type == "euler") {
        return makeSolverEuler();
    }
    else if (type == "" || type == "rk4") {
        return makeSolverRK4();
    }
    // else if <- tutaj dopisz pozostale przypadki

    else {
        throw SymulinkException("Nieznany typ solvera!");
    }
}
