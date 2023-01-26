#pragma once

class model_t;

class mstudiobbox_t
{
public:
	int bone{};
};

class mstudiohitboxset_t
{
	std::byte _0[4]{};

public:
	int numhitboxes{};
	int hitboxindex{};
	mstudiobbox_t* get_hitbox(int hitbox) { return reinterpret_cast<mstudiobbox_t*>(reinterpret_cast<std::byte*>(this) + hitboxindex) + hitbox; }
};

class studiohdr_t
{
	std::byte _0[172]{};

public:
	int numhitboxsets{};
	int hitboxsetindex{};

	mstudiohitboxset_t* get_hitbox_set(int set) { return reinterpret_cast<mstudiohitboxset_t*>(reinterpret_cast<std::byte*>(this) + hitboxsetindex) + set; }
};

class CModelInfoClient
{
public:
	studiohdr_t* get_studio_model(model_t* model) noexcept; // 28
};

inline CModelInfoClient* modelinfo{ **reinterpret_cast<CModelInfoClient***>(find_pattern(L"client", "A1 ? ? ? ? 8B 4D ? 8B 5D") + 1) };
