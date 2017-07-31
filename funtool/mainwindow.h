#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QWidget>
#include "ui_mainwindow.h"
#include "define_global.h"
#include <Windows.h>
#include "workthread.h"
#include "readthread.h"

#include  "my_combobox.h"




class mainwindow : public QWidget
{
	Q_OBJECT

public:
	mainwindow(QWidget *parent = 0);
	~mainwindow();
	void reset();

private slots:
	void refreshCom();
    void startWrite();
	void writeSnImei();
	void endWrite();
	void receiveLog(QString text,bool type);
	void receiveResult(QString,QString);
	void receiveButton();
	void showValue(QString type,QString value);


private:
	  Ui::mainwindow ui;
	  SETINGINFO  setINFO;
	  WorkThread *workThread;
	  ReadThread *readThread;
	  char FirstDriveFromMask (ULONG unitmask);


protected:
      bool nativeEvent(const QByteArray & eventType, void * message, long *result);
       
   

};

#endif 
