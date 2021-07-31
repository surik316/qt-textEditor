#include "searchhighlight.h"

SearchHighLight::SearchHighLight():QDialog(0){

    word = new QLineEdit;
    find_all = new QPushButton( QString::fromUtf8("Find"));
    connect(find_all, SIGNAL(clicked()),SLOT(accept()));
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(word,0,0);
    ptopLayout->addWidget(find_all,1,0);
    setLayout(ptopLayout);

}
QString SearchHighLight::getLine(){

    return word->text();

}


