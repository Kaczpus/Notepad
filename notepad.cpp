#include "notepad.h"
#include "ui_notepad.h"

notepad::notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->text);
}

notepad::~notepad()
{
    delete ui;
}

void notepad::on_actionNew_triggered()
{
    FileName = "";
    ui->text->setPlainText("");
}

void notepad::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open file");
    if(!file.isEmpty())
    {
       FileName = file;
        QFile _File(file);
        if(_File.open(QFile::ReadOnly | QFile::Text ))
        {
            QTextStream in(&_File);
            QString text = in.readAll();
            _File.close();
            ui->text->setPlainText(text);
        }
    }
}

void notepad::on_actionSave_triggered()
{
    QFile _File(FileName);
    if(_File.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&_File);
        out << ui->text->toPlainText();
        _File.flush();
        _File.close();
    }
}

void notepad::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open file");
    if(!file.isEmpty())
    {
        FileName = file;
        on_actionSave_as_triggered();
    }
}

void notepad::on_actionCopy_triggered()
{
    ui->text->copy();
}

void notepad::on_actionCut_triggered()
{
    ui->text->cut();
}

void notepad::on_actionPaste_triggered()
{
    ui->text->paste();
}

void notepad::on_actionUndo_triggered()
{
    ui->text->undo();
}

void notepad::on_actionRedo_triggered()
{
    ui->text->redo();
}
