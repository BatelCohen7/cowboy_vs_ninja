#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <stdexcept>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

using namespace std;

namespace ariel {

    class Team {
    private:
        Character* leader;
        std::vector<Character*> members;

    public:
        Team(Character* leader);
        ~Team();

        void changeLeader();
        void CowboysAttack(const Team& opponent);
        void NinjaAttack(const Team& opponent);
        Character* closestToLeader(const std::vector<Character*> &opponent);
        void add(Character* character);
        void attack(Team* opponent);
        void print();

        int stillAlive();
        Character* getLeader();
        std::vector<Character*> getMembers() const;
    };

}  // namespace ariel

#endif  // TEAM_H
