#pragma once
#include "shape.h"
class PointShape : virtual public Shape {
public:
	void Show(HDC);
	void DrawRubber(HWND);
	Shape* duplicateShape();
	LPCTSTR getDisplayText();
};