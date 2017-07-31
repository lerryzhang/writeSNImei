#include "readthread.h"
#include "rutil.h"
#include <Windows.h>
#include <QMessageBox>
#include<QDebug>  
#include <QVector>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

ReadThread::ReadThread(mainwindow *fmainwindow,QString fport,SETINGINFO *fSetInfo){	
	pmainwindow=fmainwindow;
	stoped=true;
	pSetInfo=fSetInfo;
	pPort=fport;
}



int ReadThread::setComPortTimeout(HANDLE handle,DWORD read_timeout,DWORD write_timeout)
{
	COMMTIMEOUTS timeout;
	timeout.ReadIntervalTimeout=0;
	timeout.ReadTotalTimeoutConstant=read_timeout;
	timeout.ReadTotalTimeoutMultiplier=0;
	timeout.WriteTotalTimeoutConstant=write_timeout;
	timeout.WriteTotalTimeoutMultiplier=0;
	return SetCommTimeouts(handle,&timeout);
}

bool ReadThread::getComParatmers(){
	QString com_port=QString("\\\\.\\%1").arg(pPort);
	QByteArray ba=com_port.toLatin1();
	hCom=CreateFileA(ba.data(),0xC0000000,0,0,OPEN_EXISTING,0,0);
	if(hCom==INVALID_HANDLE_VALUE){
		goto fail_connect;
	}
	DCB dcb;
	bool flag=GetCommState(hCom,&dcb);
	if(!flag){
		goto fail_connect;
	}
	dcb.BaudRate=pSetInfo->baud;
	dcb.ByteSize=8;
	dcb.StopBits=1;
	dcb.fRtsControl=RTS_CONTROL_ENABLE;
	flag=SetCommState(hCom,&dcb);
	if(!flag)
		goto fail_connect;
	flag=setComPortTimeout(hCom,0x388,0x388);
	if(!flag)
		goto fail_connect;
	flag=PurgeComm(hCom,PURGE_TXABORT);
	if(!flag)
		goto fail_connect;
	flag=SetupComm(hCom,0x14000,0x14000);
	if(!flag)
		goto fail_connect;
	return true;
fail_connect:
	DWORD error=GetLastError();
	if(error==170){

	}
	else{

	}
	CloseHandle(hCom);
	return false;

}



ReadThread::ReadThread(){




}
void ReadThread::stop(){
	stoped=false;
	this->terminate();    //ÖÕÖ¹Ïß³Ì  
	this->wait();    //×èÈûµÈ´ý  
	CloseHandle(hCom);
}

BOOL ReadThread::sendData(QString cmd){
	DWORD written_bytes=0;
	QByteArray ba=cmd.toLatin1();
	qDebug()<<"wirte"<<cmd<<"\r\n";

	bool flag=WriteFile(hCom,ba.data(),ba.length(),&written_bytes,NULL);
	if(!flag||written_bytes!=ba.length()){
		return false ;
	}
	return true;
}



int ReadThread::readData(QByteArray &ba){

	if(!hCom)
		return 0;


	DWORD read_bytes=0;
	bool flag=ReadFile(hCom,ba.data(),ba.length(),&read_bytes,NULL);

	if ((!flag))
	{ 
		DWORD dwError = GetLastError();
		return false;
	}

	if(read_bytes==0){
		return false;
	}
	return read_bytes;
}

QString ReadThread::readSNIMEI(QString rcmd,QString re,QString rprefix){

	bool flag=false;
	flag=sendData(rcmd.trimmed()+"\r\n");
	if(!flag) return "";
	QByteArray ba(1024,Qt::Uninitialized);
	RUtil::initArray(ba);
	flag=readData(ba);
	if(!flag) return "";
	QString result=ba.data();
	qDebug()<<"read"<<result<<"\r\n";
	if(result.contains(re)&&result.contains(rprefix)) {
		return RUtil::getValue(result,re,rprefix);
	}else {
	  return "";
	}
}


void ReadThread::run(){
	emit sendLog("OPEN COM",true);
	if(getComParatmers()){
		emit sendResult("read","READING");
		bool flag=true;
		for (int i = 0; i< pSetInfo->vector.size()&&stoped; i++)
		{
			Item item=pSetInfo->vector.at(i);
			if(item.checked){
			emit sendLog("READ "+item.name,true);
			QString value=readSNIMEI(item.rcmd,item.succrep,item.rprefix);
			emit sendValue(item.property,value);

			if(!value.isNull()&&!value.isEmpty()) { 

				emit sendLog("SUCCESS",true);
			
			}
			else {
				flag=false;
				emit sendLog("FAIL",FALSE);
				break;
			}
			}
		}
		if(flag) {
			emit sendResult("read","PASS");
		}
		else {
			emit sendResult("read","FAIL");
		}

	}else {
		emit sendLog("OPEN COM FAIL",false);
		emit sendResult("read","FAIL");
	}
	CloseHandle(hCom);
	emit sendButton();
}


