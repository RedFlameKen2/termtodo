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
using std::endl;
using std::isdigit;
using std::this_thread::sleep_for;
using std::ofstream;
using std::ifstream;
using std::regex;
using std::to_string;

string getOS(){
    #ifdef _WIN64
        return "Windows 64 bit";
    #elif _WIN32
        return "Windows 32 bit";
    #elif __linux__
        return "Linux";
    #endif 
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
bool strIsDigit(string str){
    for(char c : str)
        if(!isdigit(c))
            return false;
    return true;
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
bool optionValid(int option, int max){
    if(option <= max || option > 1)
        return true;
    return false;
}
int id_Randomizer(){
	srand((unsigned) time(NULL));
	int random = (rand() % 100000);
	return random;
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
    while(std::getline(file, temp))
        rd += temp + "\n";
    file.close();
    return rd;
}
int getIDSection(string dataline){
    string id;
    int i = 0;
    while(dataline[i] != ',')
        id+=dataline[i++];
    return stoi(id);
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
void writeDataToDb(string data){
    string write = data, ret = dbRead();
    ofstream file("db");
    write += ret;
    file << write;
    file.close();
}
void updateDB(string data, int id){
    ifstream file("db");
    string rd = "", temp = "";
    while(getline(file, temp))
        if(getIDSection(temp) == id)
            rd += data;
        else
            rd += temp;
    writeDataToDb(rd);
}
void deleteInDB(int id){
    ifstream file("db");
    string rd = "", temp = "";
    while(getline(file, temp)){
        if(getIDSection(temp) == id)
            continue;
        temp += rd;
    }
    writeDataToDb(rd);
}
