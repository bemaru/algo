#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>

using namespace std;

void set_next_bus_time(string& t, int interval) 
{
    int hour = 0;
    int min = 0;
    std::ostringstream oss;

    sscanf(t.c_str(), "%d:%d", &hour, &min);

    min += interval;
    
    if(min / 60)
    {
        hour += min / 60;
        min -= 60;
    }

    oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << min;
    t = oss.str();
}

void get_previous_time(string& t, string& out) 
{
    int hour = 0;
    int min = 0;
    std::ostringstream oss;

    sscanf(t.c_str(), "%d:%d", &hour, &min);
    min--;
    if (min < 0) 
    {
        min = 59;
        hour--;
    }
    oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << min;
    out = oss.str();
}

string solution(int n, int t, int m, vector<string> line) 
{
    string answer = "";
    string last_passenger;
    std::string bus = "09:00";

    std::sort(line.begin(), line.end());

    for (int bus_index = 0; bus_index < n; bus_index++)
    {
        int number_of_bus_persons = 0;
        bool is_bus_full = false;

        for (auto it = line.begin(); it!= line.end();)
        {
            if (*it <= bus) 
            {
                number_of_bus_persons++;
                last_passenger = *it;
                it = line.erase(it);
            }
            else 
            {
                it++;
            }

            if (number_of_bus_persons >= m) 
            {
                is_bus_full = true;
                break;
            }
        }

        if (bus_index == n - 1) 
        {
            if (is_bus_full) 
            {
                // 막차를 못타기 때문에 새치기
                get_previous_time(last_passenger, answer);
            }
            else 
            {
                // 막차시간
                answer = bus;
            }
        }

        set_next_bus_time(bus, t);
    }
    
    return answer;
}

void main()
{
    /*
n	t	m	timetable	answer
1	1	5	[08:00, 08:01, 08:02, 08:03]	09:00
2	10	2	[09:10, 09:09, 08:00]	09:09
2	1	2	[09:00, 09:00, 09:00, 09:00]	08:59
1	1	5	[00:01, 00:01, 00:01, 00:01, 00:01]	00:00
1	1	1	[23:59]	09:00
10	60	45	[23:59,23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59]	18:00
    */
    int n, t, m;
    n = 1, t = 1, m = 5;    vector<string> tt = {"08:00", "08:01", "08:02", "08:03"};
    //n = 2, t = 10, n = 2;   vector<string> tt = { "09:10", "09:09", "08:00" };
    
    printf("출력 : %s",solution(n,t,m,tt).c_str());
}