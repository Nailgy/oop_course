#include "framework.h"
#include "rect_shape.h"

void RectShape::Show(HDC hdc)
{
	hBrush = (HBRUSH)CreateSolidBrush(RGB(192, 192, 192));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, xs1, ys1, xs2, ys2);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}