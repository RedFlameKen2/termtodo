#include "removelistmenu.h"

class MainMenu : public Menu
{
private:
    void addListMenu(){
        cin.get();
        printBar();
        cout << "*** Add New list ***\n";
        string title;
        title = promptString("Enter New List: ");
        ToDoList newList(title);
        addList(todoLists, title);
        cout << "\nSuccessfully Added New list";

    }
    void removeListMenu(){
        cin.get();
        printBar();
        cout << "*** Remove a List ***\n";
        int index = 0;
        while(true){
            index = promptInt("Enter list number to remove: ");
            if(index <= todoLists->size() && index > 0)
                break;
            cout << "list doesn't exist, Try Again!\n";
        }
        /*todoLists->erase(std::next(todoLists->begin(), index-1));*/
        removeList(todoLists, index-1);
        cout << "Successfully Removed list";
    }
public:
    MainMenu(vector<ToDoList> *todoLists, int *curList)
    {
        this->todoLists = todoLists;
        this->curList = curList;
        maxOpts = 5;
        menu();
    }
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
            cout << "Program Terminating, Goodbye!";
            exit(1);
            break;
        }
        return false;
    }
};
