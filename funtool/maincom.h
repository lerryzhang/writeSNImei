/*+\New\lerry\2014.7.15\ʹ��QT��̬�⣬QSerialPort.lib�������⣬Ӧ���Ǵ���read�õ����������⣬���д��*/
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
	wchar_t keyname[256]; //��������
	char keyvalue[256];  //��ֵ����
	int indexnum;
	DWORD keysize,type,valuesize;
	HKEY hKey;
};


