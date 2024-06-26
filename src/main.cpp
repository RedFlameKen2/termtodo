#include <cstdlib>
#include <iostream>
#include <thread>
#include "helpers.h"
#include "notes.h"
#include "constants.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::thread;

void initThread() {
    thread t1(notify);
    thread t2([](){
            while(true){
            printSomething();
            }
            });
    t1.join();
    t2.join();
}

int main(){
    cout << getOS() << "\n";
    dbWrite();
    getNoteFromDB();
    initThread();
    return 0;
}
