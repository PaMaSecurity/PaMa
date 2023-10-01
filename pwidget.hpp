#ifndef PLINEEDIT_H
#define PLINEEDIT_H

#include <QLineEdit.h>
#include <QComboBox.h>
#include <QStylePainter>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPalette>
#include <QDebug.h>
#include <QListView.h>

class PLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	PLineEdit(QWidget* parent = nullptr);
	~PLineEdit();

signals:
	void focused();

protected:
	virtual void focusInEvent(QFocusEvent* e);
};

class PComboBox : public QComboBox  // http://engineer-works.blogspot.com/2010/02/flat-qcombobox.html
{
	Q_OBJECT
public:
	PComboBox(QWidget* parent = nullptr);
	bool flat() const { return flat_; }
	void setFlat(bool flat);

	Qt::Alignment arrowAlignment() const { return arrowAlignment_; }
	void setArrowAlignment(Qt::Alignment a);

	void setView(QAbstractItemView* itemView);

protected:
	virtual void paintEvent(QPaintEvent* e);

signals:
	void menuClicked();

private:
	bool connected;
	bool flat_;
	Qt::Alignment arrowAlignment_;
	QAbstractItemView* itemView;
	void menu_pressed();
};

//#include <QDialog.h>
//class Settings : public QDialog  //open() ->https://doc.qt.io/qt-5/qdialog.html#exec
//{
//public:
//	Settings(QWidget* parent = nullptr);
//	~Settings();
//};
#endif
