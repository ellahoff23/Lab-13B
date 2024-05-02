#include <iostream>
#include <string>

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
    if (month < 1 || month > 12 || year < 1582) {
        return -1; // Invalid input
    }

    int days = 31; // By default, assume 31 days in a month

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    }
    else if (month == 2) {
        days = (isLeapYear(year)) ? 29 : 28;
    }

    return days;
}

std::string getMonthName(int month) {
    static const std::string months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return months[month - 1]; // Adjust for array index
}

int main() {
    int year, month;

    while (true) {
        std::cout << "Enter a month and year (-1 to quit): ";
        if (!(std::cin >> month >> year)) {
            break;
        }

        if (month == -1 || year == -1) {
            break;
        }

        int numDays = daysInMonth(month, year);
        if (numDays == -1) {
            std::cout << "Invalid input. Please enter a valid month (1-12) and year (>= 1582)." << std::endl;
        }
        else {
            std::string monthName = getMonthName(month);
            std::cout << monthName << " " << year << " has " << numDays << " days." << std::endl;
        }
    }

    return 0;
}
