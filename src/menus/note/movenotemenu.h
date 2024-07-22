#include "../note/removenotemenu.h"

class MoveNoteMenu : Menu {
private:
    int targetList = 2;
    int curNote = 1;
    void selectNote(){
        int index;
        while(true){
            (*todoLists)[*curList-1].printNotesMin();
            printBar();
            index = promptInt ("Enter the number of the note to be moved: ");
            if(index > 0 && index <= (*todoLists)[*curList - 1].getNotes()->size())
                break;
            cout << "\nInvalid note number!\n";
        }
        curNote = index;
    }
    void moveNote(){
        Note note = (*todoLists)[*curList-1].getNotes()->at(curNote-1);
        note.listName = (*todoLists)[targetList-1].getTitle();
        (*todoLists)[*curList-1].removeNote(curNote-1);
        (*todoLists)[targetList-1].addNote(note);
        updateDB(note.getDBFormat(), note.id);
        cout << "\nNote successfully moved!\n";
    }
    void changeTargetList(){
        if(todoLists->size() < 3){
            cout << "\nThere aren't any other lists to move to!\n";
            return;
        }
        int input;
        while(true){
            displayLists();
            printBar();
            cout << "Target List: "<< targetList << ") " << (*todoLists)[targetList-1].getTitle() << "\n";
            input = promptInt("\nSelect a list number: ");
            clearTerm();
            if(input <= todoLists->size() && input > 0)
                break;
            cout << "\nNot an existing list, Try Again!\n";
        }
        targetList = input;
        cout << "\nList Successfully Changed!\n";
    }
    void listSwitch(int prev, int mode){
        if(*curList == targetList){
            if(mode == 0)
                targetList = prev;
            else
                *curList = prev;
        }
    }
public:
    MoveNoteMenu(vector<ToDoList> * todoLists, int * curList){
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 5;
        menu();
    }
    void printHelp() override {
        cout << "Here are the options for moving a Note:\n";
        cout << "1) Change current List\n";
        cout << "2) Change target List\n";
        cout << "3) Change Note to be moved\n";
        cout << "4) Move\n";
        cout << "5) Cancel";
    }
    //TODO: have only one show up, min or default
    void printInfo() override{
        (*todoLists)[*curList-1].printNotes();
    }
    void printTargetInfo() override{
            cout << "Moving from: " << *curList << ") " << (*todoLists)[*curList-1].getTitle();
            cout << "\nMoving to: " << targetList << ") " << (*todoLists)[targetList-1].getTitle();
            Note note = *(*todoLists)[*curList-1].getNote(curNote-1);
            cout << "\nMoving: #"<< curNote << "\nID:" << note.id << " " << note.title << "\n";
    }
    bool options(int option) override{
        if(todoLists->size() < 2){
            cout << "\nThere isn't a list to move to!\n";
            return true;
        }
        if ((*todoLists)[*curList-1].getNotes()->empty()) {
            cout << "\nThere are no notes in this list!\n";
            return true;
        }
        switch(option){
            case 1:
                {
                    int prev = *curList;
                    changeCurList();
                    listSwitch(prev, 0);
                }
                break;
            case 2:
                {
                    int prev = targetList;
                    changeTargetList();
                    listSwitch(prev, 1);
                }
                break;
            case 3:
                selectNote();
                break;
            case 4:
                moveNote();
                return true;
            case 5:
                if(promptConfirm("Are you sure you want to cancel?\nProgress will be lost"))
                    return true;
                break;
        }
        return false;
    }
};
