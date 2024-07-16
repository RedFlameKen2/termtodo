#include "removelistmenu.h"

class MainMenu : public Menu
{
private:
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
        cout << "3) Add list-\n";
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
            AddListMenu listMenu(todoLists, curList);
        }
        break;
        case 4:
        {
            RemoveListMenu listMenu(todoLists, curList);
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
