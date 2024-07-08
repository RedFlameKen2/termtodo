#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstddef>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include "../helpers.h"
#include "duedate.h"

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
    bool checked = false;
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
    int size(){
        return checkItems.size();
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
        if(checkItems.empty()){
            cout << "There is no CheckList!\n";
            return;
        }
        cout << "CheckList: \n";
        for(CheckItem checkItem : checkItems)
            cout << "[" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
    }
};

class Note {
private:
    CheckList checkList;
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
        checkList.printCheckList();
    }
    string getDBFormat(){
        string write;
        write += std::to_string(id);
        write += "," + title;
        write += "," + desc;
        write += "," + listName;
        write += ",";
        write += dueDate.getDBFormat();
        write += ",";
        write += checkList.getDBFormat();
        write += "\n";
        return write; 
    }
    CheckList * getChecklist(){
        return &checkList;
    }
    void fullUpdate(Note note){
        this->id = note.id;
        this->title = note.title;
        this->desc = note.desc;
        this->checkList = note.checkList;
        this->dueDate = note.dueDate;
    }
};

//Functions
/*string * getDataArray(string data);*/
Note getNoteFromDB();
string * getDataArray(string data);
vector<CheckItem> getChecklistData(string data);
Note getNoteFromDB();
