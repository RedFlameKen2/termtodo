#include <cstdlib>
#include <thread>
#include "helpers.h"
#include "constants.h"
#include "menus/menu.h"

using std::string;
using std::thread;

void initThread() {
    thread t1(notify);
    thread t2(menu);
    t1.join();
    t2.join();
}

int main(){
    initThread();
    return 0;
}
