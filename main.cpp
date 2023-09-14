#include <QApplication.h>
#include <QDebug.h>
#include "PassWindow.hpp"
#include "MainWindow.hpp"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	PassWindow pw;
	pw.show();

	MainWindow mw;

	QObject::connect(&pw, &PassWindow::password_validated, &mw, &MainWindow::display);

	return app.exec();
}

/*
Open a link: https://doc.qt.io/qt-5/qdesktopservices.html
QSS (CSS for qt): https://youtu.be/zjWfDEUsobQ
IP: https://www.showmyip.com/ip-lookup/?ip=90.105.30.215
Outline dotted: https://stackoverflow.com/questions/9795791/removing-dotted-border-without-setting-nofocus-in-windows-pyqt
QStyleSheetManipulator: https://stackoverflow.com/questions/52879480/how-to-update-a-single-property-of-the-stylesheet
Loading Screen: https://doc.qt.io/qt-5/qsplashscreen.html
*/

/*
QScreen* screen = QGuiApplication::primaryScreen();		// écran principal
QList<QScreen *> screens = QGuiApplication::screens();	// écrans (0->main)
QDesktopWidget* desk = QApplication::desktop();
desk->screenGeometry();
qDebug() << desk->screenGeometry() << desk->screenGeometry(0) << desk->screenGeometry(1);  // QRect(0,0 1920x1080) QRect(0,0 1920x1080) QRect(1920,815 1920x1080)
*/