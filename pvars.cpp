#include "pvars.hpp"

PVars::PVars(QObject* parent = nullptr) : QObject(parent)
{
	this->readfile();
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

void PVars::readfile()
{
}