#include <ctime>
#include <iostream>
#include "../helpers.h"

using std::string;
using std::cout;

class DueDate {
private:
    bool on = false;
    tm time;
public:
    DueDate(){
        time_t t;
        time = *localtime(&t);
    }
    void setMonth(){
        int month;
        while(true){
            printBar();
            month = promptInt("Enter the Month: ");
            clearTerm();
            if(month <= 12 && month > 0)
                break;
            cout << "Invalid Month, Try Again!";
        }
        time.tm_mday = month;
    }
    void setDay(){
        int day;
        while(true){
            printBar();
            day = promptInt("Enter the Day: ");
            clearTerm();
            if(day <= time.tm_mday && day > 0)
                break;
            cout << "Invalid Month, Try Again!";
        }
        time.tm_mon = day;
    }
    void setYear(int year){
        time.tm_year = year;
    }
    void setHour(int hour){
        time.tm_hour = hour;
    }
    void setMin(int min){
        time.tm_min = min;
    }
    int getMonth(){
        return time.tm_mon;
    }
    int getDay(){
        return time.tm_mday;
    }
    int getYear(){
        return time.tm_year;
    }
    int getHour(){
        return time.tm_hour;
    }
    int getMin(){
        return time.tm_min;
    }
    string getDBFormat(){
        if(!on)
            return "off";
        string write;
        write+=time.tm_mon;
        write+=" ";
        write+=time.tm_mday;
        write+=" ";
        write+=time.tm_year;
        write+=" ";
        write+=time.tm_hour;
        write+=" ";
        write+=time.tm_min;
        return write;
    }
};
