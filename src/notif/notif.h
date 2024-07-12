#include <iostream>
#include <thread>
#include "../list/todolist.h"

using std::string;
using std::cout;
using std::this_thread::sleep_for;
class Notification {
private:
    string notifString = "";
public:
    Notification(vector<ToDoList> *ToDoList){
        using namespace std::chrono_literals;
        while(true){
            printNotif();
            sleep_for(5s);
        }
    }
    void setNotifString(string notifString){
        this->notifString = notifString;
    }
    void printNotif(){
        cout << "\033[1;1H" << notifString << "\n";
    }
};
