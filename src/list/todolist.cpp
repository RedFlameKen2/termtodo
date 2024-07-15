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
vector<string> getTitlesInSection(string titleLine){
    cout << "step 3\n";
    vector<string> titles;
    int focus = 0;
    titleLine+='\n';
    while(titleLine[focus] != '\n'){
        cout << "iteration\n";
        string title = "";
        while(titleLine[focus] != ',' && titleLine[focus] != '\n'){
            title+=titleLine[focus++];
        }
        titles.push_back(title);
        focus++;
    }
    return titles;
}
vector<string> readTitlesDB(){
    cout << "step 2\n";
    vector<string> titles;
    titles = getTitlesInSection(getTitleLine());
    cout << "step 4\n";
    return titles;
}
//TODO: finish write
void writeTitleDB(string title){
    string write = "", rd = dbRead();
    cout << "step 1\n";
    for(string x : readTitlesDB())
        write += x + ",";
    cout << "step 5\n";
    write += title + "\n";
    write += rd;
    cout << write << "\n";
    std::ofstream file("db");
    file << write;
    file.close();
}

void addList(vector<ToDoList> *todoLists, string listName){
    todoLists->push_back(ToDoList(listName));
    writeTitleDB(listName);
}

//TODO: init with the list names first
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
