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
    void removeNoteByID(int id){
        for(int i = 0; i < notes.size(); i++)
            if(notes[i].id == id)
                notes.erase(std::next(notes.begin(), i));
    }
    void removeNoteByTitle(string title){
        for(int i = 0; i < notes.size(); i++)
            if(notes[i].title == title)
                notes.erase(std::next(notes.begin(), i));
    }
    string getTitle(){
        return title;
    }
    bool listEmpty(){
        return notes.empty();
    }
    void printNotes(){
        cout << "[Notes of the List " << (title) << "]\n";
        if(notes.empty()){
            cout << "The list is empty!\n";
            return;
        }
        for(Note note : notes){
            note.printData();
        }
    }
    void printNotesMin(){
        if(notes.empty()){
            cout << "The list is empty!\n";
            return;
        }
        cout << "Notes of the List " << title << ": \n";
        int i = 0;
        for(Note note : notes){
            cout << to_string(++i) << ") " << note.title << "\n";
        }
    }
    vector<Note> * getNotes(){
        return &notes;
    }
    Note * getNote(int index){
        return &notes[index];
    }
    void moveNote(ToDoList todoList, int index){
        Note note = notes[index];
        removeNote(index);
        todoList.addNote(note);
    }
};
/*void updateDB(vector<ToDoList> todoLists);*/
ToDoList getByTitle(vector<ToDoList> todoLists);
ToDoList * currentToDoList(vector<ToDoList> *todoLists, int * curList);
void initLists(vector<ToDoList> *todoLists);
void addList(vector<ToDoList> *todoLists, string listName);
void removeList(vector<ToDoList> *todoLists, int * curList, int index);
bool listExists(vector<ToDoList> *todoLists, string title);
