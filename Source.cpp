#include <string>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int day, int month, int year); // Update function declaration
void generateCalendar(int month, int year);

int main()
{
    string monthInput, yearInput;
    while (true) {
        cout << "Enter a month and year or Q to quit: ";
        cin >> monthInput;
        if (monthInput == "Q" || monthInput == "q") {
            break;
        }
        cin >> yearInput;

        string monthName = monthInput.substr(0, 3);
        int year = stoi(yearInput);

        if (monthName == "Jan") {
            generateCalendar(1, year);
        }
        else if (monthName == "Feb") {
            generateCalendar(2, year);
        }
        else if (monthName == "Mar") {
            generateCalendar(3, year);
        }
        else if (monthName == "Apr") {
            generateCalendar(4, year);
        }
        else if (monthName == "May") {
            generateCalendar(5, year);
        }
        else if (monthName == "Jun") {
            generateCalendar(6, year);
        }
        else if (monthName == "Jul") {
            generateCalendar(7, year);
        }
        else if (monthName == "Aug") {
            generateCalendar(8, year);
        }
        else if (monthName == "Sep") {
            generateCalendar(9, year);
        }
        else if (monthName == "Oct") {
            generateCalendar(10, year);
        }
        else if (monthName == "Nov") {
            generateCalendar(11, year);
        }
        else if (monthName == "Dec") {
            generateCalendar(12, year);
        }
        else {
            cout << "Invalid month input!" << endl;
        }
    }

    return 0;
}

void generateCalendar(int month, int year)
{
    string abrv;
    switch (month) {
    case 1: abrv = "January"; break;
    case 2: abrv = "February"; break;
    case 3: abrv = "March"; break;
    case 4: abrv = "April"; break;
    case 5: abrv = "May"; break;
    case 6: abrv = "June"; break;
    case 7: abrv = "July"; break;
    case 8: abrv = "August"; break;
    case 9: abrv = "September"; break;
    case 10: abrv = "October"; break;
    case 11: abrv = "November"; break;
    case 12: abrv = "December"; break;
    }

    int number = daysInMonth(month, year);
    int weekday = dayOfWeek(1, month, year); // Pass 1 as day for dayOfWeek

    string weekdays[7] = { "Su ", "Mo ", "Tu ", "We ", "Th ", "Fr ", "Sa " };
    int days[31];
    for (int i = 0; i < number; i++) {
        days[i] = i + 1;
    }

    cout << abrv << " " << year << endl;

    for (const string& day : weekdays) {
        cout << day << " ";
    }
    cout << endl;

    int spaces = (weekday + 7) % 7; // Calculate starting day offset
    for (int i = 0; i < spaces; i++) {
        cout << "    ";
    }

    for (int i = 1; i <= number; i++) {
        cout << (i < 10 ? " " : "") << i << "  ";
        if ((i + spaces) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}


bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int daysInMonth(int month, int year)
{
    switch (month) {
    case 2:
        return isLeapYear(year) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

int dayOfWeek(int day, int month, int year)
{
    static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}




