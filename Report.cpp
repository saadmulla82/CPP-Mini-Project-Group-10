#include <iostream>
using namespace std;


int calculateTotal(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += marks[i]; 
    }
    return sum;
}


float calculatePercentage(int total, int n) {
    return (float)total / n;  
}


char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 40) return 'D';
    else return 'F';
}


string calculateResult(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        if (marks[i] < 40) { 
            return "FAIL";
        }
    }
    return "PASS";
}

int main() {


    string name;
    int n;

    cout << "STUDENT RESULT SYSTEM\n\n";


    cout << "Enter the name of student: ";
    getline(cin, name); 


    cout << "Enter number of subjects: ";
    cin >> n;


    while (n <= 0) {
        cout << "Number of subjects must be at least 1. Enter again: ";
        cin >> n;
    }
    cin.ignore(); 


    string subjects[n];
    int marks[n];


    for (int i = 0; i < n; i++) {


        cout << "\nEnter subject " << i + 1 << " name: "; 
        getline(cin, subjects[i]);


        while (true) {
            cout << "Enter marks for " << subjects[i] << ": "; 
            cin >> marks[i];

            if (marks[i] >= 0 && marks[i] <= 100)
            break;




            cout << "Invalid marks. Enter again.\n";
        }
        cin.ignore(); 
    }

    cout << endl << endl << endl;

    cout << "REPORT:"<<endl;


    int total = calculateTotal(marks, n); 
    float percentage = calculatePercentage(total, n); 
    char grade = calculateGrade(percentage);
    string result = calculateResult(marks, n);


    string status;
    if (percentage >= 75) status = "Excellent";
    else if (percentage >= 60) status = "Good";
    else if (percentage >= 40) status = "Average";
    else status = "Needs Improvement";


    cout << "\nStudent Name: " << name << endl;
    cout << "Subjects and Marks:\n";

    for (int i = 0; i < n; i++) {
        cout << subjects[i] << ": " << marks[i] << " / 100" << endl;
    }


    cout << "\nTotal Marks: " << total << " out of " << 100*n << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Result: " << result << endl;
    cout << "Status: " << status << endl;


    int strongCount = 0;
    cout << "\nStrong Subjects: ";
    for (int i = 0; i < n; i++) {
        if (marks[i] >= 80) {
            cout << subjects[i] << " ";
            strongCount++;
        }
    }
    if (strongCount == 0) {
        cout << name << " has no strong subjects"<<endl; 
    }


    int weakCount = 0;
    cout << "\nWeak Subjects: ";
    for (int i = 0; i < n; i++) {
        if (marks[i] <= 50) {
            cout << subjects[i] << " ";
            weakCount++;
        }
    }
    if (weakCount == 0) {
        cout << name << " has no weak subjects"<<endl;
    }

    return 0;
}
