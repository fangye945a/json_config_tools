/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *add_param;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *del_param;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *import_config_file;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *export_config_file;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *save_config_file;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1106, 475);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(Widget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("font: 25 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 4);

        horizontalSpacer_7 = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        add_param = new QPushButton(Widget);
        add_param->setObjectName(QStringLiteral("add_param"));

        horizontalLayout_2->addWidget(add_param);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        del_param = new QPushButton(Widget);
        del_param->setObjectName(QStringLiteral("del_param"));

        horizontalLayout_2->addWidget(del_param);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        import_config_file = new QPushButton(Widget);
        import_config_file->setObjectName(QStringLiteral("import_config_file"));

        horizontalLayout->addWidget(import_config_file);

        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        export_config_file = new QPushButton(Widget);
        export_config_file->setObjectName(QStringLiteral("export_config_file"));

        horizontalLayout->addWidget(export_config_file);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 0, 3, 1, 1);

        save_config_file = new QPushButton(Widget);
        save_config_file->setObjectName(QStringLiteral("save_config_file"));

        gridLayout->addWidget(save_config_file, 0, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\345\217\202\346\225\260\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\346\211\200\345\261\236ID(HEX)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\350\265\267\345\247\213\345\234\260\345\235\200(\345\255\227\350\212\202)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\351\225\277\345\272\246\357\274\210\345\255\227\350\212\202\357\274\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\346\211\200\345\261\236bit\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "\347\273\223\346\236\234\344\271\230\344\273\24510\347\232\204n\346\254\241\346\226\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "\347\273\223\346\236\234\345\212\240\344\270\212n", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "\345\217\202\346\225\260\345\215\225\344\275\215", Q_NULLPTR));
        add_param->setText(QApplication::translate("Widget", "\345\242\236\345\212\240\345\217\202\346\225\260", Q_NULLPTR));
        del_param->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\345\217\202\346\225\260", Q_NULLPTR));
        import_config_file->setText(QApplication::translate("Widget", "\345\257\274\345\205\245\351\205\215\347\275\256\346\226\207\344\273\266", Q_NULLPTR));
        export_config_file->setText(QApplication::translate("Widget", "\345\257\274\345\207\272\351\205\215\347\275\256\346\226\207\344\273\266", Q_NULLPTR));
        save_config_file->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\351\205\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
