#ifndef LISTOFSUBJECT_H
#define LISTOFSUBJECT_H

#include <QVector>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "subject.h"
#define FilePath const QString
#define QXmlSR QXmlStreamReader
#define QXmlSW QXmlStreamWriter

class ListOfSubject
{
public:
    static ListOfSubject* GetListOfSubject();
    Subject GetByIndex(uint index);
    Subject GetById(uint id);
    bool AddSubject(Subject);//Можно перегрузить для создания по полям
    bool Load(FilePath);
    bool Save(FilePath);
private:
    Subject XmlToSubject(QXmlSR&);
    void SubjectToXml(Subject, QXmlSW&);
    ListOfSubject();
    QVector<Subject> m_Subjects;
};

#endif // LISTOFSUBJECT_H
