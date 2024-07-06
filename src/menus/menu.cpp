#include "menu.h"

void listMenu(vector<Note> notes){
    for(Note note : notes){
        note.printData();
    }
}

