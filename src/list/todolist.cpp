#include <iostream>
#include "../helpers.h"
#include "../menus/note/addmenu.h"

void printMgrHelp(){
    cout << "Here is a list of options for managing your lists: \n";
    cout << "1) Change current list\n";
    cout << "2) Display Notes in this list\n"; 
    cout << "3) Add a note to List\n";
    cout << "4) Remove a note from list\n";
    cout << "5) Manage a note in the list\n";
    cout << "6) Display notes in all lists\n";
    cout << "7) Back\n";
    cout << "8) Exit the program\n";
}

void changeCurList(int &curList, int listSize){
    int input;
    while(true){
        input = promptInt("\nSelect a list number: ");
        clearTerm();
        if(input <= listSize || input > 0)
            break;
        cout << "Not an existing list, Try Again!\n";
    }
    curList = input;
    cout << "List Successfully Changed!";
}

bool listMgrOpts(int option, vector<ToDoList> &todoLists, int &curList){
    switch(option){
        case 1:
            changeCurList(curList, todoLists.size());
            break;
        case 2:
            todoLists[curList-1].printNotes();
            break;
        case 3:
            addMenu(todoLists[curList-1]);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            return true;
        case 8:
            cout << "Program Terminating, Goodbye!";
            exit(1);
            break;
    }
    return false;
}
void listManager(vector<ToDoList> &todoLists, int &curList){
    int option = 0;
    while(true){
        printMgrHelp();
        while(true){
            cout << "Current List: " << curList << "\n";
            option = promptInt("Enter an option: ");
            clearTerm();
            if(option <= 8 || option > 1)
                break;
            cout << "Invalid Option!, try again!\n";
        }
        if(listMgrOpts(option, todoLists, curList))
            break;
    }
}

