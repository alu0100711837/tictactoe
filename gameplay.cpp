#include "gameplay.h"

Gameplay::Gameplay()
{
    for (auto &player : players_)
        player = std::unique_ptr<Player>(new(HumanPlayer));
}

Gameplay::~Gameplay()
{

}


void Gameplay::printBoard()
{
    std::cout << "Turnos: " << gameStatus_.turnCount_ << std::endl;
    for ( auto &i : gameStatus_.boardStatus_)
    {
        for (auto &j : i)
            std::cout << j << " ";
        std::cout<<std::endl;
    }
}


bool Gameplay::playTurn(int turnPlayer)
{
    std::cout << "Mueve player " << turnPlayer << ":" <<std::endl;
    Movement mov = players_[turnPlayer - 1]->nextMovement();
    if (isValidMovement(mov))
    {
        makeMovement(mov, cellStatus(turnPlayer));
        return true;
    }
    return false;
}

bool Gameplay::isValidMovement(Movement mov)
{
    if ((mov.i_ <= 2) && (mov.j_ <= 2))
    {
        if (gameStatus_.boardStatus_[mov.i_][mov.j_] == cellStatus::empty)
            return true;
    }
    return false;
}

void Gameplay::makeMovement(Movement mov, cellStatus player)
{
    std::cout<<player<<std::endl;
    gameStatus_.boardStatus_[mov.i_][mov.j_] = player;
}

void Gameplay::gameLoop()
{
    do
    {
        if(playTurn(gameStatus_.turnPlayer_))
        {
            gameStatus_.toggleTurnPlayer();
            gameStatus_.turnCount_++;
            printBoard();
        }
    } while ( (!(gameFinish())) && (gameStatus_.turnCount_< 9) );
}

bool Gameplay::gameFinish()
{
    //CHECK BOARD
    //Check by row
    for (int i = 0; i < gameStatus_.boardStatus_.size(); i++)
    {
        if (gameStatus_.boardStatus_[i][0] != 0)
        {
            if (gameStatus_.boardStatus_[i][0] == gameStatus_.boardStatus_[i][1] &&
                gameStatus_.boardStatus_[i][1] == gameStatus_.boardStatus_[i][2])
                    return true;
        }
    }
    //check by column

    //check diagonal

    //check secondary diagonal

    return false;
}

bool Gameplay::gameRaw()
{
    if (gameStatus_.turnCount_ < 9)
    {
        gameStatus_.turnCount_++;
        return false;
    }
    else
    {

        return true;
    }
}
