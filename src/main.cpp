#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
#include "helpers.h"
#include "constants.h"
#include "menu.h"

using std::cout;
using std::cin;
using std::endl;
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
