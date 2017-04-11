// https://www.hackerrank.com/challenges/time-conversion

#include <iostream>
#include <vector>
#include <string>

std::string militaryTime(std::string str){
	std::string t;
	int hours, min, sec;
	if(str[8] == 'P'){
		hours = (str[0] - '0') * 10 + str[1] - '0' + 12;
		min = (str[3] - '0') * 10 + str[4] - '0';
		sec = (str[6] - '0') * 10 + str[7] - '0';
	}
	else{
		hours = (str[0] - '0') * 10 + str[1] - '0';
		min = (str[3] - '0') * 10 + str[4] - '0';
		sec = (str[6] - '0') * 10 + str[7] - '0';
	}
	if(hours == 12 && str[8] == 'A')
		hours = 0;
	if(hours == 24)
		hours -= 12;
	if(hours < 10)
		t += "0";
	t += std::to_string(hours) + ":";
	if(min < 10)
		t += "0";
	t += std::to_string(min) + ":";
	if(sec < 10)
		t += "0";
	t += std::to_string(sec);
	return t;
}

int main(){
    std::string str, ans;
    std::cin >> str;

    ans = militaryTime(str);
    std::cout << ans;

    return 0;
}