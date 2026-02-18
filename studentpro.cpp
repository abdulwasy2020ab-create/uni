#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks[5];
    float avg;
};

Student s[50];
int countS = 0;

// ---------- Calculate Average ----------
float calculateAvg(float m[]) {
    float sum = 0;
    for(int i = 0; i < 5; i++)
        sum += m[i];
    return sum / 5;
}

// ---------- Add Student ----------
void addStudent() {
    cout << "\nEnter ID: ";
    cin >> s[countS].id;

    cout << "Enter Name: ";
    cin >> s[countS].name;

    cout << "Enter 5 Marks:\n";
    for(int i = 0; i < 5; i++)
        cin >> s[countS].marks[i];

    s[countS].avg = calculateAvg(s[countS].marks);
    countS++;

    cout << "Student Added!\n";
}

// ---------- Display ----------
void display() {
    if(countS == 0) {
        cout << "No Record\n";
        return;
    }

    for(int i = 0; i < countS; i++) {
        cout << "\nID: " << s[i].id;
        cout << "\nName: " << s[i].name;
        cout << "\nAverage: " << s[i].avg;

        if(s[i].avg >= 80) cout << " Grade: A";
        else if(s[i].avg >= 60) cout << " Grade: B";
        else if(s[i].avg >= 40) cout << " Grade: C";
        else cout << " Grade: Fail";

        cout << "\n-------------------";
    }
}

// ---------- Search ----------
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for(int i = 0; i < countS; i++) {
        if(s[i].id == id) {
            cout << "Found: " << s[i].name << " Avg: " << s[i].avg << "\n";
            return;
        }
    }
    cout << "Student not found\n";
}

// ---------- Delete ----------
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for(int i = 0; i < countS; i++) {
        if(s[i].id == id) {
            for(int j = i; j < countS - 1; j++)
                s[j] = s[j + 1];

            countS--;
            cout << "Deleted!\n";
            return;
        }
    }
    cout << "Student not found\n";
}

// ---------- Save File ----------
void saveFile() {
    ofstream out("students.txt");

    for(int i = 0; i < countS; i++)
        out << s[i].id << " " << s[i].name << " " << s[i].avg << endl;

    out.close();
    cout << "Saved in file!\n";
}

// ---------- Main ----------
int main() {
    int choice;

    do {
        cout << "\n1.Add Student";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Delete";
        cout << "\n5.Save to File";
        cout << "\n6.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: display(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveFile(); break;
        }

    } while(choice != 6);

    return 0;
}