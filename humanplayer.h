#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <string>
#include "player.h"

class HumanPlayer : public Player
{
    public:
        inline HumanPlayer(std::string name = "Human"): Player(name) {}
        inline ~HumanPlayer() {}
        Movement nextMovement();
};

#endif // HUMANPLAYER_H
