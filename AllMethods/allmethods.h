
#ifndef ALLMETHODS_H
#define ALLMETHODS_H
#include "../Data/data.h"
void Admin();
void User();
void AddStudentRecord();
void RemoveStudentRecord();
void ViewStudentRecord();
void ViewAllRecords();
void EditAdminPassword();
void EditStudentGrade();
Student readStudent();
void editStudentName(Student * st);
void EditStudentPassword(Student * st);


#endif
