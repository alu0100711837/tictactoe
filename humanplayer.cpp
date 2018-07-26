#include "humanplayer.h"

Movement HumanPlayer::nextMovement()
{
    Movement mov;
    char i, j;
    std::cout << "Fila: " , std::cin >> i;
    std::cout << "Columna: ", std::cin >> j;

    mov.i_ = i - '0';
    mov.j_ = j - '0';
    return mov;
}

