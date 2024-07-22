#include "../note/managenotemenu.h"

class AddNoteMenu : public Menu {
private:
    Note note;
public:
    AddNoteMenu(){
        maxOpts = 6;
        note.id = id_Randomizer();
        menu();
    }
    AddNoteMenu(vector<ToDoList> * todoLists, int * curList) {
        maxOpts = 6;
        this->curList = curList;
        this->todoLists = todoLists;
        note.id = id_Randomizer();
        menu();
    }
    void printHelp() override{
        cout << "List of options for adding a note: \n";
        cout << "1) Set Title:\n";
        cout << "2) Set Description\n";
        cout << "3) Manage Checklist\n";
        cout << "4) Add due date\n";
        cout << "5) Finish\n";
        cout << "6) Cancel\n";
    }
    void printInfo() override {
        note.printData();
    }
    bool options(int option) override{
        cin.get();
        switch (option) {
            case 1:
                printBar();
                note.title = promptString("\nEnter Title of the Note: ");
                clearTerm();
                cout << "\n";
                break;
            case 2:
                printBar();
                note.desc = promptString("\nEnter Description of the Note: ");
                clearTerm();
                cout << "\n";
                break;
            case 3:
                {
                    ChecklistMenu checklistMenu(&note);
                }
                break;
            case 4:
                {
                    if(!promptConfirm("Would you like to set a due date? "))
                        break;
                    ManageDueMenu manageDueMenu(&note);
                }
                break;
            case 5:
                //TODO: check if note is initiated, if not, don't save
                note.listName = (*todoLists)[*curList-1].getTitle();
                (*todoLists)[*curList-1].addNote(note);
                writeDB(note.getDBFormat());
                return true;
            case 6:
                if(promptConfirm("Are you sure you want to cancel?\nProgress will be lost"))
                    return true;
                break;
        }
        return false;
    }
};
