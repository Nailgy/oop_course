#include "cube_shape.h"

void CubeShape::Show(HDC hdc)
{
	long x1, x2, y1, y2, xCenter, yCenter;

	RectShape::Show(hdc);

	x1 = 2 * xs1 - xs2;
	y1 = 2 * ys1 - ys2; 
	x2 = xs2; 
	y2 = ys2;
	xCenter = xs1;
	yCenter = ys1;

	LineShape::Set(x1, y1, x1 + 40, y1 - 40);
	LineShape::Show(hdc);

	LineShape::Set(x2, y1, x2 + 40, y1 - 40);
	LineShape::Show(hdc);

	LineShape::Set(x1, y2, x1 + 40, y2 - 40);
	LineShape::Show(hdc);

	LineShape::Set(x2, y2, x2 + 40, y2 - 40);
	LineShape::Show(hdc);

	LineShape::Set(x1 + 40, y1 - 40, x2 + 40, y1 - 40);
	LineShape::Show(hdc);
	
	LineShape::Set(x2 + 40, y1 - 40, x2 + 40, y2 - 40);
	LineShape::Show(hdc);

	LineShape::Set(x1 + 40, y2 - 40, x2 + 40, y2 - 40);
	LineShape::Show(hdc);

	LineShape::Set(x1 + 40, y1 - 40, x1 + 40, y2 - 40);
	LineShape::Show(hdc);
	
	xs1 = xCenter;
	ys1 = yCenter;
	xs2 = x2; 
	ys2 = y2;
}

void CubeShape::DrawRubber(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	long x1, x2, y1, y2, xCenter, yCenter;

	RectShape::DrawRubber(hWnd);

	x1 = 2 * xs1 - xs2;
	y1 = 2 * ys1 - ys2;
	x2 = xs2;
	y2 = ys2;
	xCenter = xs1;
	yCenter = ys1;

	LineShape::Set(x1, y1, x1 + 40, y1 - 40);
	LineShape::DrawRubber(hWnd);

	LineShape::Set(x2, y1, x2 + 40, y1 - 40);
	LineShape::DrawRubber(hWnd);

	LineShape::Set(x1, y2, x1 + 40, y2 - 40);
	LineShape::DrawRubber(hWnd);

	LineShape::Set(x2, y2, x2 + 40, y2 - 40);
	LineShape::DrawRubber(hWnd);

	LineShape::Set(x1 + 40, y1 - 40, x2 + 40, y1 - 40);
	LineShape::DrawRubber(hWnd);
	
	LineShape::Set(x2 + 40, y1 - 40, x2 + 40, y2 - 40);
	LineShape::DrawRubber(hWnd);
	
	LineShape::Set(x1 + 40, y2 - 40, x2 + 40, y2 - 40);
	LineShape::DrawRubber(hWnd);

	LineShape::Set(x1 + 40, y1 - 40, x1 + 40, y2 - 40);
	LineShape::DrawRubber(hWnd);
	
	xs1 = xCenter;
	ys1 = yCenter;
	xs2 = x2;
	ys2 = y2;
}

Shape* CubeShape::duplicateShape() 
{ 
	return new CubeShape; 
}

LPCTSTR CubeShape::getDisplayText()
{
	return  L"–ежим вводу куб≥в";
}

std::wstring CubeShape::getName()
{
	return L" уб";
}