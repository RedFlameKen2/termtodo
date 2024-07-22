#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstddef>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include "../util/helpers.h"
#include "duedate.h"
#include "checklist.h"

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
        dueDate = DueDate(data[4]);
        this->checkList.checkItems = checkItems;
    }
    Note() : id(0), title(""), desc(""), listName(""){
    }
    void printData(){
        cout << "\n<For note ID " << id << ">\n";
        cout << "title: " << title << "\n";
        cout << "description: " << desc << "\n";
        dueDate.printDueDate();
        checkList.printCheckList();
    }
    void printDataMin(){
        cout << "Title: " << title;
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
    void removeCheckItem(int index){
        checkList.checkItems.erase(std::next(checkList.checkItems.begin(), index));
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
