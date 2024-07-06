#include "addmenu.h"
#include "../../helpers.h"

/*void printAddHelp(){*/
/*    cout << "List of options for adding a note: \n";*/
/*    cout << "1) Set Title:\n";*/
/*    cout << "2) Set Description\n";*/
/*    cout << "3) Manage Checklist\n";*/
/*    cout << "4) Finish\n";*/
/*    cout << "5) Cancel\n";*/
/*}*/
/*bool addOptions(int option, Note &note, ToDoList &todoList){*/
/*    cin.get();*/
/*    switch (option) {*/
/*        case 1:*/
/*            cout << "\nEnter Title of the Note: ";*/
/*            getline(cin, note.title);*/
/*            break;*/
/*        case 2:*/
/*            cout << "\nEnter Description of the Note: ";*/
/*            getline(cin, note.desc);*/
/*            break;*/
/*        case 3:*/
/*            break;*/
/*        case 4:*/
/*            note.id = id_Randomizer();*/
/*            note.listName = todoList.getTitle();*/
/*            note.printData();*/
/*            todoList.addNote(note);*/
/*            note.writeDataToDb();*/
/*            return true;*/
/*        case 5:*/
/*            return true;*/
/*    }*/
/*    return false;*/
/*}*/
/*void addMenu(ToDoList &todoList){*/
/*    Note note;*/
/*    while(true){*/
/*        printAddHelp();*/
/*        int option;*/
/*        while(true){*/
/*            cout << "Enter option: ";*/
/*            cin >> option;*/
/*            clearTerm();*/
/*            if(optionValid(option, 5))*/
/*                break;*/
/*            cout << "Invalid Option! Try Again!\n";*/
/*        }*/
/*        if(addOptions(option, note, todoList))*/
/*            break;*/
/*    }*/
/*}*/
