#include "findandreplace.h"

FindAndReplace::FindAndReplace(){

    word = new QLineEdit;
    word_replace = new QLineEdit;
    replace = new QPushButton( QString::fromUtf8("Заменить"));
    connect(replace, SIGNAL(clicked()),SLOT(go_to_Replace()));

    QGridLayout* ptopLayout = new QGridLayout;

    ptopLayout->addWidget(word,0,0);
    ptopLayout->addWidget(word_replace,2,0);
    ptopLayout->addWidget(replace,3,0);
    setLayout(ptopLayout);

}
QString FindAndReplace::getLine(){

    return word->text();

}

QString FindAndReplace::get_replace_line(){
    return word_replace->text();
}

void FindAndReplace::go_to_Replace(){
    emit signal_replace();

}
