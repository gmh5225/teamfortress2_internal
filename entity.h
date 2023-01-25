#pragma once

class model_t;

class C_BaseEntity
{
	void* IClientRenderable() noexcept { return this + 4; }
	void* IClientNetworkable() noexcept { return this + 8; }
	void* IClientThinkable() noexcept { return this + 12; }

public:
	// IClientRenderable
	model_t* get_model() noexcept; // 9

	// IClientNetworkable
	bool is_dormant() noexcept; // 8
	int get_index() noexcept; // 9

	// C_BaseEntity
	const glm::vec3& get_position() noexcept; // 9
	const glm::vec3& get_center() noexcept; // 66

	int get_team_number() noexcept; // 74
	bool in_same_team() noexcept; // 77
	bool in_local_team() noexcept; // 78

	bool is_alive() noexcept; // 130
	bool is_player() noexcept; // 131
	bool is_base_combat_character() noexcept; // 132
	bool is_npc() noexcept; // 133
	bool is_next_bot() noexcept; // 135
	bool is_base_object() noexcept; // 136
	bool is_base_combat_weapon() noexcept; // 137

	const glm::vec3& get_view_offset() noexcept; // 146

	glm::vec3 get_eye_position() noexcept { return get_position() + get_view_offset(); }
};

class C_BaseAnimating : public C_BaseEntity
{
	void* IModelLoadCallback() noexcept { return this + 1360; }

public:
	glm::vec3 get_bone_position(int bone);
};

class C_BaseCombatCharacter : public C_BaseAnimating
{
	void* IHasLocalToGlobalFlexSettings() noexcept { return this + 2320; }
};

class C_TFPlayer : public C_BaseCombatCharacter
{
	void* CGameEventListener() noexcept { return this + 3528; }
	void* IHasAttributes() noexcept { return this + 5472; }
	void* IInventoryUpdateListener() noexcept { return this + 5476; }
	void* C_TFMvMBossProgressUser() noexcept { return this + 5480; }
};

inline ref_ptr_t localplayer{ *reinterpret_cast<C_TFPlayer***>(find_pattern(L"client", "A1 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC A1 ? ? ? ? 83 78") + 1) };
