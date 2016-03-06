#include <iostream>
#include <string>

std::string convertTime (int seconds)
{
	int minutes = 0;
	int hours = 0;

	if (seconds > 59)
	{
		minutes = seconds / 60;
		seconds = seconds % 60;
		if (minutes > 59)
		{
			hours = minutes / 60;
			minutes = minutes % 60;
		}
	}
	std::string str = std::to_string (hours) + ":" + std::to_string (minutes) + ":" + std::to_string (seconds);
	return str;
}

int main ()
{
	while (true)
	{
		int seconds;
		std::cout << "Enter seconds: ";
		std::cin >> seconds;
		std::cout << convertTime (seconds) << std::endl;
	}
	return 0;
}