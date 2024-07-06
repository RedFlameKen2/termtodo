#include <cstdlib>
#include <thread>
#include "helpers.h"
#include "constants.h"
#include "menus/mainmenu.h"

using std::string;
using std::thread;

void initMenuSystem(){
    clearTerm();
    MainMenu mainMenu;
}

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
