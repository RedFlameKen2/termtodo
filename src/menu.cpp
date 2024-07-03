#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "helpers.h"
#include "todolist.h"

using std::cout;
using std::cin;

void printHelp(){
    cout << "List of options: \n";
    cout << "1) Manage lists\n";
    cout << "2) List ToDoLists\n";
    cout << "3) Show this menu\n";
    cout << "4) Exit Program\n";
}
bool mainOptionValid(int option){
    if(option <= 5 || option > 1)
        return true;
    return false;
}
void listMenu(vector<Note> notes){
    for(Note note : notes){
        note.printData();
    }
}

void mainMenu(int option, vector<ToDoList> todoLists, int &curList){
    switch(option){
        case 1:
            listManager(todoLists, curList);
            break;
        case 2:
            break;
        case 3:
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
    vector<ToDoList> todoLists;
    int curList = 1;
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
        mainMenu(option, todoLists, curList);
    }
}
