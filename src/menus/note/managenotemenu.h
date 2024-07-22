#include "../duedate/duemanager.h"

class ManageNoteMenu : public Menu {
private:
    Note * note = new Note;
    int curNote = 1;
    void changeCurNote(){
        int input;
        while(true){
            (*todoLists)[*curList-1].printNotesMin();
            printBar();
            printTargetInfo();
            input = promptInt("\nSelect a Note number: ");
            clearTerm();
            cout << "\n";
            if(input <= (*todoLists)[*curList-1].getNotes()->size() && input > 0)
                break;
            cout << "Not an existing Note, Try Again!\n";
        }
        curNote = input;
        updateNote();
        cout << "\nList Successfully Changed!";
    }
    void updateNote(){
        note->fullUpdate(*((*todoLists)[*curList-1].getNote(curNote-1)));
    }
    void saveNote(){
        *((*todoLists)[*curList-1].getNote(curNote-1)) = *note;
        updateDB(note->getDBFormat(), note->id);
    }
public:
    ManageNoteMenu(vector<ToDoList> * todoLists, int * curList) {
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 7;
        note = &*((*todoLists)[*curList-1].getNote(curNote-1));
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
                {
                    ManageDueMenu manageDueMenu(note);
                }
                break;
            case 5:
                {
                    ChecklistMenu checklistMenu(note);
                }
                break;
            case 6:
                saveNote();
                return true;
            case 7:
                promptConfirm("Are you sure you want to cancel?\nProgress will be lost:");
                return true;
        }
        return false;
    }
};
