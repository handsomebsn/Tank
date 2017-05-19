#ifndef WANWU_H
#define WANWU_H
#include<QPoint>
#include<QRect>
#include<QPainter>
enum Dir { UP, DOWN, LEFT, RIGHT };
class Wanwu
{
 protected:
    // 计算势力范围
    virtual void CalculateSphere() = 0;

    // 位置
    QPoint m_pos;
    // 势力范围
    QRect m_rectSphere;
    // 颜色
    //QColor m_color;
    // 方向
    Dir m_dir;
    // 存在状态
    bool m_bDisappear;
    // 单次前进步长
    int m_step;
    //生命值
    float life;
    //护甲
    float hujia;
    //魔抗
    float mokang;
    //物理攻击
    float wuli;
    //法术攻击
    float fashu;

 public:
       Wanwu(){};
       // 绘图
       virtual void Display() = 0;

       // 移动
       virtual void Move() = 0;

       // 判断是否消失
       virtual bool IsDisappear() = 0;
       //判断两物体是否碰撞
       virtual bool IsBoom(const Wanwu &wanwu)const;
};

#endif // WANWU_H
