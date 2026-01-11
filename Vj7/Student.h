#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Course.h"
#include "UniversityConstants.h"

class StudentOffice;

class Student {
private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    Course* enrolled_courses;
    size_t enrolled_count;

    Course* completed_courses;
    size_t completed_count;

    static int total_students;

    int passedEctsThisYear() const;

public:
    Student(int i = 0, std::string n = "", std::string sp = "", int y = 1);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    ~Student();

    static int get_total_students();

    Student& operator+=(const Course& c);
    Student& operator++();
    Student operator++(int);

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);

    friend class StudentOffice;
};

#endif

