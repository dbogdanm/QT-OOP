#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Helper {
public:
    static bool isNumeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    static string toUpperCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }

    static bool isValidLicense(const string& license) {
        return license.length() >= 5;
    }
};

#endif
