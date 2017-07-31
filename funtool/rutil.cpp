#include "rutil.h"
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QtXml>
#include <QXmlStreamReader> 
#include <QSqlDatabase>
#include <QSqlQuery>
RUtil::RUtil()
{
}

SETINGINFO RUtil::readSettings(QString path)
{
	SETINGINFO  setINFO;
	QVector<Item> vector;


	QDomElement	 head;
	QDomNode     node;
	QString      strCfgDir;
	QString      strTmp;
	QString fileName;
	QFile file(path);

	QDomDocument    document;  
	QString         strError;  
	int             errLin = 0, errCol = 0;

	if( !file.open(QFile::ReadOnly | QFile::Text) ) {  

		return setINFO;  
	} 
	if( !document.setContent(&file, false, &strError, &errLin, &errCol) ) 
	{  

		return setINFO;  
	}  
	if( document.isNull() ) 
	{  

		return setINFO;  
	}  
	head = document.documentElement();
	if(head.toElement().tagName()=="project")
   {
	   setINFO.pname=head.toElement().attribute("name").trimmed(); 
	}
	node = head.firstChild();
	while(!node.isNull())
	{   


		if((node.toElement().tagName().trimmed() == "baud"))
		{
			for(int i = 0; i < node.childNodes().count(); i++)
			{   
				QDomNode childNode = node.childNodes().at(i);

				if(!childNode.isNull() && childNode.toElement().tagName() == "value")
				{			
					setINFO.baud=childNode.firstChild().toText().data().trimmed().toInt();


				}	
			}
		}
		if(node.toElement().tagName() == "item")
		{ 
			Item  item ;
			item.name=node.toElement().attribute("name");
			item.property=node.toElement().attribute("property");
			for(int i = 0; i < node.childNodes().count(); i++)
			{   
				QDomNode childNode = node.childNodes().at(i);

				if(!childNode.isNull() && childNode.toElement().tagName() == "cmd")
				{	
					item.cmd=childNode.firstChild().toText().data().trimmed();		
				}
				if(!childNode.isNull() && childNode.toElement().tagName() == "rcmd")
				{	
					item.rcmd=childNode.firstChild().toText().data().trimmed();		
				}
				else if(!childNode.isNull() && childNode.toElement().tagName() == "rprefix")
				{								
					item.rprefix=childNode.firstChild().toText().data().trimmed();
				}
				else if(!childNode.isNull() && childNode.toElement().tagName() == "prefix")
				{								
					item.prefix=childNode.firstChild().toText().data().trimmed();
				}

				else if(!childNode.isNull() && childNode.toElement().tagName() == "len")
				{								
					item.len = childNode.firstChild().toText().data().trimmed().toInt();

				}else if(!childNode.isNull() && childNode.toElement().tagName() == "vald")
				{								
					item.vald = childNode.firstChild().toText().data().trimmed().toUpper();
				}
				else if(!childNode.isNull() && childNode.toElement().tagName() == "succrep")
				{								
					item.succrep = childNode.firstChild().toText().data().trimmed();
				}
			}	
			vector.push_back(item);
		}	
		node = node.nextSibling();
	}
	setINFO.vector=vector;
	return setINFO;
}
bool RUtil::isExist(QString path){
	QFile file(path);
	bool flag=false;
	if (file.exists()) flag=true;
	return flag;
}
bool RUtil::getIMEICheckDigit(QString imei){
	int len=imei.length();
	if(len!=15) return false;
	int sum1=0;
	int temp=0;
	int sum2=0;
	int total=0;
	QByteArray ba=imei.toLatin1();
	for(int i=0;i<ba.size()-1;i++){

		if((i%2)==0)  
		{  
			sum1 = sum1 + (int)ba.at(i)-'0';  
		} else  
		{  
			temp = ((int)ba.at(i)-'0')*2;  
			if( temp < 10 )  
			{  
				sum2 = sum2 + temp;  
			}  
			else  
			{  
				sum2 = sum2 + 1 + temp - 10;  
			}  
		}  

	}

	total = sum1 + sum2;
	if(total%10 != 0)
	{
		total = 10 - total%10;
	}
	else
	{
		total = 0; 
	}

	if((int)ba.at(14)-'0' == total)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}



}
QString RUtil::boolConvertString(QString flag){

	QString str=QString::fromLocal8Bit("ÊÇ");
	if(!flag.contains("TRUE")) str=QString::fromLocal8Bit("·ñ");
	return str;
}



QString RUtil::getValue(QString result,QString re,QString prefix){
	if(!prefix.isNull()&&!prefix.isEmpty()){
		int start=result.indexOf(prefix)+prefix.length()+1;
		int end=result.indexOf(re);					
		return result.mid(start,end-start).trimmed();
	}else{
		QStringList list=result.split("\r\n");
		QString s;
		for (int j = 0; j< list.size(); ++j){
			if (list.at(j).contains(re)&&list.size()>2){
				s=list.at(j-2);
				break;
				
			}else 
			{
				s="";    
			}
		}

		return s;
	}
}


void RUtil::initArray(QByteArray &ba){
	for(int i=0;i<ba.length();i++){
		ba[i]='\0';

	}
}



bool RUtil::saveData(QString imei){
	QSqlDatabase db;
	QString dbaddress;
	QString dbname;
	QString flag;
	QString dsn;
	QUuid uuid ; 
	int localsql;
	int remosql;
	if(QSqlDatabase::contains("dbtemp")){
		db = QSqlDatabase::database("dbtemp");
	}
	else{
		db = QSqlDatabase::addDatabase("QODBC", "dbtemp");
	} 
	dsn="DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=data.mdb;UID=;PWD=atwin-188";
	db.setDatabaseName(dsn);
	if(db.open())
	{	
		QSqlQuery mquery=QSqlQuery::QSqlQuery(db);
		mquery.prepare("insert into imei(imei,ptime) values (:imei,:ptime)");
		mquery.bindValue(":imei",imei);
		mquery.bindValue(":ptime",QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		if(!mquery.exec()) return false;
		mquery.clear();
		db.close();
	}else {
		return false;
	}

	return true;
}