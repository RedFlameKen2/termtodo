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
private:
    int getProgress(){
        float roof = checkItems.size();
        float progress = 0;
        for(CheckItem checkItem : checkItems)
            if(checkItem.checked)
                progress++;
        return (progress/roof)*((float)10);
    }
public:
    vector<CheckItem> checkItems; 
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
            cout << "\tThere is no CheckList!\n";
            return;
        }
        cout << "\tCHECKLIST: "<< getProgBar() << "\n";
        for(CheckItem checkItem : checkItems)
            cout << "\t[" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
    }
    void printCheckListIndexed(int current){
        if(checkItems.empty()){
            cout << "There is no CheckList!\n";
            return;
        }
        int i = 1;
        cout << "CheckList: "<< getProgBar() << "\n";
        for(CheckItem checkItem : checkItems){
            if(i == current)
                cout << ">>>>\t";
            else
                cout << "\t";
            cout << i++ << ") [" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
        }
    }
    void printCheckListIndexed(){
        if(checkItems.empty()){
            cout << "There is no CheckList!\n"; return;
        }
        cout << "CheckList: \n";
        int i = 1;
        for(CheckItem checkItem : checkItems)
            cout << i++ << ") [" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
    }
    string getProgBar(){
        string bar = "[";
        int i = 0, progress = getProgress();
        while(i< 10){
            if(i < progress)
                bar+="#";
            else
                bar+="-";
            i++;
        }
        bar += "]";
        return bar;
    }
    void printCheckItem(int index){
        cout << "[" << (checkItems[index].checked ? "x" : " ") << "] " << checkItems[index].title << "\n";
    }
    void toggleCheck(int index){
        checkItems[index].checked = !checkItems[index].checked;
    }
};

