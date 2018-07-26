#include "iaplayer.h"

/*
 * He implementado el jugador IA como un jugador normal al que el gameplay también debe validar.
 * Cuando pasé el tablero por referencia para que la IA escribiese directamente me di cuenta de que
 * no sabría si tenía que escribir un 1 o un 2 porque la IA no sabe qué jugador es. Podría añadir
 * un atributo player_id o que gameplay pase un parámetro que diga qué jugador eres y por tanto qué
 * debes escribir en el tablero. Pero me pareció que de esta forma tocaba el resto del código lo menos
 * posible.
 * */

Movement IAPlayer::nextMovement()
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 2); //Qué pasada!

    int i, j;

    i = distribution(generator);
    j = distribution(generator);

    Movement mov;
    mov.i_ = i;
    mov.j_ = j;

    std::cout << "IA juega: " << i << ", " << j <<std::endl;
    return mov;
}
