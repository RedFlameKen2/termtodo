#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "../util/helpers.h"
#include "../util/monthday.h"

using std::string;
using std::cout;
using std::to_string;

//TODO: implement am/pm
class DueDate {
private:
    bool on = false;
    bool am = true;
    tm time;

    string * readDBFormat(string data){
        data += " ";
        string * dueData = new string[5];//lols
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
    bool isOn(){
        return on;
    }
    void toggle(){
        on = !on;
    }
    void initCurDay(){
        time = getCurTime();
        if(!isAM())
            am = false;
        toggle();
    }
    void setMonth(){
        int month;
        while(true){
            printBar();
            month = promptInt("Enter the Month: ");
            clearTerm();
            if(month < 12 && month > 0)
                break;
            cout << "Invalid Month, Try Again!\n";
        }
        if(time.tm_mday > MONTH_MAX_DAYS[month])
            time.tm_mday = 1;
        time.tm_mon = month-1;
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
            if(hour <= 12 && hour > 0)
                break;
            cout << "Invalid Hour, Try Again!\n";
        }
        if(hour == 12){
            if(am)
                time.tm_hour = 0;
            else
                time.tm_hour = 12;
            return;
        }
        time.tm_hour = hour + (am ? 0 : 12);
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
    void toggleAM(){
        am = !am;
        if(time.tm_hour == 12){
            if(am)
                time.tm_hour = 0;
            else
                time.tm_hour = 12;
            return;
        }
        if(am)
            time.tm_hour -= 12;
        else
            time.tm_hour += 12;
    }
    bool isAM_V(){
        return am;
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
    int get12Hour(){
        int hour = time.tm_hour;
        if(time.tm_hour == 0 || time.tm_hour == 12)
            return 12;
        if(time.tm_hour > 12)
            hour -= 12;
        return hour;
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
        cout << "\tDUEDATE: ";
        if(!on){
            cout << "Off\n";
            return;
        }
        cout << MONTH_NAMES[time.tm_mon] << " ";
        cout << time.tm_mday << ", ";
        cout << 1900 + time.tm_year << " ";
        cout << std::setfill('0') << std::setw(2) << get12Hour() << ":";
        cout << std::setfill('0') << std::setw(2) << time.tm_min;
        cout << (am ? " AM" : " PM") << "\n";
    }
    bool isAM(){
        bool am;
        if(getHour() < 12)
            am = true;
        else
            am = false;
        return am;
    }
    string getDueDateData(){
        string out;
        if(!on){
            return "Off";
        }
        out += MONTH_NAMES[time.tm_mon] + " ";
        out += to_string(time.tm_mday) + ", ";
        out += to_string(1900 + time.tm_year)+ " ";
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << get12Hour() << ":";
        ss << std::setfill('0') << std::setw(2) << time.tm_min;
        ss << (am ? " AM" : " PM");
        out += string(ss.str());
        return out;
    }
    bool sameTime(tm time){
        if  (
                this->time.tm_mon == time.tm_mon &&
                this->time.tm_mday == time.tm_mday &&
                this->time.tm_year == time.tm_year &&
                this->time.tm_hour == time.tm_hour &&
                this->time.tm_min == time.tm_min
            )
            return true;
        return false;
    }
    void updateDueDate(DueDate dueDate){
        on = dueDate.isOn();
        time.tm_mon = dueDate.time.tm_mon;
        time.tm_mday = dueDate.time.tm_mday;
        time.tm_year = dueDate.time.tm_year;
        time.tm_hour = dueDate.time.tm_hour;
        time.tm_min = dueDate.time.tm_min;
    }
};
