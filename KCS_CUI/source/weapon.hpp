#pragma once

// ���
enum WeaponClass {
	kWeaponClassGun, kWeaponClassAP, kWeaponClassSubGun, kWeaponClassTorpedo, kWeaponClassSpecialSS,
	kWeaponClassPF, kWeaponClassPB, kWeaponClassPBF, kWeaponClassWB, kWeaponClassPA, kWeaponClassPS,
	kWeaponClassPSS, kWeaponClassDaiteiChan, kWeaponClassWS, kWeaponClassWSN, kWeaponClassASPP, kWeaponClassAJ,
	kWeaponClassSmallR, kWeaponClassLargeR, kWeaponClassAAG, kWeaponClassAAA, kWeaponClassAAD, kWeaponClassDP,
	kWeaponClassSonar, kWeaponClassDC, kWeaponClassSL, kWeaponClassLB, kWeaponClassHQ, kWeaponClassSSP,
	kWeaponClassCR, kWeaponClassOS, kWeaponClassOther
};
const vector<string> kWeaponClassStr = {
	"��C", "�Ί͋����e", "���C", "����", "������q��", "�͏�퓬�@", "�͏㔚���@","�͏㔚���@(����)", "���㔚���@",
	"�͏�U���@", "�͏��@�@", "�͏��@�@(�ʉ_)", "��^��s��", "�����@�@", "�����@�@(���)", "�ΐ������@",
	"�I�[�g�W���C��", "���^�d�T","��^�d�T", "�΋�@�e", "�΋󋭉��e", "���ˑ��u", "����", "�\�i�[", "���}�C���v��",
	"�T�Ɠ�", "�Ɩ��e", "�͑��i�ߕ��{��", "����͗v��", "�퓬�ƐH", "�m��⋋", "���̑�"
};

//�����N���X
class Weapon {
	int id_;					//����ID
	string name_;				//������
	WeaponClass weapon_class_;	//���
	int defense_;				//���b
	int attack_;				//�Η�
	int torpedo_;				//����
	int bomb_;					//����
	int anti_air_;				//�΋�
	int anti_sub_;				//�ΐ�
	int hit_;					//����
	int evade_;					//���
	int search_;				//���G
	Range range_;				//�˒�
	int level_;					//�������C�x(0-10)�A�����n���x(0-120)
public:
	// �R���X�g���N�^
	Weapon();
	Weapon(
		const int, const string, const WeaponClass, const int, const int, const int, const int,
		const int, const int, const int, const int, const int, const Range, const int);
	// ���g��\������
	void Put();
	// getter
	string Name() { return name_; }
};

// ���������ʂɕϊ�����
WeaponClass ToWC(const string);
