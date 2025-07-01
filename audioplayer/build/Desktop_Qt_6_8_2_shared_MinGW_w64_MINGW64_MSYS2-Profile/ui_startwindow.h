/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->setEnabled(true);
        StartWindow->resize(583, 377);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartWindow->sizePolicy().hasHeightForWidth());
        StartWindow->setSizePolicy(sizePolicy);
        StartWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background:  #CC63CA\n"
"}"));
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background: qlineargradient(\n"
"    x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 #F66DBB,\n"
"    stop:1 #CC63CA\n"
");\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 90, 241, 221));
        QFont font;
        font.setPointSize(50);
        font.setBold(false);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 10px; /* \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 6px 12px;\n"
"    color: white;\n"
"     background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #CD0074,  /* \321\206\320\262\320\265\321\202 \320\261\320\265\320\267 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\260 \321\201\320\262\320\265\321\200\321\205\321\203 */\n"
"        stop:0.5 #CD0074,\n"
"        stop:1 #A325A4   /* \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\201\320\275\320\270\320\267\321\203 */\n"
"	);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9A0058,  /* \320\261\320\276\320\273\320\265\320\265 \321\202\321\221\320\274\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\201\320\262\320"
                        "\265\321\200\321\205\321\203 */\n"
"        stop:0.5 #9A0058,\n"
"        stop:1 #6E1E73   /* \320\261\320\276\320\273\320\265\320\265 \321\202\321\221\320\274\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\201\320\275\320\270\320\267\321\203 */\n"
"    );\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9B005C,  /* \320\261\320\276\320\273\320\265\320\265 \320\275\320\260\321\201\321\213\321\211\320\265\320\275\320\275\321\213\320\271, \321\202\321\221\320\274\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\201\320\262\320\265\321\200\321\205\321\203 */\n"
"        stop:0.5 #9B005C,\n"
"        stop:1 #7A1E7B   /* \320\261\320\276\320\273\320\265\320\265 \320\275\320\260\321\201\321\213\321\211\320\265\320\275\320\275\321\213\320\271, \321\202\321\221\320\274\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \321\201\320\275\320\270\320\267\321\203 */\n"
"    );\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 30, 421, 31));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 90, 261, 61));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setHintingPreference(QFont::PreferDefaultHinting);
        label_2->setFont(font2);
        label_2->setTabletTracking(false);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setWordWrap(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 140, 241, 41));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3->setWordWrap(true);
        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 583, 26));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName("statusbar");
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("StartWindow", "+", nullptr));
        label->setText(QCoreApplication::translate("StartWindow", "SNK \320\277\321\200\320\270\320\262\320\265\321\202\321\201\321\202\320\262\321\203\320\265\321\202 \320\264\320\276\321\200\320\276\320\263\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217!", nullptr));
        label_2->setText(QCoreApplication::translate("StartWindow", "\320\230\320\267\320\262\320\270\320\275\320\270\321\202\320\265, \320\275\320\276 \321\203 \320\262\320\260\321\201 \320\275\320\265\321\202 \320\274\321\203\320\267\321\213\320\272\320\270 \320\264\320\273\321\217 \320\277\321\200\320\276\320\270\320\263\321\200\321\213\320\262\320\260\320\275\320\270\321\217...", nullptr));
        label_3->setText(QCoreApplication::translate("StartWindow", "\320\235\320\276 \320\262\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\265\321\221 \320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
