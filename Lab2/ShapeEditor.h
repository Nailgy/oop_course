#pragma once
#include "editor.h"
#include "shape.h"
#define MY_SHAPE_ARRAY_SIZE 116

class ShapeEditor : public Editor {
protected:
	static Shape* pcshape[MY_SHAPE_ARRAY_SIZE];
	static int index;
	POINT pt;
	int xstart, ystart, xend, yend;
	HMENU hMenu, hSubMenu;
	PAINTSTRUCT ps;
	HDC hdc;
	bool isEditing;

public:
	ShapeEditor(void);
	void OnLBdown(HWND);
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
};
