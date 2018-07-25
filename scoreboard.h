#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <array>
#include <iostream>

enum gameResult {raw, Player1, Player2};

class ScoreBoard
{
    private:
        std::array<int, 3> scores_;

    public:
        ScoreBoard();
        inline ~ScoreBoard() {}

        void incrementCounter(int);
        void print();
};

#endif // SCOREBOARD_H
