#include "../checklist/removecheckmenu.h"

class ChecklistMenu : public Menu{
private:
    Note *note = new Note;
    int curCheck = 1;
    void changeCheckitem(){
        int index = 0;
        while(true){
            printBar();
            printInfo();
            printBar();
            index = promptInt("Enter the checklist number: ");
            clearTerm();
            if(index <= note->getChecklist()->size() && index > 0)
                break;
            cout << "\nInvalid number, Try Again!";
        }
        curCheck = index;
    }
public:
    ChecklistMenu(){
        maxOpts = 5;
        menu();
    }
    ChecklistMenu(Note * note) {
        this->note = note;
        maxOpts = 5;
        menu();
    }
    void printHelp() override{
        cout << "Here are the options for managing the checklist: \n";
        cout << "1) Change selected Checklist Item\n";
        cout << "2) Toggle Check\n";
        cout << "3) Add Checklist Item\n";
        cout << "4) Remove Checklist Item\n";
        cout << "5) Back\n";
    }
    void printInfo() override{
        note->getChecklist()->printCheckListIndexed(curCheck);
    }
    void printTargetInfo() override {
        /*cout << "selected: ";*/
        /*note->getChecklist()->printCheckItem(curCheck-1);*/
    }
    bool options(int option) override{
        cin.get();
        switch(option){
            case 1:
                if(note->getChecklist()->checkItems.empty())
                    break;
                changeCheckitem();
                break;
            case 2:
                if(note->getChecklist()->checkItems.empty())
                    break;
                note->getChecklist()->toggleCheck(curCheck-1);
                break;
            case 3:
                {
                    AddCheckMenu check(note);
                }
                break;
            case 4:
                {
                    RemoveCheckMenu removeCheckMenu(note);
                }
                break;
            case 5:
                return true;
        }
        return false;
    }
};
