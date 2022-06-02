#ifndef EXEMAINWLG_H
#define EXEMAINWLG_H

/// 窗体头文件
/// QWidget是Qt内置的窗体类
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ExeMainWlg; }
QT_END_NAMESPACE

class ExeMainWlg : public QWidget
{
    Q_OBJECT

public:
    ExeMainWlg(QWidget *parent = nullptr);
    ~ExeMainWlg();

    /// 成语显示到界面函数
    void IdiomsToUI();
    /// 判断输入正误函数
    bool JudgeInput();

    /// 定时器
    /// 窗体右上角的得分情况需要定时刷新
    /// 定时器的作用就是每隔固定的时间
    /// 执行一次特定的函数
    QTimer* m_timer = nullptr;

private:
    Ui::ExeMainWlg *ui;

private slots:

    /// 该函数就是上边提到的每隔一段时间
    /// 定时器执行的函数
    void updateLabel();

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};
#endif // EXEMAINWLG_H
