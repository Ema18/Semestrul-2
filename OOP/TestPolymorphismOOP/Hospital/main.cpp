#include <iostream>
#include "Console.h"

int main()
{
    Controller c;
    Console cons{ c };

    cons.run();
    system("pause");
    return 0;
}