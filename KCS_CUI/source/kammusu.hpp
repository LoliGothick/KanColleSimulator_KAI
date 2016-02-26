#pragma once

#include "weapon.hpp"

// �͎�(�����ȒԂ��Ship Classifications�ł���)
// �������A���V�v�ǁE��q�v�ǁE���n���S/�P�E������S�́u�d���m�́v�A
// �������S�́u�q�󏄗m�́v�A���b���S/�P�E��̓����́u�q���́v�A
// �H�ÏF�́u����@��́v�J�e�S���ɓ���Ă���
enum ShipClass {
	kShipClassPT = 1, kShipClassDD, kShipClassCL, kShipClassCLT,
	kShipClassCA, kShipClassCAV, kShipClassCVL, kShipClassCC, kShipClassBB,
	kShipClassBBV, kShipClassCV, kShipClassAF, kShipClassSS, kShipClassSSV,
	kShipClassLST, kShipClassAV, kShipClassLHA, kShipClassACV, kShipClassAR,
	kShipClassAS, kShipClassCP, kShipClassAO
};
const string kShipClassStr[] = { "", "������", "�쒀��", "�y���m��", "�d�������m��",
"�d���m��", "�q�󏄗m��", "�y���", "���m���", "���", "�q����", "���K���",
"����^", "������", "�������", "�A����", "����@���", "�g����", "���b���",
"�H���", "�������", "���K���m��", "������"
};

// ����
enum Speed { kSpeedNone, kSpeedLow, kSpeedHigh };
const string kSpeedStr[] = { "��", "�ᑬ", "����" };

// �͖��N���X
class Kammusu {
	// �ύX���Ȃ�����
	int id_;						//�͑DID
	string name_;					//�͖�
	ShipClass shipclass_;			//�͎�
	int max_hp_;					//�ő�ϋv
	int defense_;					//���b
	int attack_;					//�Η�
	int torpedo_;					//����
	int anti_air_;					//�΋�
	int luck_;						//�^
	Speed speed_;					//����
	Range range_;					//�˒�
	int slots_;						//�X���b�g��
	vector<int> max_airs_;			//�ő哋�ڐ�
	int evade_;						//���
	int anti_sub_;					//�ΐ�
	int search_;					//���G
	vector<int> first_weapons_;		//��������
	bool kammusu_flg_;				//�͖��t���O
	int level_;						//���x��(���x)
	// �ύX�������
	int hp_;					//���ϋv
	vector<int> airs_;			//�����ڐ�
	vector<Weapon> weapons_;	//������
	int cond_;					//cond�l
	int ammo_;					//�c�e�򊄍�
	int fuel_;					//�c�R������
public:
	// �R���X�g���N�^
	Kammusu();
	Kammusu(
		const int, const string, const ShipClass, const int, const int, const int, const int,
		const int, const int, const Speed, const Range, const int, const vector<int>, const int,
		const int, const int, const vector<int>, const bool, const int);
	// ���g��\������
	void Put();
	// �ύX�ȕ��������Z�b�g����
	Kammusu Reset();
//	Kammusu Reset(const WeaponDB&);
};

// ������𑬗͂ɕϊ�����
Speed ToSpeed(const string&);
