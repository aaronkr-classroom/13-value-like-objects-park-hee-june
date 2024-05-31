#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <cctype>
#include <iterator>

class Str {
    // 입력 연산자
    friend std::istream& operator>>(std::istream&, Str&);
    friend std::istream& getline(std::istream&, Str&);

public:
    typedef size_t size_type;

    //비어있는 Str 객체가 만드는 기본 생성자
    Str() : value(0), length(0) { }

    // c의 복사본 n개가 있는 Str 객체를 생성
    Str(size_type n, char c) {
        //메모리 할당
        length = n;
        value = new char[length];

        //배열이 c char로 채워요
        for (size_type i = 0; i != length; ++i) {
            value[i] = c;
        }
    }

    Str(const char* cp) {
        length = std::strlen(cp);
        value = new char[length];

        std::copy(cp, cp + length, value);
    }

    Str(const Str& s) {
        length = s.length;
        value = new char[length];

        std::copy(s.value, s.value + s.length, value);
    }

    // 소멸자 
    ~Str() {
        if (value != 0)
            delete[] value;
    }

    //반복자 b와 e가 가리키는 범위에서 Str 객체를 생성
    template<class Input> Str(Input b, Input e) {
        length = e - b;
        value = new char[length];

        std::copy(b, e, value);
    }

    // 인덱스 연산자
    char& operator[](size_type i) { return value[i]; }
    const char& operator[](size_type i) const { return value[i]; }

    size_type size() const { return length; }

    // 결합 연산자
    Str& operator+=(const Str& s) {
        //메모리 할당
        size_type new_length = length + s.length;
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        //메모리 해제하기 위해 원래 value 소멸하기 
        if (value != 0)
            delete[] value;
        //새로운 value 와 length 값을 저장하기 
        std::copy(s.value, s.value + s.length, new_value + new_length);
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator+=(const char c) {
        //메모리할당
        size_type new_length = length + 1;
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        //메모리 해제하기위해 원래 value 소멸하기
        if (value != 0)
            delete[] value;

        //char를 추가하기
        new_value[length] = c;
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator+=(const char* c) {
        //메모리할당
        size_type new_length = length + strlen(c);
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        //메모리 해제하기위해 원래 value 소멸하기
        if (value != 0)
            delete[] value;

        //char를 추가하기
        std::copy(c, c + strlen(c), new_value + length);
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator=(const Str& rhs) {
        // 자기 자신 할당 확인
        if (&rhs != this) {
            if (value != 0)
                delete[] value;

            length = rhs.length;
            value = new char[length];
            std::copy(rhs.begin(), rhs.end(), value);
        }
        return *this;
    }

    // Q7
    typedef char* iterator;
    typedef const char* const_iterator;

    // begin()
    iterator begin() { return value; }
    const_iterator begin() const { return value; }

    // end()
    iterator end() { return value + length; }
    const_iterator end() const { return value + length; }

    //Q2 
    const char* c_str() const { return value + '\0'; }
    const char* data() const { return value; }
    void copy(char* p, size_type n) {//copy('=', 10)
        std::copy(value, value + n, p);//===========
    }
private:
    char* value;
    size_type length;
};

std::ostream& operator<<(std::ostream&, const Str&); //추가
std::ostream& getline(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*);
Str operator+(const char*, const Str&);

bool operator==(const Str& lhs, const Str& rhs);
bool operator!=(const Str& lhs, const Str& rhs);
bool operator<(const Str& lhs, const Str& rhs);
bool operator>(const Str& lhs, const Str& rhs);
bool operator<=(const Str& lhs, const Str& rhs);
bool operator>=(const Str& lhs, const Str& rhs);

#endif