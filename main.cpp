#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QList>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QMainWindow>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto name = QFileInfo(QCoreApplication::applicationFilePath()).fileName();
    auto args = QCoreApplication::arguments();
    args.removeAt(0);
    if (args.length() < 1) {
        qWarning() << "Error: No files provided";
        return 1;
    }

    QDir dir = QDir::current();
    QList<QUrl> files;

    foreach (QString arg, args) {
        auto filePath = QDir::cleanPath(dir.absoluteFilePath(arg));
        QFile file;
        file.setFileName(filePath);

        if (!file.exists()) {
            qWarning().noquote() << name + ": cannot access"
                       << "'" + dir.relativeFilePath(filePath) + "':"
                       << "No such file or directory";
            continue;
        }

        files.append(QUrl::fromLocalFile(filePath));
    }

    QMainWindow w;
    QDrag drag(&w);

    QMimeData *mimeData = new QMimeData;
    mimeData->setUrls(files);
    drag.setMimeData(mimeData);

    drag.exec();

    return 0;
}
