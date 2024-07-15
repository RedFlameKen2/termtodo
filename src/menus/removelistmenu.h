#include "menu.h"

class RemoveListMenu : Menu
{
public:
    RemoveListMenu(vector<ToDoList> *todoLists, int *curList)
    {
        this->curList = curList;
        this->todoLists = todoLists;
        maxOpts = 1;
        menu();
    }
};