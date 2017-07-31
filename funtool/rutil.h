#ifndef RUTIL_H
#define RUTIL_H
#include <QString>
#include "define_global.h"
#include <windows.h>


class  RUtil
{
public:
    RUtil();
	static SETINGINFO readSettings(QString path);
	static bool isExist(QString path);
	static bool getIMEICheckDigit(QString imei);  
	static QString boolConvertString(QString flag);  
	static void  initArray(QByteArray &ba);
    static bool  saveData(QString imei);
	static QString getValue(QString result,QString re,QString prefix);

};
#endif // RUTIL_H