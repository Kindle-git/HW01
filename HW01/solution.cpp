#include <iostream>
using namespace std;

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


	return 0;
}