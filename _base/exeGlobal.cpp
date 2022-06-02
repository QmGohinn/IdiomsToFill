#include <_base/exeGlobal.h>

/// Qvector是QT内置的数组
#include <QVector>

/// 全局变量需要定义
QVector<QString> exeGlobal::g_allIdioms;
int exeGlobal::g_time = 0;
int exeGlobal::g_rightNum;
QVector<QString> exeGlobal::g_rightIdioms;
int exeGlobal::g_wrongNum;
QVector<QString> exeGlobal::g_wrongIdioms;
QString exeGlobal::g_currentStr;

void exeGlobal::init()
{
    g_allIdioms.clear();
    g_rightNum = 0;
    g_wrongNum = 0;
    g_rightIdioms.clear();
    g_wrongIdioms.clear();
    g_time = 0;

    /// 开始填充
    /// 如果想更换成语或者添加成语
    /// 在下方仿写更换即可

    /// 1 - 10
    g_allIdioms.push_back("不平则鸣");
    g_allIdioms.push_back("大同世界");
    g_allIdioms.push_back("等礼相亢");
    g_allIdioms.push_back("等量齐观");
    g_allIdioms.push_back("多劳多得");
    g_allIdioms.push_back("法不阿贵");
    g_allIdioms.push_back("法不徇情");
    g_allIdioms.push_back("公平合理");
    g_allIdioms.push_back("公平无私");
    g_allIdioms.push_back("公事公办");
    /// 11 - 20
    g_allIdioms.push_back("来日可期");
    g_allIdioms.push_back("不惧人言");
    g_allIdioms.push_back("万事顺意");
    g_allIdioms.push_back("爱而无畏");
    g_allIdioms.push_back("一切安好");
    g_allIdioms.push_back("热泪盈眶");
    g_allIdioms.push_back("不期而遇");
    g_allIdioms.push_back("平安胜意");
    g_allIdioms.push_back("一腔孤勇");
    g_allIdioms.push_back("奔赴山海");
    /// 21 - 30
    g_allIdioms.push_back("来日方长");
    g_allIdioms.push_back("山河皆安");
    g_allIdioms.push_back("平安喜乐");
    g_allIdioms.push_back("陌上花开");
    g_allIdioms.push_back("枯木逢春");
    g_allIdioms.push_back("不负众望");
    g_allIdioms.push_back("策顽磨钝");
    g_allIdioms.push_back("投笔从戎");
    g_allIdioms.push_back("滴水穿石");
    g_allIdioms.push_back("行成于思");
    /// 31 - 40
    g_allIdioms.push_back("满怀希望");
    g_allIdioms.push_back("全力以赴");
    g_allIdioms.push_back("力争上游");
    g_allIdioms.push_back("孙康映雪");
    g_allIdioms.push_back("良药苦口");
    g_allIdioms.push_back("问心无愧");
    g_allIdioms.push_back("卷土重来");
    g_allIdioms.push_back("晨钟暮鼓");
    g_allIdioms.push_back("白于起家");
    g_allIdioms.push_back("夕寐宵兴");
    /// 41 - 50
    g_allIdioms.push_back("一鸣惊人");
    g_allIdioms.push_back("别来无恙");
    g_allIdioms.push_back("临池学书");
    g_allIdioms.push_back("破釜沉舟");
    g_allIdioms.push_back("囊萤映雪");
    g_allIdioms.push_back("闻鸡起舞");
    g_allIdioms.push_back("专心致志");
    g_allIdioms.push_back("悬梁刺股");
    g_allIdioms.push_back("勤能补拙");
    g_allIdioms.push_back("人定胜天");
}

