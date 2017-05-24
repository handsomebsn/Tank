#include "wanwu.h"

bool Wanwu::IsBoom(const Wanwu &wanwu)const{
bool isok=true;
if(m_bDisappear==true||wanwu.m_bDisappear==true||wanwu.m_rectSphere.left()>m_rectSphere.right()
||wanwu.m_rectSphere.right()<m_rectSphere.left()||wanwu.m_rectSphere.top()>m_rectSphere.bottom()||wanwu.m_rectSphere.bottom()<m_rectSphere.top())
isok=false;

return isok;
}

void Wanwu::downlife(float gongji, int astyle){
float  mianshang=0.00;
switch(astyle){
case 0:
mianshang=hujia/(100+hujia);
    break;
case 1:
mianshang=mokang/(100+mokang);
    break;
}

life=life-(1-mianshang)*gongji;
if(life<0)
{m_bDisappear=true;life=0;}

}
