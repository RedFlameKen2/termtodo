#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstddef>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include "../helpers.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stoi;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::to_string;

struct CheckItem {
    string title;
    bool checked;
    CheckItem(string title, bool checked) : title(title), checked(checked){
    }
    CheckItem(){};
};
class CheckList {
public:
    vector<CheckItem> checkItems;
    void add(string title, bool checked){
        checkItems.push_back(CheckItem(title, checked));
    }
    void add(CheckItem checkItem){
        checkItems.push_back(checkItem);
    }
    bool isChecked(int index){
        return checkItems[index].checked;
    }
    string getTitle(int index){
        return checkItems[index].title;
    }
    string getDBFormat(){
        string write;
        write += "{";
        for(CheckItem checkItem : checkItems){
            write+= "[";
            write+= checkItem.title;
            write+= ",";
            if(checkItem.checked)
                write+= "true";
            else
                write+= "false";
            write+= "]";
        }
        write += "}";
        return write;
    }
    void printCheckList(){
        for(CheckItem checkItem : checkItems)
            cout << "[" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
    }
};

class DueDate {
private:
    bool on = false;
    tm time;
public:
    DueDate(){
    }
    string getDBFormat(){
        if(!on)
            return "off";
        string write;
        write+=time.tm_mon;
        write+=" ";
        write+=time.tm_mday;
        write+=" ";
        write+=time.tm_year;
        write+=" ";
        write+=time.tm_hour;
        write+=" ";
        write+=time.tm_min;
        return write;
    }
    int getMonth(){
        return time.tm_mon;
    }
    int getDay(){
        return time.tm_mday;
    }
    int getYear(){
        return time.tm_year;
    }
    int getHour(){
        return time.tm_hour;
    }
    int getMin(){
        return time.tm_min;
    }
    void setMonth(int month){
        time.tm_mday = month;
    }
    void setDay(int day){
        time.tm_mon = day;
    }
    void setYear(int year){
        time.tm_year = year;
    }
    void setHour(int hour){
        time.tm_hour = hour;
    }
    void setMin(int min){
        time.tm_min = min;
    }
};

class Note {
private:
    CheckList checkList;
    string getDBFormat(){
        string write;
        write += std::to_string(id);
        write += "," + title;
        write += "," + desc;
        write += "," + listName;
        write += ",";
        dueDate.getDBFormat();
        write += ",";
        write += checkList.getDBFormat();
        write += "\n";
        return write; 
    }
public:
    int id;
    string title, desc, listName;
    DueDate dueDate;
    Note(int id, string title, string desc, string listName) : id(id), title(title), desc(desc), listName(listName){
    }
    Note(string * data, vector<CheckItem> checkItems) {
        this->id = std::stoi(data[0]);
        this->title = data[1];
        this->desc = data[2];
        this->listName = data[3];
        this->checkList.checkItems = checkItems;
    }
    Note() : id(0), title(""), desc(""), listName(""){
    }
    void printData(){
        cout << "For note ID " << id << "\n";
        cout << "title: " << title << "\n";
        cout << "description: " << desc << "\n";
        cout << "CheckList: \n";
        checkList.printCheckList();
    }
    void writeDataToDb(){
        string write = getDBFormat(), ret = dbRead();
        std::ofstream file("db");
        write += ret;
        file << write;
        file.close();
    }
    CheckList getChecklist(){
        return checkList;
    }
};

//Functions
/*string * getDataArray(string data);*/
Note getNoteFromDB();
string * getDataArray(string data);
vector<CheckItem> getChecklistData(string data);
Note getNoteFromDB();
