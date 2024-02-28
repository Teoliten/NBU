#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

inline string monthString(int tm_mon)
{
    string monthname[] = {"Jan", "Feb", "Mar", "Apr", "May", 
    "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


    return monthname[tm_mon];
}//monthString

inline string timeString(tm* ptr_time)
{
    ostringstream out_strm;

    out_strm << monthString(ptr_time->tm_mon) << " ";
    out_strm << ptr_time->tm_mday << " ";
    out_strm << 3 + ptr_time->tm_hour << ":"; 
    out_strm << ptr_time->tm_min << ":";
    out_strm << ptr_time->tm_sec << " ";
    out_strm << 1900 + ptr_time->tm_year << endl;
    return out_strm.str();
}//timeString

int main()
{
    //get current date and time
    time_t now = time(0);
    tm* ptr_local_time = localtime(&now);

    cout << timeString(ptr_local_time);

    return 0;
}//main