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
	QFrame* settingsFrame;
	PComboBox* languageCB;
	QListView* listView;
	QPushButton* themeBtn;

private: //variables
	QList<QString> LanguagesList = { "English", "Français" };  // map or hashmap | qmap ...
	QString lang = "Français";
	QString theme = "bright";
	short remaining_tests = 3;
	bool is_error_raised = false;
	QString black = "#0A0905";
	QString bright_dark = "#262625";
	QString white = "#FCFCFA";
	QString entryStyle_base = "background-color: %0; color: %1; padding-left: 15px; padding-right: 15px; border-radius: 5px;";  //can the user create a new property in qss ? ::error who can be manage with a bool
	QString entryStyle;

private: //methods
	void clear_focus();
	void raise_error(const QString message);
	void apply_style();

private slots: //slots
	void mousePressEvent(QMouseEvent* e);
	void clear_error();
	void password_forgot();
	void check_password();
	void language_changed(const QModelIndex& i);
	void change_theme();
};

#endif