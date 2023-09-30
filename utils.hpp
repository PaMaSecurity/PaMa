#ifndef PAMA_UTILS_H
#define PAMA_UTILS_H

#include <QFont.h>

class NS12_N : public QFont  //normal 12px
{
public:
	NS12_N();
	QFont get() { return font; };
private:
	QFont font;
};

class NS15_N : public QFont  //normal 15px
{
public:
	NS15_N();
	QFont get() { return font; };
private:
	QFont font;
};

class NS18_N : public QFont  //normal 18px
{
public:
	NS18_N();
	QFont get() { return font; };
private:
	QFont font;
};

class NS20_N : public QFont  //normal 20px
{
public:
	NS20_N();
	QFont get() { return font; };
private:
	QFont font;
};

class NS40_N : public QFont
{
public:
	NS40_N();
	QFont get() { return font; };
private:
	QFont font;
};

#endif