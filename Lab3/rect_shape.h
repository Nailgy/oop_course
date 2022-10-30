#pragma once
#include "shape.h"
class RectShape : public Shape {
private: 
	HBRUSH hBrush, hBrushOld;
public:
	void Show(HDC);
};
