#pragma once
//====================================================
// Utils (간소화 시키고 싶은 로직 , 혹은 수학적 기능들을 모아둔 곳)
//====================================================

// 디그리 1도의 라디안 값
#define DEG_TO_RAD		0.017453f
#define PI				3.141592653f
#define PI_2			6.283185308f

/*
부동소수점 ->실수를 정확히 표현할 수 없다.
ㄴ 실수는 수학적으로 무한함..무한한 실수를 유한한 비트로 표현하려고 하니까 문제가 발생한 것이다.
ㄴ 컴퓨터는 어쩔 수 없이 근사값으로 표현한다.
ㄴ 근사값에 주 오류 원인 - Rounding Error 를 막기위해 epsilon 값을 이용
ㄴ 2D 좌표계에선 사람이 크게 인식을 못하지만 3D 좌표계에선 전혀 다른 결과가 발생한다.
*/

#define FLOAT_EPSILON		0.001f
//실수를 정수형으로 변환
#define FLOAT_TO_INT(f1)	static_cast<int>(f1+ FLOAT_EPSILON)
//두 실수가 같은지 비교
//ㄴ fabs는 소수점 차의 절대값 반환 (abs ->int)
#define FLOAT_EQUAL(f1,f2)	(fabs(f1-f2) <= FLOAT_EPSILON)

namespace MY_UTIL
{
	//두 점 사이의 거리를 구함
	float getDistance(float startX, float startY, float endX, float endY);
	//start 부터 end까지의 각을 구한다
	float getAngle(float startX, float startY, float endX, float endY);
}
