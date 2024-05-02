#include <iostream>

bool isLeapYear(int year) {
    // Check if the year is divisible by 4
    if (year % 4 == 0) {
        // If divisible by 100, also check if divisible by 400
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    if (year >= 1582) {
        if (isLeapYear(year)) {
            std::cout << year << " is a leap year." << std::endl;
        }
        else {
            std::cout << year << " is not a leap year." << std::endl;
        }
    }
    else {
        std::cout << "Invalid input. Year must be >= 1582." << std::endl;
    }

    return 0;
}
