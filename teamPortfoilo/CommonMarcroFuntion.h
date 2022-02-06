#pragma once
//CommonMacroFunction: 필요한 함수는 직접 만들어 추가하자

inline POINT pointMake(int x, int y)
{
	POINT pt = { x, y };
	return pt;
}

//선그리기
inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY) {
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

//RECT 만들기
inline RECT RectMake(int x, int y, int width, int height) {
	RECT rc = { x,y, x + width, y + height };
	return rc;
}

//RECT 중심점에 만들기
inline RECT RectMakeCenter(int x, int y, int width, int height) {
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
	return rc;
}

//사각형 그리기(렉탱글 함수 사용)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height) {
	Rectangle(hdc, x, y, x + width, y + height);
}

//타원 그리기 (Ellipse() 함수 사용)
inline void EllipaseMake(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}