#include "SolverRK4.hpp"
using namespace std;
Vector SolverRK4::step(ODE dx, Scalar t, const Vector& x, const Vector& u, double dt)
{
     Vector k1 = dx(t, x, u) * dt;
    Vector k2 = dt * dx(t+dt/2.0, x+k1/2.0, u);
    Vector k3 = dt * dx(t+dt/2.0, x+k2/2.0, u);
    Vector k4 = dt * dx(t+dt, x+k3, u);
    Vector nx = x + 1.0/6.0 * (k1+2.0*k2+2.0*k3+k4);
     return nx;
}
