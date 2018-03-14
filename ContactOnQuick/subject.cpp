#include "subject.h"

Subject::Subject()
{

}

Subject::Subject(QString name)
{
    m_Name = name;
}

Subject::Subject(QString name, uint id)
{
    m_Name = name;
    m_ID = id;
}

uint Subject::GetId()
{
    return m_ID;
}

QString Subject::GetName()
{
    return m_Name;
}

void Subject::SetID(uint id)
{
    m_ID = id;
}

QString Subject::ShowInfo()
{
    return m_Name;
}


