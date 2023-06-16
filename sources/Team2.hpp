#ifndef TEAM2_H
#define TEAM2_H

#include <vector>
#include <stdexcept>
#include "Team.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel {

    class Team2 : public Team {
    public:
        Team2(Character* newCharacter);
        void attack(Team* opponent);
        void display();
    };

}  // namespace ariel

#endif  // TEAM2_H
