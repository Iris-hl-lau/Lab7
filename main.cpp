#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/**
 * Prints the entire schedule of courses.
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> &m)
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    auto begin = m.begin();
    auto end = m.end();
    ostream_iterator<Course> os(cout,"\n");
    std::copy(begin, end, os);
}

/**
 * Drives the progream.
 * @return    int
 */
int main () {
    //TODO read from courses.txt
    ifstream read_file;
    read_file.open("../courses.txt");

    string title, data;
    char day;
    unsigned int startTime;
    unsigned int finishTime;
    vector<Course> courses;

    while(read_file >> title >> day >> startTime >> finishTime) {
        Course c(title, Course::getDOW(day), startTime, finishTime);
        //TODO store data in an STL container
        courses.push_back(c);
    }

    //TODO sort your STL container with the sort algorithm
    sort(courses.begin(), courses.end());

    //TODO implement code to determine schedule conflicts
    for(auto it = courses.begin(); it != courses.end() - 1; ++it) {
        for(auto iter = it + 1; iter != courses.end(); ++iter) {
            if(*it == *iter) {

                //TODO print out schedule conflicts
                cout << "CONFLICT: \n";
                cout << *it << "\n";
                cout << *iter << "\n\n";
            }
        }
    }

    //TODO print out schedule
    printSchedule(courses);

    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}