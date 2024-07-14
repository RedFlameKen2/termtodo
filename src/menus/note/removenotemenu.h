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
            if(idExists(id))
                break;
            cout << "ID Doesn't Exist! Try Again!\n";
        }
        deleteInDB(id);
        (*todoLists)[*curList-1].removeNoteByID(id);
    }
public:
    RemoveNoteMenu(vector<ToDoList> * todoLists, int * curList) {
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 3;
        menu();
    }
    void printHelp() override {
        cout << "List of options for Removing a note: \n";
        cout << "1) Remove by ID\n";
        cout << "2) Remove by Title\n";
        cout << "3) Exit\n";
    }
    void printInfo() override {
        (*todoLists)[*curList-1].printNotes();
    }
    /*void printTargetInfo() override {*/
    /*}*/
    bool options(int option) override {
        switch(option){
            case 1:
                removeByID();
                break;
            case 2:
                break;
            case 3:
                return true;
        }
        return false;
    }
};
