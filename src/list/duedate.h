#include <ctime>
#include <iomanip>
#include <iostream>
#include "../util/helpers.h"
#include "../util/monthday.h"

using std::string;
using std::cout;
using std::to_string;

class DueDate {
private:
    bool on = false;
    tm time;

    string * readDBFormat(string data){
        data += " ";
        string * dueData = new string[5];
        int j = 0;
        for(int i = 0; i < 5; i++){
            while(data[j] != ' ')
                dueData[i] += data[j++];
            j++;
        }
        return dueData;
    }
public:
    DueDate(){
    }
    DueDate(string data){
        if(data == "off")
            return;
        on = true;
        string * dueData = readDBFormat(data);
        time.tm_mon = stoi(dueData[0]);
        time.tm_mday = stoi(dueData[1]);
        time.tm_year = stoi(dueData[2]);
        time.tm_hour = stoi(dueData[3]);
        time.tm_min = stoi(dueData[4]);
    }
    void initCurDay(){
        time = getCurTime();
        toggleOn();
    }
    tm getCurTime(){
        time_t t = std::time(new time_t);
        tm time = *localtime(&t);
        return time;
    }
    void toggleOn(){
        on = !on;
    }
    //TODO: Make day change when the set month doesn't support the day
    void setMonth(){
        int month;
        while(true){
            printBar();
            month = promptInt("Enter the Month: ");
            clearTerm();
            if(month < 12 && month >= 0)
                break;
            cout << "Invalid Month, Try Again!\n";
        }
        if(time.tm_mday > MONTH_MAX_DAYS[month])
            time.tm_mday = 1;
        time.tm_mon = month;
    }
    void setDay(){
        int day;
        while(true){
            printBar();
            day = promptInt("Enter the Day: ");
            clearTerm();
            if(day <= TimeUtil::getMaxMonthDay(time.tm_mon, time.tm_year) && day > 0)
                break;
            cout << "Invalid Day, Try Again!\n";
        }
        time.tm_mday = day;
    }
    void setYear(){
        int year;
        while(true){
            printBar();
            year = promptInt("Enter the Year: ");
            clearTerm();
            if(year >= 2000)
                break;
            cout << "The Past is in the past, buddy. Try Again!\n";
        }
        time.tm_year = year-1900;
    }
    void setHour(){
        int hour;
        while(true){
            printBar();
            hour = promptInt("Enter the Hour: ");
            clearTerm();
            if(hour < 24 && hour > 0)
                break;
            cout << "Invalid Hour, Try Again!\n";
        }
        time.tm_hour = hour;
    }
    void setMin(){
        int min;
        while(true){
            printBar();
            min = promptInt("Enter the Minute: ");
            clearTerm();
            if(min < 60 && min >= 0)
                break;
            cout << "Invalid Minute, Try Again!\n";
        }
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
        write+=to_string(time.tm_mon);
        write+=" ";
        write+=to_string(time.tm_mday);
        write+=" ";
        write+=to_string(time.tm_year);
        write+=" ";
        write+=to_string(time.tm_hour);
        write+=" ";
        write+=to_string(time.tm_min);
        return write;
    }
    void printDueDate(){
        cout << "DueDate: ";
        if(!on){
            cout << "Off\n";
            return;
        }
        cout << MONTH_NAMES[time.tm_mon] << " ";
        cout << time.tm_mday << ", ";
        cout << 1900 + time.tm_year << " ";
        cout << std::setfill('0') << std::setw(2) << time.tm_hour << ":";
        cout << std::setfill('0') << std::setw(2) << time.tm_min << "\n";
    }
};
