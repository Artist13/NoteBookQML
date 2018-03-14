#include "listofsubject.h"
#include <QFile>


ListOfSubject::ListOfSubject()
{

}

ListOfSubject* ListOfSubject::GetListOfSubject()
{
    static ListOfSubject MyList;
    return &MyList;
}

bool ListOfSubject::AddSubject(Subject subject)
{
    try{
        m_Subjects.push_back(subject);
        return true;
    }
    catch(...)
    {
        return false;
    }

}

Subject ListOfSubject::GetByIndex(uint index)
{
    return m_Subjects[index];
}

Subject ListOfSubject::GetById(uint id)
{
    foreach(Subject subj, m_Subjects)
    {
        if(subj.GetId() == id)
            return subj;
    }
    //Применить Null object
    return Subject();
}

Subject ListOfSubject::XmlToSubject(QXmlStreamReader &xml)
{
    QString currentName;
    uint currentId;
    foreach (const QXmlStreamAttribute &attr, xml.attributes()) {
        if(attr.name() == "name")
        {
            currentName = attr.value().toString();
        }
        if(attr.name() == "id")
        {
            currentId = attr.value().toInt();
        }
    }
    return Subject(currentName, currentId);
}

bool ListOfSubject::Load(const QString filePath)
{
    QFile *file = new QFile(filePath);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    m_Subjects.clear();
    QXmlSR xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QXmlSR::TokenType token = xml.readNext();
        if(token == QXmlSR::StartDocument)
            continue;
        if(xml.name() == "Subject" && xml.attributes().size() > 0)
        {
            m_Subjects.push_back(XmlToSubject(xml));
        }
    }
    file->close();
    delete file;
    return true;
}

void ListOfSubject::SubjectToXml(Subject subject, QXmlSW& xml)
{
    xml.writeStartElement("Subject");
    xml.writeAttribute("name", subject.GetName());
    xml.writeAttribute("id", QString::number(subject.GetId()));
    xml.writeEndElement();
}

bool ListOfSubject::Save(const QString filePath)
{
    QFile *file = new QFile(filePath);

    if(QFile::exists(filePath))
    {

    if(!file->open(QIODevice::WriteOnly))
    {
        return false;
    }
    }
    QXmlSW xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Subjects");
    for(int i = 0; i < m_Subjects.size(); i++)
    {
        SubjectToXml(m_Subjects[i], xml);
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
    delete file;
    return true;
}
