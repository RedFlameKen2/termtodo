#include <fstream>
#include <iostream>
#include "notes.h"
#include "helpers.h"
#include "constants.h"

using std::cout;
using std::ifstream;

string * getDataArray(string data){
    string * sections = new string[DATA_SIZE];
    int focus = 0;
    for(int i = 0; i < DATA_SIZE; i++){
        while(data[focus++] != ':');

        while(data[focus] != ',' && data[focus] != '\n'){
            sections[i] += data[focus];
            focus++;
        }
    }
    return sections;
}

Note getNoteFromDB(){
    /*Note * notes = new Note[DATA_SIZE];*/
    /*for(int i = 0; i < DATA_SIZE; i++){*/
    /*    notes[i] = Note(0, "", "");*/
    /*}*/
    string rd;

    ifstream file("db");
    int count = 0;
    std::getline(file, rd);
    Note note(getDataArray(rd));
    file.close();
    return note;
};

