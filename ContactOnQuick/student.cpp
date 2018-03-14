#include "student.h"

Student::Student() : Persone()
{

}

Student::Student(QString name, QString secondName) : Persone(name, secondName)
{

}

Student::Student(QString name, QString secondName, Subject subject) : Persone(name, secondName)
{
    m_Subject = subject;
}

Student::Student(QString name, QString secondName, Subject subject, uint id) : Persone(name, secondName)
{
    m_Subject = subject;
    m_ID = id;
}

Student::~Student()
{

}

QString Student::ShowInfo()
{
    return m_Name + " " + m_SecondName + " " + m_Subject.ShowInfo();
}

Subject Student::GetSubject()
{
    return m_Subject;
}
//Нужно ли указывать this
Student* Student::operator =(Student* student)
{
    this->m_Name = student->GetName();
    this->m_SecondName = student->GetSecondName();
    this->m_Subject = student->GetSubject();
    return this;
}


