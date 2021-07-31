#include "chagesyntax.h"

ChageSyntax::ChageSyntax(): QDialog(0){

    key_line = new QLineEdit;
    func_line = new QLineEdit;
    class_line = new QLineEdit;
    keywords = new QLabel("Keywords");
    functions = new QLabel("Functions");
    classFormat = new QLabel("Classes");
    change = new QPushButton("Change");
    download_style = new QPushButton("Download");
    default_style = new QPushButton("Default");

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout -> addWidget(key_line,0,1);
    ptopLayout -> addWidget(func_line,1,1);
    ptopLayout -> addWidget(class_line,2,1);

    ptopLayout -> addWidget(keywords,0,0);
    ptopLayout -> addWidget(functions,1,0);
    ptopLayout -> addWidget(classFormat,2,0);
    ptopLayout ->addWidget(change);
    ptopLayout ->addWidget(download_style);
    ptopLayout ->addWidget(default_style);


    setLayout(ptopLayout);
}
