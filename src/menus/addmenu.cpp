#include "addmenu.h"

void printAddHelp(){
    cout << "List of options for adding a note: \n";
    cout << "1) Set Title:\n";
    cout << "2) Set Description\n";
    cout << "3) Finish\n";
    cout << "4) Cancel\n";
}
Note getNoteFromDB(){
    string rd;

    ifstream file("db");
    int count = 0;
    std::getline(file, rd);
    Note note(getDataArray(rd), getChecklistData(rd));
    file.close();
    return note;
};

bool addOptionValid(int option){
    if(option <= 4 || option > 1)
        return true;
    return false;
}
bool addOptions(int option, Note &note, vector<Note> * notes){
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
            notes->push_back(note);
            note.writeDataToDb();
            return true;
        case 4:
            return true;
    }
    return false;
}
void addMenu(vector<Note> * notes){
    Note note;
    while(true){
        printAddHelp();
        int option;
        while(true){
            cout << "Enter option: ";
            cin >> option;
            clearTerm();
            if(addOptionValid(option))
                break;
            cout << "Invalid Option! Try Again!\n";
        }
        if(addOptions(option, note, notes))
            break;
    }
}
