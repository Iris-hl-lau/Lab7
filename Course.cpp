#include "Course.hpp"

using namespace std;

/**
 * Course Constructor
 * @param title    Course name.
 * @param day      Day of the week.
 * @param start_time     Class start time.
 * @param finish_time     Class end time.
 */
Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}

/**
 * Course copy constructor.
 * @param m    Address of a course constant.
 */
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

/**
 * Overloaded assignment operator.
 * Assigns each instance of rhs to lhs
 * @param m    Address of a course constant.
 * @return     Address of Course.
 */
Course & Course::operator =(const Course & m) {
    //TODO implement the operator
    this->title = m.title;
    this->day = m.day;
    this->start_time = m.start_time;
    this->finish_time = m.finish_time;
    return *this;
}

/**
 * Overloaded equals to operator.
 * Returns true when rhs has the same day, and same start time or finish time.
 * @param m    Address of a Course constant.
 * @return    Boolean.
 */
bool Course::operator == (const Course & m) const {
    //TODO implement the operator
    if(this->day == m.day) {
        if(this->start_time == m.start_time || this->finish_time == m.finish_time) {
            return true;
        }
    }
    return false;
}

/**
 * Overloaded less than operator.
 * Returns true when lhs day is less than rhs day.
 * If the days are equal, returns true when lhs start time
 * is less than rhs start time.
 * @param m    Address of a Course constant.
 * @return    Boolean.
 */
bool Course::operator < (const Course & m) const
{
    //TODO implement the operator
    if(this->day != m.day) {
        return this->day < m.day;
    } else {
        return this->start_time < m.start_time;
    }
}

/**
 * Gets the dayOfWeek value from corresponding char.
 * @param day    char
 * @return    dayOfWeek
 */
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

/**
 * Gets the char value from corresponding dayOfWeek.
 * @param dow  dayOfWeek
 * @return    char
 */
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

/**
 * Overloaded output operator.
 * @param os    Address of ostream.
 * @param m    Address of a Course constant.
 * @return    Address of ostream.
 */
ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator
    os << m.title << " ";
    os << Course::getDay(m.day) << " ";
    os << m.start_time << " ";
    os << m.finish_time;
    return os;
}