#include <iostream>
#include "GraduatedStudent.h"

int main()
{
    Student st1("Pesho", "WE made it");
    Student st2(st1);

    st2.setName("Gosho");
    std::cout << st1.getName() << std::endl;
    std::cout << st2.getName() << std::endl;

    st1.addGrade(6);
    st1.addGrade(5);
    st1.addGrade(4);
    st1.addGrade(3);
    st1.addGrade(6);

    for (size_t i = 0; i < st1.getGradesCount(); i++)
    {
        std::cout << st1.getGrades()[i] << ' ';
    }
}