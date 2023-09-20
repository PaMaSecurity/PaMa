#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	//	Instantiate objects
	this->desk = QApplication::desktop();

	this->fileMenu = new QMenu(this);				// File
	this->new_accountAct = new QAction(this);		// |---New Account
	this->new_folderAct = new QAction(this);		// |---New Folder
	this->settingsAct = new QAction(this);			// |---Settings
	this->exitAct = new QAction(this);				// |---Exit

	this->editMenu = new QMenu(this);				// Edit
	this->undoAct = new QAction(this);				// |---Undo
	this->redoAct = new QAction(this);				// |---Redo
	this->cutAct = new QAction(this);				// |---Cut
	this->copyAct = new QAction(this);				// |---Copy
	this->pasteAct = new QAction(this);				// |---Paste
	this->deleteAct = new QAction(this);			// |---Delete
	this->selectallAct = new QAction(this);			// |---Select All
	this->deselectallAct = new QAction(this);		// |---Deselect All
	
	this->viewMenu = new QMenu(this);				// View
	this->fullscreenAct = new QAction(this);		// |---Full Screen
	this->zoominAct = new QAction(this);			// |---Zoom in
	this->zoomoutAct = new QAction(this);			// |---Zoom out
	this->reset_zoomAct = new QAction(this);		// |---Reset Zoom
	this->appearenceAct = new QAction(this);		// |---Appearence (to settings)
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
	
	this->fileMenu->addAction(this->new_accountAct);
	this->new_accountAct->setText(tr("New Account"));
	this->new_accountAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));  // Qt::CTRL | Qt::Key_Plus
	this->new_accountAct->setDisabled(true);//

	this->fileMenu->addAction(this->new_folderAct);
	this->new_folderAct->setText(tr("New Folder"));
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
	
	//Edit
	this->editMenu = menuBar()->addMenu(tr("Edit"));

	this->editMenu->addAction(this->undoAct);
	this->undoAct->setText(tr("Undo"));  // Enable only if we can undo something
	this->undoAct->setShortcut(QKeySequence("Ctrl+Z"));
	this->undoAct->setDisabled(true);//

	this->editMenu->addAction(this->redoAct);
	this->redoAct->setText(tr("Redo"));  // Enable only if we can redo something
	this->redoAct->setShortcut(QKeySequence("Ctrl+Shift+Z"));  // Ctrl+Y
	this->redoAct->setDisabled(true);//

	this->editMenu->addSeparator();

	this->editMenu->addAction(this->cutAct);
	this->cutAct->setText(tr("Cut"));
	this->cutAct->setShortcut(QKeySequence("Ctrl+X"));
	this->cutAct->setDisabled(true);//

	this->editMenu->addAction(this->copyAct);
	this->copyAct->setText(tr("Copy"));
	this->copyAct->setShortcut(QKeySequence("Ctrl+C"));
	this->copyAct->setDisabled(true);//

	this->editMenu->addAction(this->pasteAct);
	this->pasteAct->setText(tr("Pase"));
	this->pasteAct->setShortcut(QKeySequence("Ctrl+V"));
	this->pasteAct->setDisabled(true);//

	this->editMenu->addAction(this->deleteAct);
	this->deleteAct->setText(tr("Delete"));
	this->deleteAct->setShortcut(QKeySequence(Qt::Key_Delete));
	this->deleteAct->setDisabled(true);//

	this->editMenu->addSeparator();

	this->editMenu->addAction(this->selectallAct);
	this->selectallAct->setText(tr("Select All"));
	this->selectallAct->setShortcut(QKeySequence("Ctrl+A"));
	this->selectallAct->setDisabled(true);//

	this->editMenu->addAction(this->deselectallAct);
	this->deselectallAct->setText(tr("Deselect All"));
	this->deselectallAct->setShortcut(QKeySequence("Ctrl+D"));
	this->deselectallAct->setDisabled(true);//
	
	//View
	this->viewMenu = menuBar()->addMenu(tr("View"));

	this->viewMenu->addAction(this->fullscreenAct);  // Change its name to "Exit Full Screen"
	this->fullscreenAct->setText(tr("Full Screen"));
	this->fullscreenAct->setShortcut(QKeySequence(Qt::Key_F11));
	this->fullscreenAct->setDisabled(true);//

	this->viewMenu->addSeparator();

	this->viewMenu->addAction(this->zoominAct);
	this->zoominAct->setText(tr("Zoom in"));
	this->zoominAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus));
	this->zoominAct->setDisabled(true);//

	this->viewMenu->addAction(this->zoomoutAct);
	this->zoomoutAct->setText(tr("Zoom out"));
	this->zoomoutAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus));
	this->zoomoutAct->setDisabled(true);//

	this->viewMenu->addAction(this->reset_zoomAct);
	this->reset_zoomAct->setText(tr("Reset Zoom"));  // Enable only if the zoom changed
	this->reset_zoomAct->setShortcut(QKeySequence("Ctrl+0"));
	this->reset_zoomAct->setDisabled(true);//

	this->viewMenu->addSeparator();

	this->viewMenu->addAction(this->appearenceAct);
	this->appearenceAct->setText(tr("Appearence"));  // Open the Settings Window on the Appearence tab.
	this->appearenceAct->setDisabled(true);//

	this->viewMenu->addAction(this->reset_layoutAct);
	this->reset_layoutAct->setText(tr("Reset Layout"));  // Enable only if the layout chanched
	this->reset_layoutAct->setDisabled(true);//

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
