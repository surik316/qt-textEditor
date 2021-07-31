#include "mainwindow.h"
#include <QColor>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    dialog = new SearchHighLight;
    dialog_replace = new FindAndReplace;

    textEdit = new CodeEditor(this);
    setCentralWidget(textEdit);
    textEdit->setFocus();
    connect(textEdit,SIGNAL(cursorPositionChanged()),this ,SLOT(StatusBarAction()));
    dialog_to_change_syntax = new ChageSyntax;


    highlighter = new Highlighter(textEdit->document(),5);

    createStatusBar();
    FileMenu();
    EditMenu();
    FormatMenu();
    ViewMenu();
    ReferenceMenu();
}

void MainWindow::FileMenu(){
     toolBar = new QToolBar(this);
     toolBar->setWindowTitle(QString::fromUtf8("Действия с файлом"));
     addToolBar(toolBar);

     QMenu *menu = new QMenu(QString::fromUtf8("Файл"), this);
     menuBar()->addMenu(menu);

     QAction *a;
     QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
     a = new QAction(newIcon, QString::fromUtf8("&Новый"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("document-open", QIcon(rsrcPath + "/fileopen.png")), QString::fromUtf8("&Открыть"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("document-save", QIcon(rsrcPath + "/filesave.png")), QString::fromUtf8("Сохранить"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction( QString::fromUtf8("Сохранить как"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
     menu->addAction(a);

     a = new QAction( QString::fromUtf8("Выход"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(normal_close()));
     menu->addAction(a);
}

void MainWindow::EditMenu(){

     toolBar->setWindowTitle(QString::fromUtf8("Работа с файлом"));
     addToolBar(toolBar);

     QMenu *menu = new QMenu(QString::fromUtf8("Правка"), this);
     menuBar()->addMenu(menu);

     QAction *a;

     a = new QAction(QIcon::fromTheme("undo", QIcon(rsrcPath + "/editundo.png")),QString::fromUtf8("Отменить"), this);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(undo()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("redo", QIcon(rsrcPath + "/editredo.png")),QString::fromUtf8("Повторить"), this);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(redo()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("copy", QIcon(rsrcPath + "/editcopy.png")), QString::fromUtf8("Копировать"), this);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(copy()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("cut", QIcon(rsrcPath + "/editcut.png")), QString::fromUtf8("Вырезать"), this);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(cut()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("paste", QIcon(rsrcPath + "/editpaste.png")), QString::fromUtf8("Вставить"), this);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(paste()));
     toolBar->addAction(a);
     menu->addAction(a);


     QMenu *toolButton_menu = new QMenu(QString::fromUtf8("Найти/Найти и заменить"));
     QToolButton* toolButton = new QToolButton();
     toolButton->setIcon(QIcon(rsrcPath + "/editfind.png"));
     toolButton->setMenu(toolButton_menu);

     a = new QAction( QString::fromUtf8("Найти"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(trigger_for_highlight()));
     menu->addAction(a);
     toolButton_menu->addAction(a);

     a = new QAction( QString::fromUtf8("Найти и заменить"), this);
     connect(a, SIGNAL(triggered()), this, SLOT(trigger_for_replace()));
     menu->addAction(a);
     toolButton_menu->addAction(a);
     toolButton->setPopupMode(QToolButton::InstantPopup);
     toolBar->addWidget(toolButton);

     a = new QAction( QString::fromUtf8("Выделить все"), this);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(selectAll()));
     menu->addAction(a);
}

void MainWindow::FormatMenu(){

     QMenu *menu = new QMenu(QString::fromUtf8("Формат"), this);
     menuBar()->addMenu(menu);

     QAction *a;

     line_break = new QAction( QString::fromUtf8("Перенос по словам"), this);
     line_break->setPriority(QAction::LowPriority);
     line_break->setShortcut(QKeySequence::New);
     line_break->setCheckable(true);
     connect(line_break, SIGNAL(triggered()), this, SLOT(LineBreakHidden()));
     line_break->setChecked(true);
     menu->addAction(line_break);

     a = new QAction( QString::fromUtf8("Выбор шрифта"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(SetCurrentTextFormat()));
     menu->addAction(a);
}

void MainWindow::ViewMenu(){
    QMenu *menu = new QMenu(QString::fromUtf8("Вид"), this);
    menuBar()->addMenu(menu);

    QAction *a;
    a = new QAction( QString::fromUtf8("Выбор цвета фона"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(SetPalleteColor()));
    menu->addAction(a);

    a = new QAction( QString::fromUtf8("Выбор цвета текущей строки"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(SetColorCurrentLine()));
    menu->addAction(a);

    line_number = new QAction( QString::fromUtf8("Отображение нумерации строк"), this);
    line_number->setCheckable(true);

    connect(line_number, SIGNAL(triggered()), this, SLOT(HighlightLineHidden()));
    line_number->setChecked(true);
    menu->addAction(line_number);

    tb = new QAction( QString::fromUtf8("Отображение панели инструментов"), this);
    tb->setCheckable(true);
    connect(tb, SIGNAL(triggered()), this, SLOT(ToolBarHidden()));
    tb->setChecked(true);
    menu->addAction(tb);

    sb  = new QAction( QString::fromUtf8("Отображение строки состояния"), this);
    sb ->setCheckable(true);
    sb ->setChecked(true);
    connect(sb , SIGNAL(triggered()), this, SLOT(StatusBarHidden()));
    menu->addAction(sb);

    QMenu* m = new QMenu( QString::fromUtf8("Выбор синтаксиса"), this);
    actionGroup = new QActionGroup(this);
    C89 = new QAction( QString::fromUtf8("Си89"), this);
    C89 ->setCheckable(true);
    C98_03 = new QAction( QString::fromUtf8("Си++98/03"), this);
    C98_03 ->setCheckable(true);
    C11_14 = new QAction( QString::fromUtf8("Си++11/14 "), this);
    C11_14 ->setCheckable(true);
    C17 = new QAction( QString::fromUtf8("Си++17"), this);
    C17 ->setCheckable(true);
    C20 = new QAction( QString::fromUtf8("Си++20"), this);
    C20->setCheckable(true);
    C20->setChecked(true);

    actionGroup->addAction(C89);
    actionGroup->addAction(C98_03);
    actionGroup->addAction(C11_14);
    actionGroup->addAction(C17);
    actionGroup->addAction(C20);

    connect(C89, SIGNAL(triggered()),this,SLOT(giveVersion89()));
    connect(C98_03, SIGNAL(triggered()),this,SLOT(giveVersion98()));
    connect(C11_14, SIGNAL(triggered()),this,SLOT(giveVersion14()));
    connect(C17, SIGNAL(triggered()),this,SLOT(giveVersion17()));
    connect(C20, SIGNAL(triggered()),this,SLOT(giveVersion20()));
    m->addActions(actionGroup->actions());
    menu->addMenu(m);

    syntaxHighlight = new QAction(QString::fromUtf8("Подсветка синтаксиса"),this);
    syntaxHighlight->setCheckable(true);
    syntaxHighlight->setChecked(true);
    menu->addAction(syntaxHighlight);
    connect(syntaxHighlight, SIGNAL(triggered()), this, SLOT(highlightHidden()));

    QAction *syntax_setting = new QAction(QString::fromUtf8("Выбор/Редактирование стиля подсветки"),this);
    connect(syntax_setting, SIGNAL(triggered()), this, SLOT(selectSyntax()));
    menu->addAction(syntax_setting);
}

void MainWindow::ReferenceMenu(){

    QMenu *menu = new QMenu(QString::fromUtf8("Справка"), this);
    menuBar()->addMenu(menu);
    QAction *a;

    a = new QAction(QString::fromUtf8("Открыть"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(openReference()));
    menu->addAction(a);

}

bool MainWindow::fileSave(){

     if (fileName.isEmpty()){
        return fileSaveAs();
     }
     QFile file(fileName);
     if (file.open(QFile::WriteOnly)){
         file.write(textEdit->toPlainText().toUtf8());
     }
     current_pos->setText((date_time->currentDateTime()).toString("yyyy-MM-dd")+" " + (date_time->currentDateTime()).toString("HH-mm"));
     return 0;
}

bool MainWindow::fileSaveAs(){
    QString file_name = QFileDialog::getSaveFileName(this, tr("Save as..."),"/Users/maksimsurkov/");
    if (file_name.isEmpty()){
       return false;
    }
    setCurrentFileName(file_name);
    return fileSave();
}

void MainWindow::fileNew(){
    textEdit->clear();
    setCurrentFileName(QString());
}

void MainWindow::fileOpen(){
    QString  file_name = QFileDialog::getOpenFileName(this, tr("Open File..."),"/Users/maksimsurkov/");
    if (!file_name.isEmpty()){
         load(file_name);
    }

}

void MainWindow::StatusBarAction(){

    len_str ->setText(QString::fromUtf8("Число символов: ") + QString::number(textEdit->toPlainText().size())
                      + QString::fromUtf8(" Число строк: ") + QString::number(textEdit->document()->blockCount())
                      +QString::fromUtf8(" Число слов: ")+ QString::number(textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count())
                      +" | "+ QString::number(floor(double(1000*(textEdit->toPlainText().size())*8)/1024 + 0.5)/1000) );

    current_pos->setText(QString::fromUtf8("Строка: ")+QString::number((textEdit->textCursor().blockNumber()))
                         + QString::fromUtf8(" Столбец: ") +QString::number(textEdit->textCursor().positionInBlock()));
    last_change->setText((date_time->currentDateTime()).toString("HH-mm"));

}

void MainWindow::createStatusBar(){

     len_str = new QLabel(QString::fromUtf8("Число символов: ") + QString::number(textEdit->toPlainText().size())
                          + QString::fromUtf8(" Число строк: ") + QString::number(textEdit->document()->blockCount())
                          +QString::fromUtf8(" Число слов: ")+ QString::number(textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count())
                          +" | "+ QString::number(floor(double(1000*(textEdit->toPlainText().size())*8)/1024 + 0.5)/1000) );

     current_pos = new QLabel(QString::fromUtf8("Строка: ")+QString::number((textEdit->textCursor().blockNumber()))
                              + QString::fromUtf8(" Столбец: ") +QString::number(textEdit->textCursor().positionInBlock()));
     last_change = new QLabel(QString::fromUtf8("Неизменено"));

     statusBar()->addWidget(last_change);

     statusBar()->addWidget(current_pos);

     statusBar()->addWidget(len_str);


}

void MainWindow::SetPalleteColor(){
    QColorDialog* d = new QColorDialog (this);
    d -> exec();
    QPalette p = textEdit->palette();
    p.setColor(QPalette::Active, QPalette::Base, d->selectedColor());
    p.setColor(QPalette::Inactive, QPalette::Base, Qt::white);
    textEdit->setPalette(p);
}

void MainWindow::trigger_for_highlight(){

    if (!dialog){
        dialog = new SearchHighLight;
    }
    dialog -> show();
    connect(dialog, SIGNAL(accepted()),this,SLOT(findText()));

}

void MainWindow::replaceALL(){

    if(!textEdit->find(dialog_replace->getLine())){
        QMessageBox::information(this,"oops" ,"Not found");
        return;
    }
    textEdit->textCursor().clearSelection();
    textEdit->textCursor().movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
    textEdit->textCursor().insertText(dialog_replace->get_replace_line());
}

void MainWindow::findText(){
    QString str = dialog->getLine();
    QTextDocument *document = textEdit->document();
    bool found = false;

    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);

    cursor.beginEditBlock();

    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    colorFormat.setForeground(Qt::red);

    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {

        highlightCursor = document->find(str, highlightCursor, QTextDocument::FindWholeWords);

        if (!highlightCursor.isNull()) {
            found = true;
            highlightCursor.movePosition(QTextCursor::WordRight, QTextCursor::KeepAnchor);
            highlightCursor.mergeCharFormat(colorFormat);
        }
    }
    cursor.endEditBlock();
    isFirstTime = false;
    if (found == false) {
        QMessageBox::information(this, QString::fromUtf8("Word Not Found"),
        "Sorry, the word cannot be found.");
    }


}

void MainWindow::trigger_for_replace(){
    if (!dialog_replace){
        dialog_replace = new FindAndReplace;
    }
    dialog_replace -> show();
    connect(dialog_replace, SIGNAL(signal_replace()),this,SLOT(replaceALL()));
}

void MainWindow::setCurrentFileName(const QString &fileName)
 {
     this->fileName = fileName;
     textEdit->document()->setModified(false);

     QString shownName;
     if (fileName.isEmpty())
         shownName = "untitled.txt";
     else
         shownName = QFileInfo(fileName).fileName();

     setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(QString::fromUtf8("Editor Text")));
     setWindowModified(false);

}

bool MainWindow::load(const QString &f)
 {
     if (!QFile::exists(f)){
         return false;
     }
     QFile file(f);
     if (!file.open(QFile::ReadOnly)){
         return false;
     }

     QByteArray data = file.readAll();
     QString str = QString::fromLocal8Bit(data);
     textEdit->setPlainText(str);
     setCurrentFileName(f);
     return true;
 }

void MainWindow::StatusBarHidden(){
    if (sb->isChecked()){
        statusBar()->show();
    }
    else{
        statusBar()->hide();
    }
}

void MainWindow::ToolBarHidden(){
    if (tb->isChecked()){
        toolBar->show();
    }
    else{
        toolBar->hide();
    }
}

void MainWindow::LineBreakHidden(){
    if (line_break->isChecked()){
        textEdit->setWordWrapMode(QTextOption::WordWrap);
    }
    else{
        textEdit->setWordWrapMode(QTextOption::NoWrap);
    }
}

void MainWindow::HighlightLineHidden(){
    if (line_number->isChecked()){
        textEdit->getlineNumberArea()->show();
    }
    else{
        textEdit->getlineNumberArea()->hide();
    }
}

void MainWindow::SetColorCurrentLine(){
   textEdit->setColorLine();
}

void MainWindow::SetCurrentTextFormat(){

    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (ok) {
        textEdit->setFont(font);

    }
}

void MainWindow::openReference(){
    ReferenceWindow* w = new ReferenceWindow();
    w->exec();

}

void MainWindow::selectWord(){
   QTextCursor cur = textEdit->textCursor();
   cur.select(QTextCursor::WordUnderCursor);
   textEdit->setTextCursor(cur);
}

void MainWindow::BlockUnderCursor(){
   QTextCursor cur = textEdit->textCursor();
   cur.select(QTextCursor::LineUnderCursor);
   textEdit->setTextCursor(cur);
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton){
       contextMenu();
    }
}

void MainWindow::d(){
    if (textEdit->textCursor().hasSelection()){
        textEdit->textCursor().removeSelectedText();
    }
}

void MainWindow::contextMenu(){

    QMenu* contextwindow = new QMenu(this);

    QAction* decline = new QAction(QString::fromUtf8("Отменить"), this);
    connect(decline,SIGNAL(triggered()),textEdit, SLOT(undo()));

    QAction* repeate = new QAction(QString::fromUtf8("Повторить"), this);
    connect(repeate,SIGNAL(triggered()),textEdit, SLOT(redo()));

    QAction* select = new QAction(QString::fromUtf8("Выделить"), this);
    connect(select,SIGNAL(triggered()),this, SLOT(selectWord()));

    QAction* select_line = new QAction(QString::fromUtf8("Выделить строку"), this);
    connect(select_line,SIGNAL(triggered()),this, SLOT(BlockUnderCursor()));

    QAction* copy = new QAction(QString::fromUtf8("Копировать"), this);
    copy->setEnabled(false);
    connect(copy,SIGNAL(triggered()),textEdit, SLOT(copy()));
    connect(textEdit, SIGNAL(copyAvailable(bool)), copy, SLOT(setEnabled(bool)));

    QAction* cut = new QAction(QString::fromUtf8("Вырезать"), this);
    cut->setEnabled(false);
    connect(cut,SIGNAL(triggered()),textEdit, SLOT(cut()));
    connect(textEdit, SIGNAL(copyAvailable(bool)), cut, SLOT(setEnabled(bool)));

    QAction* paste = new QAction(QString::fromUtf8("Вставить"), this);
    connect(paste,SIGNAL(triggered()),textEdit, SLOT(paste()));
    paste ->setEnabled(false);

    QAction* selectall = new QAction(QString::fromUtf8("Выделить все"), this);
    connect(selectall,SIGNAL(triggered()),textEdit, SLOT(selectAll()));


    QAction* del = new QAction(QString::fromUtf8("Удалить"), this);
    connect(del ,SIGNAL(triggered()),this, SLOT(d()));
    if (textEdit->textCursor().hasSelection()){
        copy -> setEnabled(true);
        cut -> setEnabled(true);
        paste -> setEnabled(true);
    }

    if (textEdit->document()->isEmpty()){
        select->setEnabled(false);
        select_line->setEnabled(false);
    }
    else if (!textEdit->document()->isEmpty()){
        select->setEnabled(true);
        select_line->setEnabled(true);
    }

    contextwindow->addAction(decline);
    contextwindow->addAction(repeate);
    contextwindow->addAction(select);
    contextwindow->addAction(select_line);
    contextwindow->addAction(copy);
    contextwindow->addAction(cut);
    contextwindow->addAction(paste);
    contextwindow->addAction(selectall);
    contextwindow->addAction(del);
    contextwindow->exec(QCursor::pos());

}

void MainWindow::giveVersion89(){

    highlighter = new Highlighter(textEdit->document(),1);

}

void MainWindow::giveVersion98(){

    highlighter = new Highlighter(textEdit->document(),2);

}

void MainWindow::giveVersion14(){

    highlighter = new Highlighter(textEdit->document(),3);

}

void MainWindow::giveVersion17(){

    highlighter = new Highlighter(textEdit->document(),4);

}

void MainWindow::giveVersion20(){

    highlighter = new Highlighter(textEdit->document(),5);

}

void MainWindow::highlightHidden(){

    if (syntaxHighlight->isChecked()==false){
        delete highlighter;
    }
    else if (C89->isChecked()==true && syntaxHighlight->isChecked()== true){
        highlighter = new Highlighter(textEdit->document(),1);

    }
    else if(C98_03->isChecked()==true && syntaxHighlight->isChecked()== true){
        highlighter = new Highlighter(textEdit->document(),2);

    }
    else if(C11_14->isChecked()==true && syntaxHighlight->isChecked()== true){
        highlighter = new Highlighter(textEdit->document(),3);

    }
    else if(C17->isChecked()==true && syntaxHighlight->isChecked()== true){
        highlighter = new Highlighter(textEdit->document(),4);

    }
    else if(C20->isChecked()==true && syntaxHighlight->isChecked()== true){
        highlighter = new Highlighter(textEdit->document(),5);

    }

}

void MainWindow::normal_close(){
    sett = new QSettings("textEdit.ini", QSettings::IniFormat,this);

    sett->beginGroup("Current_settings");
    if (C89->isChecked()){
        sett->setValue("Standart", "89");
    }
    if (C98_03->isChecked()){
       sett->setValue("Standart", "98/03");
    }
    if (C11_14->isChecked()){
       sett->setValue("Standart", "11/14");
    }
    if (C17->isChecked()){
       sett->setValue("Standart", "17");
    }
    if (C20->isChecked()){
        sett->setValue("Standart", "20");
    }

    if (tb->isChecked()){
        sett->setValue("StateOfToolBar", "Onn");
    }
    else{
        sett->setValue("StateOfToolBar", "Off");
    }

    if (line_break->isChecked()){
        sett->setValue("StateOfLineBreak", "Onn");
    }
    else{
        sett->setValue("StateOfLineBreak", "Off");
    }

    if (sb->isChecked()){
        sett->setValue("StateOfStatusBar", "Onn");
    }
    else{
        sett->setValue("StateOfStatusBar", "Off");
    }

    if (syntaxHighlight->isChecked()){
        sett->setValue("StateOfSyntaxHighlight", "Onn");
    }
    else{
        sett->setValue("StateOfSyntaxHighlight", "Off");
    }

    if (line_number->isChecked()){
        sett->setValue("StateOfNumbersLine", "Onn");
    }
    else{
        sett->setValue("StateOfNumbersLine", "Off");
    }

    sett->endGroup();
    this->close();
}

void MainWindow::selectSyntax(){
    dialog_to_change_syntax->key_line->setText(((highlighter->getKeywordColor()).color()).name());
    dialog_to_change_syntax->class_line->setText(((highlighter->getClassColor()).color()).name());
    dialog_to_change_syntax->func_line->setText(((highlighter->getFunctionColor()).color()).name());

    dialog_to_change_syntax->exec();
}
