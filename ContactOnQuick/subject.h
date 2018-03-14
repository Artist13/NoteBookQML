#ifndef SUBJECT_H
#define SUBJECT_H

#define Name QString
#define Id uint
#include <QString>

class Subject
{
public:
    Subject();
    Subject(Name);
    Subject(Name, Id);
    uint GetId();
    QString GetName();
    void SetID(Id);//Убрать. Оставить только присвоение при создании
    QString ShowInfo();
private:
    uint m_ID;
    QString m_Name;
    uint m_ClassNumber;
    //Добавить закрытый метод для преобразования в Xml. И в учениках/людях тоже void ToXml(QXmlSW & xml);
    //Потребуется подключать QxmlStreamer
};

#endif // SUBJECT_H
