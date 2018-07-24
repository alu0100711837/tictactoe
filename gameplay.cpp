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
            printBoard();
        }
    } while (!(gameFinish()));
}

bool Gameplay::gameFinish()
{
    //CHECK BOARD


    return false;
}
