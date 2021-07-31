#ifndef SEARCHHIGHLIGHT_H
#define SEARCHHIGHLIGHT_H
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class SearchHighLight : public QDialog{

    Q_OBJECT

public:

    SearchHighLight();
    QString getLine ();

private:

    QLineEdit* word;
    QPushButton *find_all;

};

#endif // SEARCHHIGHLIGHT_H
