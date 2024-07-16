#include "listmenu.h"

class AddListMenu : Menu
{
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


};
//TODO: Flores