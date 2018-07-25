#include "scoreboard.h"

ScoreBoard::ScoreBoard()
{
    for (auto i : scores_)
        i = 0;
}


void ScoreBoard::incrementCounter(int result)
{
    scores_[result]++;
}

void ScoreBoard::print()
{
    std::cout <<"Player 1: " << scores_[gameResult::Player1] <<std::endl;
    std::cout <<"Player 2: " << scores_[gameResult::Player2] <<std::endl;
    std::cout <<"Raw: " << scores_[gameResult::raw] <<std::endl;
}
