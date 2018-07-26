#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

struct Movement {
    int i_;
    int j_;
};


class Player
{
    protected:
        std::string name_;

    public:
        inline Player(std::string name = "Player"): name_(name) {}
        virtual ~Player() = 0;

        virtual Movement nextMovement() = 0;
};

#endif // PLAYER_H
