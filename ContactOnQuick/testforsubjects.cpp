#include "testforsubjects.h"
#define List ListOfSubject::GetListOfSubject()



TestForSubjects::TestForSubjects()
{

}

void TestForSubjects::Test()
{
    List->Load("C:/Users/nikit/Documents/Qt/Projects/build-ContactOnQuick-Desktop_Qt_5_9_2_MinGW_32bit-Debug/debug/Source/TestSubject.xml");
    //Не работает относительный путь
    List->Save("C:/Users/nikit/Documents/Qt/Projects/build-ContactOnQuick-Desktop_Qt_5_9_2_MinGW_32bit-Debug/debug/Source/TestSubjectOut.xml");

}
