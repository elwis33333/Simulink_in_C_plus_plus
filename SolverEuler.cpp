#include "SolverEuler.hpp"
using namespace std;
Vector SolverEuler::step(ODE dx, Scalar t, const Vector& x, const Vector& u, double dt)
{
    Vector nx = x + dx(t, x, u) * dt;
    return nx;
}
