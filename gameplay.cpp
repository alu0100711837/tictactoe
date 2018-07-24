#include "gameplay.h"

Gameplay::Gameplay()
{
    p1->printName();
    p2->printName();
}

Gameplay::~Gameplay()
{

}

void Gameplay::printBoard()
{
    for (int i = 0; i < gameStatus_.boardStatus_.size(); i++)
    {
        for (int j = 0; j < gameStatus_.boardStatus_[i].size(); j++)
            std::cout<< gameStatus_.boardStatus_[i][j] << " ";
        std::cout<<std::endl;
    }
}

void Gameplay::nextMovement()
{
    Movement mov;
    if (gameStatus_.turnPlayer_ == 1)
    {
        do
        {
            std::cout << "Mueve player 1:" <<std::endl;
            mov = p1->nextMovement();
        } while (!(isValidMovement(mov)));
            makeMovement(mov, cellStatus::player1);
        gameStatus_.turnPlayer_ = 2;
    }
    else
    {
        do
        {
            std::cout << "Mueve player 2:" <<std::endl;
            mov = p2->nextMovement();
        } while (!(isValidMovement(mov)));
            makeMovement(mov, cellStatus::player2);
     }
        gameStatus_.turnPlayer_ = 1;
        printBoard();
}

bool Gameplay::isValidMovement(Movement mov)
{
    if ((mov.i_ <= 2) && (mov.j_ <= 2))
    {
        if (gameStatus_.boardStatus_[mov.i_][mov.j_] != cellStatus::empty);
            return true;
    }
    return false;
}

void Gameplay::makeMovement(Movement mov, cellStatus player)
{
    std::cout<<player<<std::endl;
    gameStatus_.boardStatus_[mov.i_][mov.j_] = player;
}
