#include "iostream"
#include "Point.hpp"
#include "Character.hpp"


namespace ariel{
    // constructor
    Character::Character(string _name, Point _loc , int _numOfHit)
        : _name(_name), _loc(_loc), _numOfHit(_numOfHit), _inTeam(false) {}


    // Getters and seters
    string Character::getName(){
        return this->_name;
    }

    Point Character::getLocation(){
        return this->_loc;
    }

    int Character::getNumOfHit(){
        return this->_numOfHit;
    }

    bool Character::setInTeam(){
        this->_inTeam = true;
        return _inTeam;
    }


    // functions
    bool Character::isAlive() const{
        return this->_numOfHit > 0;
    }
    
    double Character::distance(const Character* another) {
    return this->_loc.distance(another->_loc);
    } 
    
    void Character::hit(int damage){
        if(damage<0){
            throw std::invalid_argument("error");
        }
        this->_numOfHit -= damage;
    }

    bool Character::isInTeam(){
        return _inTeam;
    }

    void Character::SetLocation(Point new_loc){
        this->_loc = new_loc;
    }

    // print
    string Character::print(){
    if(this->_numOfHit > 0){
        return "name: " + this->_name + " Hit: " + to_string(this->_numOfHit) + " location: " + this->_loc.print();
    } 
    return "name: (" + this->_name + ")";
    }
}