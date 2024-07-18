#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <regex>
#include <thread>
#include "helpers.h"

using std::cout;
using std::cin;
using std::string;
using std::isdigit;
using std::this_thread::sleep_for;
using std::ofstream;
using std::ifstream;
using std::regex;
using std::vector;


int getIDSection(string dataline){
    string id;
    int i = 0;
    while(dataline[i] != ',')
        id+=dataline[i++];
    return stoi(id);
}

string stolower(string &chars){
    string out;
    for(char c : chars)
        out += tolower(c);
    return out;
}

bool strIsDigit(string str){
    for(char c : str)
        if(!isdigit(c))
            return false;
    return true;
}
bool optionValid(int option, int max){
    if(option <= max || option > 1)
        return true;
    return false;
}
vector<string> getDBLines(){
    ifstream file("db");
    vector<string> rd;
    string temp = "";
    while(getline(file, temp))
        rd.push_back(temp + "\n");
    file.close();
    return rd;
}
vector<int> getIDArray(){
    vector<int> ids;
    vector<string> dataLines = getDBLines();
    for(string data : dataLines)
        ids.push_back(getIDSection(data));
    return ids;
}
/*void dbWrite(){*/
/*    string write = "", ret = dbRead();*/
/*    ofstream file("db");*/
/*    write += ret;*/
/*    write += "" + to_string(id_Randomizer());*/
/*    write += ",fuck this shit i\'m out,ok fine,{[git add .,true][git push,false]}\n";*/
/*    file << write;*/
/*    file.close();*/
/*}*/
string getTitleLine(){
    ifstream file("db");
    string titleLine;
    getline(file, titleLine);
    file.close();
    return titleLine;
}
void writeDB(string data){
    string write = getTitleLine() + "\n";
    write += dbRead();
    ofstream file("db");
    write += data;
    file << write;
    file.close();
}
ifstream getDBStream(){
    ifstream file("db");
    string x;
    getline(file, x);
    return file;
}
void overwriteDataToDB(string allData){
    string write = getTitleLine() + "\n";
    ofstream file("db");
    write += allData;
    file << write;
    file.close();
}
void clearTerm(){
    if(getOS() == "Linux")
        system("clear");
    else if (getOS() == "Windows 64 bit" || getOS() == "Windows 32 bit")
        system("cls");
}

void notify(){
    using namespace std::chrono_literals;
    while(true){
        if(getOS() == "Linux")
            system("notify-send -u normal 'hey, attention'");
        else if(getOS() == "Windows 64 bit" || getOS() == "Windows 32 bit") 
            system("msg %username% /server:%computername% /time:300 'hey, attention'");
        sleep_for(10s);
    }
}
void updateDB(string data, int id){
    ifstream file = getDBStream();
    string rd = "", temp = "";
    while(getline(file, temp))
        if(getIDSection(temp) == id)
            rd += data;
        else
            rd += temp + "\n";
    overwriteDataToDB(rd);
}

void deleteInDB(int id){
    ifstream file = getDBStream();
    string rd = "", temp = "";
    while(getline(file, temp)){
        if(getIDSection(temp) != id)
            rd += temp + "\n";
    }
    overwriteDataToDB(rd);
}

void printBar(){
    cout << "\n=====================================================\n";
}

string promptString(string prompt){
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}
string dbRead(){
    ifstream file("db");
    string rd = "", temp = "";
    getline(file,temp);
    while(getline(file, temp))
        rd += temp + "\n";
    file.close();
    return rd;
}
string getOS(){
    #ifdef _WIN64
        return "Windows 64 bit";
    #elif _WIN32
        return "Windows 32 bit";
    #elif __linux__
        return "Linux";
    #endif 
}
int id_Randomizer(){
	srand((unsigned) time(NULL));
	int random = (rand() % 100000);
	return random;
}

int promptInt(string prompt){
    string input = "";
    while(true){
        cout << prompt;
        cin >> input;
        if(strIsDigit(input))
            break;
        cout << "Invalid Input, try again!\n";
    }
    return stoi(input);
}

bool promptConfirm(string prompt){
    string input;
    while(true){
        printBar();
        cout << prompt << "(y)es/(n)o\nEnter Answer: ";
        cin >> input;
        clearTerm();
        stolower(input);
        if(input == "y" || input == "n" || input == "yes" || input == "no")
            break;
        printBar();
        cout << "Invalid input, Try Again!\n";
    }
    if(input[0] == 'y')
        return true;
    return false;
}
bool idExists(int id){
    vector<int> ids = getIDArray();
    for(int x : ids)
        if(x == id)
            return true;
    return false;
}
tm getCurTime(){
    time_t t = std::time(new time_t);
    tm time = *localtime(&t);
    return time;
}
