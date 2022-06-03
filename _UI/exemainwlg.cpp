#include "exemainwlg.h"
#include "ui_exemainwlg.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <_base/exeGlobal.h>

ExeMainWlg::ExeMainWlg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExeMainWlg)
{
    qsrand(time(nullptr));
    ui->setupUi(this);

    /// 初始化定时器
    m_timer = new QTimer;
    /// 指明定时器设定的时间到了之后执行的函数
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateLabel()));
    /// 设置定时器的更新间隔为1000ms
    /// 即1秒1刷新
    m_timer->start(1000);

    /// 设置成语的四个文本框最多只能输入一个字符
    ui->lineEdit->setMaxLength(1);
    ui->lineEdit_2->setMaxLength(1);
    ui->lineEdit_3->setMaxLength(1);
    ui->lineEdit_4->setMaxLength(1);

    /// 显示一个成语
    IdiomsToUI();
}

ExeMainWlg::~ExeMainWlg()
{
    delete ui;
}

/// 成语显示在界面上
void ExeMainWlg::IdiomsToUI()
{
    /// 每次显示成语时
    /// 我们此时不清楚四个位置中哪俩个需要填
    /// 因此我们四个文本框都清空并设置为可编辑状态
    ui->lineEdit->clear();
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->clear();
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->clear();
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->clear();
    ui->lineEdit_4->setEnabled(true);

    /// 每次显示一个成语以后
    /// 我们立即在数组删掉该成语防止重复显示
    /// 此处是如果剩下的成语数为0的情况
    if(exeGlobal::g_allIdioms.size() == 0){
        QMessageBox::information(this, "提 示", "成语库已用完!", "知道了");
        return;
    }

/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    int _index = qrand() % exeGlobal::g_allIdioms.size();           //↑
    QString _inputStr = exeGlobal::g_allIdioms.at(_index);          //随
    exeGlobal::g_currentStr = _inputStr;                            //机
    qDebug() << _inputStr;                                          //出
                                                                    //俩
    int _index1 = 0, _index2 = 0;                                   //个
    while(_index1 == _index2){                                      //空
        _index1 = qrand() % 4 + 1;                                  //白
        _index2 = qrand() % 4 + 1;                                  //位
    }                                                               //置
                                                                    //↓
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    /// 根据空白位置
    /// 把需要设置成不可以编辑的文本框设置好
    /// 同时填上俩个汉字
    switch (_index1) {
    case 1:
        ui->lineEdit->setText(_inputStr.at(0));
        ui->lineEdit->setEnabled(false);
        break;
    case 2:
        ui->lineEdit_2->setText(_inputStr.at(1));
        ui->lineEdit_2->setEnabled(false);
        break;
    case 3:
        ui->lineEdit_3->setText(_inputStr.at(2));
        ui->lineEdit_3->setEnabled(false);
        break;
    case 4:
        ui->lineEdit_4->setText(_inputStr.at(3));
        ui->lineEdit_4->setEnabled(false);
        break;
    }

    /// 同上
    switch (_index2) {
    case 1:
        ui->lineEdit->setText(_inputStr.at(0));
        ui->lineEdit->setEnabled(false);
        break;
    case 2:
        ui->lineEdit_2->setText(_inputStr.at(1));
        ui->lineEdit_2->setEnabled(false);
        break;
    case 3:
        ui->lineEdit_3->setText(_inputStr.at(2));
        ui->lineEdit_3->setEnabled(false);
        break;
    case 4:
        ui->lineEdit_4->setText(_inputStr.at(3));
        ui->lineEdit_4->setEnabled(false);
        break;
    }
}

/// 定时器每隔一秒执行的函数
void ExeMainWlg::updateLabel()
{
    exeGlobal::g_time += 1;
    ui->label->setText(QString("用时%1秒 答对%2题 答错%3题")
                       .arg(exeGlobal::g_time)
                       .arg(exeGlobal::g_rightNum)
                       .arg(exeGlobal::g_wrongNum));
}

/// 点击清除按钮执行的操作
void ExeMainWlg::on_pushButton_clicked()
{
    if(ui->lineEdit->isEnabled()){
        ui->lineEdit->clear();
    }

    if(ui->lineEdit_2->isEnabled()){
        ui->lineEdit_2->clear();
    }

    if(ui->lineEdit_3->isEnabled()){
        ui->lineEdit_3->clear();
    }

    if(ui->lineEdit_4->isEnabled()){
        ui->lineEdit_4->clear();
    }
}

/// 点击重新开始执行的函数
void ExeMainWlg::on_pushButton_3_clicked()
{
    exeGlobal::init();
    IdiomsToUI();
}

/// 点击填写完成执行的函数
void ExeMainWlg::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().compare("") == 0
            || ui->lineEdit_2->text().compare("") == 0
            || ui->lineEdit_3->text().compare("") == 0
            || ui->lineEdit_4->text().compare("") == 0){

        QMessageBox::warning(this, "提 示", "尚未补全", "知道了");
        return;
    }

    QString _res = ui->lineEdit->text() + ui->lineEdit_2->text() + ui->lineEdit_3->text() + ui->lineEdit_4->text();

    if(_res.compare(exeGlobal::g_currentStr) == 0){
        QMessageBox::information(this, "通 知", "正确,你真棒!", "继续答题");
        exeGlobal::g_rightNum += 1;
        exeGlobal::g_rightIdioms.push_back(_res);
        exeGlobal::g_allIdioms.removeOne(_res);
        IdiomsToUI();
        if(exeGlobal::g_rightNum == 2){
            QString _Str = "答对列表:\n";
            int _num = 0;
            for(auto& _it : exeGlobal::g_rightIdioms){
                _Str += _it;
                _num += 1;
                if(_num % 5 == 0){
                    _Str += "\n";
                    _num = 0;
                }
                else{
                    _Str += " ";
                }
            }
            _Str += "\n答错列表:\n";
            int _num1 = 0;
            for(auto& _it : exeGlobal::g_wrongIdioms){
                _Str += _it;
                _num1 += 1;
                if(_num1 % 5 == 0){
                    _Str += "\n";
                    _num1 = 0;
                }
                else{
                    _Str += " ";
                }
            }
            QMessageBox::information(this, "通 知", _Str, "知道了");
        }
        return;
    }
    else{
        QMessageBox::warning(this, "通 知", QString("错了, 正确答案: %1").arg(exeGlobal::g_currentStr), "继续答题");
        exeGlobal::g_wrongNum += 1;
        exeGlobal::g_wrongIdioms.push_back(exeGlobal::g_currentStr);
        exeGlobal::g_allIdioms.removeOne(exeGlobal::g_currentStr);
        IdiomsToUI();
        return;
    }
}
