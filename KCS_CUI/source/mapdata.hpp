#ifndef KCS_KAI_MAPDATA_H_
#define KCS_KAI_MAPDATA_H_

class MapData {
	vector<vector<Fleet>> fleet_;				//�e�}�X���Ƃ̊͑��f�[�^
	vector<SimulateMode> simulate_mode_;		//�e�}�X���Ƃ̐퓬�`��
	vector<string> point_name_;					//�e�}�X�̖��O
public:
	// �R���X�g���N�^
	MapData(const string &file_name, const WeaponDB &weapon_db, const KammusuDB &kammusu_db);
	// getter
	size_t GetSize() const noexcept;
	Fleet GetFleet(const size_t) const noexcept;
	// ���̑�
	void Put();	//���e��\������
};

#endif
