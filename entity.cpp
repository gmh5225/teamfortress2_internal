#include "pch.h"
#include "entity.h"

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
