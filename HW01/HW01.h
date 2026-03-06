#pragma once
/* ========================================================
*  HW01: 상태창 구현 
*  ========================================================
*  1번 과제 구현 | 목표 / 핵심 / 활용 / 기능
*  --------------------------------------------------------
*  1.학습 목표:
*  - C++의 기본 문법을 이해/활용
*  - 배열 및 함수를 사용하여 데이터를 처리
*  - 사용자 입력을 받아 출력하는 간단한 프로그램 설계 및 구현
* 
*  2.과제 핵심:
*  - 사용자의 선택에 따른 캐릭터 상태가 변하는 게임 로직을 익힘
*  - 이후 언리얼 엔진에서 캐릭터의 상태 시스템을 만들기 위한 첫걸음!
*  
*  3.활용 범위:
*  - 언리얼 엔진 - 게임 오브젝트의 상태관리의 토대
*  - 게임 로직을 모듈화하는 것의 기반이 됨
*  
*  4.구현 기능
*  = _ESSENTIAL: 필수 기능
*  = _CHALLNEGE: 필수 + 도전 기능 
   ========================================================*/

// 튜토님 질문란
/* 
* Q: 전역 변수 사용에 관하여
* setPotion 함수의 매개변수 count를 "메뉴 선택 변수"로 선언하니 다른 변수들을 안에 넣을 수 없었습니다.
* 그래서 전역 변수로 int형 배열 선언 후, 그 값들을 직접 불러오도록 했습니다.
* 여기에서, "전역 변수"는 "변하지 않는 상수값"을 의미하는 바가 높기에, 값이 바뀌는 변수를 전역 변수로 사용해도 괜찮은가?
* A: "지금" 사용하는 것에는 별 문제 없다. 조건에도 없으니, 사용하는 것은 자유.
* 그러나 본인이 고민하고 있는 부분들이 어느 정도는 맞기에, 나중에 사용할 때에는 "클래스" 형태로 변수를 안전하게 사용할 수 있게 하는 것이 좋다.
* 결론: 사용하는 것은 괜찮다. 그래도 나중엔 전역 변수보단 Class 내부에 변수를 만드는 것이 좋다.
 */



#include <iostream>
using namespace std;

// ==============[  1. 필수 기능 구현 코드   ]================
// 필수 구현 기능
// 1) 캐릭터 스탯 상자 만들기
// 2) 깐깐한 입력 검사
// 3) 스탯 관리 시스템1 : 메뉴 무한 루프
// 4) 스탯 관리 시스템2 : 포션 시스템
// ========================================================

#ifdef RUN_HW01_ESSENTIAL
// 전역 변수(setPotion 함수에 넣기 위함)
// 핵심 변수를 받아들이기 위한 공간(배열) 선언 및 초기화
int status[4] = { 0, };

// 각 배열에 맞는 이름들로 참조하기
int& HP = status[0];
int& MP = status[1];
int& Strenth = status[2];
int& Defense = status[3];

// setPotion 함수 -> 번호에 따라 상호작용하고 출력합니다.
void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	switch (count)
	{
	case 1:
		if (*p_HPPotion > 0)
		{
			cout << "* HP 증가! (+20) 포션이 1개 차감됩니다." << endl;
			HP += 20;
			--(*p_HPPotion);
			cout << "현재 HP: " << HP << endl;
			cout << "남은 HP 포션: " << *p_HPPotion << endl;
		}
		else
		{
			cout << "더 이상의 HP 포션이 남아있지 않습니다!" << endl;
		}

		break;
	case 2:
		if (*p_MPPotion > 0)
		{
			cout << "* MP 증가! (+20) 포션이 1개 차감됩니다." << endl;
			MP += 20;
			--(*p_MPPotion);
			cout << "현재 MP: " << MP << endl;
			cout << "남은 MP 포션: " << *p_MPPotion << endl;
		}
		else
		{
			cout << "더 이상의 MP 포션이 남아있지 않습니다!" << endl;
		}
		break;

	case 3:
		cout << "* 공격력 2배 증가!" << endl;
		Strenth *= 2;
		cout << "현재 공격력: " << Strenth << endl;
		break;

	case 4:
		cout << "* 방어력 2배 증가!" << endl;
		Defense *= 2;
		cout << "현재 방어력: " << Defense << endl;
		break;

	case 5:
		cout << "* 현재 캐릭터의 능력치를 확인합니다 *" << endl;
		cout << "HP: " << HP << endl;
		cout << "MP: " << MP << endl;
		cout << "공격력: " << Strenth << endl;
		cout << "방어력: " << Defense << endl;
		break;

	case 6:
		cout << "* 레벨 업!" << endl;
		cout << "* 당신의 허리춤에 있는 가방에 포션이 생성되는 것을 느낍니다." << endl;

		++(*p_HPPotion);
		++(*p_MPPotion);
		cout << "남은 HP/MP 포션 수:  " << *p_HPPotion << "/" << *p_MPPotion << endl;
		break;

	case 0:
		cout << "당신의 밖을 향해 나아갑니다.." << endl;
		break;
	default:
		break;
	}
}

