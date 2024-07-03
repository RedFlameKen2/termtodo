#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "menu.h"
#include "helpers.h"

using std::cout;
using std::cin;

void printHelp(){
    cout << "List of options: \n";
    cout << "1) Add new Note\n";
    cout << "2) Remove a Note\n";
    cout << "3) List Notes\n";
    cout << "4) Show this menu\n";
    cout << "5) Exit Program\n";
}
void printAddHelp(){
    cout << "List of options for adding a note: \n";
    cout << "1) Set Title:\n";
    cout << "2) Set Description\n";
    cout << "3) Finish\n";
    cout << "4) Cancel\n";
}
bool mainOptionValid(int option){
    if(option <= 5 || option > 0)
        return true;
    return false;
}
bool addOptionValid(int option){
    if(option <= 4 || option > 0)
        return true;
    return false;
}
bool addOptions(int option, Note &note, vector<Note> &noteList){
    cin.get();
    switch (option) {
        case 1:
            cout << "\nEnter Title of the Note: ";
            getline(cin, note.title);
            break;
        case 2:
            cout << "\nEnter Description of the Note: ";
            getline(cin, note.desc);
            break;
        case 3:
            note.id = id_Randomizer();
            noteList.push_back(note);
            return true;
        case 4:
            return true;
    }
    return false;
}
void addMenu(vector<Note> &noteList){
    Note note;
    while(true){
        printAddHelp();
        int option;
        while(true){
            cout << "Enter option: ";
            cin >> option;
            if(addOptionValid(option))
                break;
            cout << "Invalid Option! Try Again!\n";
        }
        if(addOptions(option, note, noteList))
            break;
    }
}
void listMenu(vector<Note> &noteList){
    for(Note note : noteList){
        note.printData();
    }
}

void mainMenu(int option, vector<Note> &noteList){
    switch(option){
        case 1:
            addMenu(noteList);
            break;
        case 2:
            break;
        case 3:
            listMenu(noteList);
            break;
        case 4:
            printHelp();
            break;
        case 5:
            cout << "Program Terminating, Goodbye!";
            exit(1);
            break;
    }
}

void menu(){
    vector<Note> noteList;
    clearTerm();
    printHelp();
    while(true){
        int option;
        while(true){
            cout << "Enter option: ";
            cin >> option;
            clearTerm();
            if(mainOptionValid(option))
                break;
            cout << "Invalid Option, Try Again!\n";
        }
        mainMenu(option, noteList);
    }
}
