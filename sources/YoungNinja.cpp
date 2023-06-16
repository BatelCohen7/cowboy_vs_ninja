#include "YoungNinja.hpp"

using namespace std;
using namespace ariel;

YoungNinja::YoungNinja(string name, const Point &location): Ninja(name, const_cast<Point&>(location), 100, 14) {}