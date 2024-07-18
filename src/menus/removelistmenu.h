#include "./list/listmenu.h"
#include <algorithm>

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

    void printHelp()override
    {

    }

    //I'm not sure why you're trying to use a vector of strings, if it's supposed to be for the list, then we already have
    //a vector of ToDoLists called todoLists (it's a pointer btw). manage that instead, and refer to line 23 of todolist.h
    //for an example of removing an item from a vector. the function is called removeNote()
void RemoveItem(std::vector<std::string>& strings)
{
    std::string ToRemove;
    cout << "Enter the task you want to remove: ";
    std::getline(std:: cin, ToRemove);

    //wth
    auto it = std::find(strings.begin(),strings.end(),ToRemove);

    if (it != strings.end())
    {
    strings.erase(it);
    cout << ToRemove << "has been removed"; 
    } else {
        cout << ToRemove << "is not in the vector";
    }
}

};
//TODO: Flores
