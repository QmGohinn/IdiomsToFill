/// 这里存放程序需要用到的变量
/// 主要是存放的成语

#ifndef EXEGLOBAL_H
#define EXEGLOBAL_H

/// 成语是字符串类型
/// QString是QT内置的字符串类型
/// 非常好用便捷
#include <QString>

class exeGlobal{

public:
    /// 存放所有的成语的变量
    static QVector<QString> g_allIdioms;
    /// 游戏时间秒数
    static int g_time;
    /// 答对数
    static int g_rightNum;
    /// 答对的成语
    static QVector<QString> g_rightIdioms;
    /// 答错数
    static int g_wrongNum;
    /// 答错成语
    static QVector<QString> g_wrongIdioms;
    /// 当前界面上显示的成语
    static QString g_currentStr;

public:
    /// 初始化函数
    /// 程序启动时, 填充存储的成语
    static void init();
};

#endif // EXEGLOBAL_H
