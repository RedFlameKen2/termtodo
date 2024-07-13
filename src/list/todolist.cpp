#include <cstdio>
#include <fstream>
#include <string>
#include "todolist.h"

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

void mkDefaultLists(vector<ToDoList> *todoLists){
    todoLists->push_back(ToDoList("ToDo"));
    todoLists->push_back(ToDoList("Doing"));
    todoLists->push_back(ToDoList("Done"));
}

void addList(vector<ToDoList> *todoLists, string listName){
    todoLists->push_back(ToDoList(listName));
}

void initLists(vector<ToDoList> *todoLists){
    std::ifstream file("db");
    if(!file){
        mkDefaultLists(todoLists);
        return;
    }
    vector<string> listNames;
    string curLine;
    int i = 0;
    while(getline(file, curLine)){
        listNames[i] = getListName(curLine);
        i++;
    }
    file.close();
    for(string x : listNames){
        addList(todoLists, x);
    }
}
