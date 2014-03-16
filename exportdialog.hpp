#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>
#include <QFileDialog>

class ExportDialog : public QFileDialog
{
    Q_OBJECT


public:
    ExportDialog(QWidget *parent = 0);
    ~ExportDialog();
};

#endif // EXPORTDIALOG_H
