#include <cstdlib>
#include <iostream>
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::thread;
using std::this_thread::sleep_for;
using std::system;

void notify(){
    using namespace std::chrono_literals;
    while(true){
        system("notify-send -u normal 'bruh look at me'");
        sleep_for(5s);
    }
}

void f2(){
    while(true){
        string fuck;
        cout << "Enter anything: ";
        cin >> fuck;
        cout << "Output:\n" << fuck << endl;
    }
}

void initThread() {
    thread t1(notify);
    thread t2(f2);
    t1.join();
    t2.join();
}

int main(){
    initThread();
    return 0;
}
