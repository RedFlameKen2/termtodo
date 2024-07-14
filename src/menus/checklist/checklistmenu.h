#include "../checklist/addcheckmenu.h"

class ChecklistMenu : public Menu{
private:
    Note *note = new Note;
public:
    ChecklistMenu(){
        maxOpts = 3;
        menu();
    }
    ChecklistMenu(Note * note) {
        this->note = note;
        maxOpts = 3;
        menu();
    }
    void printHelp() override{
        cout << "Here are the options for managing the checklist: \n";
        cout << "1) Add Checklist Item\n";
        cout << "2) Remove Checklist Item\n";
        cout << "3) Back\n";
    }
    void printInfo() override{
        note->getChecklist()->printCheckList();
    }
    void printTargetInfo() override {
    }
    bool options(int option) override{
        cin.get();
        switch(option){
            case 1:
                {
                    AddCheckMenu check(note);
                }
                break;
            case 2:
                {
                }
                break;
            case 3:
                return true;
        }
        return false;
    }
};
