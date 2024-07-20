#include "../checklist/removecheckmenu.h"

class RemoveCheckMenu : public Menu {
    private:
    int index;
    Note * note;
    public:
    RemoveCheckMenu();
    maxOpts = 3;
    menu();
}
RemoveCheckMenu(Note * note) : note(note){
    maxOpts = 3;
    menu();
}
void printHelp() override{
    cout << "Here are the options for removing a checklist Item: \n";
    cout << "1) Select the Item to remove\n";
    cout << "2) Finish\n";
    cout << "3) Cancel\n";
}
void printInfo() override{
    if (note->getChecklist()->size()> 0) {
        cout << "Current Checklist Items:\n";
        for (int i = 0; i < note->getChecklist()->size(); i++){
            auto item = note->getChecklist()->get(i);
            cout << i << ")[" << (item.checked ? "x": " ") << "] Title: " << item.title << "\n";
        }
    }
}
else
{
    cout << "No items in the checklist.\n";
}
void printTargetInfo() override {
}
bool options(int option) override{
    cin.get();
    switch (option){
        case 1:
        printBar();
        if(note->getChecklist()->size()>0){
            index = promptInt("Enter the index of the item to remove: ") = 1;
            if (index >= 0 && index < note -> getChecklist()->size()){
                note ->getChecklist()->remove(index);
            }
            else{
                cout << "Invalid index. \n";
            }
            else{
                cout << "No items to remove. \n";
            }
            break;
            case 2;
            return true;
            case 3:
            return true;
        }
    }
    return false;
};

#include "removecheckmenu.h"

int main(){
    Note note;
    RemoveCheckMenu menu(&note);
    return 0;
}