int main()
{
	// 1.HP/MP 입력 (둘 중에 하나라도 50 이하면, 다시 입력합니다)
	cout << "당신의 상태창에 오신것을 환영합니다." << endl;
	cout << "HP와 MP를 입력하세요: ";
	cin >> HP;
	cin >> MP;

	while (HP <= 50 || MP <= 50)
	{
		cout << "당신은 그렇게 약하지 않습니다." << endl;
		cout << "다시 한번." << endl;
		cout << "HP와 MP를 입력하세요: ";
		cin >> HP;
		cin >> MP;
		cout << endl;
	}
	cout << "잘 하셨습니다." << endl << endl;;

	// 2.공격력/방어력 입력 (둘 중에 하나라도 0 이하면, 다시 입력합니다)
	cout << "이번엔 공격력과 방어력을 입력해보세요: ";
	cin >> Strenth;
	cin >> Defense;

	while (Strenth <= 0 || Defense <= 0)
	{
		cout << "당신은 그렇게 약하지 않습니다." << endl;
		cout << "다시 한번." << endl;
		cout << "공격력과 방어력을 입력하세요: ";
		cin >> Strenth;
		cin >> Defense;
		cout << endl;
	}
	cout << "당신의 캐릭터를 생성했습니다." << endl;

	// a. 기초 포션 추가하기(각 5개씩)
	cout << "이에 대한 보상으로 HP포션과 MP포션을 5개씩 드리겠습니다." << endl << endl;
	int HPPotion = 5;
	int MPPotion = 5;
	cout << "* 포션이 지급되었습니다 *" << endl;
	cout << "이제, 선택할 시간입니다.." << endl;
	cout << "원하시는 번호를 입력하여 당신의 캐릭터를 성장시키십시오." << endl;
	cout << endl;

	// 3. 매뉴판 생성
	cout << "===================================\"[   선택창   ]\"===================================" << endl;
	cout << "   1.HP UP!               2.MP UP!            3.공격력 UP!              4.방어력 UP!" << endl;
	cout << "   5.현재 능력치 보기       6.LEVEL UP!         0.나가기.." << endl;
	cout << "=======================================================================================" << endl;

	int Select = 10;
	while (Select != 0)
	{
		cout << endl;
		cout << "번호를 입력하십시오(숫자만 입력): ";
		cin >> Select;
		setPotion(Select, &HPPotion, &MPPotion);
	}
	cout << "---------------------------------------------------------------------------------------" << endl;

	return 0;
}
#endif


// =============================[  2. 도전 기능 구현 코드   ]==================================
// 도전 구현 기능
// 0) 필수 구현 기능 포함
// 1) 레벨 시스템 추가: Level 변수 - 6번(Level up!)을 누를 때마다 레벨도 1 상승
// 2) 함수 활용: 포션을 충전하는 기능 - 별도의 함수로 분리
// 3) 스탯 정보 추가1: 5번(현재 능력치) 선택 시 현재 레벨을 함께 표시
// 4) 스탯 정보 추가2: 3)번과 동일하게, 남은 포션 개수도 표시
// 5) 확장: 공격력/방어력 외 힘, 민첩, 지능 등 자신만의 스탯 추가
// + 확장 방법
// - 레벨 1 오르면 능력 포인트 3개를 준다. 포인트는 확장한 스탯에 올릴 수 있다. 포인트 1개 당 5씩 오른다.
// =========================================================================================

