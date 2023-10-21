#ifndef PVARS_HPP
#define PVARS_HPP

#include <QObject.h>

class PVars : public QObject
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
	PVars(QObject* parent, Language l, Theme t);
	PVars(QObject* parent = nullptr);
	~PVars();

	inline void setLanguage(Language value) { this->language = value; };
	inline void setTheme(Theme value) { this->theme = value; };

	inline Language getLanguage() { return this->language == Language::DeviceLanguage ? this->deviceLanguage : this->language; };
	Language getDeviceLanguage();
	inline Theme getTheme() { return this->theme == Theme::DeviceTheme ? this->deviceTheme : this->theme; };
	Theme getDeviceTheme();

signals:
	void themeChanged();

private:
	void fillVars();

protected:
	Language language;
	Language deviceLanguage;
	Theme theme;
	Theme deviceTheme;
};
#endif