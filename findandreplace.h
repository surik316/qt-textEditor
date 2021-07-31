#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H
#include <QSyntaxHighlighter>

#include <QTextCharFormat>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class FindAndReplace: public QDialog{

    Q_OBJECT

public:

    FindAndReplace();
    QString getLine ();
    QString get_replace_line();

private:

    QLineEdit* word;
    QLineEdit* word_replace;
    QPushButton *replace;

private slots:

   void go_to_Replace();

signals:

    void signal_replace();
};

#endif
