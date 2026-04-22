#ifndef FUNCTIONS_H  
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <vector>


struct Student_info {
    std::string name;
    std::vector<int> homework; 
};

std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<int>&);

double grade(const Student_info&);
bool compare(const Student_info&, const Student_info&);

#endif
