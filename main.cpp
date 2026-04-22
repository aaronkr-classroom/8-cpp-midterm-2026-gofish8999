//main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "functions.h"
#include <stdexcept>

using std::cin;     using std::cout;
using std::endl;    using std::vector;
using std::sort;    using std::setprecision;
using std::domain_error;

int main() {
    int num_students;
    cout << "학생 수를 입력하세요: ";

    if (!(cin >> num_students)) {
        cout << "오류: 숫자가 아닌 값" << endl;
        return 1;
    }

    cin.ignore(1000, '\n');
    // ai사용 뒤에 엔터때문에 이름 입력할 때 오류생기는 걸 방지하는 거 물어봄

    vector<Student_info> students;
    Student_info record;

    for (int i = 0; i < num_students; ++i) {
        cout << "== 학생 " << i + 1 << " == " << endl;
        cout << "이름을 입력하세요: ";
        if (read(cin, record)) {
            students.push_back(record);
        }
    }


    sort(students.begin(), students.end(), compare);

    cout << "\n--- 성적 요약 ---" << endl;
    for (const auto& s : students) {
        cout << s.name << ": ";

        try {
            double final_grade = grade(s);

            cout << std::fixed << std::setprecision(1) << final_grade;

            // 2. 90점 이상이면 "Excellent" 추가 출력
            if (final_grade >= 90.0) {
                cout << " (Excellent!!)";
            }

            cout << endl; 
        }
        catch (domain_error e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
