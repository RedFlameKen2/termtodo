#include "../note/movenotemenu.h"

class ListMenu : public Menu{
private:
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
            break;
        case 8:
            return true;
        case 9:
            cout << "Program Terminating, Goodbye!";
            exit(1);
            break;
    }
    return false;
}
};
