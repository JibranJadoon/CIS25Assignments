#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
};

int binarySearch(Student students[], int size, int targetId) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (students[mid].id == targetId) {
            return mid;
        } else if (students[mid].id < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    Student students[3] = {
        {101, "Michael", 3.8},
        {102, "Lakisha", 3.5},
        {103, "Charlie", 3.9}
    };

    for (int i = 0; i < 3; ++i) {
        cout << "Student ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", GPA: " << students[i].gpa << endl;
    }

    int searchId;
    cout << "\nEnter a student ID to search: ";
    cin >> searchId;

    int index = binarySearch(students, 3, searchId);
    if (index != -1) {
        cout << "Found: " << students[index].name
             << " with GPA " << students[index].gpa << endl;
    } else {
        cout << "Student ID not found." << endl;
    }

    return 0;
}
