// main.cpp

// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <fstream> // 에런 (파일을 사용하기 위해)
#include <ios>
#include <iomanip>
#include <iostream> // cin/cout을 사용하기 위해
#include <stdexcept>
// #include <Str> -> "Str.h"를 대신 사용
#include "Vec.h" // vector -> Vec
#include "Str.h"

#include "analysis.h"
#include "grade.h"
#include "util.h"
#include "Student_info.h"

using namespace std;

int main() {

    int fileChoice = printGreeting();
    // cout << fileChoice << typeid(fileChoice).name();

    Vec<Student_info> students, did, didnt;
    Str::size_type maxlen = 0;

    fileSelect(fileChoice, students, did, didnt, maxlen);

    // loadGrades(student_file, students, did, didnt, maxlen);

    // cout << "Welcome to Student Gradebook!" << endl;
    // cout << "Read " << students.size() << " records." << endl << endl;

    bool quit = false;
    int choice;

    while (!quit) {
        printMenu();

        // Read menu choice
        cin >> choice;

        // 과제 점수를 일음
        switch (choice) {
        case 1: // Check Homework
            checkHw(did, didnt);
            break;
        case 2: // Analyze Grades
            analyzeGrades(did, didnt);
            break;
        case 3: // Show Final Scores
            showScores(students, maxlen);
            break;
        case 4:
            fileChoice = printGreeting();
            fileSelect(fileChoice, students, did, didnt, maxlen);
            break;
        case 0: // Quit
            quit = true;
            break;
        default:
            cout << "Incorrect input. Enter a choice between 1, 2, 3, or 0: " << endl;
        }
    }

    return 0;
} // main 끝