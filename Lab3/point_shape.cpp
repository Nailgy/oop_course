#include "framework.h"
#include "point_shape.h"

PointShape::PointShape() {};
void PointShape::Show(HDC hdc)
{
	SetPixel(hdc, xs2, ys2, 0x00000000);

	SetPixel(hdc, xs2 - 2, ys2, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2, 0x00000000);
	SetPixel(hdc, xs2 + 2, ys2, 0x00000000);

	SetPixel(hdc, xs2, ys2 - 2, 0x00000000);
	SetPixel(hdc, xs2, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2, ys2 + 1, 0x00000000);
	SetPixel(hdc, xs2, ys2 + 2, 0x00000000);

	SetPixel(hdc, xs2 - 1, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2 + 1, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2 + 1, 0x00000000);
}