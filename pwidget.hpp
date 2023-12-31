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
	void setTextAlignment(Qt::Alignment a);

	void setView(QAbstractItemView* itemView);

protected:
	virtual void paintEvent(QPaintEvent* e);

signals:
	void menuClicked(const QModelIndex& i);

private:
	inline void menu_pressed(const QModelIndex& i) { emit menuClicked(i); };
	bool connected;
	bool flat_;
	Qt::Alignment arrowAlignment_;
	Qt::Alignment textAlignment_;
	QAbstractItemView* actual_itemView;
};
#endif
