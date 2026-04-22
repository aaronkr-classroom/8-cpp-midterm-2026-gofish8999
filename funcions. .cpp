#include "functions.h"
#include <algorithm>
#include <stdexcept>

using std::istream; using std::vector;
using std::domain_error; 

double calculateAverage(vector<int> grades) {
    int total = 0;
    for (int i = 0; i < grades.size(); i++) {
        total += grades[i];//+=누적
    }
    return grades.empty() ? 0 : (double)total / grades.size();
}//더블 함수



istream& read(istream& is, Student_info& s) {
    is >> s.name;
    read_hw(is, s.homework);
    return is; 
}


istream& read_hw(istream& in, vector<int>& hw) {
    if (in) {
        hw.clear(); 
        int x;
        
        while (hw.size() < 5 && in >> x) {
            hw.push_back(x); 
        }
        in.clear();
    }
    return in;
}


double grade(const Student_info& s) {
    
    if (s.homework.size() == 0)
        throw domain_error("과제 점수가 없습니다"); 

    return calculateAverage(s.homework);
}


bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}
