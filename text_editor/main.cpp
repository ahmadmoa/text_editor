#include "text_editor.h"
#include <QtWidgets/QApplication>
#include "option.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    text_editor w;
    w.show();
   // option o;
    //o.show();
    return a.exec();
    
}
