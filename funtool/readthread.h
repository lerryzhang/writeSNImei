#pragma once
#include <QtCore/QCoreApplication>  
#include <QThread>
#include "Windows.h"
#include "define_global.h"

class mainwindow;
class ReadThread:public QThread 
{ 
	Q_OBJECT 
public: 
	ReadThread();
	ReadThread(mainwindow *fmainwindow,QString port,SETINGINFO *fSetInfo);	
	void stop();
	void run();
	BOOL sendData(QString cmd);
    int readData(QByteArray &ba);
	QString readSNIMEI(QString cmd,QString re,QString prefix);
	int setComPortTimeout(HANDLE handle,DWORD read_timeout,DWORD write_timeout);
	bool getComParatmers();
	
private:
	mainwindow *pmainwindow;
	bool stoped;
	HANDLE hCom;
	QString pPort;
	SETINGINFO *pSetInfo;
	
signals:  
	void sendLog(QString,bool);
	void sendResult(QString,QString);
	void sendButton();
	void sendValue(QString,QString);
public slots:	
};
