#include <QApplication.h>
#include <QDebug.h>
#include "pvars.hpp"
#include "PassWindow.hpp"
#include "MainWindow.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	PVars vars;

	PassWindow pw{ &vars };
	pw.show();

	MainWindow mw;

	QObject::connect(&pw, &PassWindow::password_validated, &mw, &MainWindow::display);

	return app.exec();
}

/* Ideas:
- Have a menu where all actions done that can be undone are listed
- App on phone that can unlock the software (need to be oversecured)
- Use a stack for undo and an other for redo
*/

/*
Windows Theme: https://stackoverflow.com/questions/75457687/detect-dark-application-style-theme-of-currently-used-desktop-in-qt
Open a link: https://doc.qt.io/qt-5/qdesktopservices.html
QSS (CSS for qt): https://youtu.be/zjWfDEUsobQ
IP: https://www.showmyip.com/ip-lookup/?ip=90.105.30.215
Outline dotted: https://stackoverflow.com/questions/9795791/removing-dotted-border-without-setting-nofocus-in-windows-pyqt
QStyleSheetManipulator: https://stackoverflow.com/questions/52879480/how-to-update-a-single-property-of-the-stylesheet
Loading Screen: https://doc.qt.io/qt-5/qsplashscreen.html
Create a QSS property: https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-using-dynamic-properties
Variables in QSS: https://stackoverflow.com/questions/10898399/using-variables-in-qt-stylesheets
Differences between List and Vector: https://www.geeksforgeeks.org/difference-between-vector-and-list/
*/

/*
QScreen* screen = QGuiApplication::primaryScreen();		// écran principal
QList<QScreen *> screens = QGuiApplication::screens();	// écrans (0->main)
QDesktopWidget* desk = QApplication::desktop();
desk->screenGeometry();
qDebug() << desk->screenGeometry() << desk->screenGeometry(0) << desk->screenGeometry(1);  // QRect(0,0 1920x1080) QRect(0,0 1920x1080) QRect(1920,815 1920x1080)
*/