#include <iostream>
#include <iterator>
#include <vector>

using std::string;
using std::vector;
using std::cout;

struct CheckItem {
    string title;
    bool checked = false;
    CheckItem(string title, bool checked) : title(title), checked(checked){
    }
    CheckItem(){};
};
class CheckList {
public:
    vector<CheckItem> checkItems; //wow nice one bitch
    void add(string title, bool checked){
        checkItems.push_back(CheckItem(title, checked));
    }
    void add(CheckItem checkItem){
        checkItems.push_back(checkItem);
    }
    void remove(int index){
        checkItems.erase(std::next(checkItems.begin(), index));
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
    void printCheckListIndexed(){
        if(checkItems.empty()){
            cout << "There is no CheckList!\n";
            return;
        }
        cout << "CheckList: \n";
        int i = 1;
        for(CheckItem checkItem : checkItems)
            cout << i++ << ") [" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
    }
};

