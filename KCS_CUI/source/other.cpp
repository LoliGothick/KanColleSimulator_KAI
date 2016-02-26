#include "base.hpp"
#include "other.hpp"

// ����DB�̃R���X�g���N�^
WeaponDB::WeaponDB() {
	// �t�@�C�����J��
	ifstream ifs("slotitems.csv");
	if (!ifs.is_open()) throw "slotitems.csv������ɓǂݍ��߂܂���ł���.";
	// 1�s�Âǂݍ���ł���
	string temp_str;
	getline(ifs, temp_str);
	auto header = ToHash(Split(temp_str, ','));
	while (getline(ifs, temp_str)) {
		auto list         = Split(temp_str, ',');
		auto id           = stoi(list[header.at("����ID")]);
		auto name         = list[header.at("������")];
		auto weapon_class = ToWC(list[header.at("���")]);
		auto defense      = stoi(list[header.at("���b")]);
		auto attack       = stoi(list[header.at("�Η�")]);
		auto torpedo      = stoi(list[header.at("����")]);
		auto bomb         = stoi(list[header.at("����")]);
		auto anti_air     = stoi(list[header.at("�΋�")]);
		auto anti_sub     = stoi(list[header.at("�ΐ�")]);
		auto hit          = stoi(list[header.at("����")]);
		auto evade        = stoi(list[header.at("���")]);
		auto search       = stoi(list[header.at("���G")]);
		auto range        = static_cast<Range>(stoi(list[header.at("�˒�")]));
		auto level        = 0;
		Weapon temp_w(
			id, name, weapon_class, defense, attack, torpedo, bomb, anti_air,
			anti_sub, hit, evade, search, range, level);
		hash_[id] = temp_w;
	}
	// �_�~�[�f�[�^��������
	hash_[-1] = Weapon();
}

// ����DB����f�[�^��ǂ݂���
Weapon WeaponDB::Get(const int id) const{
	if (hash_.find(id) != hash_.end()) {
		return hash_.at(id);
	}
	else {
		return hash_.at(-1);
	}
}

// �͖�DB�̃R���X�g���N�^
KammusuDB::KammusuDB() {
	// �t�@�C�����J��
	ifstream ifs("ships.csv");
	if (!ifs.is_open()) throw "ships.csv������ɓǂݍ��߂܂���ł���.";
	// 1�s�Âǂݍ���ł���
	string temp_str;
	getline(ifs, temp_str);
	auto header = ToHash(Split(temp_str, ','));
	while (getline(ifs, temp_str)) {
		// �܂�Lv1�̕���������
		auto list = Split(temp_str, ',');
		auto id = stoi(list[header.at("�͑DID")]);
		auto name = list[header.at("�͖�")];
		auto shipclass = static_cast<ShipClass>(stoi(list[header.at("�͎�")]));
		auto max_hp = stoi(Split(list[header.at("�ϋv")], '.')[0]);
		auto defense = stoi(Split(list[header.at("���b")], '.')[0]);
		auto attack = stoi(Split(list[header.at("�Η�")], '.')[0]);
		auto torpedo = stoi(Split(list[header.at("����")], '.')[0]);
		auto anti_air = stoi(Split(list[header.at("�΋�")], '.')[0]);
		auto luck = stoi(Split(list[header.at("�^")], '.')[0]);
		auto speed = ToSpeed(list[header.at("����")]);
		auto range = static_cast<Range>(stoi(list[header.at("�˒�")]));
		auto slots = stoi(list[header.at("�X���b�g��")]);
		auto max_airs = ToInt(Split(list[header.at("���ڐ�")], '.'));
		auto evade = stoi(Split(list[header.at("���")], '.')[0]);
		auto anti_sub = stoi(Split(list[header.at("�ΐ�")], '.')[0]);
		auto search = stoi(Split(list[header.at("���G")], '.')[0]);
		auto first_weapons = ToInt(Split(list[header.at("��������")], '.'));
		auto kammusu_flg = (stoi(list[header.at("�͖��t���O")]) == 1);
		Kammusu temp_k1(id, name, shipclass, max_hp, defense, attack, torpedo, anti_air, luck, speed,
			range, slots, max_airs, evade, anti_sub, search, first_weapons, kammusu_flg, 1);
		hash_lv1_[id] = move(temp_k1);
		// ����Lv99�̕�����������
		defense = stoi(Split(list[header.at("���b")], '.')[1]);
		attack = stoi(Split(list[header.at("�Η�")], '.')[1]);
		torpedo = stoi(Split(list[header.at("����")], '.')[1]);
		anti_air = stoi(Split(list[header.at("�΋�")], '.')[1]);
		evade = stoi(Split(list[header.at("���")], '.')[1]);
		anti_sub = stoi(Split(list[header.at("�ΐ�")], '.')[1]);
		search = stoi(Split(list[header.at("���G")], '.')[1]);
		Kammusu temp_k2(id, name, shipclass, max_hp, defense, attack, torpedo, anti_air, luck, speed,
			range, slots, max_airs, evade, anti_sub, search, first_weapons, kammusu_flg, 99);
		hash_lv99_[id] = move(temp_k2);
	}
	// �_�~�[�f�[�^��������
	hash_lv1_[-1] = Kammusu();
	hash_lv99_[-1] = Kammusu();
}

// �͖�DB����f�[�^��ǂ݂���
// id�Ŏw�肵���͐�ID�͖̊����A���x����level�̏�Ԃɂ��ĕԂ�
Kammusu KammusuDB::Get(const int id, const int level) const {
	if (hash_lv99_.find(id) != hash_lv99_.end()) {
		return hash_lv99_.at(id);
	}
	else {
		return hash_lv99_.at(-1);
	}
}

// ��������f���~�^�ŋ�؂蕪������
vector<string> Split(const string str, const char delim) {
	vector<string> list;
	std::istringstream iss(str);
	string temp;
	while (getline(iss, temp, delim)) {
		list.push_back(temp);
	}
	return move(list);
}

// ������z��𐔎��z��ɕϊ�����
vector<int> ToInt(const vector<string> arr_str) {
	vector<int> arr_int;
	for (auto &it : arr_str) {
		arr_int.push_back(stoi(it));
	}
	return move(arr_int);
}

// �z����n�b�V���ɕϊ�����
template<typename T>
unordered_map<T, size_t> ToHash(const vector<T> &vec) {
	unordered_map<T, size_t> hash;
	for (auto i = 0u; i < vec.size(); ++i) {
		hash[vec[i]] = i;
	}
	return move(hash);
}
