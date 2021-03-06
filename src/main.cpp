#include "dialogs/WelcomeDialog.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load our custom fonts
    QFontDatabase fontDb;
    fontDb.addApplicationFont(":/global/assets/Roboto-Regular.ttf");
    fontDb.addApplicationFont(":/global/assets/Roboto-Light.ttf");
    fontDb.addApplicationFont(":/global/assets/Roboto-BoldCondensedItalic.ttf");

    // Read the stylesheet
    QFile style(":/global/assets/mainstyle.qss");
    if (!style.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(NULL, "Error", "Cannot open stylesheet: " + style.errorString());
        QMessageBox::critical(NULL, "Permission issues?",
                             "It looks like OmniInstaller resources file couldn't be opened. "
                             "Make sure the app is ran in a folder with the proper permissions, "
                             "and/or with Administrator privileges.");
    }

    qApp->setStyleSheet(style.readAll());

    WelcomeDialog w;
    w.show();

    return a.exec();
}
