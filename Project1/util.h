// util.h

#ifndef GUARD_util_h
#define GUARD_util_h

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "Vec.h" // vector -> Vec

#include "analysis.h"
#include "Student_info.h"

int printGreeting();
void printMenu();

void loadGrades(ifstream&, 
	Vec<Student_info>&,
	Vec<Student_info>&, 
	Vec<Student_info>&,
	Str::size_type&
);

void fileSelect(int,
	Vec<Student_info>&,
	Vec<Student_info>&,
	Vec<Student_info>&,
	Str::size_type&
);

int checkHw(Vec<Student_info>&, Vec<Student_info>&);

// Overloaded from analysis.h - to handle a single Vec<Student_info> (not two)
void write_analysis(ostream&, const Str&,
	double analysis(const Vec<Student_info>&),
	const Vec<Student_info>&,
	Str);

void analyzeGrades(Vec<Student_info>&, Vec<Student_info>&);
void showScores(Vec<Student_info>&, Str::size_type&);

#endif