#ifdef RUN_HW01_CHALLENGE
// 전역 변수(setPotion 함수에 넣기 위함)
// 핵심 변수를 받아들이기 위한 공간(배열) 선언 및 초기화
int status[4] = { 0, };

// 각 배열에 맞는 이름들로 참조하기
int& HP = status[0];
int& MP = status[1];
int& Attack = status[2];
int& Defense = status[3];

// 확장 스탯
int statusP[3] = {5,5,5};

int& Strenth = statusP[0];
int& Haste = statusP[1];
int& Intelligence = statusP[2];

// 레벨 변수
int Level = 1;
int StatPoint = 3;

// setPotion 함수 -> 번호에 따라 상호작용하고 출력합니다.
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
// 포션을 충전하는 함수
int plusPotion(int* Potion);
// 확장 능력을 선택하는 함수
void selectStatusPoint(int select);

int main()
{
	// 1.HP/MP 입력 (둘 중에 하나라도 50 이하면, 다시 입력합니다)
	cout << "당신의 상태창에 오신것을 환영합니다." << endl;
	cout << "HP와 MP를 입력하세요: ";
	cin >> HP;
	cin >> MP;

	while (HP <= 50 || MP <= 50)
	{
		cout << "당신은 그렇게 약하지 않습니다." << endl;
		cout << "다시 한번." << endl;
		cout << "HP와 MP를 입력하세요: ";
		cin >> HP;
		cin >> MP;
		cout << endl;
	}
	cout << "잘 하셨습니다." << endl << endl;;

	// 2.공격력/방어력 입력 (둘 중에 하나라도 0 이하면, 다시 입력합니다)
	cout << "이번엔 공격력과 방어력을 입력해보세요: ";
	cin >> Attack;
	cin >> Defense;

	while (Attack <= 0 || Defense <= 0)
	{
		cout << "당신은 그렇게 약하지 않습니다." << endl;
		cout << "다시 한번." << endl;
		cout << "공격력과 방어력을 입력하세요: ";
		cin >> Attack;
		cin >> Defense;
		cout << endl;
	}
	cout << "당신의 캐릭터를 생성했습니다." << endl;

	// a. 기초 포션 추가하기(각 5개씩)
	cout << "이에 대한 보상으로 HP포션과 MP포션을 5개씩 드리겠습니다." << endl << endl;
	int HPPotion = 5;
	int MPPotion = 5;
	cout << "* 포션이 지급되었습니다 *" << endl;
	cout << "이제, 선택할 시간입니다.." << endl;
	cout << "원하시는 번호를 입력하여 당신의 캐릭터를 성장시키십시오." << endl;
	cout << endl;

	// 3. 매뉴판 생성
	cout << "===================================\"[   선택창   ]\"===================================" << endl;
	cout << "   1.HP UP!               2.MP UP!            3.공격력 UP!              4.방어력 UP!" << endl;
	cout << "   5.현재 능력치 보기       6.LEVEL UP!         7. 능력 포인트				0.나가기.." << endl;
	cout << "=======================================================================================" << endl;

	int Select = 10;
	while (Select != 0)
	{
		cout << endl;
		cout << "번호를 입력하십시오(숫자만 입력): ";
		cin >> Select;
		setPotion(Select, &HPPotion, &MPPotion);
	}
	cout << "---------------------------------------------------------------------------------------" << endl;


	return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	switch (count)
	{
	case 1:		// HP 20 증가
		if (*p_HPPotion > 0)
		{
			cout << "* HP 증가! (+20) 포션이 1개 차감됩니다." << endl;
			HP += 20;
			--(*p_HPPotion);
			cout << "현재 HP: " << HP << endl;
			cout << "남은 HP 포션: " << *p_HPPotion << endl;
		}
		else
		{
			cout << "더 이상의 HP 포션이 남아있지 않습니다!" << endl;
		}

		break;
	case 2:		// MP 20 증가
		if (*p_MPPotion > 0)
		{
			cout << "* MP 증가! (+20) 포션이 1개 차감됩니다." << endl;
			MP += 20;
			--(*p_MPPotion);
			cout << "현재 MP: " << MP << endl;
			cout << "남은 MP 포션: " << *p_MPPotion << endl;
		}
		else
		{
			cout << "더 이상의 MP 포션이 남아있지 않습니다!" << endl;
		}
		break;

	case 3:		// 공격력 2배 증가
		cout << "* 공격력 2배 증가!" << endl;
		Attack *= 2;
		cout << "현재 공격력: " << Attack << endl;
		break;

	case 4:		// 방어력 2배 증가
		cout << "* 방어력 2배 증가!" << endl;
		Defense *= 2;
		cout << "현재 방어력: " << Defense << endl;
		break;

	case 5:		// 현재 능력치 확인
		cout << "* 현재 캐릭터의 능력치를 확인합니다 *" << endl;
		cout << "현재 Level: " << Level << endl;
		cout << "HP: " << HP << endl;
		cout << "MP: " << MP << endl;
		cout << "공격력: " << Attack << endl;
		cout << "방어력: " << Defense << endl;
		cout << "힘: " << Strenth << endl;
		cout << "민첩: " << Haste << endl;
		cout << "지능: " << Intelligence << endl;
		cout << "현재 HP/MP 포션 수:  " << *p_HPPotion << "/" << *p_MPPotion << endl;
		cout << "남은 능력 포인트: " << StatPoint << endl;
		break;

	case 6:		// 레벨 증가, 포션 증가, 확장 능력 포인트 3 증가
		cout << "* 레벨 업!" << endl;
		++Level;
		StatPoint += 3;
		// 함수를 이용한 포션 충전
		*p_HPPotion = plusPotion(p_HPPotion);
		*p_MPPotion = plusPotion(p_MPPotion);
		// 현재 레벨, 능력 포인트, 포션 수 출력
		cout << "현재 Level: " << Level << endl;
		cout << "현재 능력 포인트:  " << StatPoint << endl;
		cout << "* 당신의 허리춤에 있는 가방에 포션이 생성되는 것을 느낍니다." << endl;
		cout << "현재 HP/MP 포션 수:  " << *p_HPPotion << "/" << *p_MPPotion << endl;
		break;
	case 7:		// 확장 능력 포인트 사용
		// 능력 포인트가 있어야 확장 능력치를 올릴 수 있다.
		if (StatPoint == 0)
		{
			cout << "사용할 수 있는 포인트가 부족합니다!" << endl;
			cout << "레벨을 올린 다음 다시 오십시오." << endl;
		}
		else
		{
			selectStatusPoint(count);
		}
		break;
	case 0:
		cout << "당신의 밖을 향해 나아갑니다.." << endl;
		break;
	default:
		cout << "당신의 언어를 이해하지 못했습니다.." << endl;
		break;
	}
}
int plusPotion(int* Potion)
{
	++(*Potion);
	return *Potion;
}

