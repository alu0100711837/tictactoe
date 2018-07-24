#include "scoreboard.h"

ScoreBoard::ScoreBoard()
{
    for (auto i : scores_)
        i = 0;
}


void ScoreBoard::incrementCounter(gameResult result)
{
    scores_[result]++;
}
