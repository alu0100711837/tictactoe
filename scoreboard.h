#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <array>
#include <iostream>

enum class gameResult {raw, player1, player2};

class ScoreBoard
{
    private:
        std::array<int, 3> scores_; //{ empates, puntos de player 1, puntos de player 2 }

    public:
        ScoreBoard();
        inline ~ScoreBoard() {}

        inline void incrementCounter(gameResult result) { scores_[static_cast<int>(result)]++; }
        void print();
};

#endif // SCOREBOARD_H
