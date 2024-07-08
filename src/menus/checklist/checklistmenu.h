#include "../checklist/addcheckmenu.h"

class ChecklistMenu : public Menu{
private:
    Note *note;
public:
    ChecklistMenu(){
        maxOpts = 4;
        menu();
    }
    ChecklistMenu(Note * note) {
        this->note = note;
        maxOpts = 4;
        menu();
    }
    void printHelp() override{
        cout << "Here are the options for managing the checklist: \n";
        cout << "1) List Checklist Items\n";
        cout << "2) Add Checklist Item\n";
        cout << "3) Remove Checklist Item\n";
        cout << "4) Back\n";
    }
    bool options(int option) override{
        cin.get();
        switch(option){
            case 1:
                note->getChecklist()->printCheckList();
                break;
            case 2:
                {
                    AddCheckMenu check(note);
                }
                break;
            case 3:
                break;
            case 4:
                return true;
        }
        return false;
    }
};
