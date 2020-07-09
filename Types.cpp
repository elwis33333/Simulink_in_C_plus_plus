#include "Types.hpp"
using namespace std;
ostream& operator<<(std::ostream& str, const Vector& v)
{for (auto& x : v) {
        str << x << "\t ,";
    }
    return str;}
