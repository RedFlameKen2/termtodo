#include "addcheckmenu.h"

void printAddcheckHelp(){
    cout << "Here are the options for adding a checklist Item";
    cout << "1) Set the Title\n";
    cout << "2) Toggle Checked (Default: False)\n";
    cout << "3) Finish\n";
    cout << "4) Cancel\n";
}

bool addCheckitemOptions(int option, CheckItem checkItem, Note note){
    switch(option){
        case 1:
            checkItem.title = promptString("Enter Title of CheckItem: ");
            break;
        case 2:
            checkItem.checked = !checkItem.checked;
            break;
        case 3:
            note.getChecklist().add(checkItem);
            return true;
        case 4:
            return true;
    }
    return false;
}

void addCheckMenu(Note note){
    CheckItem checkItem;
    checkItem.checked = false;
    while(true){
        printAddcheckHelp();
        int option;
        while(true){
            cout << "Enter option: ";
            cin >> option;
            clearTerm();
            if(optionValid(option, 4))
                break;
            cout << "Invalid Option! Try Again!\n";
        }
        if(addCheckitemOptions(option, checkItem, note))
            break;
    }
}
