#include <stdio.h> 
#include <memory.h>
#include <iostream>  
#include <ctime>
#include <string>

 
  
time_t strTime2unix(std::string timeStamp)  
{  
    struct tm tm;  
    memset(&tm, 0, sizeof(tm));  
      
    sscanf(timeStamp.c_str(), "%d-%d-%d %d:%d:%d",   
           &tm.tm_year, &tm.tm_mon, &tm.tm_mday,  
           &tm.tm_hour, &tm.tm_min, &tm.tm_sec);  
  
    tm.tm_year -= 1900;  
    tm.tm_mon--;  
  
    return mktime(&tm);  
}  
  
int main()  
{  
    //std::string str = "2021-04-01 12:12:12";  
    std::string str;
    std::cin >> str;
    time_t t = strTime2unix(str);
    std::cout << t << std::endl;  
    //std::cout << ctime(&t) << std::endl;  
  
    return 0;  
}   
 
 
//