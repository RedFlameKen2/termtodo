#include "../duedate/duemanager.h"

//TODO: remove in db too
class RemoveCheckMenu : public Menu {
    private:
        int index;
        Note * note;
        CheckList checkList;
        void removeCheckItem(){
            printInfo();
            printBar();
            int index;
            while(true){
                index = promptInt("Enter Item number to remove: ");
                clearTerm();
                if(index <= checkList.size() && index > 0)
                    break;
                cout << "Invalid number, Try Again!\n";
            }
            checkList.remove(index-1);
        }
        void saveChecklist(){
            *(note->getChecklist()) = checkList;
        }
    public:
        RemoveCheckMenu(){
            maxOpts = 3;
            menu();
        }
        RemoveCheckMenu(Note * note) : note(note){
            this->checkList = *note->getChecklist();
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
            checkList.printCheckListIndexed();
        }
        void printTargetInfo() override {
        }
        bool options(int option) override{
            cin.get();
            switch (option){
                case 1:
                    removeCheckItem();
                    break;
                case 2:
                    saveChecklist();
                    return true;
                case 3:
                    if(promptConfirm("Are you sure you want to cancel?\nprogress will be lost"))
                        return true;
                    break;
            }
            return false;
        }
};
