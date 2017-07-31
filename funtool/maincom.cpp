
/*+\New\lerry\2014.7.15\ʹ��QT��̬�⣬QSerialPort.lib�������⣬Ӧ���Ǵ���read�õ����������⣬���д��*/
#include "maincom.h"
#include <QDebug>

QStringList maincom ::initCom()
{
	QString path="HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM";
    QSettings *settings=new QSettings(path,QSettings::NativeFormat);
    QStringList key=settings->allKeys();
    QStringList comlist ;
    comlist.clear();
    for( int i=0;i< key.size();i++)
    {
		comlist << getcomm(i,"value");
    }
	 return comlist;
}
QString maincom::getcomm(int index,QString keyorvalue)
{
    QString commresult="";
    QString strkey="HARDWARE\\DEVICEMAP\\SERIALCOMM";//�Ӽ�·��
    int a=strkey.toWCharArray(subkey);
    subkey[a]=L'\0';
    if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ|KEY_QUERY_VALUE,&hKey)!=0)
    {
        QString error="Cannot open regedit!";
    }
 
    QString keymessage="";//����
    QString message="";
    QString valuemessage="";//��ֵ
    indexnum=index;//Ҫ��ȡ��ֵ��������
 
    keysize=sizeof(keyname);
    valuesize=sizeof(keyvalue);
 
    if(::RegEnumValue(hKey,indexnum,keyname,&keysize,0,&type,(BYTE*)keyvalue,&valuesize)==0)
    {
        //��ȡ����
        for(int i=0;i<keysize;i++)
        {
            message=QString::fromStdWString(keyname);
            keymessage.append(message);
        }
        //��ȡ��ֵ
        for(int j=0;j<valuesize;j++)
        {
            if(keyvalue[j]!=0x00)
            {
                valuemessage.append(keyvalue[j]);
            }
        }
 
        if(keyorvalue=="key")
        {
            commresult=keymessage;
        }
        if(keyorvalue=="value")
        {
            commresult=valuemessage;
        }
    }
    else
    {
        commresult="nokey";
    }
    ::RegCloseKey(hKey);//�ر�ע���
    return commresult;
}