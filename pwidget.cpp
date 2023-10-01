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
	setPalette(plt);
	QObject::connect(view(), &QAbstractItemView::pressed, this, &PComboBox::menu_pressed);
	connected = true;
}

void PComboBox::menu_pressed()
{
	emit menuClicked();
}

void PComboBox::setView(QAbstractItemView* itemView)
{
	if (connected)
	{
		QObject::disconnect();
	}
	QObject::connect(itemView, &QAbstractItemView::pressed, this, [=] { emit menuClicked(); });
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
		painter.drawItemText(rect(), Qt::AlignCenter, palette(), true, displayText);
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

//Settings::Settings(QWidget* parent) : QDialog(parent)
//{
//	setWindowTitle("CoverWindow");
//	setWindowFlag(Qt::WindowMinimizeButtonHint, true);
//}
//
//Settings::~Settings()
//{
//}