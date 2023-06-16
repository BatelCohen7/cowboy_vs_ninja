#include "SmartTeam.hpp"
#include <limits>

namespace ariel {
     // Constructor for SmartTeam class, calls the base class constructor to initialize the leader
    SmartTeam::SmartTeam(Character* character): Team(character) {}

    // Find the closest enemy character to the given ninja
    Character* ariel::SmartTeam::findNinjaTarget(const std::vector<Character*>& team, Ninja* ninja) {
        double minDistance = std::numeric_limits<double>::max();
        Character* closestEnemy = nullptr;
        for (Character* enemy : team) {
            if (enemy->isAlive()) {
                double distance = enemy->distance(ninja);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestEnemy = enemy;
                }
            }
        }
        return closestEnemy;
    }

    // Find a target character for the cowboy in the enemy team
   Character* ariel::SmartTeam::findCowboyTarget(Team* enemy) {
        for(auto* target : enemy->getMembers()) {
            if(auto* cowboy = dynamic_cast<Cowboy*>(target)) {
                if(cowboy->isAlive())
                    return target;
            }
        }
        for(auto* target : enemy->getMembers()) {
            if(target->isAlive()) {
                return target;
            }
        }
        return nullptr;
    }

    // Perform an attack on the enemy team using smart tactics
    void SmartTeam::attack(Team* enemy) {
        if(enemy == nullptr) {
            throw std::invalid_argument("Enemy team not specified");
        }

        for(auto* character : this->getMembers()) {
            if(!character->isAlive())
                continue;

            if(auto* cowboy = dynamic_cast<Cowboy*>(character)) {
                Character* target = findCowboyTarget(enemy);
                if(target == nullptr) {
                    return;
                }
                if(cowboy->hasboolets()) {
                    cowboy->shoot(target);
                }
                else {
                    cowboy->reload();
                }
            }
            else {
                auto* ninja = dynamic_cast<Ninja*>(character);
                Character* target = findNinjaTarget(enemy->getMembers(), ninja);
                if(ninja->distance(target) <= 1)
                    ninja->slash(target);
                else
                    ninja->move(target);
            }
        }
    }
}
