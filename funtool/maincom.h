/*+\New\lerry\2014.7.15\使用QT静态库，QSerialPort.lib编译问题，应该是串口read用的类库兼容问题，后改写了*/
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QtXml>  
#include "windows.h"
class maincom
{
public:
	
	QString getcomm(int index,QString keyorvalue);
	QStringList initCom();
	wchar_t subkey[80];
	wchar_t keyname[256]; //键名数组
	char keyvalue[256];  //键值数组
	int indexnum;
	DWORD keysize,type,valuesize;
	HKEY hKey;
};


