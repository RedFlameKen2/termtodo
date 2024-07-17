#include <iostream>
#include <thread>
#include "../list/todolist.h"

using std::string;
using std::cout;
using std::to_string;
using std::this_thread::sleep_for;

class Notification {
private:
    vector<ToDoList> * todoLists;
    int * curList;
    string notifString = "";
    //TODO: loop through each note in each list and check if their due dates matches current time
    bool matchTime(DueDate dueDate){
        if(dueDate.sameTime(getCurTime()))
                return true;
        return false;
    }
    void checkDueClose(){
        for(ToDoList todoList : *todoLists)
            for(Note note : *(todoList.getNotes()))
                if(matchTime(note.dueDate)){
                    string notif;
                    notif += "The Note ";
                    notif += note.title + " is Due RIGHT NOW! Time: ";
                    notif += to_string(note.dueDate.getHour()) + " : " + to_string(note.dueDate.getMin()) ;
                    setNotifString(notif);
                    return;
                }
    }
    void checkDue(){
        for(ToDoList todoList : *todoLists)
            for(Note note : *(todoList.getNotes()))
                if(matchTime(note.dueDate)){
                    string notif;
                    notif += "The Note ";
                    notif += note.title + " is Due RIGHT NOW! Time: ";
                    notif += to_string(note.dueDate.getHour()) + " : " + to_string(note.dueDate.getMin()) ;
                    setNotifString(notif);
                    return;
                }
    }
public:
    Notification(vector<ToDoList> *todoLists, int * curList) : todoLists(todoLists), curList(curList){
        using namespace std::chrono_literals;
        while(true){
            printNotif();
            sleep_for(10s);
            notifString = "";
        }
    }
    void setNotifString(string notifString){
        this->notifString = notifString;
    }
    void printNotif(){
        cout << "\033[1;1H" << notifString << "\n";
    }
};
