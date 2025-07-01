/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *pushButton;
    QSlider *timeSlider;
    QPushButton *next_btn;
    QPushButton *previous_btn;
    QPushButton *repeat_btn;
    QLabel *currentTime_label;
    QLabel *time_of_track;
    QLabel *label;
    QLabel *name_track_label;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listWidget;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(684, 645);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(684, 645));
        MainWindow->setMaximumSize(QSize(684, 645));
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background: qlineargradient(\n"
"    x1:0, y1:0, x2:0, y2:1,\n"
"    stop:0 #F66DBB,\n"
"    stop:1 #CC63CA\n"
");\n"
"}"));
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 40, 51, 51));
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
        timeSlider = new QSlider(MainWindow);
        timeSlider->setObjectName("timeSlider");
        timeSlider->setGeometry(QRect(270, 60, 391, 22));
        timeSlider->setStyleSheet(QString::fromUtf8("QSlider{\n"
"background: transparent;\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 7px;\n"
"    background: #CD0074;               /* \321\206\320\262\320\265\321\202 \320\276\321\201\321\202\320\260\320\262\321\210\320\265\320\271\321\201\321\217 \321\207\320\260\321\201\321\202\320\270 */\n"
"    border-radius: 3.5px;           /* \320\277\320\276\320\273\320\276\320\262\320\270\320\275\320\260 \320\262\321\213\321\201\320\276\321\202\321\213 \320\264\320\273\321\217 \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\321\217 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #CD0074;            /* \321\206\320\262\320\265\321\202 \320\277\321\200\320\276\320\271\320\264\320\265\320\275\320\275\320\276\320\271 \321\207\320\260\321\201\321\202\320\270 */\n"
"    border-radius: 3.5px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #FFE9F6;            /* \321\206\320\262\320\265\321\202 \320\276\321\201\321\202\320\260\320\262\321\210\320\265\320"
                        "\271\321\201\321\217 \321\207\320\260\321\201\321\202\320\270 (\320\260\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271) */\n"
"    border-radius: 3.5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #FFE9F6;            /* \321\206\320\262\320\265\321\202 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260 */\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    margin: -4px 0;                 /* \321\207\321\202\320\276\320\261\321\213 \320\277\320\276\320\273\320\267\321\203\320\275\320\276\320\272 \320\275\320\265 \320\276\320\261\321\200\320\265\320\267\320\260\320\273\321\201\321\217 */\n"
"    border-radius: 7px;             /* \320\272\321\200\321\203\320\263\320\273\321\213\320\271 \320\277\320\276\320\273\320\267\321\203\320\275\320\276\320\272 */\n"
"}\n"
""));
        timeSlider->setOrientation(Qt::Orientation::Horizontal);
        next_btn = new QPushButton(MainWindow);
        next_btn->setObjectName("next_btn");
        next_btn->setGeometry(QRect(130, 50, 41, 31));
        next_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        previous_btn = new QPushButton(MainWindow);
        previous_btn->setObjectName("previous_btn");
        previous_btn->setGeometry(QRect(19, 49, 41, 31));
        previous_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        repeat_btn = new QPushButton(MainWindow);
        repeat_btn->setObjectName("repeat_btn");
        repeat_btn->setGeometry(QRect(191, 50, 41, 31));
        repeat_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 10px;\n"
"    padding: 6px 12px;\n"
"    color: white;\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #CD0074,\n"
"        stop:0.5 #CD0074,\n"
"        stop:1 #A325A4\n"
"    );\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9A0058,\n"
"        stop:0.5 #9A0058,\n"
"        stop:1 #6E1E73\n"
"    );\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9B005C,\n"
"        stop:0.5 #9B005C,\n"
"        stop:1 #7A1E7B\n"
"    );\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;\n"
"}\n"
""));
        currentTime_label = new QLabel(MainWindow);
        currentTime_label->setObjectName("currentTime_label");
        currentTime_label->setGeometry(QRect(250, 100, 63, 20));
        QFont font;
        font.setPointSize(10);
        currentTime_label->setFont(font);
        currentTime_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        time_of_track = new QLabel(MainWindow);
        time_of_track->setObjectName("time_of_track");
        time_of_track->setGeometry(QRect(610, 100, 63, 20));
        time_of_track->setFont(font);
        time_of_track->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        label = new QLabel(MainWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 121, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        name_track_label = new QLabel(MainWindow);
        name_track_label->setObjectName("name_track_label");
        name_track_label->setGeometry(QRect(270, 10, 391, 20));
        name_track_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background: transparent;\n"
"}"));
        widget = new QWidget(MainWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 140, 651, 471));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border-radius: 15px;           /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 \321\200\320\260\320\264\320\270\321\203\321\201\320\276\320\274 15px */\n"
"    background-color: #FFE9F6;     /* \320\227\320\260\320\273\320\270\320\262\320\272\320\260 \321\201\320\277\320\273\320\276\321\210\320\275\321\213\320\274 \321\206\320\262\320\265\321\202\320\276\320\274 */\n"
"}\n"
""));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 631, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 629, 449));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        listWidget = new QListWidget(scrollAreaWidgetContents);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 0, 631, 551));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        pushButton->setText(QString());
        next_btn->setText(QString());
        previous_btn->setText(QString());
        repeat_btn->setText(QString());
        currentTime_label->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        time_of_track->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\202\321\200\320\265\320\272:", nullptr));
        name_track_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\270\320\263\321\200\320\260\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
