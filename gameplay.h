#ifndef GAMEPLAY_H
#define GAMEPLAY_H


#include <memory>
#include "player.h"
#include "humanplayer.h"
#include "iaplayer.h"
#include "gamestatus.h"
#include "scoreboard.h"


class Gameplay
{
    private:
        Player* p1 = new HumanPlayer;
        Player* p2 = new IAPlayer;
        GameStatus gameStatus_;

    public:
        Gameplay();
        ~Gameplay();

        void printBoard();
        void nextMovement();
        bool isValidMovement(Movement);
        void makeMovement(Movement, cellStatus);

};

#endif // GAMEPLAY_H
