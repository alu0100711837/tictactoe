#include "gamestatus.h"

GameStatus::GameStatus():
    turnCount_(0),
    turnPlayer_(1)
{
    for (int i = 0; i < boardStatus_.size(); i++)
    {
        for (int j = 0; j < boardStatus_[i].size(); j++)
            boardStatus_[i][j] = cellStatus::empty;
    }
}

GameStatus::~GameStatus()
{

}
