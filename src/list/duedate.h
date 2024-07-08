#include <iostream>

using std::string;

class DueDate {
private:
    bool on = false;
    tm time;
public:
    DueDate(){
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
    void setMonth(int month){
        time.tm_mday = month;
    }
    void setDay(int day){
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
};
