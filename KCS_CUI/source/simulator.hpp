﻿#pragma once

// 制空状態(制空権確保・航空優勢・制空拮抗・航空劣勢・制空権喪失)
enum AirWarStatus { kAirWarStatusBest, kAirWarStatusGood, kAirWarStatusNormal, kAirWarStatusBad, kAirWarStatusWorst};

// 戦闘フェーズ(航空戦・開幕雷撃・砲撃戦・雷撃戦・夜戦)
enum BattlePhase{ kBattlePhaseAir, kBattlePhaseFirstTorpedo, kBattlePhaseGun, kBattlePhaseTorpedo, kBattlePhaseNight };

// 陣形(同航戦・反航戦・丁字有利・丁字不利)
enum BattlePosition{ kBattlePositionSame, kBattlePositionReverse, kBattlePositionGoodT, kBattlePositionBadT };

class Fleet;
#include "result.hpp"
#include "random.hpp"
class Simulator {
	vector<Fleet> fleet_;	//シミュレーションに使用する艦隊
	Result result_;			//シミュレーション結果を保存するクラス
	SharedRand rand;
	// 各フェーズ
	bitset<kBattleSize> SearchPhase();
	tuple<AirWarStatus, vector<double>> AirWarPhase(const bitset<kBattleSize>&);
	// 計算用メソッド(内部)
	AirWarStatus JudgeAirWarStatus(const bitset<kBattleSize>&, const vector<int>&);	//制空状態を判断する
	int CalcDamage(
		const BattlePhase&, const int&, const vector<int>&, const vector<int>&,		//与えるダメージ量を計算する
		const int&, const vector<double>&, const BattlePosition&);
public:
	// コンストラクタ
	Simulator(){}
	Simulator(const vector<Fleet> &fleet, const unsigned int seed);
	SharedRand GetGenerator() noexcept { return this->rand; }
	// 計算用メソッド
	Result Calc();
};
