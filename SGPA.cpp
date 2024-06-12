#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string name;
    int credits;
    string grade; 
};

double calculateGPA(string grade) {
    if (grade == "A+") {
        return 4.0;
    }
    else if (grade == "A") {
        return 4.0;
    }
    else if (grade == "A-") {
        return 3.67;
    }
    else if (grade == "B+") {
        return 3.33;
    }
    else if (grade == "B") {
        return 3.0;
    }
    else if (grade == "B-") {
        return 2.67;
    }
    else if (grade == "C+") {
        return 2.33;
    }
    else if (grade == "C") {
        return 2.0;
    }
    else if (grade == "C-") {
        return 1.67;
    }
    else if (grade == "D+") {
        return 1.33;
    }
    else if (grade == "D") {
        return 1.00;
    }
    else if (grade == "F") {
        return 0.0;
    }
    else {
        return 0.0; 
    }
}

double calculatesgpa(vector<Course> courses) {
    double totalGPA = 0.0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGPA += calculateGPA(course.grade) * course.credits;
        totalCredits += course.credits;
    }

    return totalGPA / totalCredits;
}

int main() {
    vector<Course> courses;

    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        cin.ignore();
        Course course;
        cout << "Enter course " << (i + 1) << " name: ";
        getline(cin, course.name);
        cout << "Enter course " << (i + 1) << " credits: ";
        cin >> course.credits;
        cout << "Enter course " << (i + 1) << " grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D or F): ";
        cin >> course.grade;
        courses.push_back(course);
    }

    double sgpa = calculatesgpa(courses);

    cout << "sgpa: " << sgpa << endl;

    return 0;
}
