#ifndef IAPLAYER_H
#define IAPLAYER_H

#include <string>
#include "player.h"

class IAPlayer : public Player
{
    public:
        inline IAPlayer(std::string name = "Computer"): Player(name) {};
        inline ~IAPlayer() {};
};

#endif // IAPLAYER_H
