#include "gamestatus.h"

GameStatus::GameStatus():
    turnCount_(0),
    turnPlayer_(1)
{
    for ( auto &i : boardStatus_)
    {
        for (auto &j : i)
            j = cellStatus::empty;
    }
}

GameStatus::~GameStatus()
{

}
