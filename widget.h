#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QFileDevice>
#include <QFileDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QDebug>
#include <QMessageBox>
#include "cJSON.h"

typedef struct _CONFIG_FILE
{
    QString dataname;
    QString canid;
    unsigned char datatype;
    unsigned char data_addr;
    unsigned char data_len;
    unsigned char bit_addr;
    double multi;
    int add;
    QString unit;
}CONFIG_FILE;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void add_param_from_config(CONFIG_FILE *config);    //添加一行参数
    CONFIG_FILE get_param_from_item(int row); // 获得某一行的配置信息
    bool check_param_config();                 //检查参数合法性

private slots:
    void on_add_param_clicked();

    void on_del_param_clicked();

    void on_import_config_file_clicked();

    void on_export_config_file_clicked();

    void on_save_config_file_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int rows;
    int cols;
    QString m_filepath;
    cJSON *root;
};

#endif // WIDGET_H
