#ifndef PERSONE_H
#define PERSONE_H

#include <QString>


class Persone
{
public:
    Persone();
    Persone(QString, QString);
    ~Persone();
    QString ShowInfo();
    void SetID(int);
    QString GetName();
    QString GetSecondName();
    uint GetID();

protected:
    QString m_Name;
    QString m_SecondName;
    uint m_ID;
};

#endif // PERSONE_H
