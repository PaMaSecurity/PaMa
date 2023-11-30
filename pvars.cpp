#include "pvars.hpp"

PVars::PVars(QObject* parent) : QObject(parent)
{
	this->readfile();
}

PVars::~PVars()
{

}

//PVars::Language PVars::getDeviceLanguage()
//{
//	return this->deviceLanguage;
//}
//
//PVars::Theme PVars::getDeviceTheme()
//{
//	return this->deviceTheme;
//}

void PVars::readfile()
{
}