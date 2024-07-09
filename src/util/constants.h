#include <iostream>

using std::string;

const int DATA_SIZE = 4;



const int JAN_DAYS = 31;
const int FEB_DAYS = 29;
const int FEB_DAYS_LEAP = 29;
const int MAR_DAYS = 31;
const int APR_DAYS = 30;
const int MAY_DAYS = 31;
const int JUN_DAYS = 30;
const int JUL_DAYS = 31;
const int AUG_DAYS = 31;
const int SEP_DAYS = 30;
const int OCT_DAYS = 31;
const int NOV_DAYS = 30;
const int DEC_DAYS = 31;

const int MONTH_MAX_DAYS[12] = 
{
    JAN_DAYS,
    FEB_DAYS,
    MAR_DAYS,
    APR_DAYS,
    MAY_DAYS,
    JUN_DAYS,
    JUL_DAYS,
    AUG_DAYS,
    SEP_DAYS,
    OCT_DAYS,
    NOV_DAYS,
    DEC_DAYS
};

const string MONTH_NAMES[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

