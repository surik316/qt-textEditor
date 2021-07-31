#ifndef REFERENCEWINDOW_H
#define REFERENCEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class ReferenceWindow: public QDialog{

    Q_OBJECT
private:

    QLabel* photo;
    QLabel* version;
    QLabel* name_author;
    QLabel* version_QT;
    QLabel* data_make;
    QPushButton* make_cancel;

public:
    ReferenceWindow();

};

#endif // REFERENCEWINDOW_H
