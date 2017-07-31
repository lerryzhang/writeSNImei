#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <qdatetime.h>
#include <mainlog.h>
#include <QtWidgets/QApplication>
void Log(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QString text;
	switch(type) 
	{
	case QtDebugMsg:
		text = QString("");
		break;

	case QtCriticalMsg:
		text = QString("Critical:");
		break;

	case QtFatalMsg:
		text = QString("Fatal:");
		break;
	}
	QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString message = text.append(current_date).append(":").append(msg).append("");
	QFile file(QCoreApplication::applicationDirPath()+ "/log.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream<<message<<"\r\n";
	file.close();
}
