#ifndef MY_COMBOBOX_H
#define MY_COMBOBOX_H
#include<QComboBox>
class MyComboBox : public QComboBox{ 
	Q_OBJECT
public:
	MyComboBox(QWidget *parent = 0);  

protected:
virtual void mouseReleaseEvent(QMouseEvent * ev);



signals:
void clicked(void); 

};
#endif 