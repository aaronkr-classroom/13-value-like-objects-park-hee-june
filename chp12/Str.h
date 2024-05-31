#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <cctype>
#include <iterator>

class Str {
    // �Է� ������
    friend std::istream& operator>>(std::istream&, Str&);
    friend std::istream& getline(std::istream&, Str&);

public:
    typedef size_t size_type;

    //����ִ� Str ��ü�� ����� �⺻ ������
    Str() : value(0), length(0) { }

    // c�� ���纻 n���� �ִ� Str ��ü�� ����
    Str(size_type n, char c) {
        //�޸� �Ҵ�
        length = n;
        value = new char[length];

        //�迭�� c char�� ä����
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

    // �Ҹ��� 
    ~Str() {
        if (value != 0)
            delete[] value;
    }

    //�ݺ��� b�� e�� ����Ű�� �������� Str ��ü�� ����
    template<class Input> Str(Input b, Input e) {
        length = e - b;
        value = new char[length];

        std::copy(b, e, value);
    }

    // �ε��� ������
    char& operator[](size_type i) { return value[i]; }
    const char& operator[](size_type i) const { return value[i]; }

    size_type size() const { return length; }

    // ���� ������
    Str& operator+=(const Str& s) {
        //�޸� �Ҵ�
        size_type new_length = length + s.length;
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        //�޸� �����ϱ� ���� ���� value �Ҹ��ϱ� 
        if (value != 0)
            delete[] value;
        //���ο� value �� length ���� �����ϱ� 
        std::copy(s.value, s.value + s.length, new_value + new_length);
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator+=(const char c) {
        //�޸��Ҵ�
        size_type new_length = length + 1;
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        //�޸� �����ϱ����� ���� value �Ҹ��ϱ�
        if (value != 0)
            delete[] value;

        //char�� �߰��ϱ�
        new_value[length] = c;
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator+=(const char* c) {
        //�޸��Ҵ�
        size_type new_length = length + strlen(c);
        char* new_value = new char[new_length];
        std::copy(value, value + length, new_value);

        //�޸� �����ϱ����� ���� value �Ҹ��ϱ�
        if (value != 0)
            delete[] value;

        //char�� �߰��ϱ�
        std::copy(c, c + strlen(c), new_value + length);
        value = new_value;
        length = new_length;
        return *this;
    }

    Str& operator=(const Str& rhs) {
        // �ڱ� �ڽ� �Ҵ� Ȯ��
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

std::ostream& operator<<(std::ostream&, const Str&); //�߰�
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