#ifndef LISTOFSTUDENTS_H
#define LISTOFSTUDENTS_H

#define ID uint
#define FilePath const QString
#define QXmlSR QXmlStreamReader
#define QXmlSW QXmlStreamWriter

#include <QObject>
#include <QVector>
#include <QXmlStreamReader>
#include "student.h"
#include "listofsubject.h"
#include <QStringList>

/*
 * Singletone
 * Наследование от QObject  под вопросом
 * Система контроля идентификаторов не работает. Надо сделать отображение
 */

class ListOfStudents : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList List READ List CONSTANT)
public:
    static ListOfStudents* GetListOfStudents();
    QString ShowStudents();
    void AddStudent(Student*);
    void AddStudent(Student *, ID);
    bool Load(FilePath);
    bool Save(FilePath);
    QStringList List() const;
    ~ListOfStudents();
signals:

public slots:

private:
    explicit ListOfStudents(QObject *parent = nullptr);
    Student* XmlToStudent(QXmlSR&);
    void StudentToXml(Student*, QXmlSW&);
    QVector<Student*> m_Students;
    ID last_id = 0;//Некорректное название. Этот ID не принадлежит последнему элементу.
                   //Последнему элементу принадлежит last_id - 1
};

#endif // LISTOFSTUDENTS_H
