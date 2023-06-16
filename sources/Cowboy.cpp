#include "Cowboy.hpp"
#include "iostream"

namespace ariel {

    // constructor
    Cowboy::Cowboy(std::string name, Point location):Character(name, location, 110), bullets(6) {}

    
    // shoot cases
    void Cowboy::shoot(Character * enemy){
        if(enemy == this){
            throw std::runtime_error("cant shoot myself");
        }
        if(!isAlive()){
            throw std::runtime_error("i am dead i cant shoot");
        } 
        if( !enemy->isAlive() ){
            throw std::runtime_error("Cannot shoot a dead character!");
        }
        if (enemy == nullptr){
		    throw invalid_argument("enemy character is null!");
        }
        if(bullets <= 0){
            return;
        }
        else
            bullets -= 1;
            enemy->hit(10);
    }
    
    bool Cowboy::hasboolets(){
        return bullets > 0;
    }

    void Cowboy::reload(){
        if(!isAlive()){
            throw std::runtime_error("Cannot reload while dead!");
        }
        this->bullets = 6;
    }
    
    string Cowboy::print() {
        if (!isAlive()){
		    return "C (" + getName() + "), Location: " + getLocation().print();
        }
       std::string str = "C, " + this->getName() + " HP: " + std::to_string(this->getNumOfHit()) + " location: " + this->getLocation().print();

        return str;
    }
    
}