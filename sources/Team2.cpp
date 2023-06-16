#include "Team2.hpp"

namespace ariel {

    // Constructor for Team2 class, calls the base class constructor to initialize the leader
    Team2::Team2(Character* newCharacter):Team(newCharacter) {}

    // Perform an attack on an opponent team
    void Team2::attack(Team* opponent){
        if(opponent == nullptr){
            throw  std::invalid_argument("Opponent team not provided");
        }
        this->changeLeader(); // Change the team's captain based on the closest living member to the current captain

        for(auto* character : this->getMembers()){
            if(!character->isAlive())
                continue;
            Character* target = closestToLeader(opponent->getMembers());
            if(target == nullptr) return;
            if(auto* cowboy = dynamic_cast<Cowboy*>(character)){
                if(cowboy->hasboolets()){
                    cowboy->shoot(target);
                }
                else{
                    cowboy->reload();
                }
            }
            else{
                auto* ninja = dynamic_cast<Ninja*>(character);
                if(ninja->distance(target) <= 1)
                    ninja->slash(target);
                else
                    ninja->move(target);
            }
        }
    }

    // Display the characters in the team
    void Team2::display(){
        for(auto* character: this->getMembers()){
            cout << character->print() << endl;
        }
    }
}
