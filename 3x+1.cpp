#include <iostream>
#include <Windows.h>

#define DARK_RED_COLOR 12
#define YELLOW_COLOR 14
#define WHITE_COLOR 15

using namespace std;


bool reaches421Loop(long long n) {
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;  
        }
        else {
            n = 3 * n + 1;
        }

        if (n <= 1) { 
            return true;
        }
    }
    return false;
}

int main() {
    long long num = 1;  // Start from 1

    while (true) {
        if (!reaches421Loop(num)) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARK_RED_COLOR);
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<NUMBERS FOUND!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW_COLOR);
            printf("Exclude one though...\n");
            cout << num << endl;  // Print the number that doesn't reach the loop
        }
        num = (num % 2 == 0) ? num + 2 : num + 4;  // Jump by 2 for evens, 4 for odds
        if (num < 1) {
            break;
        }
    }

    return 0;
}
