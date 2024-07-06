#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "../list/todolist.h"

class Menu {
protected:
    vector<ToDoList> todoLists;
    int maxOpts;
    int * curList = new int;
public:
    Menu(){
    }
    Menu(vector<ToDoList> todoLists, int * curList) : todoLists(todoLists) {
        this->curList = curList;
    }
    bool optionValid(int option){
        if(option <= maxOpts && option > 0)
            return true;
        return false;
    }
    void menu(){
        while(true){
            printHelp();
            int option;
            while(true){
                option = promptInt("Enter option: ");
                clearTerm();
                if(optionValid(option))
                    break;
                cout << "Invalid Option, Try Again!\n";
            }
            options(option);
        }
    }
    virtual void printHelp(){
    };
    virtual bool options(int option){
        return false;
    };
};
