#ifndef STUDENT_H
#define STUDENT_H

#include "persone.h"
#include "subject.h"
#define Name QString
#define SecondName QString
#define ID uint

class Student : public Persone
{
public:
    Student();
    Student(Name, SecondName);
    Student(Name, SecondName, Subject);
    Student(Name, SecondName, Subject, ID);
    QString ShowInfo();
    Subject GetSubject();
    ~Student();

    Student* operator = (Student*);

private:
    Subject m_Subject;
};

#endif // STUDENT_H
