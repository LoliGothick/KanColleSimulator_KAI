/* KanColleSimulator Ver.1.0 */

#include "base.hpp"
#include "config.hpp"
#include "weapon.hpp"
#include "kammusu.hpp"
#include "other.hpp"

int main(int argc, char *argv[]) {
	try {
		// ���݂̐ݒ���擾����
		Config config(argc, argv);
		config.Put();
		// �f�[�^�x�[�X��ǂݍ���
		WeaponDB weapon_db;
		weapon_db.Get(-1).Put();
		weapon_db.Get(1).Put();
		KammusuDB kammusu_db;
		kammusu_db.Get(-1, 1).Reset().Put();
		kammusu_db.Get(1, 1).Reset().Put();
//		kammusu_db.Get(1, 1).Reset(weapon_db).Put();
		kammusu_db.Get(1, 99).Reset().Put();
		kammusu_db.Get(1, 155).Reset().Put();
	}
	catch (char *e) {
		std::cerr << "�G���[�F" << e << std::endl;
	}
	return 0;
}
