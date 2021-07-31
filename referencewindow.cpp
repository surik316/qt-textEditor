#include "referencewindow.h"
#include "mainwindow.h"
ReferenceWindow::ReferenceWindow(): QDialog(0){

    photo = new QLabel(this);
    version = new QLabel("5.15");
    name_author = new QLabel("Maksim");
    version_QT = new QLabel(QString::fromUtf8(qVersion()));
    data_make = new QLabel(QString::fromUtf8("Дата сборки программы: ") + __DATE__ + QString::fromUtf8(" в ")  + __TIME__);
    make_cancel = new QPushButton(QString::fromUtf8("Закрыть"));
    QPixmap pixmap("/media/sf_share/images/fileopen.png");
    photo->setPixmap(pixmap);
    connect(make_cancel, SIGNAL(clicked()),this,SLOT(reject()));
    QGridLayout* ptopLayout = new QGridLayout;

    ptopLayout->addWidget(photo, 0, 0);
    ptopLayout->addWidget(version, 1, 0);
    ptopLayout->addWidget(name_author, 2, 0);
    ptopLayout->addWidget(version_QT, 3, 0);
    ptopLayout->addWidget(data_make, 4, 0);
    ptopLayout->addWidget(make_cancel, 5, 0);

    setLayout(ptopLayout);
}
