#include "cbuiltindlg.h"
#include <QtWidgets>
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/qpagesetupdialog.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>

Cbuiltindlg::Cbuiltindlg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayoyt= new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("Qt標準通用對話盒"));
    colorButton = new QPushButton(QStringLiteral("顏色對話盒"));
    errorButton = new QPushButton(QStringLiteral("錯誤訊息盒"));
    fileButton = new QPushButton(QStringLiteral("檔案對話盒"));
    fontButton = new QPushButton(QStringLiteral("字體對話盒"));
    inputButton = new QPushButton(QStringLiteral("輸入對話盒"));
    pageButton = new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressButton = new QPushButton(QStringLiteral("進度對話盒"));
    printButton = new QPushButton(QStringLiteral("列印對話盒"));
    textcolorButton = new QPushButton(QStringLiteral("設定字體顏色"));

    gridLayoyt->addWidget(colorButton,0,0,1,1);
    gridLayoyt->addWidget(errorButton,0,1,1,1);
    gridLayoyt->addWidget(fileButton,0,2,1,1);
    gridLayoyt->addWidget(fontButton,1,0,1,1);
    gridLayoyt->addWidget(inputButton,1,1,1,1);
    gridLayoyt->addWidget(pageButton,1,2,1,1);
    gridLayoyt->addWidget(progressButton,2,0,1,1);
    gridLayoyt->addWidget(printButton,2,1,1,1);
    gridLayoyt->addWidget(textcolorButton,2,2,1,1);
    gridLayoyt->addWidget(displayTextEdit,3,0,3,3);
    // 以上是將QPushButton及QTextEdit納入gridLayout管理
    setLayout(gridLayoyt); // 將目前對話盒視窗設為gridLayout管理
    setWindowTitle(tr("內建對話盒展示"));
    resize(400,300);
    connect(colorButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(fileButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(fontButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(progressButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(pageButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(printButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(errorButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(inputButton, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(textcolorButton, SIGNAL(clicked()), this, SLOT(doTextColor()));
}

Cbuiltindlg::~Cbuiltindlg() {}

void Cbuiltindlg::doTextColor()
{
    QPalette palette = displayTextEdit->palette();
    const QColor& color =
        QColorDialog::getColor(palette.color(QPalette::Text),
                                                 this, tr("設定文字顏色"));
    if(color.isValid())
    {
        palette.setColor(QPalette::Text, color);
        displayTextEdit->setPalette(palette);
    }
}

void Cbuiltindlg::doPushBtn()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if (btn == colorButton)
    {
        // qDebug() << "Hello World!";
        QPalette palette = displayTextEdit->palette();
        const QColor& color =
            QColorDialog::getColor(palette.color(QPalette::Base),
                                                     this, tr("設定背景顏色"));
        if(color.isValid())
        {
            palette.setColor(QPalette::Base, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn == fileButton)
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        QStringLiteral("開啟檔案"),
                                                        tr("."),
                                                        QStringLiteral("任何檔案(*.*)"
                                                            ";;文字檔(*.txt)"
                                                            ";;XML檔(*.xml)"));
        displayTextEdit->setText(fileName);
    }
    if(btn == fontButton)
    {
        bool ok;
        const QFont& font = QFontDialog::getFont(&ok,
                                         displayTextEdit->font(),
                                         this,
                                         tr("字體對話盒"));
        if(ok) displayTextEdit->setFont(font);
    }
    if(btn == inputButton)
    {
        bool ok;
        const QString& text = QInputDialog::getText(this,
                                            tr("輸入對話盒"),
                                            tr("請輸入文字:"),
                                            QLineEdit::Normal,
                                            QDir::home().dirName(),
                                            &ok
                                            );
        if(ok) displayTextEdit->setText(text);
    }
    if(btn == progressButton)
    {
        QProgressDialog progress(tr("正在複製檔案.."),
                                 tr("取消"),
                                 0,
                                 10000,
                                 this);
        progress.setWindowTitle(tr("進度對話盒"));
        progress.show();
        for(int i=0;i<10000;i++)
        {
            progress.setValue(i);
            qApp->processEvents();
            if(progress.wasCanceled()) break;
            qDebug() << i;
        }
        progress.setValue(10000);
        // _sleep(10000);
    }
    if(btn == printButton)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog dialog(&printer, this);
        if (dialog.exec() != QDialog::Accepted)
            return;
    }
    if(btn == pageButton)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPageSetupDialog* dlg = new QPageSetupDialog(&printer, this);
        dlg->setWindowTitle(tr("頁面設定對話方塊"));
        if(dlg->exec() == QDialog::Accepted)
        {

        }
    }
    if(btn == errorButton)
    {
        QErrorMessage box(this);
        box.setWindowTitle(tr("錯誤訊息盒"));
        box.showMessage(QStringLiteral("錯誤訊息盒實例xx : "));
        box.showMessage(QStringLiteral("錯誤訊息盒實例yy : "));
        box.showMessage(QStringLiteral("錯誤訊息盒實例zz : "));
        box.exec();
    }
}
