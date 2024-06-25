#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::this_thread::sleep_for;


void notify(){
    using namespace std::chrono_literals;
    while(true){
        system("notify-send -u normal 'hey, attention'");
        sleep_for(10s);
    }
}

void printSomething(){
    cout << "Enter anything: ";
    string input; 
    getline(cin, input);
    cout << "output:\n" << input << endl;
}
