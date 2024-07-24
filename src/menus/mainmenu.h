#include "list/listmenu.h"

class MainMenu : public Menu
{
private:
    void addListMenu(){
        string title;
        while(true){
            printBar();
            cout << "*** Add New list ***\nExisting Lists:\n";
            displayLists();
            printBar();
            title = promptString("Enter New List Title: ");
            clearTerm();
            if(!listExists(todoLists, title))
                break;
            cout << "\na list with that name already exists, Try Again!";
        }
        addList(todoLists, title);
        cout << "\nSuccessfully Added New list";
    

    }
    void removeListMenu(){
        int index = 0;
        while(true){
            printBar();
            cout << "*** Remove a List ***\nExisting Lists:\n";
            displayLists();
            printBar();
            index = promptInt("Enter list number to remove: ");
            clearTerm();
            //Checks if the inputed number is an existing list if not then make the user try again
            if(index <= todoLists->size() && index > 0)
                break;
            cout << "\nlist doesn't exist, Try Again!";
        }
        
        removeList(todoLists, index-1);
        cout << "\nSuccessfully Removed list";
    }
public:
    MainMenu(vector<ToDoList> *todoLists, int *curList)
    {
        //Passes the address from main.cpp
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 5;
        menu();
    }
    //override changes what a virtual funtion does
    void printHelp() override
    {
        cout << "List of options: \n";
        cout << "1) Manage lists\n";
        cout << "2) List ToDoLists\n";
        cout << "3) Add list\n";
        cout << "4) Remove list\n";
        cout << "5) Exit Program\n";
    }
    bool options(int option) override
    {
        switch (option)
        {
            case 1:
                {
                    ListMenu listMenu(todoLists, curList);
                }
                break;
            case 2:
                displayLists();
                break;
            case 3:
                {
                    addListMenu();
                }
                break;
            case 4:
                {
                    removeListMenu();
                }
                break;
            case 5:
                if(promptConfirm("Are you sure you want to exit?")){
                    cout << "Program Terminating, Goodbye!";
                    exit(1);
                }
                break;
        }
        return false;
    }
};
