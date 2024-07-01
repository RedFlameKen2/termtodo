#include <cstddef>
#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::this_thread::sleep_for;
using std::system;
using std::stoi;
using std::vector;

class CheckList {
private:
    struct CheckItem {
        string title;
        bool checked;
        CheckItem(string title, bool checked) : title(title), checked(checked){
        }
    };
    vector<CheckItem> checkItems;
public:
    void add(string title, bool checked){
        checkItems.push_back(CheckItem(title, checked));
    }
};

class Note {
private:
    int id;
    string title, desc;
public:
    Note(int id, string title, string desc) : id(id), title(title), desc(desc){
    }
    Note(string * data) {
        this->id = std::stoi(data[0]);
        this->title = data[1];
        this->desc = data[2];
    }
    Note() : id(0), title(0), desc(0){
    }
    int getID(){
        return id;
    }
    string getTitle(){
        return title;
    }
    string getDesc(){
        return desc;
    }
    string getDBFormat(){
        string write;
        write += "id:" + std::to_string(id);
        write += ", title: \"" + title;
        write += "\", desc: \"" + desc;
        write += "\"\n";
        return write; 
    }
};

//Functions
/*string * getDataArray(string data);*/
Note getNoteFromDB();

