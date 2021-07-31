#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H
#include <QMainWindow>
#include <QTextEdit>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QFontDialog>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QFileDialog>
#include <QTextCodec>
#include <QMessageBox>
#include <QTextDocumentWriter>
#include <QTextStream>
#include <QStatusBar>
#include <QLabel>
#include <QTextDocument>
#include <QString>
#include <cmath>
#include <QDateTime>
#include<QDebug>
#include <string>
#include <QTextCursor>
#include <QToolButton>
#include <QSyntaxHighlighter>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:

    Highlighter(QTextDocument *parent = 0, int n = 0);
    int number ;
    QBrush getKeywordColor();
    QBrush getClassColor();
    QBrush getQuotationColor();
    QBrush getFunctionColor();
    QBrush getMultiLineColor();


    void setKeywordColor( QBrush);
    void setClassColor( QBrush);
    void setQuotationColor( QBrush);
    void setFunctionColor( QBrush);
    void setMultiLineColor( QBrush);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

    QBrush colorKeyword = Qt::magenta;
    QBrush colorClassFormat = Qt::darkMagenta;
    QBrush colorQuotationFormat = Qt::darkGreen;
    QBrush colorFunctionFormat = Qt::blue;
    QBrush colorMultiLineFormat = Qt::red;

};

#endif // HIGHLIGHTER_H
