#include <QCoreApplication>

#include <iostream>
#include "gameplay.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Hola!" <<std::endl;

    Gameplay A;
    //A.start();


    return a.exec();


}

