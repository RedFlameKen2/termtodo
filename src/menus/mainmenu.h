#include "list/listmenu.h"

class MainMenu : public Menu {
private:
    void displayLists(vector<ToDoList> todoLists){
        int i = 1;
        for(ToDoList todoList : todoLists){
            cout << "List #" << i << ": " << todoList.getTitle() << "\n";
            i++;
        }
    }
public:
    MainMenu(){
        *curList = 1;
        maxOpts = 5;
        initLists();
        menu();
    }
    void initLists(){
        todoLists.push_back(ToDoList("ToDo"));
        todoLists.push_back(ToDoList("Doing"));
        todoLists.push_back(ToDoList("Done"));
    }
    void printHelp(){
        cout << "List of options: \n";
        cout << "1) Manage lists\n";
        cout << "2) List ToDoLists\n";
        cout << "3) ???????\n";
        cout << "4) Show this menu\n";
        cout << "5) Exit Program\n";
    }
    bool options(int option){
        switch(option){
            case 1:
                {
                    ListMenu listMenu(todoLists, curList);
                }
                break;
            case 2:
                displayLists(todoLists);
                break;
            case 3:
                cout << "HOOOHOOO BOOO\n";
                break;
            case 4:
                printHelp();
                break;
            case 5:
                cout << "Program Terminating, Goodbye!";
                exit(1);
                break;
        }
        return false;
    }
};
