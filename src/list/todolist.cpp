#include <cstdio>
#include <fstream>
#include "todolist.h"

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
    for(int i = 0; i < getDataArray(curLine)->size(); i++)
        cout << *getDataArray(curLine);
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

void mkDefaultLists(vector<ToDoList> *todoLists){
    todoLists->push_back(ToDoList("ToDo"));
    todoLists->push_back(ToDoList("Doing"));
    todoLists->push_back(ToDoList("Done"));
}

void addList(vector<ToDoList> *todoLists, string listName){
    todoLists->push_back(ToDoList(listName));
}

ToDoList * getByTitle(vector<ToDoList> *todoLists, string title){
    for(ToDoList &x : *todoLists)
        if(x.getTitle() == title)
            return &x;
    return &(*todoLists)[0];
}

void initLists(vector<ToDoList> *todoLists){
    std::ifstream file("db");
    if(!file){
        mkDefaultLists(todoLists);
        return;
    }
    vector<string> listNames;
    string curLine = "";
    while(getline(file, curLine)){
        string listName = getListName(curLine);
        if(!listExists(*todoLists, listName))
            listNames.push_back(listName);
    }
    file.close();
    for(string x : listNames){
        addList(todoLists, x);
    }
    file = ifstream("db");
    int i = 0;
    while(getline(file, curLine)){
        retrieveNote(getByTitle(todoLists, getListName(curLine)), curLine);
        i++;
    }
}
