#include <iostream>
#include <fstream>

constexpr unsigned STUDENTS_NAME_LENGTH = 20;

enum class Major {
    SE, CS, IS, I
};

struct Student {
    char name[STUDENTS_NAME_LENGTH];
    int age;
    Major major;
};

void saveStudent(const Student& st, std::ostream& outFile) {
    outFile << st.name << std::endl << st.age << std::endl << (int)st.major << std::endl;
}


void saveStudents(const Student* st, size_t count, std::ostream& outFile) {
    outFile << count << std::endl;
    
    for (size_t i = 0; i < count; i++)
    {
        saveStudent(st[i], outFile);
    }
}

Student readStudent(std::ifstream& inFile) {
    Student st;
    inFile.ignore();
    inFile.getline(st.name, 20);
    inFile >> st.age;
    int majorNum;
    inFile >> majorNum;
    st.major = (Major)majorNum;

    return st;
}

Student* readStudents(std::ifstream& inFile, size_t& count) {
    inFile >> count;
    Student* st = new Student[count];

    for (size_t i = 0; i < count; i++)
    {
        st[i] = readStudent(inFile);
    }

    return st;
}

int main()
{
    std::ofstream outFile("students.txt");
    Student st[] = { { "Pesho", 20, Major::CS },{ "Pesho2", 21, Major::CS } };

    saveStudents(st, 2, outFile);
    outFile.close();

    size_t count = 0;
    std::ifstream inFile("students.txt");
    Student* st2 = readStudents(inFile, count);

    saveStudents(st2, count, std::cout);
}
