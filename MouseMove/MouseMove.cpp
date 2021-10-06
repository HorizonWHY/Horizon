// MouseMove.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    double stepx, stepy;
    stepx = 65535/ (double)x;
    stepy = 65535/ (double)y;
    double ratex=0;
    double ratey = 0.1;
    cout << x << " " << y<<"\n";
    cout << stepx << " " << stepy;

    mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, (x/2)*stepx, (y/2)* stepy, 0, GetMessageExtraInfo());
    int i = 0;
    while (i < 1000)
    {
        mouse_event(MOUSEEVENTF_MOVE , ratex * stepx, ratey * stepy, 0, GetMessageExtraInfo());
        i++;
        Sleep(5);
    }
    return 0;
}

