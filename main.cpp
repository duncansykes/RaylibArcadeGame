#include <iostream>
#include "app.h"
#include <fstream>

void saveToFile( const char* path, char name, float score){

    std::ofstream outFile;
    outFile.open(path, std::ios_base::app);
    outFile << name << " : " << score << "\n";
    outFile.close();

}

int main() {

    app newApp(250,500,60.0f, "TS");

    newApp.run();

    system("cls");
    std::cout<< "\n";
    char name = (char) "";
    std::cout << "Please enter 1 character for your name: ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "Total Score --  " << name << " : " << newApp.SCORE << std::endl;
    saveToFile("scores.txt", name, newApp.SCORE);
    std::cout << "Saved to scores.txt" << std::endl;

    system("pause");
    return 0;
}
