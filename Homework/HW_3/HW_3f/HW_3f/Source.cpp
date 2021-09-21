#include "Time.h"

void getTime(Time&);
bool isTimeValid(Time&);
void addOneSecond(Time&);
void displayTime(Time&);


int const MAX_HOURS = 23;
int const MAX_MINS = 59;
int const MAX_SECS = 59;


int main()
{
	Time hours;
	Time minutes;
	Time seconds;

	Time currentTime{};

	getTime(currentTime);
	addOneSecond(currentTime);
	displayTime(currentTime);

	return 0;
}


void getTime(Time& currentTime)
{
	do {
		cout << "Enter the time in \"military time\", (24-hour format),\n" 
			 << " in the following order : HH:MM:SS, (Hours, Minutes, Seconds).\n";

		cout << "\nHours:  ";
		cin >> currentTime.hours;

		cout << "Minutes:  ";
		cin >> currentTime.minutes;

		cout << "Seconds:  ";
		cin >> currentTime.seconds;

	} while (isTimeValid(currentTime) == false);
}

bool isTimeValid(Time& currentTime)
{
	if (((currentTime.hours >= 0) && (currentTime.hours <= MAX_HOURS)) &&
		((currentTime.minutes >= 0) && (currentTime.hours <= MAX_MINS)) &&
		((currentTime.seconds >= 0) && (currentTime.seconds <= MAX_SECS)))
	{
		return true;
	}
	else {
		cout << "\nInvalid time.\n";
		return false;
	}
}

void addOneSecond(Time& currentTime)
{
	currentTime.seconds++;
	
	if (currentTime.seconds > MAX_SECS)
	{
		currentTime.seconds = 0;
		currentTime.minutes++;

		if (currentTime.minutes > MAX_MINS)
		{
			currentTime.minutes = 0;
			currentTime.hours++;

			if (currentTime.hours > MAX_HOURS)
			{
				currentTime.hours = 0;
			}
		}
	}
}


void displayTime(Time& currentTime)
{
	char again;

	cout << "\nAfter adding one second, the time is ";
	cout.fill('0');
	cout << setw(2) << currentTime.hours << ":";
	cout.fill('0');
	cout << setw(2) << currentTime.minutes << ":";
	cout.fill('0');
	cout << setw(2) << currentTime.seconds << "." << endl << endl;

	cout << "Do it again? (Y/N)";
	cin >> again;

	if (toupper(again) == 'Y')
	{
		main();
	}

}



/* ================================ Output #1 ==================================

Enter the time in "military time", (24-hour format),
 in the following order : HH:MM:SS, (Hours, Minutes, Seconds).

Hours:  14
Minutes:  44
Seconds:  22

After adding one second, the time is 14:44:23.

Do it again? (Y/N) y

============================================================================ */

/* ================================ Output #2 ==================================

Enter the time in "military time", (24-hour format),
 in the following order : HH:MM:SS, (Hours, Minutes, Seconds).

Hours:  1
Minutes:  9
Seconds:  59

After adding one second, the time is 01:10:00.

Do it again? (Y/N) y

============================================================================ */

/* ================================ Output #3 ==================================

Enter the time in "military time", (24-hour format),
 in the following order : HH:MM:SS, (Hours, Minutes, Seconds).

Hours:  21
Minutes:  59
Seconds:  59

After adding one second, the time is 22:00:00.

Do it again? (Y/N) y

============================================================================ */

/* ================================ Output #4 ==================================

Enter the time in "military time", (24 - hour format),
in the following order : HH:MM:SS, (Hours, Minutes, Seconds).

Hours : 23
Minutes : 59
Seconds : 59

After adding one second, the time is 00 : 00 : 00.

Do it again ? (Y / N) y

============================================================================ */

/* ================================ Output #5 ==================================

Enter the time in "military time", (24 - hour format),
in the following order : HH:MM:SS, (Hours, Minutes, Seconds).

Hours:  27
Minutes : 23
Seconds : 11

Invalid time.
Enter the time in "military time", (24 - hour format),
in the following order : HH:MM:SS, (Hours, Minutes, Seconds).

============================================================================ */