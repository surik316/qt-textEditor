#ifndef CHAGESYNTAX_H
#define CHAGESYNTAX_H



#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include "highlighter.h"
class ChageSyntax: public QDialog{

    Q_OBJECT

public:
    QLabel* keywords;
    QLabel* functions;
    QLabel* classFormat;
    QPushButton* change;
    QPushButton* download_style;
    QPushButton* default_style;
    QLineEdit* key_line ;
    QLineEdit* func_line ;
    QLineEdit* class_line ;
    ChageSyntax();

};




#endif // CHAGESYNTAX_H
