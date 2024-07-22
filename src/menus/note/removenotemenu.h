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
            (*todoLists)[*curList-1].printNotes();
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
        string title;
        while(true){
            (*todoLists)[*curList-1].printNotesMin();
            printBar();
            title = promptString("Enter title to remove: ");
            clearTerm();
            if(listExists(todoLists, title))
                break;
            cout << "Note Doesn't Exist! Try Again!\n";
        }
        deleteInDB(title);
        (*todoLists)[*curList-1].removeNoteByTitle(title);
    }
    void removeByNumber(){
        if((*todoLists)[*curList-1].listEmpty()){
            cout << "The List is Empty!\n";
            return; 
        }
        int index = 0, id = 0;
        while(true){
            (*todoLists)[*curList-1].printNotesMin();
            printBar();
            index = promptInt("Enter number to remove: ");
            clearTerm();
            id = (*todoLists)[*curList-1].getNote(index-1)->id;
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
        maxOpts = 5;
        menu();
    }
    void printHelp() override {
        cout << "List of options for Removing a note: \n";
        cout << "1) Change current list\n";
        cout << "2) Remove by Number\n";
        cout << "3) Remove by ID\n";
        cout << "4) Remove by Title\n";
        cout << "5) Exit\n";
    }
    void printInfo() override {
        (*todoLists)[*curList-1].printNotes();
    }
    bool options(int option) override {
        switch(option){
            case 1:
                changeCurList();
                break;
            case 2:
                removeByNumber();
                break;
            case 3:
                removeByID();
                break;
            case 4:
                removeByTitle();
                break;
            case 5:
                return true;
        }
        return false;
    }
};
