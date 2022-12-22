#pragma once
#include "shape.h"
class RectShape : virtual public Shape {
private: 
	HBRUSH hBrush, hBrushOld;
public:
	void Show(HDC);
	void DrawRubber(HWND);
	Shape* duplicateShape();
	LPCTSTR getDisplayText();
	std::wstring getName();
};
