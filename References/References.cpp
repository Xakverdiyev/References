#include <iostream>

struct Student
{
    char* name;
    char* surname;
    int crystall;
    int age;
};

struct Auidience
{
    int number;
    Student** Students;
};

struct Floor
{
    int NumberOfFloor;
    Auidience** room;
};


struct Academy{
    char* NameAcademy;
    char* AdressOfLocation;
    Floor** floors;
    Auidience** auidience;
    Student** students;
};

Student* create_student(const char* name, const char* surname, int crystall, int age) {
    Student* student = new Student;

    student->name = new char[64] {};
    student->surname = new char[64] {};
    student->crystall = crystall;
    student->age = age;

    strcpy_s(student->name, 64, name);
    strcpy_s(student->surname, 64, surname);

    return student;
}

Auidience* create_auidience(int num, size_t students_count = 2) {
    Auidience* auidience = new Auidience;
    auidience->number = num;
    auidience->Students = new Student * [students_count];
    return auidience;
}

Floor* create_floors(int NumberOffFloor, size_t auidience_count = 2) {
    Floor* floors = new Floor;
    floors->NumberOfFloor = NumberOffFloor;
    floors->room = new Auidience * [auidience_count];
    return floors;
}

Academy* create_academy(char* NameAcademy, char* Adress, size_t all_count = 1) {
    Academy* academy = new Academy;
    academy->NameAcademy = NameAcademy;
    academy->AdressOfLocation = Adress;
    academy->floors = new Floor * [all_count];
    academy->auidience = new Auidience * [all_count];
    academy->students = new Student * [all_count];
    return academy;
}

void delete_user(Student* student) {
    delete[] student->name;
    delete[] student->surname;

    delete student;
}

void delete_auidience(Auidience* auidience, size_t students_count = 2) {
    for (size_t i = 0; i < students_count; ++i) {
        delete_user(auidience->Students[i]);
    }
    delete auidience;
}

void delete_floors(Floor* floors, size_t auidience_count = 2) {
    for (size_t i = 0; i < auidience_count; ++i) {
        delete_auidience(floors->room[i]);
    }
    delete floors;
}

void del_academy(Academy* academy, size_t all_count = 1) {
    for (size_t i = 0; i < all_count; ++i) {
        delete_floors(academy->floors[i]);
    }
    delete academy;
}

void print_students(Student* student) {
    std::cout << "Name --> " << student->name << '\n';
    std::cout << "Surname --> " << student->surname << '\n';
    std::cout << "Crystall --> " << student->crystall << '\n';
    std::cout << "Age --> " << student->age << '\n';
}

void print_auidience(Auidience* auidience) {
    std::cout << auidience->number << '\n';
}

int main()
{
    size_t len = 1;
    Student** students = new Student * [len];
    const char* name = "vadim69";
    const char* surname = "vadick";
    int crystall{ 12 };
    int age{ 43 };

    Student* stud = create_student(name, surname, crystall, age);

    students[0] = stud;

    for (size_t i = 0; i < len; ++i) {
        print_students(students[i]);
    }

    std::cout << "------------------";
    size_t len2 = 2;
    Auidience** auidience = new Auidience * [len2];
    int num{2};
    Auidience* aud = create_auidience(num);
    auidience[0] = aud;
    
}
