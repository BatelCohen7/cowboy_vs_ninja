#ifndef SMARTTEAM_H
#define SMARTTEAM_H

#include <vector>
#include "Team.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel {

    class SmartTeam : public virtual Team{
    private:
       vector<Character*> Characters; 
    public:
        SmartTeam(Character* character);
        void attack(Team* enemy);

    Character* findNinjaTarget(const std::vector<Character*>& team, Ninja* ninja);
    Character* findCowboyTarget(Team* enemy);
    };

}  // namespace ariel

#endif  // SMARTTEAM_H
