#include "base.hpp"
#include "config.hpp"

// �R���X�g���N�^
Config::Config(int argc, char *argv[]) {
	if (argc < 4) {
		throw "�����̐�������Ă��܂���.";
	}
	// �e�I�v�V�����̃f�t�H���g�l��ݒ肷��
	input_filename_.resize(kBattleSize);
	formation_.resize(kBattleSize);
	fill(formation_.begin(), formation_.end(), kFormationTrail);
	times_ = 1;
	threads_ = 1;
	// �I�v�V�����̕������ǂݍ���
	for (auto i = 1; i < argc; ++i) {
		// ��Ustring�ɗ��Ƃ�����
		string temp(argv[i]);
		// �I�v�V�����p������Ȃ�A�e�I�v�V�����ɔ��f������
		if (temp == "-i") {
			// ���̓t�@�C����
			if (argc - i <= 2) throw "�R�}���h���C���������ُ�ł�.";
			input_filename_[0] = argv[i + 1];
			input_filename_[1] = argv[i + 2];
			i += 2;
		}
		else if (temp == "-f") {
			// �w�`
			if (argc - i <= 2) throw "�R�}���h���C���������ُ�ł�.";
			formation_[0] = static_cast<Formation>(stoi(argv[i + 1]));
			formation_[1] = static_cast<Formation>(stoi(argv[i + 2]));
			i += 2;
		}
		else if (temp == "-n") {
			// ���s��
			if (argc - i <= 1) throw "�R�}���h���C���������ُ�ł�.";
			times_ = stoi(argv[i + 1]);
			if (times_ <= 0) times_ = 1;
			++i;
		}
		else if (temp == "-t") {
			// ���s�X���b�h��
			if (argc - i <= 1) throw "�R�}���h���C���������ُ�ł�.";
			threads_ = stoi(argv[i + 1]);
			if (threads_ <= 0) threads_ = 1;
			++i;
		}
		else if (temp == "-o") {
			// �o�̓t�@�C����
			if (argc - i <= 1) throw "�R�}���h���C���������ُ�ł�.";
			output_filename_ = argv[i + 1];
			++i;
		}
	}
	// ���̓t�@�C�����͕K�{�ł��邱�Ƃɒ��ӂ���
	if (input_filename_[0] == "" && input_filename_[1] == "") {
		throw "���̓t�@�C�����͕K���w�肵�Ă�������.";
	}
}

// ���g��\������
void Config::Put() const{
	cout << "���̓t�@�C�����F\n";
	for (auto &it : input_filename_) {
		cout << "�@" << it << "\n";
	}
	cout << "�w�`�w��F\n";
	for (auto &it : formation_) {
		cout << "�@" << kFormationStr[it] << "\n";
	}
	cout << "���s�񐔁F" << times_ << "\n";
	cout << "�X���b�h���F" << threads_ << "\n";
	cout << "�o�̓t�@�C�����F\n�@" << (output_filename_ != "" ? output_filename_ : "<�Ȃ�>") << "\n";
}
