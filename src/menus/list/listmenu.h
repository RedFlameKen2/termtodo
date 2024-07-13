#include "../note/addnotemenu.h"

class ListMenu : public Menu{
private:
    void changeCurList(){
        int input;
        while(true){
            displayLists();
            printBar();
            input = promptInt("\nSelect a list number: ");
            clearTerm();
            if(input <= todoLists->size() && input > 0)
                break;
            cout << "Not an existing list, Try Again!\n";
        }
        *curList = input;
        cout << "List Successfully Changed!";
    }
public:
    ListMenu(){
        maxOpts = 8;
        menu();
    }
    ListMenu(vector<ToDoList> * todoLists, int * curList){
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 8;
        menu();
    }
    void printHelp() override{
        cout << "Here is a list of options for managing your lists: \n";
        cout << "1) Change current list\n";
        cout << "2) Display Notes in this list\n"; 
        cout << "3) Add a note to List\n";
        cout << "4) Remove a note from list\n";
        cout << "5) Manage notes in the list\n";
        cout << "6) Display notes in all lists\n";
        cout << "7) Back\n";
        cout << "8) Exit the program\n";
    }
    bool options(int option) override{
        switch(option){
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
                break;
            case 5:
                {
                    if(((*todoLists)[*curList-1]).getNotes()->empty()){
                        cout << "There are no notes in this list!";
                        break;
                    }

                    ManageNoteMenu ManageNoteMenu(todoLists, curList);
                }
                break;
            case 6:
                break;
            case 7:
                return true;
            case 8:
                cout << "Program Terminating, Goodbye!";
                exit(1);
                break;
        }
        return false;
    }
};
