#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "editor.h"
#include "point_editor.h"
#include "line_editor.h"
#include "rect_editor.h"
#include "ellipse_editor.h"

ShapeObjectsEditor::ShapeObjectsEditor(void) {}
ShapeObjectsEditor::~ShapeObjectsEditor() {}

void ShapeObjectsEditor::StartPointEditor(HWND hWnd)
{
	if (pse) delete pse;
	pse = new PointEditor;
	SetWindowText(hWnd, L"����� ����� �����");
}

void ShapeObjectsEditor::StartLineEditor(HWND hWnd)
{
	if (pse) delete pse;
	pse = new LineEditor;
	SetWindowText(hWnd, L"����� ����� ���");
}

void ShapeObjectsEditor::StartRectEditor(HWND hWnd)
{
	if (pse) delete pse;
	pse = new RectEditor;
	SetWindowText(hWnd, L"����� ����� ������������");
}

void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd)
{
	if (pse) delete pse;
	pse = new EllipseEditor;
	SetWindowText(hWnd, L"����� ����� �����");
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd) 
{
	if (pse) pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd) 
{
	if (pse) pse->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd) 
{
	if (pse) pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd) 
{
	if (pse) pse->OnPaint(hWnd);
}

