#include "../menu.h"

class ManageNoteMenu : public Menu {
private:
public:
    ManageNoteMenu(){
    }
    bool options(int option) override {
        return false;
    }
};
