#ifndef PLINEEDIT_H
#define PLINEEDIT_H

#include <QLineEdit.h>

class PLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	PLineEdit(QWidget* parent = nullptr);
	~PLineEdit();

signals:
	void focused();

private:
	void focusInEvent(QFocusEvent* e);
};

#include <QDialog.h>
class Settings : public QDialog  //open() ->https://doc.qt.io/qt-5/qdialog.html#exec
{
public:
	Settings(QWidget* parent = nullptr);
	~Settings();
};
#endif
