#pragma once
#include "editor.h"
#include "shape.h"
#define MY_SHAPE_ARRAY_SIZE 117

class ShapeEditor : public Editor {
protected:
	static Shape* pcshape[MY_SHAPE_ARRAY_SIZE];
	static int index;
	POINT pt;
	HPEN hPenOld, hPen;
	int constXstart, constYstart, xstart, ystart, xend, yend;
	PAINTSTRUCT ps;
	HDC hdc;
	bool isEditing;

public:
	ShapeEditor(void);
	void OnLBdown(HWND);
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
	void ShiftStartPoint();
};
