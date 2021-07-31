#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H
#include <QWidget>
#include <QTextEdit>
#include "mainwindow.h"

class LineNumberArea : public QWidget{
public:
    LineNumberArea(CodeEditor *editor) ;
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    CodeEditor *codeEditor;
};

#endif
