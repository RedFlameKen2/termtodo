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
    if(c == ',' && c == '\n')
        return true;
    return false;
}

string getSection(string data, int &focus){
    string section;
    while(data[++focus] != ',')
        section += data[focus];
    return section;
}

string * getDataArray(string data){
    string * sections = new string[DATA_SIZE];
    int focus = 0;
    for(int i = 0; i < DATA_SIZE; i++){
        sections[i] = getSection(data, focus);
    }
    return sections;
}

vector<CheckItem> getChecklistData(string data){
    vector<CheckItem> checkItems;
    int focus = 0;
    while(data[focus++] != '{');
    while(data[focus] != '}'){
        while(data[focus] != '['){
            focus++;
        }
        string title;
        bool checked = false;
        while(data[++focus] != ',')
            title += data[focus];
        if(data[++focus] == 't')
            checked = true;
        while(data[++focus] != ']');
        checkItems.push_back(CheckItem(title, checked));
        focus++;
    }
    return checkItems;
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
    Note note(getDataArray(rd), getChecklistData(rd));
    file.close();
    return note;
};

