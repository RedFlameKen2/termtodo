#include <iostream>
#include <sstream>
#include <thread>
#include "../list/todolist.h"

using std::string;
using std::cout;
using std::to_string;
using std::stringstream;
using std::this_thread::sleep_for;

class Notification {
private:
    vector<ToDoList> * todoLists;
    int * curList;
    string notifString = "";
    bool matchTime(DueDate dueDate){
        if(dueDate.sameTime(getCurTime()))
                return true;
        return false;
    }
    bool matchTime(DueDate dueDate, int dayOffset){
        tm time = getCurTime();
        time.tm_mday += dayOffset;
        if(dueDate.sameTime(time))
                return true;
        return false;
    }
    void checkDueClose(){
        for(ToDoList todoList : *todoLists)
            for(Note note : *(todoList.getNotes()))
                if(matchTime(note.dueDate, 1)){
                    string notif;
                    notif += "The Note ";
                    notif += note.title + " is ALMOST DUE! Time: ";
                    notif += note.dueDate.getDueDateData();
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
                    stringstream ss;
                    ss << to_string(note.dueDate.getHour()) << " : " << to_string(note.dueDate.getMin());
                    notif += string(ss.str());
                    setNotifString(notif);
                    return;
                }
    }
    void update(){
        checkDueClose();
        checkDue();
    }
public:
    Notification(vector<ToDoList> *todoLists, int * curList) : todoLists(todoLists), curList(curList){
        using namespace std::chrono_literals;
        while(true){
            update();
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
