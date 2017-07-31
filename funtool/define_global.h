#ifndef DEFINE_GLOBAL_H
#define DEFINE_GLOBAL_H
#include <QString>
#include <QVector>

typedef struct
{
    QString name;
	QString property;
	QString cmd;
	QString rcmd;
	QString prefix;
	QString rprefix;
	QString succrep;
	int len;
	QString vald;
	QString value;
	bool checked;


}Item;


typedef struct
{
   
	int baud;
	QString pname;
	QVector<Item> vector ;
}SETINGINFO;

















#endif
