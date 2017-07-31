#include "mainwindow.h"
#include "maincom.h"
#include <Windows.h>
#include <QWidget> 
#include <QDebug>
#include <QComboBox>
#include "my_combobox.h"
#include "rutil.h"
#include "workthread.h"
#include <Windows.h>
#include <dbt.h>


mainwindow::mainwindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	workThread=NULL;
	readThread=NULL;
	maincom maincom;
	ui.combox->addItems(maincom.initCom()); 
	ui.textEdit->setAlignment(Qt::AlignLeft);
	ui.label_4->setAlignment(Qt::AlignCenter);
	QString path=QCoreApplication::applicationDirPath()+"/cfg/config.xml";
	if(!RUtil::isExist(path)) return;
	setINFO=RUtil::readSettings(path);
	QString title=QString("%1%2").arg(setINFO.pname).arg(QStringLiteral("写号工具V1.6"));
	this->setWindowTitle(title);
	ui.label_9->setText(QString::number(setINFO.baud));
	ui.label_12->setText(QString::number(setINFO.vector[1].len));
	ui.label_3->setText(QString::number(setINFO.vector[0].len));
	ui.label_14->setText(RUtil::boolConvertString(setINFO.vector[1].vald));
	ui.label_17->setText(RUtil::boolConvertString(setINFO.vector[0].vald));
	QRegExp regx("^[0-9]{15}$");
	QValidator *validator = new QRegExpValidator(regx, ui.imeitext);
    ui.imeitext->setValidator(validator);
	//QRegExp regx1("^[0-9]{"+QString::number(setINFO.vector[1].len)+"}$");
	QRegExp regx1("^[A-Za-z0-9]{"+QString::number(setINFO.vector[1].len)+"}$");
	validator = new QRegExpValidator(regx1, ui.sntext);
	ui.sntext->setValidator(validator);
	ui.imeitext->setFocus();
	connect(ui.combox, SIGNAL(clicked()), this, SLOT(refreshCom()));
	connect(ui.toolButton, SIGNAL(clicked()), this, SLOT(startWrite()));
	connect(ui.toolButton_2, SIGNAL(clicked()), this, SLOT(endWrite()));
	connect(ui.toolButton_4, SIGNAL(clicked()), this, SLOT(writeSnImei()));
}

mainwindow::~mainwindow()
{
	if(workThread!=NULL) {
		workThread->stop();
		delete workThread;
		workThread=NULL;
	}

	if(readThread!=NULL) {
		readThread->stop();
		delete readThread;
		readThread=NULL;
	}
}



void mainwindow::refreshCom(){
	ui.combox->clear();
	maincom maincom;
	qDebug()<<maincom.initCom().size();
	ui.combox->addItems(maincom.initCom()); 

}

void mainwindow::reset(){
	ui.textEdit->clear();
	QPalette pa;
	pa.setColor(QPalette::WindowText,Qt::black);
	ui.label_4->setPalette(pa);
	ui.label_4->setText(QStringLiteral("未启动"));
	ui.imeitext->setEnabled(true);
	ui.sntext->setEnabled(true);

}

void mainwindow::startWrite(){
	QString imei=ui.imeitext->text();
	QString sn=ui.sntext->text();
	reset();
	if(setINFO.vector[0].vald=="TRUE"&&ui.imeicheck->isChecked()){
		if(!RUtil::getIMEICheckDigit(imei)){
			ui.textEdit->insertPlainText(QString::fromLocal8Bit("非法的IMEI\r\n"));	
			return;
		} 
	}
	if(setINFO.vector[1].vald=="TRUE"&&ui.sncheck->isChecked()){
		if(sn.length()!=setINFO.vector[1].len){
		ui.textEdit->insertPlainText(QString::fromLocal8Bit("非法的SN\r\n"));	
			return;
		}
	}
	setINFO.vector[0].value=imei;
	setINFO.vector[0].checked=ui.imeicheck->isChecked();
	setINFO.vector[1].value='"'+sn+'"';
	setINFO.vector[1].checked=ui.sncheck->isChecked();

	ui.toolButton->setEnabled(false);
	ui.combox->setEnabled(false);	
	ui.imeitext->setEnabled(false);
	ui.sntext->setEnabled(false);
	ui.toolButton_4->setEnabled(false);
	workThread=new WorkThread(this,ui.combox->currentText(),&setINFO);
	connect(workThread,SIGNAL(sendLog(QString,bool)),this,SLOT(receiveLog(QString,bool)));
	connect(workThread,SIGNAL(sendResult(QString,QString)),this,SLOT(receiveResult(QString,QString)));
	connect(workThread,SIGNAL(sendButton()),this,SLOT(receiveButton()));
	workThread->start();
}
void mainwindow::endWrite(){
	ui.toolButton->setEnabled(true);
	ui.toolButton_2->setEnabled(true);
	ui.toolButton_4->setEnabled(true);
    ui.combox->setEnabled(true);
	reset();
	ui.imeitext->setFocus();
	if(workThread!=NULL) {
	workThread->stop();
	delete workThread;
	workThread=NULL;
	}
	if(readThread!=NULL) {
	readThread->stop();
	delete readThread;
	readThread=NULL;
	}
}

