#include <iostream>
#include <string>

int dayOfWeek(int month, int day, int year) {
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1582) {
        return -1; // Invalid input
    }

    // Adjust month and year for Zeller's congruence
    if (month <= 2) {
        month += 12;
        year--;
    }

    int K = year % 100;
    int J = year / 100;

    int h = (day + ((13 * (month + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    // Adjust h to match 0 = Saturday, 1 = Sunday, ..., 6 = Friday
    return (h + 6) % 7; // Adjusted by adding 6 instead of 5
}

std::string getDayOfWeekName(int dow) {
    static const std::string daysOfWeek[7] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    return daysOfWeek[dow];
}

std::string getMonthName(int month) {
    static const std::string months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return months[month - 1]; // Adjust for array index
}

void generateCalendar(int month, int year) {
    int dow = dayOfWeek(month, 1, year);
    std::string monthName = getMonthName(month);

    std::cout << monthName << " " << year << std::endl;
    std::cout << "Su Mo Tu We Th Fr Sa" << std::endl;

    std::string calendar[6] = {
        " 1  2  3  4  5  6  7 ",
        " 8  9 10 11 12 13 14 ",
        "15 16 17 18 19 20 21 ",
        "22 23 24 25 26 27 28 ",
        "29 30                 ",
        "                      "
    };

    for (int i = 0; i < dow; i++) {
        calendar[0].insert(0, "   ");
    }

    int daysInMonth;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    else {
        daysInMonth = 31;
    }

    int dayCounter = 1;
    for (int i = dow; i < 7; i++) {
        if (dayCounter <= daysInMonth) {
            calendar[0].insert((i * 3) + 2, std::to_string(dayCounter));
            dayCounter++;
        }
    }

    for (int i = 0; i < 6; i++) {
        std::cout << calendar[i] << std::endl;
    }
}

int main() {
    std::string monthInput, yearInput;
    while (true) {
        std::cout << "Enter a month and year (e.g., November 2023) or Q to quit: ";
        std::cin >> monthInput;
        if (monthInput == "Q" || monthInput == "q") {
            break;
        }
        std::cin >> yearInput;

        std::string monthName = monthInput.substr(0, 3);
        int year = std::stoi(yearInput);

        if (monthName == "Jan") generateCalendar(1, year);
        else if (monthName == "Feb") generateCalendar(2, year);
        else if (monthName == "Mar") generateCalendar(3, year);
        else if (monthName == "Apr") generateCalendar(4, year);
        else if (monthName == "May") generateCalendar(5, year);
        else if (monthName == "Jun") generateCalendar(6, year);
        else if (monthName == "Jul") generateCalendar(7, year);
        else if (monthName == "Aug") generateCalendar(8, year);
        else if (monthName == "Sep") generateCalendar(9, year);
        else if (monthName == "Oct") generateCalendar(10, year);
        else if (monthName == "Nov") generateCalendar(11, year);
        else if (monthName == "Dec") generateCalendar(12, year);
        else std::cout << "Invalid month input!" << std::endl;
    }

    return 0;
}
