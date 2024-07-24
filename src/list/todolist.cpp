#include <cstdio>
#include "todolist.h"
#include "../util/helpers.h"

bool listExists(vector<ToDoList> *todoLists, string title){
    bool found = false;
    for(ToDoList x : *todoLists)
        if(x.getTitle() == title)
            found = true;
    return found;
}
ToDoList * currentToDoList(vector<ToDoList> *todoLists, int * curList){
    return &(*todoLists)[*curList-1];
}
bool isFormatSeparator(char c){
    if(c == ',' && c == '\n')
        return true;
    return false;
}
string getSection(string data, int &focus){
    string section;
    while(data[++focus] != ',')
        section += data[focus];
    return section;
}
string * getDataArray(string data){
    string * sections = new string[DATA_SIZE];
    int focus = -1;
    for(int i = 0; i < DATA_SIZE; i++)
        sections[i] = getSection(data, focus);
    return sections;
}
vector<CheckItem> getChecklistData(string data){
    vector<CheckItem> checkItems;
    int focus = 0;
    while(data[focus++] != '{');
    while(data[focus] != '}'){
        while(data[focus] != '[')
            focus++;
        string title;
        bool checked = false;
        while(data[++focus] != ',')
            title += data[focus];
        if(data[++focus] == 't')
            checked = true;
        while(data[++focus] != ']');
        checkItems.push_back(CheckItem(title, checked));
        focus++;
    }
    return checkItems;
}
void retrieveNote(ToDoList *todoList, string curLine){
    Note note(getDataArray(curLine), getChecklistData(curLine));
    todoList->addNote(note);
}

string getListName(string curLine){
    int commas = 0;
    string listName;
    for(int i = 0; curLine[i] != '\n'; i++){
        if(curLine[i] != ','){
            continue;
        }
        commas++;
        if(commas != 3)
            continue;
        while(curLine[++i] != ',')
            listName += curLine[i];
        break;
    }
    return listName;
}

bool listExists(vector<ToDoList> todoLists, string listName){
    for(ToDoList todoList : todoLists)
        if(todoList.getTitle() == listName)
            return true;
    return false;
}
vector<string> readTitlesDB(){
    string titleLine = getTitleLine();
    vector<string> titles;
    int focus = 0;
    titleLine+='\n';
    while(titleLine[focus] != '\n' && titleLine[focus] != 0){
        string title = "";
        while(titleLine[focus] != ',' && titleLine[focus] != '\n')
            title+=titleLine[focus++];
        titles.push_back(title);
        focus++;
    }
    return titles;
}
void writeTitleDB(string title){
    string write = "", rd = dbRead();
    for(string x : readTitlesDB())
        write += x + ",";
    write += title + "\n";
    write += rd;
    ofstream file("db");
    file << write;
    file.close();
}

void addList(vector<ToDoList> *todoLists, string listName){
    todoLists->push_back(ToDoList(listName));
    writeTitleDB(listName);
}


void deleteListNotesInDB(string title){
    ifstream file = getDBStream();
    string temp, write = "";
    while(getline(file, temp)){
        if(getListTitleSection(temp) != title)
            write += temp + "\n";
    }
    overwriteDataToDB(write);
}

void deleteListInDB(string title){
    vector<string> titles = readTitlesDB();
    string data;
    int i = 0;
    for(string x : titles){
        if(x == title)
            break;
        i++;
    }
    titles.erase(std::next(titles.begin(), i));
    for(string x : titles)
        data += x + ",";
    data[data.size()-1] = '\n';
    writeTitleLine(data);
    deleteListNotesInDB(title);
}

void removeList(vector<ToDoList> *todoLists, int index){
    deleteListInDB((*todoLists)[index].getTitle());
    todoLists->erase(std::next(todoLists->begin(), index));
}

void mkDefaultLists(vector<ToDoList> *todoLists){
    addList(todoLists, "ToDo");
    addList(todoLists, "Doing");
    addList(todoLists, "Done");
}

ToDoList * getByTitle(vector<ToDoList> *todoLists, string title){
    for(ToDoList &x : *todoLists)
        if(x.getTitle() == title)
            return &x;
    return &(*todoLists)[0];
}

void initLists(vector<ToDoList> *todoLists){
    ifstream file("db");
    if(!file){
        mkDefaultLists(todoLists);
        return;
    }
    vector<string> listNames = readTitlesDB();
    for(string listName : listNames)
        todoLists->push_back(ToDoList(listName));
    file.close();
    file = ifstream("db");
    string curLine = "";
    getline(file,curLine);
    while(getline(file, curLine)){
        retrieveNote(getByTitle(todoLists, getListName(curLine)), curLine);
    }
    file.close();
}
