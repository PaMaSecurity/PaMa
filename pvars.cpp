#include "pvars.hpp"

PVars::PVars(QObject* parent, Language l, Theme t) : QObject(parent), language(l), theme(t)
{
	this->fillVars();
}

PVars::PVars(QObject* parent = nullptr) : QObject(parent)
{
	this->fillVars();
}

PVars::~PVars()
{
	qDebug() << "not here anymore !";
}

PVars::Language PVars::getDeviceLanguage()
{
	return this->deviceLanguage;
}

PVars::Theme PVars::getDeviceTheme()
{
	return this->deviceTheme;
}

void PVars::fillVars()
{
	this->language = PVars::Language::English;
	this->deviceLanguage = PVars::Language::English;
	this->theme = PVars::Theme::Bright;
	this->deviceTheme = PVars::Theme::Bright;
}