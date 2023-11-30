#ifndef PAMA_MAINWINDOW_
#define PAMA_MAINWINDOW_

#include <QMainWindow.h>
#include <QApplication.h>
#include <QDesktopWidget.h>
#include <QMenuBar.h>
#include <QDebug.h>

#include <stack>
	
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
	QAction* shortcut_refAct;		// |---Shortcut Reference
	QAction* feedbackAct;			// |---Feedback
	QAction* release_notesAct;		// |---Release Notes
	QAction* open_srcAct;			// |---About Open-soucre

private:  //vars
	/*
	https://stackoverflow.com/questions/8915797/calling-a-function-through-its-address-in-memory-in-c-c
	*/
	std::stack<int> redoSK;
	std::stack<int> undoSK;

private slots:
	// File
	void new_account();
	void new_folder();
	void open_settings();
	void exit();
	// Edit
	void undo();
	void redo();
	void cut();
	void copy();
	void paste();
	void suppr();
	void selectall();
	void deselectall();
	// View
	void full_screen();
	void zoom_in();
	void zoom_out();
	void reset_zoom();
	void reset_layout();
	// Help
	void view_help();
	void getting_started();
	void shortcut_reference();
	void feedback();
	void release_notes();
	void about_open_src();
};

#endif 