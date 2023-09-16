#ifndef PAMA_CRYPTO_H
#define PAMA_CRYPTO_H

#include <QCryptographicHash.h>
#include <Windows.h>
#include <QMessageBox.h>

/*
1°: Windows Password Hash
	We need to ask the user the old password when he changes it.
	It's inaccessible.
2°: Mac address
	Which one do we choose wifi or ethernet or... ?
	And if the PC doesn't have a network card, what do we do ?
3°: Windows PRNG Seed
	Administator permission is required
ProductKey
*/

namespace pcry
{

	QString encrypt(QString file);

	QString decrypt(QString file);

	QString getPrdKey();
	
	//Windows ProductKey
	static QString prdKey = "";
};

#endif