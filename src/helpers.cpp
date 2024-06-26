#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <thread>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::this_thread::sleep_for;
using std::ofstream;
using std::ifstream;

string getOS(){
    #ifdef _WIN64
        return "Windows 64 bit";
    #elif _WIN32
        return "Windows 32 bit";
    #elif __linux__
        return "Linux";
    #endif 
}

string dbRead(){
    ifstream file("db");
    string rd = "", temp = "";
    while(std::getline(file, temp))
        rd += temp + "\n";
    return rd;
};

void dbWrite(){
    string write = "", ret = dbRead();
    ofstream file("db");
    write += ret;
    write += "test1\nbreh\n";
    file << write;
    file.close();
}


void notify(){
    using namespace std::chrono_literals;
    while(true){
        if(getOS() == "Linux")
            system("notify-send -u normal 'hey, attention'");
        else if(getOS() == "Windows 64 bit" || getOS() == "Windows 32 bit") 
            system("msg %user% /server:%computername% /time:300 'hey, attention'");
        sleep_for(10s);
    }
}

void printSomething(){
    cout << "Enter anything: ";
    string input; 
    getline(cin, input);
    cout << "output:\n" << input << endl;
}
