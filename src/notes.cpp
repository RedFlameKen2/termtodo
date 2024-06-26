#include <fstream>
#include <iostream>
#include "notes.h"
#include "helpers.h"

using std::cout;
using std::cin;
using std::ifstream;

Note * getNotesFromDB(){
    ifstream file("db");
    string rd = "", temp = "";
    Note * notes = new Note[5];
    while(std::getline(file, temp)){
        rd += temp + "\n";
    }
    file.close();
};
