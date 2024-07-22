#include "../note/addnotemenu.h"

class RemoveNoteMenu : Menu {
private:
    void removeByID(){
        if((*todoLists)[*curList-1].listEmpty()){
            cout << "The List is Empty!\n";
            return; 
        }
        int id;
        while(true){
            printBar();
            id = promptInt("Enter ID to remove: ");
            clearTerm();
            if(idExists(id))
                break;
            cout << "ID Doesn't Exist! Try Again!\n";
        }
        deleteInDB(id);
        (*todoLists)[*curList-1].removeNoteByID(id);
    }
    void removeByTitle(){
        if((*todoLists)[*curList-1].listEmpty()){
            cout << "The List is Empty!\n";
            return; 
        }
        int id;
        while(true){
            printBar();
            id = promptInt("Enter title to remove: ");
            clearTerm();
            if(idExists(id))
                break;
            cout << "Note Doesn't Exist! Try Again!\n";
        }
        deleteInDB(id);
        (*todoLists)[*curList-1].removeNoteByID(id);
    }
public:
    RemoveNoteMenu(vector<ToDoList> * todoLists, int * curList) {
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 4;
        menu();
    }
    void printHelp() override {
        cout << "List of options for Removing a note: \n";
        cout << "1) Change current list\n";
        cout << "2) Remove by ID\n";
        cout << "3) Remove by Title\n";
        cout << "4) Exit\n";
    }
    void printInfo() override {
        (*todoLists)[*curList-1].printNotes();
    }
    //TODO: make this thing remove by number instead
    bool options(int option) override {
        switch(option){
            case 1:
                changeCurList();
                break;
            case 2:
                removeByID();
                break;
            case 3:
                removeByTitle();
                break;
            case 4:
                return true;
        }
        return false;
    }
};
