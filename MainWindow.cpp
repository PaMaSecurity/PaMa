#include "MainWindow.hpp"

//		ctor & dtor

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	//		Instantiate objects
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
	this->shortcut_refAct = new QAction(this);		// |---Shortcut Reference
	this->feedbackAct = new QAction(this);			// |---Feedback
	this->release_notesAct = new QAction(this);		// |---Release Notes
	this->open_srcAct = new QAction(this);			// |---About Open-soucre


	//		Window
	resize(this->desk->screenGeometry().size()*.75);
	setMinimumSize(QSize(450, 500));
	setWindowIcon(QIcon("images/icon-colour.svg"));
	setWindowTitle("PaMa");
	setAnimated(false);


	//		Menu
	//	file
	this->fileMenu = menuBar()->addMenu(tr("File")); 
	
	this->fileMenu->addAction(this->new_accountAct);
	this->new_accountAct->setText(tr("New Account"));
	this->new_accountAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
	QObject::connect(this->new_accountAct, &QAction::triggered, this, &MainWindow::new_account);

	this->fileMenu->addAction(this->new_folderAct);
	this->new_folderAct->setText(tr("New Folder"));
	this->new_folderAct->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
	QObject::connect(this->new_folderAct, &QAction::triggered, this, &MainWindow::new_folder);
	
	this->fileMenu->addAction(this->settingsAct); 
	this->settingsAct->setText(tr("Settings"));
	this->settingsAct->setShortcut(QKeySequence("Ctrl+P"));
	QObject::connect(this->settingsAct, &QAction::triggered, this, &MainWindow::open_settings);

	this->fileMenu->addAction(this->exitAct); 
	this->exitAct->setText(tr("Exit"));
	this->exitAct->setShortcut(QKeySequence("Ctrl+Q"));
	QObject::connect(this->exitAct, &QAction::triggered, this, &MainWindow::exit);
	
	//	Edit
	this->editMenu = menuBar()->addMenu(tr("Edit"));

	this->editMenu->addAction(this->undoAct);
	this->undoAct->setText(tr("Undo"));  // Enable only if we can undo something
	this->undoAct->setShortcut(QKeySequence("Ctrl+Z"));
	QObject::connect(this->undoAct, &QAction::triggered, this, &MainWindow::undo);

	this->editMenu->addAction(this->redoAct);
	this->redoAct->setText(tr("Redo"));  // Enable only if we can redo something
	this->redoAct->setShortcut(QKeySequence("Ctrl+Shift+Z"));  // Ctrl+Y
	QObject::connect(this->redoAct, &QAction::triggered, this, &MainWindow::redo);

	this->editMenu->addSeparator();

	this->editMenu->addAction(this->cutAct);
	this->cutAct->setText(tr("Cut"));
	this->cutAct->setShortcut(QKeySequence("Ctrl+X"));
	QObject::connect(this->cutAct, &QAction::triggered, this, &MainWindow::cut);

	this->editMenu->addAction(this->copyAct);
	this->copyAct->setText(tr("Copy"));
	this->copyAct->setShortcut(QKeySequence("Ctrl+C"));
	QObject::connect(this->copyAct, &QAction::triggered, this, &MainWindow::copy);

	this->editMenu->addAction(this->pasteAct);
	this->pasteAct->setText(tr("Pase"));
	this->pasteAct->setShortcut(QKeySequence("Ctrl+V"));
	QObject::connect(this->pasteAct, &QAction::triggered, this, &MainWindow::paste);

	this->editMenu->addAction(this->deleteAct);
	this->deleteAct->setText(tr("Delete"));
	this->deleteAct->setShortcut(QKeySequence(Qt::Key_Delete));
	QObject::connect(this->deleteAct, &QAction::triggered, this, &MainWindow::suppr);

	this->editMenu->addSeparator();

	this->editMenu->addAction(this->selectallAct);
	this->selectallAct->setText(tr("Select All"));
	this->selectallAct->setShortcut(QKeySequence("Ctrl+A"));
	QObject::connect(this->selectallAct, &QAction::triggered, this, &MainWindow::selectall);

	this->editMenu->addAction(this->deselectallAct);
	this->deselectallAct->setText(tr("Deselect All"));
	this->deselectallAct->setShortcut(QKeySequence("Ctrl+D"));
	QObject::connect(this->deselectallAct, &QAction::triggered, this, &MainWindow::deselectall);
	
	//	View
	this->viewMenu = menuBar()->addMenu(tr("View"));

	this->viewMenu->addAction(this->fullscreenAct);  // Change its name to "Exit Full Screen"
	this->fullscreenAct->setText(tr("Full Screen"));
	this->fullscreenAct->setShortcut(QKeySequence(Qt::Key_F11));
	QObject::connect(this->fullscreenAct, &QAction::triggered, this, &MainWindow::full_screen);

	this->viewMenu->addSeparator();

	this->viewMenu->addAction(this->zoominAct);
	this->zoominAct->setText(tr("Zoom in"));
	this->zoominAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus));
	QObject::connect(this->zoominAct, &QAction::triggered, this, &MainWindow::zoom_in);

	this->viewMenu->addAction(this->zoomoutAct);
	this->zoomoutAct->setText(tr("Zoom out"));
	this->zoomoutAct->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus));
	QObject::connect(this->zoomoutAct, &QAction::triggered, this, &MainWindow::zoom_out);

	this->viewMenu->addAction(this->reset_zoomAct);
	this->reset_zoomAct->setText(tr("Reset Zoom"));  // Enable only if the zoom changed
	this->reset_zoomAct->setShortcut(QKeySequence("Ctrl+0"));
	QObject::connect(this->reset_zoomAct, &QAction::triggered, this, &MainWindow::reset_zoom);

	this->viewMenu->addSeparator();

	this->viewMenu->addAction(this->appearenceAct);
	this->appearenceAct->setText(tr("Appearence"));  // Open the Settings Window on the Appearence tab.
	QObject::connect(this->appearenceAct, &QAction::triggered, this, &MainWindow::open_settings);

	this->viewMenu->addAction(this->reset_layoutAct);
	this->reset_layoutAct->setText(tr("Reset Layout"));  // Enable only if the layout chanched
	QObject::connect(this->reset_layoutAct, &QAction::triggered, this, &MainWindow::reset_layout);

	//	help
	this->helpMenu = menuBar()->addMenu(tr("Help"));

	this->helpMenu->addAction(this->view_helpAct);
	this->view_helpAct->setText(tr("View Help"));
	this->view_helpAct->setShortcut(QKeySequence("Ctrl+F1"));
	QObject::connect(this->view_helpAct, &QAction::triggered, this, &MainWindow::view_help);

	this->helpMenu->addAction(this->getting_startedAct);
	this->getting_startedAct->setText(tr("Getting started"));
	QObject::connect(this->getting_startedAct, &QAction::triggered, this, &MainWindow::getting_started);

	this->helpMenu->addAction(this->shortcut_refAct);
	this->shortcut_refAct->setText(tr("Shortut Reference"));
	QObject::connect(this->shortcut_refAct, &QAction::triggered, this, &MainWindow::shortcut_reference);

	this->helpMenu->addAction(this->feedbackAct);
	this->feedbackAct->setText(tr("FeedBack"));
	QObject::connect(this->feedbackAct, &QAction::triggered, this, &MainWindow::suppr);

	this->helpMenu->addAction(this->release_notesAct);
	this->release_notesAct->setText(tr("Release Notes"));
	QObject::connect(this->release_notesAct, &QAction::triggered, this, &MainWindow::release_notes);

	this->helpMenu->addAction(this->open_srcAct);
	this->open_srcAct->setText(tr("About Open-soucre"));
	QObject::connect(this->open_srcAct, &QAction::triggered, this, &MainWindow::about_open_src);

}

