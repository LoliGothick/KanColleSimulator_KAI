#pragma once

#include "weapon.hpp"
#include "kammusu.hpp"

// ����DB
class WeaponDB {
	unordered_map<int, Weapon> hash_;
public:
	// �R���X�g���N�^
	WeaponDB();
	// �n�b�V������f�[�^��ǂ݂���
	Weapon Get(const int) const;
};

// �͖�DB
class KammusuDB {
	unordered_map<int, Kammusu> hash_lv1_;
	unordered_map<int, Kammusu> hash_lv99_;
public:
	// �R���X�g���N�^
	KammusuDB();
	// �n�b�V������f�[�^��ǂ݂���
	Kammusu Get(const int, const int) const;
};

// ��������f���~�^�ŋ�؂蕪������
vector<string> Split(const string, const char);

// ������z��𐔎��z��ɕϊ�����
vector<int> ToInt(const vector<string>);

// �z����n�b�V���ɕϊ�����
template<typename T>
unordered_map<T, size_t> ToHash(const vector<T>&);
