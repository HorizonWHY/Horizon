#pragma once

#include <Windows.h>
#include <Xinput.h>
#include <map>
#include <string>

using namespace std;

typedef map<int, string> _Button_Name;

_Button_Name Button_Name = {
	{0,"No_Press"},
	{VK_PAD_A,"A"},
	{VK_PAD_B,"B"},
	{VK_PAD_X,"X"},
	{VK_PAD_Y,"Y"},
	{VK_PAD_RSHOULDER,"Right shoulder button"},
	{VK_PAD_LSHOULDER,"Left shoulder button"},
	{VK_PAD_LTRIGGER,"Left trigger"},
	{VK_PAD_RTRIGGER,"Right trigger"},
	{VK_PAD_DPAD_UP,"Directional pad up"},
	{VK_PAD_DPAD_DOWN,"Directional pad down"},
	{VK_PAD_DPAD_LEFT,"Directional pad left"},
	{VK_PAD_DPAD_RIGHT,"Directional pad right"},
	{VK_PAD_START,"START button"},
	{VK_PAD_BACK,"BACK button"},
	{VK_PAD_LTHUMB_PRESS,"Left thumbstick click"},
	{VK_PAD_RTHUMB_PRESS,"Right thumbstick click"},
	{VK_PAD_LTHUMB_UP,"Left thumbstick up"},
	{VK_PAD_LTHUMB_DOWN,"Left thumbstick down"},
	{VK_PAD_LTHUMB_RIGHT,"Left thumbstick right"},
	{VK_PAD_LTHUMB_LEFT,"Left thumbstick left"},
	{VK_PAD_LTHUMB_UPLEFT,"Left thumbstick up and left"},
	{VK_PAD_LTHUMB_UPRIGHT,"Left thumbstick up and right"},
	{VK_PAD_LTHUMB_DOWNRIGHT,"Left thumbstick down and right"},
	{VK_PAD_LTHUMB_DOWNLEFT,"Left thumbstick down and left"},
	{VK_PAD_RTHUMB_UP,"Right thumbstick up"},
	{VK_PAD_RTHUMB_DOWN	,"Right thumbstick down"},
	{VK_PAD_RTHUMB_RIGHT,"Right thumbstick right"},
	{VK_PAD_RTHUMB_LEFT,"Right thumbstick left"},
	{VK_PAD_RTHUMB_UPLEFT,"Right thumbstick up and left"},
	{VK_PAD_RTHUMB_UPRIGHT,"Right thumbstick up and right"},
	{VK_PAD_RTHUMB_DOWNRIGHT,"Right thumbstick down and right"},
	{VK_PAD_RTHUMB_DOWNLEFT,"Right thumbstick down and left"}
};


