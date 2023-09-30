#ifndef PAMA_PASSWINDOW_H
#define PAMA_PASSWINDOW_H

#include <QMainWindow.h>
#include <QGroupBox.h>
#include <QBoxLayout.h>
#include <QPushButton.h>
#include <QLabel.h>
#include <QCombobox.h>
#include <QListView.h>
#include "crypto.hpp"
#include "utils.hpp"
#include "pwidget.hpp"

#include <QDebug.h>

class PassWindow : public QMainWindow
{
	Q_OBJECT
public: //ctor dtor
	PassWindow(QWidget* parent = nullptr);
	~PassWindow();

signals:
	void password_validated(const QString password);

private: //objects
	QVBoxLayout* vlayout;
	QVBoxLayout* entriesLayout;
	QWidget* mainWidget;
	QLabel* titleLabel;
	QGroupBox* entriesBox;
	QLabel* emailLabel;
	PLineEdit* emailEntry;
	QHBoxLayout* passwordLayout;
	QLabel* passwordLabel;
	QPushButton* forgotButton;
	PLineEdit* passwordEntry;
	QPushButton* loginButton;
	QLabel* errorLabel;
	QHBoxLayout* settingsLayout;
	QComboBox* languageCB;
	//QPushButton* themeBtn;
	//QComboBox* themeCB;

private: //variables
	QList<QString> LanguagesList = { "English", "Français" };  // map or hashmap | qmap ...
	QString lang = "Français";
	short remaining_tests = 3;
	bool is_error_raised = false;
	QString entryStyle = "selection-background-color: #486ED9; background: #FCFCFA; padding-left: 15px; padding-right: 15px; border-radius: 5px;";

private: //methods
	void clear_focus();
	void raise_error(const QString message);

private slots: //slots
	void mousePressEvent(QMouseEvent* e);
	void clear_error();
	void password_forgot();
	void check_password();
	void language_changed();
};

#endif