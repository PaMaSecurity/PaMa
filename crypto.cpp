#include "crypto.hpp"

/*
if (prdKey.isEmpty())
{
	LPCSTR path = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SoftwareProtectionPlatform";
		
	LPCSTR key = "BackupProductKeyDefault";

	HKEY hKey;
	LONG result;

	// Ouvrir la clé du registre contenant la clé de produit Windows
	result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, path, 0, KEY_READ, &hKey);

	if (result == ERROR_SUCCESS) {
		char productKey[255] = "";
		DWORD bufferSize = sizeof(productKey);

		// Lire la valeur de la clé de produit Windows
		result = RegGetValueA(hKey, nullptr, key, RRF_RT_ANY, nullptr, productKey, &bufferSize);

		if (result == ERROR_SUCCESS) {
			prdKey = productKey;
		}
		else {
			QMessageBox err;
			err.setWindowTitle("Critical Error !");
			err.setIcon(QMessageBox::Critical);
			err.setText("Erreur lors de la lecture de la clé de produit Windows");
			err.exec();
			exit(1);
		}

		// Fermer la clé du registre
		RegCloseKey(hKey);
	}
	else {
		QMessageBox err;
		err.setWindowTitle("Critical Error !");
		err.setIcon(QMessageBox::Critical);
		err.setText("Impossible d'ouvrir la clé de registre");
		err.exec();
	}
}
*/