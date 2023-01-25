#include "pch.h"
#include "entity.h"

model_t* C_BaseEntity::get_model() noexcept
{
	return call_vfunc<model_t*>(IClientRenderable(), 9);
}

bool C_BaseEntity::is_dormant() noexcept
{
	return call_vfunc<bool>(IClientNetworkable(), 8);
}

int C_BaseEntity::get_index() noexcept
{
	return call_vfunc<int>(IClientNetworkable(), 9);
}

const glm::vec3& C_BaseEntity::get_position() noexcept
{
	return call_vfunc<const glm::vec3&>(this, 9);
}

const glm::vec3& C_BaseEntity::get_center() noexcept
{
	return call_vfunc<const glm::vec3&>(this, 66);
}

int C_BaseEntity::get_team_number() noexcept
{
	return call_vfunc<int>(this, 74);
}

bool C_BaseEntity::in_same_team() noexcept
{
	return call_vfunc<bool>(this, 77);
}

bool C_BaseEntity::in_local_team() noexcept
{
	return call_vfunc<bool>(this, 78);
}

bool C_BaseEntity::is_alive() noexcept
{
	return call_vfunc<bool>(this, 130);
}

bool C_BaseEntity::is_player() noexcept
{
	return call_vfunc<bool>(this, 131);
}

bool C_BaseEntity::is_base_combat_character() noexcept
{
	return call_vfunc<bool>(this, 132);
}

bool C_BaseEntity::is_npc() noexcept
{
	return call_vfunc<bool>(this, 133);
}

bool C_BaseEntity::is_next_bot() noexcept
{
	return call_vfunc<bool>(this, 135);
}

bool C_BaseEntity::is_base_object() noexcept
{
	return call_vfunc<bool>(this, 136);
}

bool C_BaseEntity::is_base_combat_weapon() noexcept
{
	return call_vfunc<bool>(this, 137);
}

const glm::vec3& C_BaseEntity::get_view_offset() noexcept
{
	return call_vfunc<const glm::vec3&>(this, 146);
}

glm::vec3 C_BaseAnimating::get_bone_position(int bone)
{
	glm::vec3 origin{};
	glm::vec3 angles{};

	using GetBonePosition_t = void(__thiscall*)(C_BaseAnimating* thisptr, int bone, glm::vec3& origin, glm::vec3& angles);
	static const auto GetBonePosition = reinterpret_cast<GetBonePosition_t>(find_pattern(L"client", "55 8B EC 83 EC ? 56 6A ? 8B F1 E8 ? ? ? ? FF 75"));
	GetBonePosition(this, bone, origin, angles);

	return origin;
}
