#pragma once

class C_BaseEntity
{
	void* IClientRenderable() noexcept { return this + 4; }
	void* IClientNetworkable() noexcept { return this + 8; }
	void* IClientThinkable() noexcept { return this + 12; }

public:
	// IClientNetworkable
	bool is_dormant() noexcept;
	int get_index() noexcept;

	// C_BaseEntity
	bool is_alive() noexcept;
	bool is_player() noexcept;
	bool is_base_combat_character() noexcept;
	bool is_npc() noexcept;
	bool is_next_bot() noexcept;
	bool is_base_object() noexcept;
	bool is_base_combat_weapon() noexcept;
};

class C_BaseCombatCharacter : public C_BaseEntity
{
	void* IModelLoadCallback() noexcept { return this + 1360; }
	void* IHasLocalToGlobalFlexSettings() noexcept { return this + 2320; }
};

class C_TFPlayer : public C_BaseCombatCharacter
{
	void* CGameEventListener() noexcept { return this + 3528; }
	void* IHasAttributes() noexcept { return this + 5472; }
	void* IInventoryUpdateListener() noexcept { return this + 5476; }
	void* C_TFMvMBossProgressUser() noexcept { return this + 5480; }
};
