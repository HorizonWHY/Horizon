#include <windows.h>
#include <iostream>
#include <Xinput.h>
#include <string>
#include "ButtonName.h"
#include <map>
#pragma comment(lib,"Xinput.lib")//加入有关静态库

using namespace std;

//有关结构体声明
XINPUT_BATTERY_INFORMATION information;
XINPUT_CAPABILITIES capabilities;
XINPUT_GAMEPAD gamepad;
XINPUT_KEYSTROKE keystroke;
XINPUT_STATE state;
XINPUT_VIBRATION vibration;

void Send_Vib(int left, int right, XINPUT_VIBRATION vibration);
string Get_Press();
void MoveMouseLeft(string PressButton);
void MoveMouseRight(string PressButton);
void MoveMouseUp(string PressButton);
void MoveMouseDown(string PressButton);
void MoveMouseDownRight(string PressButton);
void MoveMouseDownLeft(string PressButton);
void MoveMouseUpRight(string PressButton);
void MoveMouseUpLeft(string PressButton);

int main()
{
	/*
	//实时检测手柄按键并输出
	//XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
	string Press_Name;

	while (1)
	{
		Press_Name = Get_Press();
		if (Press_Name != "No_Press"&&(keystroke.Flags==1||keystroke.Flags==5))
		{
			cout << Press_Name << "\n";
		}
	}
	
	*/


	//设置鼠标初始位置
	mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, 50000, 32500, 0, GetMessageExtraInfo());
	//事件循环开始
	string Press_Name;
	
	while (1)
	{
		Press_Name = Get_Press();
		if (Press_Name == "Left thumbstick left")
			MoveMouseLeft(Press_Name);
		if (Press_Name == "Left thumbstick right")
			MoveMouseRight(Press_Name);
		if (Press_Name == "Left thumbstick up")
			MoveMouseUp(Press_Name);
		if (Press_Name == "Left thumbstick down")
			MoveMouseDown(Press_Name);
		if (Press_Name == "Left thumbstick up and left")
			MoveMouseUpLeft(Press_Name);
		if (Press_Name == "Left thumbstick up and right")
			MoveMouseUpRight(Press_Name);
		if (Press_Name == "Left thumbstick down and right")
			MoveMouseDownRight(Press_Name);
		if (Press_Name == "Left thumbstick down and left")
			MoveMouseDownLeft(Press_Name);
		
	}
	
	
	return 0;
}

//振动功能
void Send_Vib(int left, int right,XINPUT_VIBRATION vibration)
{
	if (left <= 65535 && left >= 0 && right <= 65535 && right >= 0)
	{
		vibration.wLeftMotorSpeed = left;
		vibration.wRightMotorSpeed = right;
		XInputSetState(0, &vibration);
	}
	else
	{
		cout << "ERROR VIBRATION NUMBERS\n";
	}
	
}

//输入检测
string Get_Press()
{
	XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
	return Button_Name[keystroke.VirtualKey];
}

//移动鼠标
void MoveMouseLeft(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, -step, 0, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseRight(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, step, 0, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseUp(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, 0, -step, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseDown(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, 0, step, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseUpLeft(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, -step, -step, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseUpRight(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, step, -step, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseDownLeft(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, -step, step, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}

void MoveMouseDownRight(string PressButton)
{
	int step = 1;
	while (keystroke.Flags == 5)
	{
		XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
		mouse_event(MOUSEEVENTF_MOVE, step, step, 0, GetMessageExtraInfo());
		if (step <= 80)
			step += 1;
		Sleep(40);
		if (keystroke.Flags != 5)
			break;
	}
	step = 1;
}
//以上函数包含八个方向的移动