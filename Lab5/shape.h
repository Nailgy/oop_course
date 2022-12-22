#pragma once
#include "framework.h"
#include <string>
#include <typeinfo>

class Shape 
{
protected:
	long xs1, ys1, xs2, ys2;
public:
	void Set(long, long, long, long);
	void SetEnd(long, long);
	void ShowGlobal(HDC, bool);
	std::wstring getProperties();
	virtual std::wstring getName() = 0;

	virtual void Show(HDC) = 0;
	virtual void DrawRubber(HWND) = 0;
	virtual Shape* duplicateShape() = 0;
	virtual LPCTSTR getDisplayText() = 0;
};