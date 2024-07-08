#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include "../list/todolist.h"

/*
 * The Menu class is a blueprint for User Interfaces where you can select options.
 * To make a custom Menu, you simply must inherit Menu to that class
 * Here is a list of files that contains a Menu
 * src/menus/list/listmenu.h
 * src/menus/menu.h
 * src/menus/note/addmenu.h
 * src/menus/checklist/checklistmenu.h
 * src/menus/checklist/addcheckmenu.h
 * src/menus/mainmenu.h
*/
class Menu {
/*
 * The "protected" access modifier is a basically like "private". However,
 * classes that inherit Menu will have access to it. unlike private, private
 * members will only be seen by Menu, and not by its children.
 * private:
 * { Menu: int * curlist } will not be see by MainMenu
 * protected:
 * { Menu: int * curlist } will be see by MainMenu
*/
protected:
    /*
     * A vector is basically an array (more of a list similar to what we learned in datastruct)
     * How to use:
     * vector<Template> vectName;
     * Template is just whatever datatype you wanna store inside it.
     *
     * in this case, he have a pointer to our vector so that we can manipulate it anywhere.
     *
     * to add, use push_back(dataToAdd)
     * to remove, use erase()
    */
    vector<ToDoList> * todoLists = new vector<ToDoList>;
    int maxOpts;
    int * curList = new int;
    void displayLists(){
        int i = 1;
        for(ToDoList todoList : *todoLists){
            cout << "List #" << i << ": " << todoList.getTitle() << "\n";
            i++;
        }
    }
public:
    Menu(){
    }
    /*
     * Please use this for those menus that require the todoList's vector!
     *
    */
    Menu(vector<ToDoList> * todoLists, int * curList) : todoLists(todoLists) {
        this->curList = curList;
    }
    bool optionValid(int option){
        if(option <= maxOpts && option > 0)
            return true;
        return false;
    }
    void menu(){
        while(true){
            printInfo();
            printBar();
            printHelp();
            int option;
            while(true){
                printBar();
                printTargetInfo();
                option = promptInt("Enter option: ");
                clearTerm();
                if(optionValid(option))
                    break;
                cout << "Invalid Option, Try Again!\n";
            }
            if(options(option))
                break;
        }
    }
    virtual void printTargetInfo(){
        cout << "Current List: "<< *curList << ") " << (*todoLists)[*curList-1].getTitle() << "\n";
    }
    virtual void printInfo(){
    }
    virtual void printHelp(){
    }
    virtual bool options(int option){
        return false;
    }
};
