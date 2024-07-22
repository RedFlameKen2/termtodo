#include "../note/movenotemenu.h"

class ListMenu : public Menu{
private:
    void changeCurList(){
        int input;
        while(true){
            cout << "\n";
            displayLists();
            printBar();
            printTargetInfo();
            input = promptInt("Select a list number: ");
            clearTerm();
            if(input <= todoLists->size() && input > 0)
                break;
            cout << "Not an existing list, Try Again!\n";
        }
        *curList = input;
        cout << "\nList Successfully Changed!";
    }


    void moveNote(){
        int noteIndex, targetListIndex;
        if ((*todoLists)[*curList-1].getNotes()->empty()) {
            cout << "There are no notes in this list!";
            return;
        }

        (*todoLists)[*curList-1].printNotes();
        noteIndex = promptInt ("Enter the number of the note to be moved: ") - 1;

        if (noteIndex < 0 || noteIndex >= (*todoLists)[*curList - 1].getNotes()->size()){
            cout << "Invalid note number!";
            return;
        }

        displayLists();
        targetListIndex = promptInt("Enter the number of the target list: ") - 1;
        
        if (targetListIndex < 0 || targetListIndex >= todoLists->size()){
            cout << "Invalid list number!"; 
            return;
        }

        Note note = (*todoLists)[*curList-1].getNotes()->at(noteIndex);
        (*todoLists)[*curList-1].removeNote(noteIndex);
        (*todoLists)[*curList-1].addNote(note);

        cout << "Note successfully moved!";
    }
public:
    ListMenu(){
        maxOpts = 9;
        menu();
    }
    ListMenu(vector<ToDoList> * todoLists, int * curList){
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 9;
        menu();
    }
    void printHelp() override{
        cout << "Here is a list of options for managing your lists: \n";
        cout << "1) Change current list\n";
        cout << "2) Display Notes in this list\n"; 
        cout << "3) Add a note to List\n";
        cout << "4) Move a note to another list\n";
        cout << "5) Remove a note from list\n";
        cout << "6) Manage notes in the list\n";
        cout << "7) Display notes in all lists\n";
        cout << "8) Back\n";
        cout << "9) Exit the program\n";
    }
    bool options(int option) override {
    switch(option) {
        case 1:
            changeCurList();
            break;
        case 2:
            (*todoLists)[*curList-1].printNotes();
            break;
        case 3:
            {
                AddNoteMenu addNoteMenu(todoLists, curList);
            }
            break;
        case 4:
            {
                MoveNoteMenu MoveNoteMenu(todoLists, curList);
            }
            break;
        case 5:
            {
                RemoveNoteMenu removeNoteMenu(todoLists, curList);
            }
            break;
        case 6:
            {
                if(((*todoLists)[*curList-1]).getNotes()->empty()) {
                    cout << "There are no notes in this list!";
                    break;
                }

                ManageNoteMenu manageNoteMenu(todoLists, curList);
            }
            break;
        case 7:
                for(ToDoList todoList : *todoLists){
                    printBar();
                    todoList.printNotes();
                }
            break;
        case 8:
            return true;
        case 9:
            cin.get();
            if(promptConfirm("Are you sure you want to exit?")){
                cout << "Program Terminating, Goodbye!";
                exit(1);
            }
            break;
    }
    return false;
}
};
