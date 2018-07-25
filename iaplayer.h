#ifndef IAPLAYER_H
#define IAPLAYER_H

#include <string>
#include <random>
#include "player.h"

class IAPlayer : public Player
{
    public:
        inline IAPlayer(std::string name = "Computer"): Player(name) {}
        inline ~IAPlayer() {}

        Movement nextMovement();
};

#endif // IAPLAYER_H
