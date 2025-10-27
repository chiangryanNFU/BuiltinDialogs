#ifndef CBUILTINDLG_H
#define CBUILTINDLG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>

class Cbuiltindlg : public QDialog
{
    Q_OBJECT

public:
    Cbuiltindlg(QWidget *parent = nullptr);
    ~Cbuiltindlg();
private:
    QTextEdit *displayTextEdit;
    QPushButton *colorButton;
    QPushButton *errorButton;
    QPushButton *fileButton;
    QPushButton *fontButton;
    QPushButton *inputButton;
    QPushButton *pageButton;
    QPushButton *progressButton;
    QPushButton *printButton;
    QPushButton *textcolorButton;
private slots:
    void doPushBtn();
    void doTextColor();
};
#endif // CBUILTINDLG_H