MainWindow::~MainWindow()
{
}

//		public slots

void MainWindow::display(QString p)
{
	this->showMaximized();
}

//		private slots

//	file
void MainWindow::new_account()
{
	qDebug() << "new account";
}

void MainWindow::new_folder()
{
	qDebug() << "new folder";
}

void MainWindow::open_settings()
{
	qDebug() << "settings";
}

void MainWindow::exit()
{
	qDebug() << "exit";
}

//	Edit
void MainWindow::undo()
{
	qDebug() << "undo";
}

void MainWindow::redo()
{
	qDebug() << "redo";
}

void MainWindow::cut()
{
	qDebug() << "cut";
}

void MainWindow::copy()
{
	qDebug() << "copy";
}

void MainWindow::paste()
{
	qDebug() << "paste";
}

void MainWindow::suppr()
{
	qDebug() << "suppr";
}

void MainWindow::selectall()
{
	qDebug() << "select all";
}

void MainWindow::deselectall()
{
	qDebug() << "deselect all";
}

//	View
void MainWindow::full_screen()
{
	if (isFullScreen())
	{
		showMaximized();
		this->fullscreenAct->setText(tr("Full Screen"));
	}
	else
	{
		this->fullscreenAct->setText(tr("Exit Screen"));
		showFullScreen();
	}
	qDebug() << "full screen";
}

void MainWindow::zoom_in()
{
	qDebug() << "zoom in";
}

void MainWindow::zoom_out()
{
	qDebug() << "zoom out";
}

void MainWindow::reset_zoom()
{
	qDebug() << "reset zoom";
}

void MainWindow::reset_layout()
{
	qDebug() << "reset_layout";
}

//	Help
void MainWindow::view_help()
{
	qDebug() << "view help";
}

void MainWindow::getting_started()
{
	qDebug() << "getting started";
}

void MainWindow::shortcut_reference()
{
	qDebug() << "shortcut reference";
}

void MainWindow::feedback()
{
	qDebug() << "feedback";
}

void MainWindow::release_notes()
{
	qDebug() << "release notes";
}

void MainWindow::about_open_src()
{
	qDebug() << "about open source";
}
