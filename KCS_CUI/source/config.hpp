#pragma once

// �w�`
enum Formation { kFormationTrail, kFormationSubTrail, kFormationCircle, kFormationEchelon, kFormationAbreast };
const string kFormationStr[] = { "�P�c�w", "���c�w", "�֌`�w", "��`�w", "�P���w" };

// �ݒ�N���X
class Config {
	vector<string> input_filename_;	//���̓t�@�C����
	vector<Formation> formation_;	//�w�`�w��
	int times_;		//���s��
	int threads_;	//�X���b�h��
	string output_filename_;	//�o�̓t�@�C����
public:
	// �R���X�g���N�^
	Config(int argc, char *argv[]);
	// ���g��\������
	void Put() const;
};
