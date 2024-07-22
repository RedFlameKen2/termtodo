#include "../checklist/checklistmenu.h"

class ManageDueMenu : public Menu {
private:
    Note * note = new Note;
    DueDate * dueDate = new DueDate();
public:
    ManageDueMenu(Note * note) : note(note){
        /*dueDate = &(note->dueDate);*/
        if(note->dueDate.isOn())
            dueDate = &note->dueDate;
        else
            dueDate->initCurDay();
        maxOpts = 7;
        menu();
    }
    void printHelp() override{
        cout << "List of options for managing due dates: \n";
        cout << "1) Set Day:\n";
        cout << "2) Set Month\n";
        cout << "3) Set Year\n";
        cout << "4) Set Hour\n";
        cout << "5) Set Minute\n";
        cout << "6) Save\n";
        cout << "7) Cancel\n";
    }
    void printInfo() override{
        dueDate->printDueDate();
    }
    void printTargetInfo() override{
    }
    bool options(int option) override{
        switch(option){
            case 1:
                dueDate->setDay();
                break;
            case 2:
                dueDate->setMonth();
                break;
            case 3:
                dueDate->setYear();
                break;
            case 4:
                dueDate->setHour();
                break;
            case 5:
                dueDate->setMin();
                break;
            case 6:
                note->dueDate = *dueDate;
                cout << "Due date set successfully!\n";
                return true;
            case 7:
                if(promptConfirm("Are you sure you want to exit?\nProgress will be lost"))
                    return true;
                break;

        }
        return false;
    }
};
