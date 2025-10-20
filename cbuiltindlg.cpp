#include "cbuiltindlg.h"
#include <QGridLayout>
Cbuiltindlg::Cbuiltindlg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayoyt= new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("Qt的標準通用對話盒"));
    colorButton = new QPushButton(QStringLiteral("顏色對話盒"));
    errorButton = new QPushButton(QStringLiteral("錯誤訊息盒"));
    fileButton = new QPushButton(QStringLiteral("檔案對話盒"));
    fontButton = new QPushButton(QStringLiteral("字體對話盒"));
    inputButton = new QPushButton(QStringLiteral("輸入對話盒"));
    pageButton = new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressButton = new QPushButton(QStringLiteral("進度對話盒"));
    printButton = new QPushButton(QStringLiteral("列印對話盒"));

}

Cbuiltindlg::~Cbuiltindlg() {}
