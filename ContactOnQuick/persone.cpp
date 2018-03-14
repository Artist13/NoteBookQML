#include "persone.h"

Persone::Persone()
{
    m_Name = "Unknown";
    m_SecondName ="Unknown";
    m_ID = -1;
}

Persone::Persone(QString name, QString secondName)
{
    m_Name = name;
    m_SecondName = secondName;
    m_ID = -1;
}

Persone::~Persone()
{

}

QString Persone::ShowInfo()
{
    return m_Name + " " + m_SecondName;
}

QString Persone::GetName()
{
    return m_Name;
}

QString Persone::GetSecondName()
{
    return m_SecondName;
}

void Persone::SetID(int id)
{
    m_ID = id;
}

uint Persone::GetID()
{
    return m_ID;
}


