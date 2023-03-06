#include "Math.h"
#include <stdarg.h>
#include <cstring>

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return x + y;
}

int Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return x * y;
}

int Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) {
        char* result = new char[8];
        strcpy(result, "nullptr");
        return result;
    }
    else {
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int maxLen = (len1 > len2) ? len1 : len2;
        int carry = 0;
        char* result = new char[maxLen + 2];
        result[maxLen + 1] = '\0';
        for (int i = 0; i < maxLen; i++) {
            int digit1 = (i < len1) ? s1[len1 - i - 1] - '0' : 0;
            int digit2 = (i < len2) ? s2[len2 - i - 1] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result[maxLen - i] = (sum % 10) + '0';
        }
        if (carry != 0) {
            result[0] = carry + '0';
        }
        else {
            result++;
        }
        return result;
    }
}