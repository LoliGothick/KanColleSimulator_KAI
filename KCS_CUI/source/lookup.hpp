#pragma once
#include <cstddef>		// std::size_t
#include <stdexcept>	// std::invalid_argument
#include <type_traits>	// std::add_const_t
#include <utility>		// std::get, std::tuple_element_t

/// <summary>�y�A�z��̒�����L�[���܂܂�Ă��邩���������܂��B</summary>
/// <param name="pairs">�y�A�z��Bstd::pair�z��Astd::tuple�z��Astd::array�z��̂����ꂩ���g���܂��B</param>
/// <param name="key">��������L�[�Bstd::pair�̏ꍇ��first�Astd::tuple��std::array�̏ꍇ�͍ŏ��̗v�f�Ɣ�r���܂��B</param>
/// <param name="i">�������J�n����C���f�b�N�X�B�ȗ������ꍇ�͐擪���猟�����܂��B</param>
/// <returns>�L�[���܂܂�Ă���ꍇ��true�B</returns>
/// <remarks>�^���_�ɂ��e���v���[�g�����͑S�ďȗ��\�ł��B</remarks>
template<class T, std::size_t N, class Key = std::add_const_t<std::tuple_element_t<0, T>>>
constexpr bool Contains(const T (&pairs)[N], Key& key, std::size_t i = 0) {
	return i != N && (std::get<0>(pairs[i]) == key || Contains(pairs, key, i + 1));
}

/// <summary>�y�A�z��̒�����L�[���������ŏ��Ɍ������l��Ԃ��܂��B������Ȃ������ꍇ�͎w�肳�ꂽ�f�t�H���g�l��Ԃ��܂��B</summary>
/// <param name="pairs">�y�A�z��Bstd::pair�z��Astd::tuple�z��Astd::array�z��̂����ꂩ���g���܂��B</param>
/// <param name="key">��������L�[�Bstd::pair�̏ꍇ��first�Astd::tuple��std::array�̏ꍇ�͍ŏ��̗v�f�Ɣ�r���܂��B</param>
/// <param name="defaultValue">������Ȃ������ꍇ�ɕԂ��f�t�H���g�l�B</param>
/// <param name="i">�������J�n����C���f�b�N�X�B�ȗ������ꍇ�͐擪���猟�����܂��B</param>
/// <returns>�ŏ��Ɍ������l�Bstd::pair�̏ꍇ��second�Astd::tuple��std::array�̏ꍇ�͂Q�Ԗڂ̗v�f�ɂȂ�܂��B������Ȃ������ꍇ�͎w�肳�ꂽ�f�t�H���g�l�B</returns>
/// <remarks>�^���_�ɂ��e���v���[�g�����͑S�ďȗ��\�ł��B</remarks>
template<class T, std::size_t N, class Key = std::add_const_t<std::tuple_element_t<0, T>>, class Value = std::tuple_element_t<1, T>>
constexpr Value FirstOrDefault(const T (&pairs)[N], Key& key, Value defaultValue, std::size_t i = 0) {
	return i == N ? defaultValue
		: std::get<0>(pairs[i]) == key ? std::get<1>(pairs[i])
		: FirstOrDefault(pairs, key, defaultValue, i + 1);
}

/// <summary>�y�A�z��̒�����L�[���������������l��Ԃ��܂��B������Ȃ������ꍇ�╡�����������ꍇ�͗�O�𓊂��܂��B</summary>
/// <param name="pairs">�y�A�z��Bstd::pair�z��Astd::tuple�z��Astd::array�z��̂����ꂩ���g���܂��B</param>
/// <param name="key">��������L�[�Bstd::pair�̏ꍇ��first�Astd::tuple��std::array�̏ꍇ�͍ŏ��̗v�f�Ɣ�r���܂��B</param>
/// <param name="i">�������J�n����C���f�b�N�X�B�ȗ������ꍇ�͐擪���猟�����܂��B</param>
/// <returns>�������l�Bstd::pair�̏ꍇ��second�Astd::tuple��std::array�̏ꍇ�͂Q�Ԗڂ̗v�f�ɂȂ�܂��B</returns>
/// <exception cref="std::invalid_argument">������Ȃ������ꍇ�╡�����������ꍇ�ɓ������܂��B</exception>
/// <remarks>�^���_�ɂ��e���v���[�g�����͑S�ďȗ��\�ł��B</remarks>
template<class T, std::size_t N, class Key = std::add_const_t<std::tuple_element_t<0, T>>, class Value = std::tuple_element_t<1, T>>
constexpr Value Single(const T (&pairs)[N], Key& key, std::size_t i = 0) {
	return i == N ? throw std::invalid_argument("not found.")
		: std::get<0>(pairs[i]) != key ? Single(pairs, key, i + 1)
		: Contains(pairs, key, i + 1) ? throw std::invalid_argument("duplicated key.")
		: std::get<1>(pairs[i]);
}
