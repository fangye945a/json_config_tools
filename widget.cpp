#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("参数配置工具");
    rows = 0;
    cols = 9;
    root = NULL;
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setColumnCount(cols);

    //使行列头自适应宽度，最后一列将会填充空白部分
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //使行列头自适应宽度，所有列平均分来填充空白部分
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //只选中一行
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //不允许选择多行
}

Widget::~Widget()
{
    delete ui;
}

void Widget::add_param_from_config(CONFIG_FILE *config)
{
    ui->tableWidget->insertRow(rows);

    QLineEdit *param_name = new QLineEdit(this);
    param_name->setText(config->dataname);
    param_name->setAlignment(Qt::AlignHCenter); //水平居中
    param_name->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 0, (QWidget*)param_name);

    QLineEdit *canid = new QLineEdit(this);
    canid->setText(config->canid);
    canid->setAlignment(Qt::AlignHCenter); //水平居中
    canid->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 1, (QWidget*)canid);

    QComboBox *data_type = new QComboBox(this);
    data_type->addItem(QString("无符号"));
    data_type->addItem(QString("有符号"));
    data_type->addItem(QString("浮点型"));
    if(config->datatype == 1)
        data_type->setCurrentIndex(0);
    else if(config->datatype == 2)
        data_type->setCurrentIndex(1);
    else if(config->datatype == 4)
        data_type->setCurrentIndex(2);
    ui->tableWidget->setCellWidget(rows, 2, (QWidget*)data_type);

    QSpinBox *data_addr = new QSpinBox(this);
    data_addr->setMinimum(0);
    data_addr->setMaximum(7);
    data_addr->setAlignment(Qt::AlignHCenter); //水平居中
    data_addr->setAlignment(Qt::AlignVCenter); //垂直居中
    data_addr->setValue(config->data_addr);
    ui->tableWidget->setCellWidget(rows, 3, (QWidget*)data_addr);

    QSpinBox *data_len = new QSpinBox(this);
    data_len->setMinimum(1);
    data_len->setMaximum(8);
    data_len->setAlignment(Qt::AlignHCenter); //水平居中
    data_len->setAlignment(Qt::AlignVCenter); //垂直居中
    data_len->setValue(config->data_len);
    ui->tableWidget->setCellWidget(rows, 4, (QWidget*)data_len);

    QSpinBox *data_bit = new QSpinBox(this);
    data_bit->setMinimum(0);
    data_bit->setMaximum(7);
    data_bit->setAlignment(Qt::AlignHCenter); //水平居中
    data_bit->setAlignment(Qt::AlignVCenter); //垂直居中
    data_bit->setValue(config->bit_addr);
    ui->tableWidget->setCellWidget(rows, 5, (QWidget*)data_bit);

    QDoubleSpinBox *data_multi = new QDoubleSpinBox(this);
    data_multi->setMinimum(0);
    data_multi->setMaximum(1000);
    data_multi->setAlignment(Qt::AlignHCenter); //水平居中
    data_multi->setAlignment(Qt::AlignVCenter); //垂直居中
    data_multi->setValue(config->multi);
    ui->tableWidget->setCellWidget(rows, 6, (QWidget*)data_multi);

    QSpinBox *data_add = new QSpinBox(this);
    data_add->setMinimum(-9999);
    data_add->setMaximum(9999);
    data_add->setAlignment(Qt::AlignHCenter); //水平居中
    data_add->setAlignment(Qt::AlignVCenter); //垂直居中
    data_add->setValue(config->add);
    ui->tableWidget->setCellWidget(rows, 7, (QWidget*)data_add);

    QLineEdit *data_unit = new QLineEdit(this);
    data_unit->setText(QString("无"));
    data_unit->setAlignment(Qt::AlignHCenter); //水平居中
    data_unit->setAlignment(Qt::AlignVCenter); //垂直居中
    data_unit->setText(config->unit);
    ui->tableWidget->setCellWidget(rows, 8, (QWidget*)data_unit);

    rows++;
}


