#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <array>

enum cellStatus {empty, player1, player2};

class GameStatus
{
    public:
        std::array<std::array<cellStatus, 3>, 3> boardStatus_;
        short int turnCount_;
        short int turnPlayer_;
        time_t startTime_;

    public:
        GameStatus();
        ~GameStatus();
};

#endif // GAMESTATUS_H
