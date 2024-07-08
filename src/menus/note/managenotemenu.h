#include "../checklist/checklistmenu.h"

class ManageNoteMenu : public Menu {
private:
    Note * note;
    int curNote = 1;
    void changeCurNote(){
        int input;
        while(true){
            displayLists();
            printBar();
            printTargetInfo();
            input = promptInt("\nSelect a Note number: ");
            clearTerm();
            if(input < (*note).getChecklist()->size() || input > 0)
                break;
            cout << "Not an existing Note, Try Again!\n";
        }
        curNote = input;
        updateNote();
        cout << "List Successfully Changed!";
    }
    void updateNote(){
        note->fullUpdate(*((*todoLists)[*curList-1].getNote(curNote-1)));
    }
public:
    ManageNoteMenu(vector<ToDoList> * todoLists, int * curList) {
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 7;
        updateNote();
        menu();
    }
    ManageNoteMenu(Note * note) : note(note){
        maxOpts = 7;
        menu();
    }
    void printHelp() override{
        cout << "Here are the options for Managing a Note:\n";
        cout << "1) Change Active Note\n";
        cout << "2) Edit Title\n";
        cout << "3) Edit Description\n";
        cout << "4) Edit Due Date\n";
        cout << "5) Manage Check list\n";
        cout << "6) Save\n";
        cout << "7) Cancel\n";
    }
    void printInfo() override{
        note->printData();
    }
    void printTargetInfo() override {
        cout << "Current Note: " << curNote << ") " << note->title << "\n";
    }
    bool options(int option) override{
        cin.get();
        switch(option){
            case 1:
                changeCurNote();
                break;
            case 2:
                printBar();
                cout << "Old Title: " << note->title << "\n";
                note->title = promptString("Enter new Title: ");
                clearTerm();
                break;
            case 3:
                printBar();
                cout << "Old Description: " << note->desc << "\n";
                note->desc = promptString("Enter new Description: ");
                clearTerm();
                break;
            case 4:
                break;
            case 5:
                {
                    AddCheckMenu addCheckMenu(note);
                }
                break;
            case 6:
                *((*todoLists)[*curList-1].getNote(curNote-1)) = *note;
                return true;
            case 7:
                promptConfirm("Are you sure you want to cancel?\nProgress will be lost:");
                return true;
        }
        return false;
    }
};
