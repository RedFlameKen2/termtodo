#include <iostream>

using std::string;
using std::ifstream;

void clearTerm();
void notify();
void writeDB(string data);
void updateDB(string data, int id);
void deleteInDB(int id);
void printBar();
void writeTitleLine(string titleData);
void overwriteDataToDB(string allData);

string getOS();
string dbRead();
string promptString(string prompt);
string getTitleLine();
string getListTitleSection(string dataLine);

int id_Randomizer();
int promptInt(string prompt);

bool promptConfirm(string prompt);
bool idExists(int id);

ifstream getDBStream();
tm getCurTime();
