#include "iaplayer.h"

Movement IAPlayer::nextMovement()
{
    //IA CODE HERE
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 2);

    int i, j;

    i = distribution(generator);
    j = distribution(generator);

    Movement mov;
    mov.i_ = i;
    mov.j_ = j;

    std::cout << i << " " << j <<std::endl;
    return mov;

}
