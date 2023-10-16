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

class QVars : public QObject
{
	Q_OBJECT
public:
	enum Language
	{
		DeviceLanguage = 0,
		English = 1,
		French = 2
	};

	enum Theme
	{
		DeviceTheme = 0,
		Bright = 1,
		Dark = 2,
		Custom = 3
	};

public:
	QVars(Language l, Theme t);
	QVars();
	
	inline void setLanguage(Language value) { this->language = value; };
	inline void setTheme(Theme value) { this->theme = value; };

	inline Language getLanguage() { return this->language == Language::DeviceLanguage ? this->deviceLanguage : this->language; };
	Language getDeviceLanguage();
	inline Theme getTheme() { return this->theme == Theme::DeviceTheme ? this->deviceTheme : this->theme; };
	Theme getDeviceTheme();

signals:
	void themeChanged();

protected:
	Language language;
	Language deviceLanguage;
	Theme theme;
	Theme deviceTheme;

private:
	void fillVars();
};

//#include <QDialog.h>
//class Settings : public QDialog  //open() ->https://doc.qt.io/qt-5/qdialog.html#exec
//{
//public:
//	Settings(QWidget* parent = nullptr);
//	~Settings();
//};
#endif
