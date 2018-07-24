#include "player.h"


Player::~Player()
{

}

Movement Player::nextMovement()
{
    Movement mov;
    std::cin >> mov.i_;
    std::cin >> mov.j_;
    return mov;
}
