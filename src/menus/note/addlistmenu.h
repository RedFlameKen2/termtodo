#include "../menu.h"

class AddListMenu : Menu
{
private:

public:
    AddListMenu(vector<ToDoList> *todoLists, int *curList)
    {
        this->curList = curList;
        this->todoLists = todoLists;
        maxOpts = 1;
        menu();
    }

    void printHelp()override
    {

    }

    void AddMenu()
    {
        printBar();
        cout << "*** Add New task ***";
        cout << "Enter New task: ";

        string NewTask;
        cin >> NewTask;
//idk what to put below here so i just put list
        //RE: the vector of lists is called todoLists, also it's a pointer to the vector of Lists
        todoLists->push_back(NewTask);

        cout << "Successfully Added New task";
        cin.clear();
    }
 
};
//TODO: Flores
