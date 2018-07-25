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
        std::array<std::unique_ptr<Player>, 2> players_;
        GameStatus gameStatus_;

    public:
        Gameplay();
        ~Gameplay();

        void printBoard();
        bool playTurn(int);
        bool isValidMovement(Movement);
        void makeMovement(Movement, cellStatus);
        void gameLoop();
        bool gameFinish();
        bool gameRaw();

};

#endif // GAMEPLAY_H
