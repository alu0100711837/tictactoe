#include "gameplay.h"

Gameplay::Gameplay(gameMode mode)
{
    if (mode == gameMode::humanVsHuman)
    {
        for (auto &player : players_)
            player = std::unique_ptr<Player>(new(HumanPlayer));
    }
    if (mode == gameMode::cpuVsCpu)
    {
        for (auto &player : players_)
            player = std::unique_ptr<Player>(new(IAPlayer));
    }
    if (mode == gameMode::humanVsCpu)
    {
        players_[0] = std::unique_ptr<Player>(new(HumanPlayer));
        players_[1] = std::unique_ptr<Player>(new(IAPlayer));
    }
}

Gameplay::~Gameplay()
{

}


void Gameplay::mainLoop()
{
    char exit = '1';
    do
    {
        start();
        std::cout << "Repetir?: " <<std::endl;
        std::cin >> exit;
    } while(exit != '0');
}


void Gameplay::start()
{
    gameStatus_.reset();
    gameLoop();
    scoreBoard_.print();
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
            scoreBoard_.print();
        }
    } while (!gameFinish());
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
    gameStatus_.boardStatus_[mov.i_][mov.j_] = player;
}


void Gameplay::printBoard()
{
    std::cout << "Turnos: " << gameStatus_.turnCount_ << std::endl;
    for ( auto &i : gameStatus_.boardStatus_)
    {
        for (auto &j : i)
            std::cout << static_cast<int>(j) << " ";
        std::cout<<std::endl;
    }
}


bool Gameplay::gameFinish()
{
    if (checkWinner())
    {
        gameStatus_.toggleTurnPlayer();

        scoreBoard_.incrementCounter(static_cast<gameResult>(gameStatus_.turnPlayer_));
        return true;
    }
    if (gameRaw())
    {
        scoreBoard_.incrementCounter(gameResult::raw);
        return true;
    }
    return false;
}


int Gameplay::checkWinner()
{
    /*
     * Método no terminado. De momento con las filas es suficiente para centrarme
     * en otros aspectos más importantes.
     * NOTA: cambiar el bucle por notación de C++ moderno.
     * */
    //Chequear filas
    for (int i = 0; i < gameStatus_.boardStatus_.size(); i++)
    {
        if (gameStatus_.boardStatus_[i][0] != cellStatus::empty)
        {
            if (gameStatus_.boardStatus_[i][0] == gameStatus_.boardStatus_[i][1] &&
                gameStatus_.boardStatus_[i][1] == gameStatus_.boardStatus_[i][2])
                    return true;
        }
    }
    //Chequear columnas
    //Chequear diagonal
    //Chequear diagonal secundaria

    return false;
}
