#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(const Course & m) {
    //TODO implement the operator
    this->title = m.title;
    this->day = m.day;
    this->start_time = m.start_time;
    this->finish_time = m.finish_time;
    return *this;
}
bool Course::operator == (const Course & m) const {
    //TODO implement the operator
    if(this->day == m.day) {
        if(this->start_time == m.start_time || this->finish_time == m.finish_time) {
            return true;
        }
    }
    return false;
}

bool Course::operator < (const Course & m) const
{
    //TODO implement the operator
    if(this->day != m.day) {
        return this->day < m.day;
    } else {
        return this->start_time < m.start_time;
    }
}

Course::dayOfWeek Course::getDOW(char day) {
    switch(day) {
        case 'M':
            return Course::dayOfWeek::MON;
        case 'T':
            return Course::dayOfWeek::TUE;
        case 'W':
            return Course::dayOfWeek::WED;
        case 'R':
            return Course::dayOfWeek::THUR;
        case 'F':
            return Course::dayOfWeek::FRI;
        default:
            break;
    }
}

char Course::getDay(Course::dayOfWeek dow) {
    switch(dow) {
        case Course::dayOfWeek ::MON:
            return 'M';
        case Course::dayOfWeek::TUE:
            return 'T';
        case Course::dayOfWeek::WED:
            return 'W';
        case Course::dayOfWeek::THUR:
            return 'R';
        case Course::dayOfWeek::FRI:
            return 'F';
        default:
            break;
    }
}

ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator
    os << m.title << " ";
    os << Course::getDay(m.day) << " ";
    os << m.start_time << " ";
    os << m.finish_time << " ";
    return os;
}