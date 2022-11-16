#include "lineOO_shape.h"

void LineOOShape::Show(HDC hdc)
{
	long x1, x2, y1, y2;

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1, y1, x2, y2);
	LineShape::Show(hdc);

	EllipseShape::Set(x1 - 20, y1 - 20, x1 + 20, y1 + 20);
	EllipseShape::Show(hdc);

	EllipseShape::Set(x2 - 20, y2 - 20, x2 + 20, y2 + 20);
	EllipseShape::Show(hdc);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

void LineOOShape::DrawRubber(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	long x1, x2, y1, y2;

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1 , y1 , x2 , y2);
	LineShape::DrawRubber(hWnd);

	EllipseShape::Set(x1 - 20, y1 - 20, x1 + 20, y1 + 20);
	EllipseShape::DrawRubber(hWnd);

	EllipseShape::Set(x2 - 20, y2 - 20, x2 + 20, y2 + 20);
	EllipseShape::DrawRubber(hWnd);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* LineOOShape::duplicateShape() 
{ 
	return new LineOOShape; 
}

LPCTSTR LineOOShape::getDisplayText()
{
	return  L"Режим вводу гантелей";
}