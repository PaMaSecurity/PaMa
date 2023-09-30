#include "pwidget.hpp"

PLineEdit::PLineEdit(QWidget* parent) : QLineEdit(parent)
{
}

void PLineEdit::focusInEvent(QFocusEvent* e)
{
	QLineEdit::focusInEvent(e);
	emit(focused());
}

PLineEdit:: ~PLineEdit()
{
}

//Settings::Settings(QWidget* parent) : QDialog(parent)
//{
//	setWindowTitle("CoverWindow");
//	setWindowFlag(Qt::WindowMinimizeButtonHint, true);
//}
//
//Settings::~Settings()
//{
//}