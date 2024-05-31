// Str.cpp

#include <cctype>

#include <iostream>
#include <iterator>

#include "Str.h"

using namespace std;

ostream& operator<<(ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i) {
        os << s[i];
    }
    return os;
}

// 입력 연산자
istream& operator>>(istream& is, Str& s) {
    // 기존의 값 제거
    delete[] s.value;
    char c;

    // 조건을 판별하는 것 외의 동작은 없음
    while (is.get(c) && std::isspace(c));

    // 읽을 문자가 남아있다면 다음 공백문자에
    // 도달할 때까지 문자를 읽음
    if (is) {
        do s += c;
        while (is.get(c) && !isspace(c));

        // 공백을 읽었다면 다시 스트림에 남겨둠
        if (is) {
            is.unget();
        }
    }
    return is;
}

// 입력 연산자
istream& getline(istream& is, Str& s) {
    // 기존의 값 제거
    delete[] s.value;
    char c;

    // 조건을 판별하는 것 외의 동작은 없음
    while (is.get(c) && std::isspace(c));

    // 읽을 문자가 남아있다면 다음 공백문자에
    // 도달할 때까지 문자를 읽음
    if (is) {
        do s += c;
        while (is.get(c) && !isspace(c));

        // 공백을 읽었다면 다시 스트림에 남겨둠
        if (is) {
            is.unget();
        }
    }
    return is;
}

Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

// 비교 연산자
bool operator<(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<=(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator==(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

