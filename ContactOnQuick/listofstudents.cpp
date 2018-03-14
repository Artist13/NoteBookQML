#include "listofstudents.h"
#include <QFile>

ListOfStudents::ListOfStudents(QObject *parent) : QObject(parent)
{
    last_id = 0;
}

ListOfStudents* ListOfStudents::GetListOfStudents()
{
    static ListOfStudents MyList;
    return &MyList;
}

void ListOfStudents::AddStudent(Student *student)
{
    student->SetID(last_id++);
    m_Students.push_back(student);
}

void ListOfStudents::AddStudent(Student *student, uint id)
{
    student->SetID(id);;
    last_id = id + 1;
    m_Students.push_back(student);
}

QString ListOfStudents::ShowStudents()
{
    QString tempInfo = "";
    for(int index = 0; index < m_Students.size(); index++)
    {
        tempInfo += m_Students[index]->ShowInfo() + '\n';
    }
    return tempInfo;
}

//Система хранения предметов должна быть изменена
Student* ListOfStudents::XmlToStudent(QXmlSR &xml)
{
    QString currentName, currentSecondName;
    Subject currentSubject;
    int currentID;
    foreach (const QXmlStreamAttribute &attr, xml.attributes()) {
        if(attr.name() == "name")
        {
            currentName = attr.value().toString();
        }
        if(attr.name() == "secondName")
        {
            currentSecondName = attr.value().toString();
        }
        if(attr.name() == "subject")
        {
            currentSubject = ListOfSubject::GetListOfSubject()->GetById(attr.value().toInt());
        }
        if(attr.name() == "id")
        {
            currentID = attr.value().toInt();
            last_id = currentID + 1;
        }
    }
    return new Student(currentName, currentSecondName, currentSubject, currentID);
}

bool ListOfStudents::Load(const QString filePath)
{
    QFile *file = new QFile(filePath);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    m_Students.clear();//Нужна функция для очистки вектора. УТЕЧКА ПАМЯТИ
    QXmlSR xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QXmlSR::TokenType token = xml.readNext();
        if(token == QXmlSR::StartDocument)
            continue;
        if(xml.name() == "Student" && xml.attributes().size() > 0)
        {
            m_Students.push_back(XmlToStudent(xml));
        }
    }
    file->close();
    delete file;
    return true;
}

void ListOfStudents::StudentToXml(Student *student, QXmlSW &xml)
{
    xml.writeStartElement("Student");
    xml.writeAttribute("name", student->GetName());
    xml.writeAttribute("secondName", student->GetSecondName());
    xml.writeAttribute("subject", QString::number(student->GetSubject().GetId()));
    xml.writeAttribute("id", QString::number(student->GetID()));
    xml.writeEndElement();
}

bool ListOfStudents::Save(const QString filePath)
{
    QFile *file = new QFile(filePath);
    file->open(QIODevice::WriteOnly);
    QXmlSW xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Students");
    foreach (Student* student, m_Students) {
        StudentToXml(student, xml);
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
    delete file;
    return true;
}
//Отдельный метод для очистки
ListOfStudents::~ListOfStudents(){
    foreach (Student* student, m_Students) {
        delete student;
    }
    m_Students.clear();
}


//To QML
QStringList ListOfStudents::List() const
{
    QStringList list;
    foreach (Student* st, m_Students) {
        list << st->ShowInfo();
    }
    return list;
}
