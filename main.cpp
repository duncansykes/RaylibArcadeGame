#include <iostream>
#include "app.h"


int main() {

    app newApp(250,500,60.0f, "TOWER SWORD PROTOTYPE");

    newApp.run();


    std::cout << "Program ended" << std::endl;
    return 0;
}
