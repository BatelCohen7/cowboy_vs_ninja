#pragma once

#include "iostream"
#include "Point.hpp"

using namespace std;

namespace ariel{
    class Character{
        private:
            std::string _name;
            Point _loc;
            int _numOfHit;
            bool _inTeam;

        public:
            // constructors
            Character(std::string _name, Point _loc, int _numOfHit);
            
            // A class is considered polymorphic if it has at least one virtual function
            virtual ~Character() = default;
           
            // Getters and setters
           std::string getName();
            Point getLocation();
            int getNumOfHit();
            bool setInTeam();
    
        
            // functions
            bool isAlive() const;
            double distance(const Character *element);
            void hit(int Hit);
            bool isInTeam();
            void SetLocation(Point new_loc);
            std::string print();
            
        };
}