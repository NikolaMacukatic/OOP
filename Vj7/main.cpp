#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentOffice.h"
#include "UniversityConstants.h"

int main()
{
    UniversityConstants::print_university_rules();

    Student s1(1, "Ana", "CS", 1);
    Student s2(2, "Ivan", "IT", 1);

    Course c1("OOP", "CS101", 5);
    Course c2("Math", "MA101", 5);

    StudentOffice::enroll_student(s1, c1);
    StudentOffice::enroll_student(s1, c2);

    StudentOffice::process_exam_results(s1, 0);
    StudentOffice::process_exam_results(s1, 0);

    ++s1;

    StudentOffice::moveStudent(s2, "AI");

    std::vector<Student> students;
    students.push_back(s1);
    students.push_back(s2);

    for (const auto& s : students)
        std::cout << s << "\n";

    std::cout << Student::get_total_students() << "\n";
}
