#include "mainwindow.h"

#include "mainlog.h"
#include <QtWidgets/QApplication>
#include <QTextStream>
#include <QTextCodec>
#include <QSqlDatabase> 
#include <QtPlugin>  
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin) 


	
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qInstallMessageHandler(Log);
	qRegisterMetaType<QVector<int>>("QVector<int>");
	mainwindow m;
	m.show();
	return a.exec();
	

}
