/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <my_combobox.h>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QGroupBox *groupBox_4;
    QFrame *frame;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_3;
    QLabel *label_21;
    QGroupBox *groupBox;
    QLabel *label_27;
    QLineEdit *imeitext;
    QLabel *label_28;
    QLineEdit *sntext;
    QToolButton *toolButton_4;
    QCheckBox *imeicheck;
    QCheckBox *sncheck;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    MyComboBox *combox;
    QLabel *label;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QStringLiteral("mainwindow"));
        mainwindow->resize(933, 678);
        QIcon icon;
        icon.addFile(QString::fromUtf8("D:/Project/task\347\264\240\346\235\220/20070312002/gif_47_040.gif"), QSize(), QIcon::Normal, QIcon::Off);
        mainwindow->setWindowIcon(icon);
        groupBox_4 = new QGroupBox(mainwindow);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(490, 30, 431, 631));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(16);
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        frame = new QFrame(groupBox_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 30, 391, 591));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(85, 85, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 20, 191, 21));
        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(100, 80, 81, 21));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 180, 61, 21));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(80, 210, 54, 31));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(70, 270, 141, 41));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 375, 71, 31));
        label_25 = new QLabel(frame);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(60, 470, 141, 31));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(190, 90, 91, 41));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 70, 151, 41));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 200, 141, 51));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(230, 260, 111, 61));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(220, 460, 121, 51));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 410, 91, 51));
        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(60, 420, 54, 31));
        groupBox = new QGroupBox(mainwindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 90, 451, 181));
        groupBox->setMinimumSize(QSize(0, 0));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(50, 20, 54, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        label_27->setFont(font1);
        imeitext = new QLineEdit(groupBox);
        imeitext->setObjectName(QStringLiteral("imeitext"));
        imeitext->setGeometry(QRect(130, 18, 311, 41));
        imeitext->setFont(font1);
        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(60, 90, 51, 31));
        label_28->setFont(font1);
        sntext = new QLineEdit(groupBox);
        sntext->setObjectName(QStringLiteral("sntext"));
        sntext->setGeometry(QRect(130, 79, 311, 41));
        sntext->setFont(font1);
        toolButton_4 = new QToolButton(groupBox);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(310, 130, 111, 41));
        toolButton_4->setFont(font1);
        imeicheck = new QCheckBox(groupBox);
        imeicheck->setObjectName(QStringLiteral("imeicheck"));
        imeicheck->setGeometry(QRect(20, 20, 40, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imeicheck->sizePolicy().hasHeightForWidth());
        imeicheck->setSizePolicy(sizePolicy);
        imeicheck->setIconSize(QSize(16, 16));
        imeicheck->setChecked(true);
        sncheck = new QCheckBox(groupBox);
        sncheck->setObjectName(QStringLiteral("sncheck"));
        sncheck->setGeometry(QRect(20, 80, 40, 51));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sncheck->sizePolicy().hasHeightForWidth());
        sncheck->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(14);
        sncheck->setFont(font2);
        sncheck->setChecked(true);
        groupBox_2 = new QGroupBox(mainwindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 280, 451, 201));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 411, 181));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(12);
        textEdit->setFont(font3);
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 0);"));
        groupBox_3 = new QGroupBox(mainwindow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 500, 451, 161));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 51, 221, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(36);
        label_4->setFont(font4);
        toolButton = new QToolButton(groupBox_3);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(300, 40, 111, 41));
        toolButton->setFont(font1);
        toolButton_2 = new QToolButton(groupBox_3);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(300, 110, 111, 41));
        toolButton_2->setFont(font1);
        combox = new MyComboBox(mainwindow);
        combox->setObjectName(QStringLiteral("combox"));
        combox->setGeometry(QRect(150, 31, 311, 41));
        combox->setFont(font1);
        label = new QLabel(mainwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 91, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setWeight(50);
        label->setFont(font5);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QString());
        groupBox_4->setTitle(QApplication::translate("mainwindow", "\351\205\215\347\275\256\344\277\241\346\201\257", 0));
        label_15->setText(QApplication::translate("mainwindow", "\347\253\257\345\217\243\347\261\273\345\236\213\357\274\232\344\270\262\345\217\243", 0));
        label_16->setText(QApplication::translate("mainwindow", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        label_19->setText(QApplication::translate("mainwindow", "SN:", 0));
        label_20->setText(QApplication::translate("mainwindow", "\344\275\215\346\225\260\357\274\232", 0));
        label_22->setText(QApplication::translate("mainwindow", "\346\230\257\345\220\246\346\240\241\351\252\214\345\220\210\346\263\225\357\274\232", 0));
        label_24->setText(QApplication::translate("mainwindow", "IMEI:", 0));
        label_25->setText(QApplication::translate("mainwindow", "\346\230\257\345\220\246\346\240\241\351\252\214\345\220\210\346\263\225\357\274\232", 0));
        label_10->setText(QString());
        label_9->setText(QString());
        label_12->setText(QString());
        label_14->setText(QString());
        label_17->setText(QString());
        label_3->setText(QString());
        label_21->setText(QApplication::translate("mainwindow", "\344\275\215\346\225\260\357\274\232", 0));
        groupBox->setTitle(QString());
        label_27->setText(QApplication::translate("mainwindow", "IMEI", 0));
        label_28->setText(QApplication::translate("mainwindow", "SN", 0));
        toolButton_4->setText(QApplication::translate("mainwindow", "\350\257\273\345\217\226", 0));
        imeicheck->setText(QString());
        sncheck->setText(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_4->setText(QApplication::translate("mainwindow", "\346\234\252\345\220\257\345\212\250", 0));
        toolButton->setText(QApplication::translate("mainwindow", "\345\206\231\345\205\245", 0));
        toolButton_2->setText(QApplication::translate("mainwindow", "\345\201\234\346\255\242", 0));
        label->setText(QApplication::translate("mainwindow", "\347\253\257\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
