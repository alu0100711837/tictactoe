#include "humanplayer.h"

Movement HumanPlayer::nextMovement()
{
    Movement mov;
    std::cin >> mov.i_;
    std::cin >> mov.j_;
    return mov;
}

