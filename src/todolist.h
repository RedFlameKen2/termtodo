#include <iostream>
#include "notes.h"

using std::string;

class ToDoList {
private:
    string title;
    vector<Note> notes;
    void initNotes(){
    }
public:
    ToDoList(){
        initNotes();
    }
    ToDoList(string title){
        this->title = title;
        initNotes();
    }
    void addNote(Note note){
        notes.push_back(note);
    }
    void removeNote(int index){
        notes.erase(std::next(notes.begin(), index));
    }
    string getTitle(){
        return title;
    }
    void printNotes(){
        cout << "Notes of the List " << title << ": \n";
        for(Note note : notes){
            note.printData();
            cout << "\n\n";
        }
    }
    vector<Note>& getNotes(){
        return notes;
    }
    void moveNote(ToDoList todoList, int index){
        Note note = notes[index];
        removeNote(index);
        todoList.addNote(note);
    }
};

void listManager(vector<ToDoList> todoLists, int &curList);

