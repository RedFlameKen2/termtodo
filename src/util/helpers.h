#include <iostream>

using std::string;

/*void dbWrite();*/
void clearTerm();
void notify();
void writeDataToDb(string data);
void updateDB(string data, int id);
void deleteInDB(int id);
void printBar();

string getOS();
string dbRead();
string promptString(string prompt);

int id_Randomizer();
int promptInt(string prompt);

bool promptConfirm(string prompt);
bool idExists(int id);
