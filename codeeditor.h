#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QStatusBar>
#include <QLabel>
#include <QTextDocument>
#include <QString>
#include <QDateTime>
#include <QTextCursor>
#include <QToolButton>
#include <QSettings>
#include <QFontDialog>
#include <QPlainTextEdit>

class CodeEditor : public QPlainTextEdit{

    Q_OBJECT

public:

    CodeEditor(QWidget *parent = 0);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    QWidget* getlineNumberArea();
    QColor current_color = "green";
    QColorDialog *lineFontDialog;
    QFontDialog *textFormatDialog;
    void setColorLine();
    bool getRmbp();
protected:

    void resizeEvent(QResizeEvent *event);

private slots:

    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);


private:
    QTextEdit::ExtraSelection selection;
    QWidget *lineNumberArea;


};

#endif
