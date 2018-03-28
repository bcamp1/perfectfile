#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// convert time to military time
string toMilitary(string time) {
    string newTime; // We will return this

    // -------------Checks--------------

    // Check if TBA
    if (time == "TBA") {
        return "0";
    }

    // Check if length is correct
    if (time.length() != 6) {
        cout << "Time format is incorrect: " << time << endl;
        return "0";
    }

    string numberstr = time.substr(0, 4); // example 0150
    string suffix = time.substr(4, 2);  // example PM

    int numbers = stoi(numberstr);

    if (suffix == "am" || suffix == "AM") {
        return to_string(numbers-1200);
    } else {
        return to_string(numbers);
    }

    return newTime;
}

int main() {
    return 0;
}
