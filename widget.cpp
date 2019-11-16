#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("中联智能参数配置工具V1.0");
    rows = 0;
    cols = 9;
    m_filepath.clear();
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

CONFIG_FILE Widget::get_param_from_item(int row)
{
    CONFIG_FILE row_config;

    row_config.dataname = ((QLineEdit *)(ui->tableWidget->cellWidget(row-1, 0)))->text();

    row_config.canid = ((QLineEdit *)(ui->tableWidget->cellWidget(row-1, 1)))->text();

    int index = ((QComboBox *)(ui->tableWidget->cellWidget(row-1, 2)))->currentIndex();
    switch (index){
    case 0:
        row_config.datatype = 1;
        break;
    case 1:
        row_config.datatype = 2;
        break;
    case 2:
        row_config.datatype = 4;
        break;
    default:
        row_config.datatype = 1;
        break;
    }

    row_config.data_addr = ((QSpinBox *)(ui->tableWidget->cellWidget(row-1, 3)))->value();

    row_config.data_len = ((QSpinBox *)(ui->tableWidget->cellWidget(row-1, 4)))->value();

    row_config.bit_addr = ((QSpinBox *)(ui->tableWidget->cellWidget(row-1, 5)))->value();

    row_config.multi = ((QDoubleSpinBox *)(ui->tableWidget->cellWidget(row-1, 6)))->value();

    row_config.add = ((QSpinBox *)(ui->tableWidget->cellWidget(row-1, 7)))->value();

    row_config.unit = ((QLineEdit *)(ui->tableWidget->cellWidget(row-1, 8)))->text();

    return row_config;
}


void Widget::on_add_param_clicked()
{
    if(rows != 0)   //与上一行相同
    {
       CONFIG_FILE config =  get_param_from_item(rows);
       add_param_from_config(&config);
       return;
    }

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
    m_filepath = QFileDialog::getOpenFileName(this,"打开配置文件","./","*");
    qDebug()<<"filepath:"<<m_filepath;
    QFile file(m_filepath);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    json_str = file.readAll();
    file.close();
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
    if(rows < 1)
        return;
    m_filepath.clear();
    m_filepath = QFileDialog::getSaveFileName(this,"保存配置文件","./","*");
    if(!m_filepath.isEmpty())
    {
        CONFIG_FILE config_tmp;

        cJSON *root = cJSON_CreateObject();  //创建对象
        cJSON *candecode_config = cJSON_CreateArray();   //创建数组
        for(int i=1; i<= rows; i++)
        {
            config_tmp = get_param_from_item(i);
            cJSON *param = cJSON_CreateObject();
            cJSON_AddItemToObject(param,"dataname",cJSON_CreateString(config_tmp.dataname.toUtf8().data()));
            cJSON_AddItemToObject(param,"canid",cJSON_CreateString(config_tmp.canid.toUtf8().data()));
            cJSON_AddItemToObject(param,"datatype",cJSON_CreateNumber(config_tmp.datatype));
            cJSON_AddItemToObject(param,"dataaddr",cJSON_CreateNumber(config_tmp.data_addr));
            cJSON_AddItemToObject(param,"length",cJSON_CreateNumber(config_tmp.data_len));
            cJSON_AddItemToObject(param,"bitaddr",cJSON_CreateNumber(config_tmp.bit_addr));
            cJSON_AddItemToObject(param,"multiplenum",cJSON_CreateNumber(config_tmp.multi));
            cJSON_AddItemToObject(param,"additionnum",cJSON_CreateNumber(config_tmp.add));
            cJSON_AddItemToObject(param,"unit",cJSON_CreateString(config_tmp.unit.toUtf8().data()));
            cJSON_AddItemToArray(candecode_config,param);    //添加至json数据
        }
        cJSON_AddItemToObject(root,"candecode_config",candecode_config); //将数组添加至对象

        char *json_str = cJSON_PrintUnformatted(root);
        qDebug("%s",json_str);
        QByteArray json_data(json_str,strlen(json_str));
        qDebug()<<"len = "<<json_data.length();

        for(int i=0; i<json_data.length(); i++)
        {
            if(json_data.at(i) == '[' )
                json_data.insert(++i,'\n');

            if(json_data.at(i) == ']')
            {
                json_data.insert(i++,'\n');
                json_data.insert(++i,'\n');
            }

            if((json_data.at(i) == ',' && json_data.at(i-1) == '}'))
                json_data.insert(++i,'\n');
        }

        qDebug()<<"len = "<<json_data.length();
        /*********    保存文件   *********/
        QFile file(m_filepath);
        file.open(QIODevice::WriteOnly |QIODevice::Text | QIODevice::Truncate);
        file.write(json_data);
        file.close();

        cJSON_Delete(root);
    }
}

void Widget::on_save_config_file_clicked()
{
   if(rows < 1) //无数据不保存
       return;


   if(m_filepath.isEmpty())
   {
        on_export_config_file_clicked();
        return;
   }

   int ret = QMessageBox::information(this,"提示","将覆盖最后一次导入的文件,是否继续保存？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No); //
   if(ret == QMessageBox::No)
        return;


   CONFIG_FILE config_tmp;

   cJSON *root = cJSON_CreateObject();  //创建对象
   cJSON *candecode_config = cJSON_CreateArray();   //创建数组
   for(int i=1; i<= rows; i++)
   {
       config_tmp = get_param_from_item(i);
       cJSON *param = cJSON_CreateObject();
       cJSON_AddItemToObject(param,"dataname",cJSON_CreateString(config_tmp.dataname.toUtf8().data()));
       cJSON_AddItemToObject(param,"canid",cJSON_CreateString(config_tmp.canid.toUtf8().data()));
       cJSON_AddItemToObject(param,"datatype",cJSON_CreateNumber(config_tmp.datatype));
       cJSON_AddItemToObject(param,"dataaddr",cJSON_CreateNumber(config_tmp.data_addr));
       cJSON_AddItemToObject(param,"length",cJSON_CreateNumber(config_tmp.data_len));
       cJSON_AddItemToObject(param,"bitaddr",cJSON_CreateNumber(config_tmp.bit_addr));
       cJSON_AddItemToObject(param,"multiplenum",cJSON_CreateNumber(config_tmp.multi));
       cJSON_AddItemToObject(param,"additionnum",cJSON_CreateNumber(config_tmp.add));
       cJSON_AddItemToObject(param,"unit",cJSON_CreateString(config_tmp.unit.toUtf8().data()));
       cJSON_AddItemToArray(candecode_config,param);    //添加至json数据
   }
   cJSON_AddItemToObject(root,"candecode_config",candecode_config); //将数组添加至对象

   char *json_str = cJSON_PrintUnformatted(root);
   qDebug("%s",json_str);
   QByteArray json_data(json_str,strlen(json_str));
   qDebug()<<"len = "<<json_data.length();

   for(int i=0; i<json_data.length(); i++)
   {
       if(json_data.at(i) == '[' )
           json_data.insert(++i,'\n');

       if(json_data.at(i) == ']')
       {
           json_data.insert(i++,'\n');
           json_data.insert(++i,'\n');
       }

       if((json_data.at(i) == ',' && json_data.at(i-1) == '}'))
           json_data.insert(++i,'\n');
   }

   qDebug()<<"len = "<<json_data.length();
   /*********    保存文件   *********/
   QFile file(m_filepath);
   file.open(QIODevice::WriteOnly |QIODevice::Text | QIODevice::Truncate);
   file.write(json_data);
   file.close();

   cJSON_Delete(root);
}
