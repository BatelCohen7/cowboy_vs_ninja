#pragma once

#include "iostream"
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{
    class Cowboy:public Character{
        private:
            int bullets;
        public:
            // constructors
            Cowboy(string name, Point location);

            // functions
            void shoot(Character * enemy);
            bool hasboolets();
            void reload();
            string print();           
    };
    
}