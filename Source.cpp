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

int main() {
    int year, month, day;

    while (true) {
        std::cout << "Enter a date (month day year) or Q to quit: ";
        if (!(std::cin >> month >> day >> year)) {
            break;
        }

        if (month == -1 || day == -1 || year == -1) {
            break;
        }

        int dow = dayOfWeek(month, day, year);
        if (dow == -1) {
            std::cout << "Invalid input. Please enter a valid date." << std::endl;
        }
        else {
            std::string dayOfWeekName = getDayOfWeekName(dow);
            std::string monthName = getMonthName(month);
            std::cout << dayOfWeekName << ", " << monthName << " " << day << ", " << year << std::endl;
        }
    }

    return 0;
}
