/*
### Exercise 1

Create a structure called `Person` that has the following members:

- `name` (string)
- `age` (integer)
- `address` (string)
- `phone_number` (string)

Write a program that creates an array of `Person` structures and initializes them with the following values:

- Name: John, Age: 25, Address: 123 Main St., Phone Number: 555-1234
- Name: Mary, Age: 30, Address: 456 Elm St., Phone Number: 555-5678
- Name: Bob, Age: 20, Address: 789 Oak St., Phone Number: 555-9012

The program should then display all of the information for each `Person` in the array.

### Exercise 3

Create a structure called `Student` that has the following members:

- `name` (string)
- `num_grades` (integer)
- `grades` (array of integers)

Write a program that prompts the user to enter the name and number of grades for a student, then prompts the user to enter each grade. The program should store the student's name and grades in a `Student` structure and then calculate and display the average grade for the student.

### Combined:

Create a program that utilizes both the `Person` and `Student` structures. First, create an array of `Person` structures and initialize them with the following values:

- Name: John, Age: 25, Address: 123 Main St., Phone Number: 555-1234
- Name: Mary, Age: 30, Address: 456 Elm St., Phone Number: 555-5678
- Name: Bob, Age: 20, Address: 789 Oak St., Phone Number: 555-9012

Next, prompt the user to enter the name and number of grades for a student. Store this information in an instance of the `Student` structure. Then, prompt the user to enter each grade for the student and store the grades in the `grades` array.

Calculate the average grade for the student and display all of the information for the student, including their name, grades, and average grade.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

struct Person {
    string name;
    int age;
    int num_grades;
    int *grades;
};

void getInfo(Person *p, int i) {
    cout << "Type the Name: ";
    cin >> p[i].name;
    cout << "Type the Age: ";
    cin >> p[i].age;
    cout << "Type the Number of Grades: ";
    cin >> p[i].num_grades;
    p[i].grades = new int[p[i].num_grades];
    for (int j = 0; j < p[i].num_grades; j++) {
        cout << "Type the Grade: ";
        cin >> p[i].grades[j];
    }
}

void printInfo(Person *p, int i) {
    cout << "Name: " << p[i].name << endl;
    cout << "Age: " << p[i].age << endl;
    cout << "Number of Grades: " << p[i].num_grades << endl;
    for (int j = 0; j < p[i].num_grades; j++) {
        cout << "Grade: " << p[i].grades[j] << endl;
    }
}

void writeToFile(Person *p, int i) {
    fstream outfile("student.txt", ios::app | ios::out | ios::binary | ios::in);
    if (outfile.fail()) {
        cout << "Unable to open file" << endl;
    }
    outfile.seekp(0, ios::end);
    outfile.write(reinterpret_cast<const char*>(&p[i]), sizeof(p[i]));
}

int main() {
    Person *student = new Person[3];
    student[0] = {"John", 25, 3, nullptr};
    student[1] = {"Mary", 30, 3, nullptr};
    student[2] = {"Bob", 20, 3, nullptr};
    int i = 0;
    int cont = 1;

    while (cont == 1) {
        getInfo(student, i);
        printInfo(student, i);
        writeToFile(student, i);
        i++;
        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> cont;
    }

    return 0;
}

