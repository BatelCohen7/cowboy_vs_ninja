#pragma once

#include "iostream"
#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel{
    class Ninja:public Character{
        private:
            int speed;
        protected:
            // constructors
            Ninja(string name, Point _loc, int _numOfHit, int _speed);

        public:
             // functions
            void move(Character* character);
            void slash(Character* character);
            int getSpeed();
            string print(); 
    };
}