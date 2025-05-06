#include <iostream>
#include "StudentsCollection.h"

int main()
{
    Student st1("Ivan", 16);
    Student st2("Mimi", 16);

    StudentsCollection students;
    students.addAtFirstFreeIndex(st1);
    students.addAtFirstFreeIndex(st2);

    students.removeAtIndex(0);
    std::cout << students.getAtIndex(1)->getName() << std::endl; //Mimi

    Student st3("Pesho", 18);
    students.addAtFirstFreeIndex(st3);
    std::cout << students.getAtIndex(0)->getName() << std::endl; //Pesho

    Student st4("Marto", 19);
    students.setAtIndex(st4, 0);
    std::cout << students.getAtIndex(0)->getName() << std::endl; //Marto

}