void selectStatusPoint(int select)
{
	cout << "* 현재 능력 포인트: " << StatPoint << " *" << endl;
	cout << "올리고 싶은 능력을 선택하세요." << endl;
	while (select != 0) 
	{
		cout << "1: 힘    2: 민첩     3: 지능     0: 돌아간다" << endl;
		cout << "입력: ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "당신은 몸에 붉은 기운을 느낍니다." << endl;
			Strenth += 5;
			cout << "현재 당신의 힘: " << Strenth << endl;
			--StatPoint;
			break;
		case 2:
			cout << "당신은 몸에 신선한 기운을 느낍니다." << endl ;
			Haste += 5;
			cout << "현재 당신의 민첩: " << Haste << endl;
			--StatPoint;
			break;
		case 3:
			cout << "당신은 머리가 깨끗해짐을 느낍니다." << endl;
			Intelligence += 5;
			cout << "현재 당신의 지능: " << Intelligence << endl;
			--StatPoint;
			break;
		case 0:
			break;
		default:
			cout << "이해하지 못했습니다. " << endl << endl;
			break;
		}
		if (StatPoint <= 0)
		{
			cout << endl;
			cout << "소지한 모든 능력 포인트를 사용했습니다." << endl;
			cout << "메인 선택창으로 돌아옵니다." << endl;
			break;
		}
		else
		{
			cout << endl;
			cout << "* 남은 능력 포인트: " << StatPoint << " *" << endl;
		}
	}

}

#endif