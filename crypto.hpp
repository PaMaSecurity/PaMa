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
	(SOFTWARE\\Microsoft\\Cryptography\\RNG -> Seed)
	Administrator permissions are required

ProductKey 
	(SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SoftwareProtectionPlatform -> BackupProductKeyDefault)
	Administrator permissions aren't required
*/

//class Pcry
//{
//public:
//	Pcry() = default;
//	Pcry(QString text);
//	void setText();
//	QString encrypt();
//	QString decrypt();
//	void operator=(QString text);
//
//private: // methods
//	QString getPrdKey();
//
//private: // vars
//	QString prdKey;
//};

#endif