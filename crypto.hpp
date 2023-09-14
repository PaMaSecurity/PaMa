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

ProductKey
Windows PRNG Seed
*/

namespace pcry
{

	QString encrypt(QString file);

	QString decrypt(QString file);

	QString getWinSeed();

	QString getPrdKey();

	//Windows PRNG Seed
	static QString winseed = "52756E6E696E672100D00700A5321BAFCB32B9DF75FBF31A2547B215B1D78B89381D9DBFE306D9D43162B77F83CE24F06CED2A1B2034C60D7904040855812820D98EE32754B7881C8BDBDCFD";
	
	//Windows ProductKey
	static QString prdKey = "";
};

#endif