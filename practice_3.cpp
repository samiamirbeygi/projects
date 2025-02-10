#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cout << "Enter the number of students: ";
    while (true) {
        cin >> number;
        if (cin.fail() || number <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a positive integer: ";
        } else {
            break;
        }
    }

    vector<int> grades(number);
    for (int i = 0; i < number; i++) {
        while (true) {
            cout << "Enter grade for student " << i + 1 << ": ";
            cin >> grades[i];
            if (cin.fail() || grades[i] < 0 || grades[i] > 20) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a grade between 0 and 20: ";
            } else {
                break;
            }
        }
    }

    float sum = 0;
    for (int i = 0; i < number; i++) {
        sum += grades[i];
    }

    float average = sum / number;
    cout << "The average grade is: " << average << endl;

    return 0;
}