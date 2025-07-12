//Jibran Jadoon

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int studentID;
    string fullName;
    float averageScore;

public:
    Student() {
        studentID = 0;
        fullName = "";
        averageScore = 0.0;
    }

    Student(int id, string name, float score) {
        studentID = id;
        fullName = name;
        averageScore = score;
    }

    int getID() const {
        return studentID;
    }

    string getName() const {
        return fullName;
    }

    float getScore() const {
        return averageScore;
    }

    void printInfo() const {
        cout << "ID: " << studentID << ", Name: " << fullName << ", Grade: " << averageScore << endl;
    }

    string formatForFile() const {
        return to_string(studentID) + "," + fullName + "," + to_string(averageScore);
    }
};

//Tracker class manages students
class Tracker {
private:
    Student* roster[100];
    int size;

public:
    Tracker() {
        size = 0;
    }

    //Adds student to the roster
    void add(int id, string name, float score) {
        if (size < 100) {
            roster[size] = new Student(id, name, score);
            size++;
        }
    }

    void displayAll() const {
        for (int i = 0; i < size; i++) {
            roster[i]->printInfo();
        }
    }

    //Saves student data to a (.txt)
    void exportToFile(const string& filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "Couldn't open file.\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            fout << roster[i]->formatForFile() << endl;
        }

        fout.close();
        cout << "Data saved to " << filename << endl;
    }

    void importFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "File not found for reading.\n";
            return;
        }

        string line;
        size = 0;

        while (getline(fin, line)) {
            int id;
            string name;
            float score;

            size_t firstComma = line.find(',');
            size_t secondComma = line.find_last_of(',');

            if (firstComma != string::npos && secondComma != string::npos) {
                id = stoi(line.substr(0, firstComma));
                name = line.substr(firstComma + 1, secondComma - firstComma - 1);
                score = stof(line.substr(secondComma + 1));

                add(id, name, score);
            }
        }

        fin.close();
        cout << "Data loaded from " << filename << endl;
    }

    //Binary Search by student ID
    int searchByID(int id) const {
        int low = 0, high = size - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (roster[mid]->getID() == id) {
                return mid;
            } else if (roster[mid]->getID() < id) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    //Find and displays a student by ID
    void findStudent(int id) const {
        int index = searchByID(id);
        if (index != -1) {
            cout << "Student found:\n";
            roster[index]->printInfo();
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    ~Tracker() {
        for (int i = 0; i < size; i++) {
            delete roster[i];
        }
    }
};

int main() {
    Tracker studentSystem;

    studentSystem.add(1001, "Albert Smith", 92.4);
    studentSystem.add(1002, "Jay James", 81.7);
    studentSystem.add(1003, "Sofia marqués", 88.2);

    cout << "Current Students:\n";
    studentSystem.displayAll();

    //File I/O operations
    string fileName = "student_data.txt";
    studentSystem.exportToFile(fileName);
    studentSystem.importFromFile(fileName);

    int queryID;
    cout << "\nEnter student ID to search: ";
    cin >> queryID;
    studentSystem.findStudent(queryID);

    return 0;
}
