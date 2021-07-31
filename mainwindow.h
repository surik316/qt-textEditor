#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QStatusBar>
#include <QLabel>
#include <QTextDocument>
#include <QDateTime>
#include <QTextCursor>
#include <QToolButton>
#include <QSettings>


#include "searchhighlight.h"
#include "findandreplace.h"
#include "codeeditor.h"
#include "referencewindow.h"
#include "highlighter.h"
#include "chagesyntax.h"

const QString rsrcPath = "/media/sf_share/images";
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    CodeEditor *textEdit;
    QToolBar *toolBar;
    QString fileName;
    QLabel *len_str;
    QLabel *current_pos;
    QLabel *last_change;
    QDateTime *date_time;
    QDateTime *saved_date_time;
    SearchHighLight *dialog;
    FindAndReplace *dialog_replace;
    QAction *sb;
    QAction *tb;
    QAction *line_break;
    QAction *line_number;
    QAction* C89;
    QAction* C98_03;
    QAction* C11_14;
    QAction* C17;
    QAction* C20;
    QActionGroup* actionGroup;
    Highlighter *highlighter;
    QAction *syntaxHighlight;
    QSettings* sett;
    ChageSyntax* dialog_to_change_syntax;

    void createStatusBar();
    bool maybeSave();
    void FileMenu ();
    void EditMenu();
    void FormatMenu();
    void ViewMenu();
    void ReferenceMenu();
    void contextMenu();
    bool load(const QString &f);
    void setCurrentFileName(const QString &fileName);
    bool rmbp = false;

protected:
    void mousePressEvent(QMouseEvent* event);

public:
    MainWindow(QWidget *parent = 0);
    bool isFirstTime;

private slots:

    void openReference();
    void SetCurrentTextFormat();
    void SetColorCurrentLine();
    void LineBreakHidden();
    void ToolBarHidden();
    void StatusBarHidden();
    void replaceALL();
    void StatusBarAction();
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void findText();
    void trigger_for_highlight();
    void selectWord();
    void trigger_for_replace();
    void SetPalleteColor();
    void HighlightLineHidden();
    void BlockUnderCursor();
    void d();
    void giveVersion89();
    void giveVersion98();
    void giveVersion14();
    void giveVersion17();
    void giveVersion20();
    void highlightHidden();
    void normal_close();
    void selectSyntax();
};
#endif // MAINWINDOW_H
