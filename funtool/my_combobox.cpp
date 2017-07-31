#include "my_combobox.h"
#include<QComboBox>

MyComboBox::MyComboBox(QWidget *parent): QComboBox(parent)  {
	
}


void MyComboBox::mouseReleaseEvent(QMouseEvent * ev)
{
Q_UNUSED(ev)
emit clicked();
}

/*
void MyComboBox::mouseDownEvent(QMouseEvent * ev)
{



}
void MyComboBox::mouseUpEvent(QMouseEvent * ev)
{



}
*/