void mainwindow::receiveLog(QString text,bool type){
	if(!type){
		ui.textEdit->insertHtml("<span style='color:RED;'>"+text+"</span>");
		ui.textEdit->insertPlainText("\r\n");
	}else {
		//ui.textEdit->insertPlainText(text+"\r\n");
		ui.textEdit->insertHtml("<span style='color:YELLOW;'>"+text+"</span>");
		ui.textEdit->insertPlainText("\r\n");
	}
}
void mainwindow::receiveResult(QString type,QString s){
	QPalette pa;
	if(s.contains("PASS")){

		pa.setColor(QPalette::WindowText,Qt::green);

		if("write"==type){

		ui.sntext->clear();
		ui.imeitext->clear();
		}
		ui.sntext->setEnabled(true);
		ui.imeitext->setEnabled(true);
		
	    ui.imeitext->setFocus();
	}else if(s.contains("FAIL")){

		pa.setColor(QPalette::WindowText,Qt::red);
		ui.sntext->setEnabled(true);
		ui.imeitext->setEnabled(true);
	    ui.imeitext->setFocus();
	}else {

		pa.setColor(QPalette::WindowText,Qt::black);
	}
	ui.label_4->setPalette(pa);
	ui.label_4->setText(s);
	
}

void mainwindow::receiveButton(){
	ui.toolButton->setEnabled(true);
	ui.toolButton_4->setEnabled(true);
	ui.toolButton_2->setEnabled(true);
	ui.combox->setEnabled(true);
	ui.imeitext->setFocus();
}

void mainwindow::writeSnImei(){
	reset();
	ui.sntext->clear();
	ui.imeitext->clear();
	ui.toolButton_4->setEnabled(false);
	ui.toolButton_2->setEnabled(false);
	ui.toolButton->setEnabled(false);
	setINFO.vector[0].checked=ui.imeicheck->isChecked();
	setINFO.vector[1].checked=ui.sncheck->isChecked();
	readThread=new  ReadThread(this,ui.combox->currentText(),&setINFO);
	connect(readThread,SIGNAL(sendLog(QString,bool)),this,SLOT(receiveLog(QString,bool)));
	connect(readThread,SIGNAL(sendResult(QString,QString)),this,SLOT(receiveResult(QString,QString)));
	connect(readThread,SIGNAL(sendButton()),this,SLOT(receiveButton()));
	connect(readThread,SIGNAL(sendValue(QString,QString)),this,SLOT(showValue(QString,QString)));
	readThread->start();

}
void mainwindow::showValue(QString type,QString value){
	if(type=="RImei"){
	
		ui.imeitext->setText(value);
	}else if(type=="RSN"){
	
		ui.sntext->setText(value);
	}

}
bool mainwindow::nativeEvent(const QByteArray & eventType, void * message, long*result)
{
  
	 const MSG *msg=static_cast<MSG*>(message);  
    int msgType = msg->message;
    if(msgType==WM_DEVICECHANGE)
    {
        PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)msg->lParam;
        switch (msg->wParam) {
        case DBT_DEVICEARRIVAL:
 
            if(lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
            {
                PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;
                if(lpdbv->dbcv_flags ==0)
                {
                    QString USBDisk = QString(this->FirstDriveFromMask(lpdbv ->dbcv_unitmask));
                    qDebug() << "USB_Arrived and The USBDisk is: "<<USBDisk ;
                    
                }
            }
            break;
        case DBT_DEVICEREMOVECOMPLETE:
            if(lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
            {
                PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;
                if(lpdbv->dbcv_flags == 0)
                {
                    qDebug() << "USB_Removed";
                    
                }
            }
            break;
        }
    }
    return false;
}

char mainwindow::FirstDriveFromMask (ULONG unitmask)
{
    char i;
    for (i = 0; i < 26; ++i)
    {
        if (unitmask & 0x1)
            break;
        unitmask = unitmask >> 1;
    }
    return (i + 'A');
}