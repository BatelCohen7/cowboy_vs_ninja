#include "iostream"
#include "Team.hpp"
#include <limits>


namespace ariel {
    // Constructor for Team class, initializes the leader and adds it to the members vector
    Team::Team(Character* leader): leader(leader) {
        this->members.reserve(10);
        if(leader->isInTeam()) {
            throw std::runtime_error("Leader already in a team");
        }
        leader->setInTeam();
        members.push_back(leader);
    }

    // Add a character to the team
    void Team::add(Character* character){
        if(this->members.size() >= 10)
            throw std::runtime_error("Team cannot exceed 10 members");
        if(character->isInTeam())
            throw std::runtime_error("Character already in a team");
        character->setInTeam();
        members.push_back(character);
    }

    // Perform an attack on an opponent team
    void Team::attack(Team* opponent) {
        if(opponent == nullptr)
            throw std::invalid_argument("Opponent must be specified");
        if(!opponent->stillAlive())
            throw std::runtime_error("Opponent team is already defeated");

        this->leader = closestToLeader(this->members); // Change the team's leader based on the closest living member to the current captain
        CowboysAttack(*opponent);    // Perform attacks by Cowboys in the team
        NinjaAttack(*opponent);      // Perform attacks by Ninjas in the team
    }

    // Display the characters in the team
    void Team::print(){
        for(auto* character:this->members) {
            cout << character->print() << endl;
        }
    }

    // Check if the team is alive (has any living members)
    int Team::stillAlive() {
        int aliveCount = 0;
        for (auto character : this->members) {
            if(character->isAlive())
                aliveCount++;
        }
        return aliveCount;
    }

    // Get the leader of the team
    Character* Team::getLeader() {
        return this->leader;
    }

     // Get the members of the team
    vector<Character*> Team::getMembers() const {
        return this->members;
    }

     // Destructor for the Team class, frees the memory allocated to the character members
    Team::~Team() {
        for (Character* member : members) {
            delete member;
        }
        members.clear();
    }

    // Change the leader of the team to the closest living member to the current captain
    void Team::changeLeader(){
        double minDistance = std::numeric_limits<double>::max();
        for (Character* member : members) {
            if(member->isAlive() && leader->distance(member) < minDistance){
                minDistance = leader->distance(member);
                leader = member;
            }
        }
    }

    // Perform attacks by Cowboys in the team
    void Team::CowboysAttack(const Team& opponent) {
        for(auto character : this->members){
            if(!character->isAlive()) continue;
            Character* target = closestToLeader(opponent.members);
            if(target == nullptr) return;
            if(auto* cowboy = dynamic_cast<Cowboy*>(character)) {
                if(!target->isAlive()) target = closestToLeader(opponent.members);
                if(target == nullptr) return;
                if(cowboy->hasboolets())
                    cowboy->shoot(target);
                else
                    cowboy->reload();
            }
        }
    }

    // Perform attacks by Ninjas in the team
    void Team::NinjaAttack(const Team& opponent) {
        for(auto* character : this->members){
            if(!character->isAlive()) continue;
            if(auto* ninja = dynamic_cast<Ninja*>(character)) {
                Character* target = closestToLeader(opponent.members);
                if(target == nullptr) return;
                if(ninja->distance(target) <= 1)
                    ninja->slash(target);
                else
                    ninja->move(target);
            }
        }
    }

    // 
    Character* Team::closestToLeader(const vector<Character*> &opponent) {
        double minDistance = std::numeric_limits<double>::max();
        Character* nearestEnemy = nullptr;
        for (Character* enemy : opponent) {
            if(enemy->isAlive()){
                double distance = enemy->distance(this->leader);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestEnemy = enemy;
                }
            }
        }
        return nearestEnemy;
    }
}
