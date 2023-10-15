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

PComboBox::PComboBox(QWidget* parent) : QComboBox(parent), arrowAlignment_(Qt::AlignRight), flat_(true)
{
	setFlat(true);
	setAutoFillBackground(true);
	QPalette plt(palette());
	plt.setColor(QPalette::Background, Qt::white);
	setTextAlignment(Qt::AlignmentFlag::AlignLeft);
	setPalette(plt);
	QObject::connect(view(), &QAbstractItemView::pressed, this, &PComboBox::menu_pressed);
	actual_itemView = view();
}

void PComboBox::setView(QAbstractItemView* itemView)
{
	QObject::disconnect(actual_itemView);
	QObject::connect(itemView, &QAbstractItemView::pressed, this, &PComboBox::menu_pressed);
	QComboBox::setView(itemView);
}

void PComboBox::paintEvent(QPaintEvent* e)
{
	if (flat()) {
		QStylePainter painter(this);
		painter.setPen(palette().color(QPalette::Text));
		QStyleOptionComboBox opt;
		initStyleOption(&opt);
		QString displayText(opt.currentText);
		opt.currentText = "";
		painter.drawItemText(rect(), textAlignment_, palette(), true, displayText);
		const QRect rcOld(opt.rect);
		opt.rect = QStyle::alignedRect(Qt::LeftToRight, arrowAlignment(), QSize(16, rcOld.height()), rcOld);
		painter.drawPrimitive(QStyle::PE_IndicatorArrowDown, opt);
		opt.rect = rcOld;
		painter.drawControl(QStyle::CE_ComboBoxLabel, opt);
	}
	else {
		QComboBox::paintEvent(e);
	}
}

void PComboBox::setFlat(bool flat)
{
	flat_ = flat;
}
void PComboBox::setArrowAlignment(Qt::Alignment a)
{
	arrowAlignment_ = a;
}
void PComboBox::setTextAlignment(Qt::Alignment a)
{
	textAlignment_ = a;
}

QVars::QVars()
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