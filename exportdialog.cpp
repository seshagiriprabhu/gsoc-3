#include "exportdialog.hpp"
#include <QFileDialog>
#include <QSettings>
#include <QDebug>
#include <QFile>

#define RAW "Raw Profile"
#define ENC "Encrypted Profile"
#define TOX_RAW "Toxcore Raw"

ExportDialog::ExportDialog(QWidget *parent)
    : QFileDialog(parent)
{
    const QString DEFAULT_DIR_KEY("default_dir");
    const QString suffix = "tox";
    setDefaultSuffix(suffix);
    QSettings MySettings;
    QString selectedFilter;
    QString filename = this->getSaveFileName(this, tr("Export Profile"),
                    MySettings.value(DEFAULT_DIR_KEY).toString(),
                    tr(RAW";;"ENC";;"TOX_RAW), &selectedFilter);

    if (!filename.isEmpty()) {
            QDir CurrentDir;
            MySettings.setValue(DEFAULT_DIR_KEY, CurrentDir.absoluteFilePath(filename));
    }

    if (filename.isEmpty()) {
        return;
    }
    if (selectedFilter == RAW) {
        qDebug() << "User has chosen a raw profile export";
        // code for encrypted-> raw or raw -> raw should be added here
    } else if (selectedFilter == ENC) {
        qDebug() << "User has chosen an encrypted export";
        // code for enc -> enc or raw -> enc
    } else if (selectedFilter == TOX_RAW) {
        qDebug() << "User has chosen a toxcore raw export";
        // code for enc -> tox_raw or raw -> tox_raw goes here
    } else {
        qDebug() << "User has chosen nothing";
    }
    filename += ".tox";
    qDebug() << "Filename: " << filename;
}

ExportDialog::~ExportDialog()
{


}
