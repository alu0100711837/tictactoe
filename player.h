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
    private:
        std::string name_;

    public:
        inline Player(std::string name = "Player"): name_(name) {};
        virtual ~Player() = 0;

        Movement nextMovement();
        inline void printName() { std::cout<<name_<<std::endl; } ;
};

#endif // PLAYER_H
