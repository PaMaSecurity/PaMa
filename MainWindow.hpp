#ifndef PAMA_MAINWINDOW_
#define PAMA_MAINWINDOW_

#include <QMainWindow.h>
#include <QApplication.h>
#include <QDesktopWidget.h>
#include <QMenuBar.h>
	
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

public slots:
	void display(QString p);

private: //objects
	QDesktopWidget* desk;

	QMenu* fileMenu;				// File
	QMenu* newActGrp;				// |---New
	QAction* new_accountAct;		// |   |---Account
	QAction* new_folderAct;			// |   |---Folder
	QAction* settingsAct;			// |---Settings
	QAction* exitAct;				// |---Exit

	QMenu* helpMenu;				// Help
	QAction* view_helpAct;			// |---View Help
	QAction* getting_startedAct;	// |---Getting Started
	QAction* shortcut_refdAct;		// |---Shortcut Reference
	QAction* feedbackAct;			// |---Feedback
	QAction* release_notesAct;		// |---Release Notes
	QAction* open_srcAct;			// |---About Open-soucre
};

#endif