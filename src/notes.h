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
public:
    vector<CheckItem> checkItems;
    void add(string title, bool checked){
        checkItems.push_back(CheckItem(title, checked));
    }
    bool isChecked(int index){
        return checkItems[index].checked;
    }
    string getTitle(int index){
        return checkItems[index].title;
    }
    string getDBWrite(){
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
};

class Note {
private:
    int id;
    string title, desc;
    CheckList checkList;
public:
    Note(int id, string title, string desc) : id(id), title(title), desc(desc){
    }
    Note(vector<string> noteData){
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
        write += "\"";
        write += checkList.getDBWrite();
        write += "\n";
        return write; 
    }
};

//Functions
/*string * getDataArray(string data);*/
Note getNoteFromDB();

