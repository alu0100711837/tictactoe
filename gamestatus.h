#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <array>

enum class cellStatus {empty, player1, player2};

class GameStatus
{
    public:
        std::array<std::array<cellStatus, 3>, 3> boardStatus_;
        int turnCount_;
        int turnPlayer_;

    public:
        inline GameStatus() { initialize(); }
        ~GameStatus();

        void initialize();
        void reset();
        inline void toggleTurnPlayer() { turnPlayer_ = turnPlayer_ == 1? 2: 1; }
};

#endif // GAMESTATUS_H
