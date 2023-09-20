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
	QAction* new_accountAct;		// |---New Account
	QAction* new_folderAct;			// |---New Folder
	QAction* settingsAct;			// |---Settings
	QAction* exitAct;				// |---Exit

	QMenu* editMenu;				// Edit
	QAction* undoAct;				// |---Undo
	QAction* redoAct;				// |---Redo
	QAction* cutAct;				// |---Cut
	QAction* copyAct;				// |---Copy
	QAction* pasteAct;				// |---Paste
	QAction* deleteAct;				// |---Delete
	QAction* selectallAct;			// |---Select All
	QAction* deselectallAct;		// |---Deselect All

	QMenu* viewMenu;				// View
	QAction* fullscreenAct;			// |---Full Screen
	QAction* zoominAct;				// |---Zoom in
	QAction* zoomoutAct;			// |---Zoom out
	QAction* reset_zoomAct;			// |---Reset Zoom
	QAction* appearenceAct;			// |---Appearence (to settings)
	QAction* reset_layoutAct;		// |---Reset Window Layout

	QMenu* helpMenu;				// Help
	QAction* view_helpAct;			// |---View Help
	QAction* getting_startedAct;	// |---Getting Started
	QAction* shortcut_refdAct;		// |---Shortcut Reference
	QAction* feedbackAct;			// |---Feedback
	QAction* release_notesAct;		// |---Release Notes
	QAction* open_srcAct;			// |---About Open-soucre

private slots:
	void new_account();
	void new_folder();
	void settings();
	void exit();
	void undo();
	void redo();
	void cut();
	void copy();
	void paste();
};

#endif