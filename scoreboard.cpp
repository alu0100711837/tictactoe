#include "scoreboard.h"

ScoreBoard::ScoreBoard()
{
    for (auto &i : scores_)
        i = 0;
}


void ScoreBoard::print()
{
    std::cout <<"Player 1: " << scores_[static_cast<int>(gameResult::player1)] <<std::endl;
    std::cout <<"Player 2: " << scores_[static_cast<int>(gameResult::player2)] <<std::endl;
    std::cout <<"Raw: " << scores_[static_cast<int>(gameResult::raw)] <<std::endl;
}
