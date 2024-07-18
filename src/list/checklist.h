#include <iostream>
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
        cout << "CheckList: "<< getProgBar() << "\n";
        for(CheckItem checkItem : checkItems)
            cout << "[" << (checkItem.checked ? "x" : " ") << "] " << checkItem.title << "\n";
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
};

