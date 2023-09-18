#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	//	Instantiate objects
	this->desk = QApplication::desktop();

	this->fileMenu = new QMenu(this);				// File
	this->newActGrp = new QMenu(this);				// |---New
	this->new_accountAct = new QAction(this);		// |   |---Account
	this->new_folderAct = new QAction(this);		// |   |---Folder
	this->settingsAct = new QAction(this);			// |---Settings
	this->exitAct = new QAction(this);				// |---Exit

	this->editMenu = new QMenu(this);				// Edit
	this->undoAct = new QAction(this);				// |---Undo
	this->redoAct = new QAction(this);				// |---Redo
	this->cutAct = new QAction(this);				// |---Cut
	this->copyAct = new QAction(this);				// |---Copy
	this->pasteAct = new QAction(this);				// |---Paste
	this->duplicateAct = new QAction(this);			// |---Duplicate
	this->deleteAct = new QAction(this);			// |---Delete
	this->selectallAct = new QAction(this);			// |---Select All
	this->deselectallAct = new QAction(this);		// |---Deselect All
	
	this->viewMenu = new QMenu(this);				// View
	this->fullscreenAct = new QAction(this);		// |---Full Screen
	this->appearenceAct = new QAction(this);		// |---Appearence
	this->zoominAct = new QAction(this);			// |---Zoom in
	this->zoomoutAct = new QAction(this);			// |---Zoom out
	this->reset_zoomAct = new QAction(this);		// |---Reset Zoom
	this->reset_layoutAct = new QAction(this);		// |---Reset Window Layout

	this->helpMenu = new QMenu(this);				// Help
	this->view_helpAct = new QAction(this);			// |---View Help
	this->getting_startedAct = new QAction(this);	// |---Getting Started
	this->shortcut_refdAct = new QAction(this);		// |---Shortcut Reference
	this->feedbackAct = new QAction(this);			// |---Feedback
	this->release_notesAct = new QAction(this);		// |---Release Notes
	this->open_srcAct = new QAction(this);			// |---About Open-soucre


	//	Window
	resize(this->desk->screenGeometry().size()*.75);
	setWindowIcon(QIcon("window_icon.ico"));


	//	Menu
	//file
	this->fileMenu = menuBar()->addMenu(tr("File")); 

	this->newActGrp = this->fileMenu->addMenu(tr("New"));
	
	this->newActGrp->addAction(this->new_accountAct);
	this->new_accountAct->setText(tr("Account"));
	this->new_accountAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));  // Qt::CTRL | Qt::Key_Plus
	this->new_accountAct->setDisabled(true);//

	this->newActGrp->addAction(this->new_folderAct);
	this->new_folderAct->setText(tr("Folder"));
	this->new_folderAct->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));  // Qt::CTRL | Qt::SHIFT | Qt::Key_Plus
	this->new_folderAct->setDisabled(true);//
	
	this->fileMenu->addAction(this->settingsAct); 
	this->settingsAct->setText(tr("Settings"));
	this->settingsAct->setShortcut(QKeySequence("Ctrl+P")); 
	this->settingsAct->setDisabled(true);//

	this->fileMenu->addAction(this->exitAct); 
	this->exitAct->setText(tr("Exit"));
	this->exitAct->setShortcut(QKeySequence("Ctrl+Q"));
	this->exitAct->setDisabled(true);//

	//help
	this->helpMenu = menuBar()->addMenu(tr("Help"));

	this->helpMenu->addAction(this->view_helpAct);
	this->view_helpAct->setText(tr("View Help"));
	this->view_helpAct->setShortcut(QKeySequence("Ctrl+F1"));
	this->view_helpAct->setDisabled(true);//

	this->helpMenu->addAction(this->getting_startedAct);
	this->getting_startedAct->setText(tr("Getting started"));
	this->getting_startedAct->setDisabled(true);//

	this->helpMenu->addAction(this->shortcut_refdAct);
	this->shortcut_refdAct->setText(tr("Shortut Reference"));
	this->shortcut_refdAct->setDisabled(true);//

	this->helpMenu->addAction(this->feedbackAct);
	this->feedbackAct->setText(tr("FeedBack"));
	this->feedbackAct->setDisabled(true);//

	this->helpMenu->addAction(this->release_notesAct);
	this->release_notesAct->setText(tr("Release Notes"));
	this->release_notesAct->setDisabled(true);//

	this->helpMenu->addAction(this->open_srcAct);
	this->open_srcAct->setText(tr("About Open-soucre"));
	this->open_srcAct->setDisabled(true);//

}

MainWindow::~MainWindow()
{
}

void MainWindow::display(QString p)
{
	this->showMaximized();
}
