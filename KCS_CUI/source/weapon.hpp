﻿#ifndef KCS_KAI_INC_WEAPON_HPP_
#define KCS_KAI_INC_WEAPON_HPP_

#include <cstdint>
#include <iostream>
#include <type_traits>
// 種別
enum class WeaponClass : std::uint64_t {
	Gun        = 0x0000000000000001,	//主砲
	AP         = 0x0000000000000002,	//対艦強化弾
	SubGun     = 0x0000000000000004,	//副砲
	Torpedo    = 0x0000000000000008,	//魚雷
	SpecialSS  = 0x0000000000000010,	//特殊潜航艇
	PF         = 0x0000000000000020,	//艦上戦闘機
	PB         = 0x0000000000000040,	//艦上爆撃機
	PBF        = 0x0000000000000080,	//艦上爆撃機(爆戦)
	WB         = 0x0000000000000100,	//水上爆撃機
	PA         = 0x0000000000000200,	//艦上攻撃機
	PS         = 0x0000000000000400,	//艦上偵察機
	PSS        = 0x0000000000000800,	//艦上偵察機(彩雲)
	DaiteiChan = 0x0000000000001000,	//大型飛行艇
	WS         = 0x0000000000002000,	//水上偵察機
	WSN        = 0x0000000000004000,	//水上偵察機(夜偵)
	ASPP       = 0x0000000000008000,	//対潜哨戒機
	AJ         = 0x0000000000010000,	//オートジャイロ
	SmallR     = 0x0000000000020000,	//小型電探
	LargeR     = 0x0000000000040000,	//大型電探
	AAG        = 0x0000000000080000,	//対空機銃
	AAA        = 0x0000000000100000,	//対空強化弾
	AAD        = 0x0000000000200000,	//高射装置
	DP         = 0x0000000000400000,	//爆雷
	Sonar      = 0x0000000000800000,	//ソナー
	DC         = 0x0000000001000000,	//応急修理要員
	SL         = 0x0000000002000000,	//探照灯
	LB         = 0x0000000004000000,	//照明弾
	HQ         = 0x0000000008000000,	//艦隊司令部施設
	SSP        = 0x0000000010000000,	//水上艦要員
	CR         = 0x0000000020000000,	//戦闘糧食
	OS         = 0x0000000040000000,	//洋上補給
	WF         = 0x0000000080000000,	//水上戦闘機
	Other      = 0x8000000000000000,	//その他
	AirFight = PF | PBF | PB | WB | PA | WF,					//航空戦に参加する艦載機
	AirTrailer = PA | PS | PSS | DaiteiChan | WS | WSN | WF,	//触接に参加する艦載機
	AirBomb = PBF | PB | WB | PA,								//開幕爆撃に参加する艦載機
	Air = AirFight | AirTrailer,								//(熟練度が存在する)艦載機
};
constexpr inline auto operator|(const WeaponClass& l, const WeaponClass& r) { return static_cast<WeaponClass>(static_cast<std::underlying_type_t<WeaponClass>>(l) | static_cast<std::underlying_type_t<WeaponClass>>(r)); }
template<class E, class T>
inline auto& operator<<(std::basic_ostream<E, T>& os, const WeaponClass& wc) { return os << static_cast<std::underlying_type_t<WeaponClass>>(wc); }

//装備クラス
class Weapon {
	int id_;					//装備ID
	wstring name_;				//装備名
	WeaponClass weapon_class_;	//種別
	int defense_;				//装甲
	int attack_;				//火力
	int torpedo_;				//雷撃
	int bomb_;					//爆装
	int anti_air_;				//対空
	int anti_sub_;				//対潜
	int hit_;					//命中
	int evade_;					//回避
	int search_;				//索敵
	Range range_;				//射程
	int level_;					//装備改修度(0-10)、外部熟練度(0-7)
	int level_detail_;			//内部熟練度(0-120)
	int air_;					//現搭載数
	// キャッシュ
	double anti_air_bonus_;
public:
	// コンストラクタ
	Weapon() noexcept;
	Weapon(
		const int, wstring, const WeaponClass, const int, const int, const int, const int,
		const int, const int, const int, const int, const int, const Range, const int, const int, const int) noexcept;
	// getter
	int GetID() const noexcept;
	const std::wstring& GetName() const noexcept;
	WeaponClass GetWeaponClass() const noexcept;
	int GetDefense() const noexcept;
	int GetAttack() const noexcept;
	int GetTorpedo() const noexcept;
	int GetBomb() const noexcept;
	int GetAntiAir() const noexcept;
	int GetAntiSub() const noexcept;
	int GetHit() const noexcept;
	int GetEvade() const noexcept;
	int GetSearch() const noexcept;
	Range GetRange() const noexcept;
	int GetLevel() const noexcept;
	int GetAir() const noexcept;
	// setter
	void SetLevel(const int level);
	void SetLevelDetail(const int level_detail);
	void SetAir(const int air);
	// その他
	void Put() const;					//中身を表示する
	int AntiAirScore(const int&) const noexcept;	//制空値を計算する
	void AntiAirBonus_() noexcept;		//艦隊防空ボーナスを計算する
	double AntiAirBonus() const noexcept;
	// 指定のIDか判別する。
	bool AnyOf(const int test) const noexcept { return id_ == test; }
	// 指定の種別か判定する。
	bool AnyOf(const WeaponClass& wc) const noexcept { return (static_cast<std::underlying_type_t<WeaponClass>>(weapon_class_) & static_cast<std::underlying_type_t<WeaponClass>>(wc)) != 0; }
	// 指定の名前か判定する。名前は完全一致で比較する。
	template<class String, class = std::enable_if_t<std::is_same<String, std::wstring>::value>>		// 暗黙の型キャストにより非効率とならないようstd::wstringのみを受け付ける。
	bool AnyOf(const String& test) const noexcept { return std::size(name_) == std::size(test) && name_ == test; }	// 長さが一致した場合に限り文字列比較を行う。
	// 引数に指定された条件を満たすか判定する。引数はint型のID、WeaponClass型の種別、std::wstring型の名前のいずれでも指定できる。名前は完全一致で比較する。
	template<class Head, class... Rest>
	bool AnyOf(Head head, Rest... rest) const noexcept { return AnyOf(head) || AnyOf(rest...); }
	bool IsHAG() const noexcept;					//高角砲ならtrue
	friend std::ostream& operator<<(std::ostream& os, const Weapon& conf);
	friend std::wostream& operator<<(std::wostream& os, const Weapon& conf);
};
std::ostream& operator<<(std::ostream& os, const Weapon& conf);
std::wostream& operator<<(std::wostream& os, const Weapon& conf);

// 文字列を種別に変換する
WeaponClass ToWC(const string);

// 外部熟練度(Simple)を内部熟練度(Detail)に変換する
int ConvertStoD(const int&);

// 内部熟練度を外部熟練度に変換する
int ConvertDtoS(const int&);

#endif //KCS_KAI_INC_WEAPON_HPP_
