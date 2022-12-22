#pragma once
#include "shape.h"

class LineShape : virtual public Shape {
public:
	virtual void Show(HDC);
	void DrawRubber(HWND);
	Shape* duplicateShape();
	LPCTSTR getDisplayText();
	std::wstring getName();
};