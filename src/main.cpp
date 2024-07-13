#include <cstdlib>
#include <thread>
#include "util/helpers.h"
#include "menus/mainmenu.h"

using std::string;
using std::thread;

/*
 * This function is just to initialize the the main menu.
 * The entire menu system starts there
 * See src/menus/menu.h and src/menus/mainmenu.h
*/
void initMenuSystem(vector<ToDoList> *todoLists, int * curList){
    clearTerm();
    MainMenu mainMenu(todoLists, curList);
}

/*
 * Threads allow Multiple Processes to run at the same time.
 * Here we have t1 for the notification system (WIP)
 * t2 will run the initMenuSystem() function above
 * thread.join() basically tells when then threads will stop (no need to worry about that)
*/

void initThread() {
    vector<ToDoList> todoLists;
    int curList = 1;
    
    thread t1([](vector<ToDoList> * todoLists){
    }, &todoLists);
    thread t2(initMenuSystem, &todoLists, &curList);
    t1.join();
    t2.join();
}

int main(){
    initThread();
    return 0;
}
