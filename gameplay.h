#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <memory>
#include "player.h"
#include "humanplayer.h"
#include "iaplayer.h"
#include "gamestatus.h"
#include "scoreboard.h"

enum class gameMode {humanVsHuman, humanVsCpu, cpuVsCpu};

class Gameplay
{
    private:
        std::array<std::unique_ptr<Player>, 2> players_;
        GameStatus gameStatus_;
        ScoreBoard scoreBoard_;

    public:
        Gameplay(gameMode = gameMode::humanVsCpu);
        ~Gameplay();

        void mainLoop();

    private:
        void start();
        void gameLoop();

        bool playTurn(int);
        bool isValidMovement(Movement);
        void makeMovement(Movement, cellStatus);
        void printBoard();

        bool gameFinish();
        int checkWinner();
        inline bool gameRaw() { return (gameStatus_.turnCount_ > 8); }

};

#endif // GAMEPLAY_H
