#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

    // Static member to count active Student objects
    static int studentCount;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        marks = 0.0f;
        studentCount++;
    }

    // Parameterized constructor
    Student(string studentName, int roll, float m) {
        name = studentName;
        rollNumber = roll;
        marks = m;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Function overloading: update only marks
    void updateDetails(float newMarks) {
        marks = newMarks;
    }

    // Function overloading: update name and marks
    void updateDetails(string newName, float newMarks) {
        name = newName;
        marks = newMarks;
    }

    // Getter methods
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    float getMarks() const {
        return marks;
    }

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Friend function declaration
    friend void displayStudentInfo(const Student &s);

    // Overloaded greater-than operator
    bool operator>(const Student &other) const {
        return marks > other.marks;
    }
};

// Initialize static data member
int Student::studentCount = 0;

// Friend function definition
void displayStudentInfo(const Student &s) {
    cout << "----------------------------------------\n";
    cout << "Student Name : " << s.name << "\n";
    cout << "Roll Number  : " << s.rollNumber << "\n";
    cout << "Marks        : " << s.marks << "\n";
    cout << "----------------------------------------\n";
}

int main() {
    cout << "===== OOP Using C++ - Task 1 =====\n\n";

    cout << "Initial Total Students: "
         << Student::getStudentCount() << "\n\n";

    // Create two Student objects
    Student s1("Alice Smith", 101, 85.5f);
    Student s2("Bob Jones", 102, 92.0f);

    cout << "Total Students after admission: "
         << Student::getStudentCount() << "\n\n";

    cout << "Details of Student 1:\n";
    displayStudentInfo(s1);

    cout << "\nDetails of Student 2:\n";
    displayStudentInfo(s2);

    // Demonstrate function overloading
    cout << "\n--- Updating Student 1 Details ---\n";
    s1.updateDetails(89.0f);
    displayStudentInfo(s1);

    cout << "\n--- Updating Student 2 Details ---\n";
    s2.updateDetails("Robert Jones", 94.5f);
    displayStudentInfo(s2);

    // Demonstrate operator overloading
    cout << "\n--- Comparing Students Based on Marks ---\n";
    if (s2 > s1) {
        cout << s2.getName() << " has higher marks than "
             << s1.getName() << ".\n";
    } else if (s1 > s2) {
        cout << s1.getName() << " has higher marks than "
             << s2.getName() << ".\n";
    } else {
        cout << "Both students have equal marks.\n";
    }

    return 0;
}
