#include "../checklist/checklistmenu.h"

class AddNoteMenu : public Menu {
private:
    Note note;
public:
    AddNoteMenu(){
        maxOpts = 5;
        menu();
    }
    AddNoteMenu(vector<ToDoList> * todoLists, int * curList) {
        maxOpts = 5;
        this->curList = curList;
        this->todoLists = todoLists;
        menu();
    }
    void printHelp(){
        cout << "List of options for adding a note: \n";
        cout << "1) Set Title:\n";
        cout << "2) Set Description\n";
        cout << "3) Manage Checklist\n";
        cout << "4) Finish\n";
        cout << "5) Cancel\n";
    }
    bool options(int option){
        cin.get();
        switch (option) {
            case 1:
                note.title = promptString("\nEnter Title of the Note: ");
                break;
            case 2:
                note.desc = promptString("\nEnter Description of the Note: ");
                break;
            case 3:
                {
                    ChecklistMenu checklistMenu(&note);
                }
                break;
            case 4:
                note.id = id_Randomizer();
                note.listName = (*todoLists)[*curList-1].getTitle();
                (*todoLists)[*curList-1].addNote(note);
                note.writeDataToDb();
                return true;
            case 5:
                return true;
        }
        return false;
    }
};

/*bool addOptions(int option, Note &note, vector<Note> &notes);*/
/*void addMenu(ToDoList &todoList);*/
/*void printAddHelp();*/
