#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "testforsubjects.h"
#include "listofstudents.h"

#define MyList ListOfStudents::GetListOfStudents()

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MyList->Load("C:/Users/nikit/Documents/Qt/Projects/ContactOnQuick/build-ContactOnQuick-Desktop_Qt_5_9_2_MinGW_32bit-Debug/debug/Source/TestStudents.xml");
    QStringList dataList = MyList->List();
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("students", QVariant::fromValue(dataList));
    //qmlRegisterType<ListOfStudents>("students", 1, 0, "ListOfStudents");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;



    return app.exec();
}
