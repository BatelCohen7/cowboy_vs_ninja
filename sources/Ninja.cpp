#include "Ninja.hpp"
#include <stdexcept>
#include <string>

namespace ariel {

    // constructor
    Ninja::Ninja(std::string _name, Point location, int _numOfHit, int _speed) : Character(std::move(_name), location, _numOfHit), speed(_speed) {}

    // move
    void Ninja::move(Character* character) {
        if (character == nullptr) {
            throw std::invalid_argument("Other character is null!");
        } else if (character == this) {
            throw std::invalid_argument("Cant move to yourself!");
        } else if (!isAlive()) {
            throw std::runtime_error("i am dead i cant move");
        }

        Point new_location = this->getLocation();
        new_location = Point::moveTowards(new_location, character->getLocation(), speed);
        this->SetLocation(new_location);
    }

    // slash cases
    void Ninja::slash(Character* enemy) {
        if (enemy == nullptr) {
            throw std::invalid_argument("Other character is null!");
        }
        if (enemy == this) {
            throw std::runtime_error("cant shoot myself");
        }
        if (!isAlive()) {
            throw std::runtime_error("i am dead i cant shoot");
        } 
        if (!enemy->isAlive()) {
            throw std::runtime_error("no alive target");
        }
        if (distance(enemy) <= 1) {
            enemy->hit(40);
        }
    }

    int Ninja::getSpeed() {
        return this->speed;
    }

    // print
    std::string Ninja::print() {
        std::string str = "N, " +
        this->getName() + " HP: " +
        std::to_string(this->getNumOfHit()) + " location: " +
        this->getLocation().print();
        return str;
    }

}
