#include "addlistmenu.h"
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

void RemoveItem(std::vector<std::string>& strings)
{
    std::string ToRemove;
    cout << "Enter the task you want to remove: ";
    std::getline(std:: cin, ToRemove);

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