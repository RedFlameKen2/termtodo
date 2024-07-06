#include "../menu.h"

class AddCheckMenu : public Menu {
private:
    CheckItem checkItem;
    Note note;
public:
    AddCheckMenu(Note note){
        maxOpts = 5;
    }
    void printHelp(){
        cout << "Here are the options for adding a checklist Item";
        cout << "1) Set the Title\n";
        cout << "2) Toggle Checked (Default: False)\n";
        cout << "3) Finish\n";
        cout << "4) Cancel\n";
    }
    bool options(int option){
        switch(option){
            case 1:
                checkItem.title = promptString("Enter Title of CheckItem: ");
                break;
            case 2:
                checkItem.checked = !checkItem.checked;
                break;
            case 3:
                note.getChecklist().add(checkItem);
                return true;
            case 4:
                return true;
        }
        return false;

    }
};
/*void addCheckMenu(Note note);*/
