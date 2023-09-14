#ifndef PAMA_PASSWINDOW_H
#define PAMA_PASSWINDOW_H

#include <QMainWindow.h>
#include <QGroupBox.h>
#include <QBoxLayout.h>
#include <QPushButton.h>
#include <QLabel.h>
#include "crypto.hpp"
#include "utils.hpp"
#include <QDebug.h>
#include "pwidget.hpp"

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

private: //variables
	short remaining_tests = 3;
	bool is_error_raised = false;
	QString entryStyle = "background: #FDFDF7; padding-left: 15px; padding-right: 15px; border-radius: 5px;";

private: //methods
	void raise_error(const QString message);

private slots: //slots
	void clear_error();
	void password_forgot();
	void check_password();
};

#endif