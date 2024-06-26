#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::this_thread::sleep_for;
using std::system;

class Note {
private:
    int id;
    string title, desc;
public:
    Note(int id, string title, string desc) : id(id), title(title), desc(desc){
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
        write += "{id:" + std::to_string(id);
        write += ",title:" + title;
        write += ",desc:" + desc;
        write += "},\n";
        return write; 
    }
};


