#include "constants.h"

class TimeUtil {
private:
public:
    static bool isLeap(int year){
        if(year % 4 == 0)
            if(year % 100 == 0)
                if(year % 400 == 0)
                    return true;
        return false;
    }
    static int getMaxMonthDay(int month, int year){
        switch(month){
            case 0:
                return MONTH_MAX_DAYS[0];
            case 1:
                if(isLeap(year))
                    return FEB_DAYS_LEAP;
                return FEB_DAYS;
            case 2:
                return MONTH_MAX_DAYS[2];
            case 3:
                return MONTH_MAX_DAYS[3];
            case 4:
                return MONTH_MAX_DAYS[4];
            case 5:
                return MONTH_MAX_DAYS[5];
            case 6:
                return MONTH_MAX_DAYS[6];
            case 7:
                return MONTH_MAX_DAYS[7];
            case 8:
                return MONTH_MAX_DAYS[8];
            case 9:
                return MONTH_MAX_DAYS[9];
            case 10:
                return MONTH_MAX_DAYS[10];
            case 11:
                return MONTH_MAX_DAYS[11];
        }
        return 0;
    }
};
