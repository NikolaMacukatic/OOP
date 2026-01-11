#include "StudentOffice.h"

void StudentOffice::moveStudent(Student& s, std::string new_program)
{
    s.study_program = std::move(new_program);
}

void StudentOffice::enroll_student(Student& s, const Course& c)
{
    int ects = 0;
    for (size_t i = 0; i < s.enrolled_count; i++)
        ects += s.enrolled_courses[i].getEcts();

    if (ects + c.getEcts() <= UniversityConstants::MAX_ETCS_PER_YEAR)
        s += c;
}

void StudentOffice::process_exam_results(Student& s, size_t index)
{
    Course passed = s.enrolled_courses[index];

    Course* new_completed = new Course[s.completed_count + 1];
    for (size_t i = 0; i < s.completed_count; i++)
        new_completed[i] = s.completed_courses[i];
    new_completed[s.completed_count] = passed;

    Course* new_enrolled = new Course[s.enrolled_count - 1];
    size_t j = 0;
    for (size_t i = 0; i < s.enrolled_count; i++)
        if (i != index)
            new_enrolled[j++] = s.enrolled_courses[i];

    delete[] s.completed_courses;
    delete[] s.enrolled_courses;

    s.completed_courses = new_completed;
    s.completed_count++;
    s.enrolled_courses = new_enrolled;
    s.enrolled_count--;
}

void StudentOffice::update_student_years(Student* students, size_t count)
{
    for (size_t i = 0; i < count; i++)
        ++students[i];
}
