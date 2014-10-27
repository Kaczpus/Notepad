#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>

namespace Ui {
class notepad;
}

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepad(QWidget *parent = 0);
    ~notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::notepad *ui;
    QString FileName;
};

#endif // NOTEPAD_H
