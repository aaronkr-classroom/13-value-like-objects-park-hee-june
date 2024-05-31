// Str.cpp

#include <cctype>
#include <cstring>
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

// �Է� ������
istream& operator>>(istream& is, Str& s) {
    // ������ �� ����
    delete[] s.value;
    char c;

    // ������ �Ǻ��ϴ� �� ���� ������ ����
    while (is.get(c) && std::isspace(c));

    // ���� ���ڰ� �����ִٸ� ���� ���鹮�ڿ�
    // ������ ������ ���ڸ� ����
    if (is) {
        do s.value += c;
        while (is.get(c) && !isspace(c));

        // ������ �о��ٸ� �ٽ� ��Ʈ���� ���ܵ�
        if (is) {
            is.unget();
        }
    }
    return is;
}

// �Է� ������
istream& getline(istream& is, Str& s) {

    char c;
    while (is.get(c) && c != '\n')
        s += c;
    return is;
    // ������ �� ����
    
}

Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const Str& s, const char* t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const char* t, const Str& s) {
    Str r(t);
    r += s;
    return r;
}

// �� ������
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
