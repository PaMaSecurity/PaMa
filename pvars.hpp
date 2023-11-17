#ifndef PVARS_HPP
#define PVARS_HPP

#include <QObject.h>
#include <QDebug.h>

class PVars : public QObject
{
	Q_OBJECT

public:
	PVars(QObject* parent = nullptr);
	~PVars();

	/*inline void setLanguage(Language value) { this->language = value; };
	inline void setTheme(Theme value) { this->theme = value; };

	inline Language getLanguage() { return this->language == Language::DeviceLanguage ? this->deviceLanguage : this->language; };
	Language getDeviceLanguage();
	inline Theme getTheme() { return this->theme == Theme::DeviceTheme ? this->deviceTheme : this->theme; };
	Theme getDeviceTheme();*/

signals:
	void themeChanged();

protected:
	QString language;
	QString deviceLanguage;
	QString theme;
	QString deviceTheme;

private:
	void readfile();
	QMap<int, QString> Language;
	QMap<int, QString> Theme;
};
#endif