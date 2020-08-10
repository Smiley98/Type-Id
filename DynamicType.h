#pragma once
#include <type_traits>
#include <string>
#include <cstdint>

//Doesn't make use of CLASS_TYPE, but passing it improves legibility.
#define DECLARE_TYPE(CLASS_TYPE) \
public: \
	virtual uint32_t getType() const; \
	static uint32_t getTypeStatic(); \
	static std::hash<std::string> s_type_string; \
	static uint32_t s_type_hash;

#define IMPLEMENT_TYPE(CLASS_TYPE) \
	std::hash<std::string> CLASS_TYPE::s_type_string; \
	uint32_t CLASS_TYPE::s_type_hash = static_cast<uint32_t>(s_type_string(#CLASS_TYPE)); \
	uint32_t CLASS_TYPE::getTypeStatic() {  return s_type_hash; } \
	uint32_t CLASS_TYPE::getType() const { return CLASS_TYPE::getTypeStatic(); }

template<typename T, typename U>
bool types_equal() { return T::getTypeStatic() == U::getTypeStatic(); }