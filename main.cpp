#include <iostream>
#include "app.h"


int main() {

    app newApp(1000,500,60.0f, "newApp");

    newApp.run();


    std::cout << "Program ended" << std::endl;
    return 0;
}
