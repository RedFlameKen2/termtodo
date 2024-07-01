#include <fstream>
#include <iostream>
#include <vector>
#include "notes.h"
#include "helpers.h"
#include "constants.h"

using std::cout;
using std::ifstream;
using std::vector;

bool isFormatSeparator(char c){
    if(c == ',' && c == '\n' && c == '[' && c == ']' && c == '{' && c == '}')
        return true;
    return false;
}
vector<string> getDataArray(string data){
    vector <string> sections;
    int focus = 0;
    for(int i = 0; i < DATA_SIZE; i++){
        while(data[focus++] != ':');
        while(isFormatSeparator(data[focus])){
            if(data[focus] == '{'){
                while(data[++focus] != '[');
                while(data[++focus] != ']'){
                    while(data[++focus] != ':');
                    while(data[++focus] != ','){
                        sections[i] += data[focus];
                    }
                }
            }
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

