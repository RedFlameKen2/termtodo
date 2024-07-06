#include "checklistmenu.h"

bool checklistOptionValid(int option){
    if(option <= 4 || option > 1)
        return true;
    return false;
}
void printChecklistHelp(){
    cout << "Here are the options for managing the checklist: ";
    cout << "1) List Checklist Items\n";
    cout << "2) Add Checklist Item\n";
    cout << "3) Remove Checklist Item\n";
    cout << "4) Back\n";
}

bool checklistOptions(int option, Note note){
    switch(option){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
    return false;
}
void checklistMenu(Note note){
    while(true){
        printChecklistHelp();
        int option;
        while(true){
            cout << "Enter option: ";
            cin >> option;
            clearTerm();
            if(checklistOptionValid(option))
                break;
            cout << "Invalid Option! Try Again!\n";
        }
        if(checklistOptions(option, note))
            break;
    }
}
