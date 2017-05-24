#include "wanwu.h"

bool Wanwu::IsBoom(const Wanwu &wanwu)const{
bool isok=true;
if(wanwu.m_rectSphere.left()>m_rectSphere.right()
||wanwu.m_rectSphere.right()<m_rectSphere.left()||wanwu.m_rectSphere.top()>m_rectSphere.bottom()||wanwu.m_rectSphere.bottom()<m_rectSphere.top())
isok=false;

return isok;
}

