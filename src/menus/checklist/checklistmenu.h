#include "../menu.h"

class ChecklistMenu : public Menu{
private:
public:
    ChecklistMenu(){
        maxOpts = 4;
    }
    void printHelp(){
        cout << "Here are the options for managing the checklist: ";
        cout << "1) List Checklist Items\n";
        cout << "2) Add Checklist Item\n";
        cout << "3) Remove Checklist Item\n";
        cout << "4) Back\n";
    }
    bool options(int option){
        switch(option){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }
        return false;
    }
};

void checklistMenu(Note note);
