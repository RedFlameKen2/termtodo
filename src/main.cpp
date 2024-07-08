#include <cstdlib>
#include <thread>
#include "helpers.h"
#include "constants.h"
#include "menus/mainmenu.h"

using std::string;
using std::thread;

/*
 * This function is just to initialize the the main menu.
 * The entire menu system starts there
 * See src/menus/menu.h and src/menus/mainmenu.h
*/
void initMenuSystem(){
    clearTerm();
    MainMenu mainMenu;
}

/*
 * Threads allow Multiple Processes to run at the same time.
 * Here we have t1 for the notification system (WIP)
 * t2 will run the initMenuSystem() function above
 * thread.join() basically tells when then threads will stop (no need to worry about that)
*/
void initThread() {
    thread t1(notify);
    thread t2(initMenuSystem);
    t1.join();
    t2.join();
}

int main(){
    initThread();
    return 0;
}