void Widget::on_add_param_clicked()
{
    ui->tableWidget->insertRow(rows);

    QLineEdit *param_name = new QLineEdit(this);
    param_name->setText(QString("参数名"));
    param_name->setAlignment(Qt::AlignHCenter); //水平居中
    param_name->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 0, (QWidget*)param_name);

    QLineEdit *canid = new QLineEdit(this);
    canid->setText(QString("110"));
    canid->setAlignment(Qt::AlignHCenter); //水平居中
    canid->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 1, (QWidget*)canid);

    QComboBox *data_type = new QComboBox(this);
    data_type->addItem(QString("无符号"));
    data_type->addItem(QString("有符号"));
    data_type->addItem(QString("浮点型"));
    ui->tableWidget->setCellWidget(rows, 2, (QWidget*)data_type);

    QSpinBox *data_addr = new QSpinBox(this);
    data_addr->setMinimum(0);
    data_addr->setMaximum(7);
    data_addr->setAlignment(Qt::AlignHCenter); //水平居中
    data_addr->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 3, (QWidget*)data_addr);

    QSpinBox *data_len = new QSpinBox(this);
    data_len->setMinimum(1);
    data_len->setMaximum(8);
    data_len->setAlignment(Qt::AlignHCenter); //水平居中
    data_len->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 4, (QWidget*)data_len);

    QSpinBox *data_bit = new QSpinBox(this);
    data_bit->setMinimum(0);
    data_bit->setMaximum(7);
    data_bit->setAlignment(Qt::AlignHCenter); //水平居中
    data_bit->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 5, (QWidget*)data_bit);

    QDoubleSpinBox *data_multi = new QDoubleSpinBox(this);
    data_multi->setMinimum(0);
    data_multi->setMaximum(1000);
    data_multi->setAlignment(Qt::AlignHCenter); //水平居中
    data_multi->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 6, (QWidget*)data_multi);

    QSpinBox *data_add = new QSpinBox(this);
    data_add->setMinimum(-9999);
    data_add->setMaximum(9999);
    data_add->setAlignment(Qt::AlignHCenter); //水平居中
    data_add->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 7, (QWidget*)data_add);

    QLineEdit *data_unit = new QLineEdit(this);
    data_unit->setText(QString("无"));
    data_unit->setAlignment(Qt::AlignHCenter); //水平居中
    data_unit->setAlignment(Qt::AlignVCenter); //垂直居中
    ui->tableWidget->setCellWidget(rows, 8, (QWidget*)data_unit);

 //   ui->tableWidget->setItem(rows, 0, item);
    rows++;
}

void Widget::on_del_param_clicked()
{
    int rowIndex = ui->tableWidget->currentRow();
    if (rowIndex != -1)
    {
        ui->tableWidget->removeRow(rowIndex);
        rows--;
    }
}

void Widget::on_import_config_file_clicked()
{
    QByteArray json_str;
    QString filepath = QFileDialog::getOpenFileName(this,"打开配置文件","./","*");
    qDebug()<<"filepath:"<<filepath;
    QFile file(filepath);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    json_str = file.readAll();
    qDebug()<<json_str;
    if(root != NULL)
    {
        cJSON_Delete(root);
        root = NULL;
    }
    qDebug()<<__LINE__;
    root = cJSON_Parse(json_str.data());
    if(root)
    {
        qDebug()<<__LINE__;
        cJSON *candecode_config = cJSON_GetObjectItem(root,"candecode_config");
        if(candecode_config && candecode_config->type == cJSON_Array)
        {
            int size = cJSON_GetArraySize(candecode_config);
            qDebug()<<"size:"<<size;
            CONFIG_FILE config;
            for(int i=0; i<size; i++)
            {
                cJSON *param = cJSON_GetArrayItem(candecode_config, i);
                if(param && param->type == cJSON_Object)    //获取到参数
                {
                    cJSON *dataname = cJSON_GetObjectItem(param, "dataname");
                    cJSON *canid = cJSON_GetObjectItem(param,"canid");
                    cJSON *datatype = cJSON_GetObjectItem(param,"datatype");
                    cJSON *data_addr = cJSON_GetObjectItem(param,"dataaddr");
                    cJSON *data_len = cJSON_GetObjectItem(param,"length");
                    cJSON *bit_addr = cJSON_GetObjectItem(param,"bitaddr");
                    cJSON *multi = cJSON_GetObjectItem(param,"multiplenum");
                    cJSON *add = cJSON_GetObjectItem(param,"additionnum");
                    cJSON *unit = cJSON_GetObjectItem(param,"unit");

                    if(dataname && canid && datatype && data_addr && data_len &&
                        bit_addr && multi && add && unit)
                    {
                        config.dataname = QString(dataname->valuestring);
                        config.canid = QString(canid->valuestring);
                        config.datatype = datatype->valueint;
                        config.data_addr = data_addr->valueint;
                        config.data_len = data_len->valueint;
                        config.bit_addr = bit_addr->valueint;
                        config.multi = multi->valuedouble;
                        config.add = add->valueint;
                        config.unit = QString(unit->valuestring);
                        add_param_from_config(&config); //添加显示
                    }
                    else
                    {
                        qDebug()<<"对象参数解析出错!";
                    }
                }
            }
        }
        else
            qDebug()<<"解析出错!";
    }else
        qDebug()<<"解析失败!";
}

void Widget::on_export_config_file_clicked()
{

}

void Widget::on_save_config_file_clicked()
{

}
