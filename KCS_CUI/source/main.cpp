﻿/* KanColleSimulator Ver.1.0 */

#include "base.hpp"
#include "config.hpp"
#include "other.hpp"
#include "fleet.hpp"

int main(int argc, char *argv[]) {
	try {
//		TIME_ELAPSED(
			// 現在の設定を取得する
			Config config(argc, argv);
			config.Put();
			// データベースを読み込む
			WeaponDB weapon_db;
			weapon_db.Get(-1).Put();
			weapon_db.Get(114).Put();
			KammusuDB kammusu_db;
			kammusu_db.Get(-1, 1).Reset(weapon_db).Put();
			kammusu_db.Get(178, 99).Reset(weapon_db).Put();
			// ファイルから艦隊を読み込む
			vector<Fleet> fleet(kBattleSize);
			for (auto i = 0; i < kBattleSize; ++i) {
				fleet[i] = Fleet(config.InputFilename(i), config.GetFormation(i), weapon_db, kammusu_db);
				fleet[i].Put();
			}
//		);
	}
	catch (char *e) {
		std::cerr << "エラー：" << e << std::endl;
	}
	return 0;
}
