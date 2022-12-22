#pragma once
#include "shape.h"
#include <string>
#define MY_SHAPE_ARRAY_SIZE 117

class MyEditor
{
private:
	static MyEditor* p_instance;
	MyEditor() {}
	MyEditor(const MyEditor&);
	MyEditor& operator=(MyEditor&);
	static Shape* pcshape[MY_SHAPE_ARRAY_SIZE];
	Shape* currentShape;
	static int index;
	POINT pt;
	bool isEditing;
	
public:
	~MyEditor();
	static MyEditor* getInstance();
	void Start(HWND, Shape*);
	void OnLBdown(HWND);
	std::wstring OnLBup(HWND);
	void RemoveItem(int);
	void OnMouseMove(HWND);
	void OnPaint(HWND, int);
};
