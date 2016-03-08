#include "base.hpp"
#include "fleet.hpp"
#include "mapdata.hpp"

// �R���X�g���N�^
MapData::MapData(const string &file_name, const WeaponDB &weapon_db, const KammusuDB &kammusu_db) {
	// �t�@�C����ǂݍ���
	ifstream fin(file_name);
	FILE_THROW_WITH_MESSAGE_IF(!fin.is_open(), "�}�b�v�f�[�^������ɓǂݍ��߂܂���ł���.")
	using picojson::object;
	picojson::value v;
	fin >> v;
	// �ǂݍ���JSON�f�[�^����͂���
	auto& o = v.get<object>();
	for (auto &it : o) {
		if (it.first == "version") continue;
		cout << it.first << endl;
	}
	return;
}

//���e��\������
void MapData::Put() {

}
