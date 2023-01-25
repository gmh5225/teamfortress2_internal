#include "pch.h"
#include "hooks.h"
#include "entity.h"
#include "entitylist.h"
#include "usercmd.h"

bool __fastcall hooks::tf_player::create_move::detour(C_TFPlayer* player, int32_t, float input_sample_time, CUserCmd* cmd)
{
    if (localplayer == player && cmd->buttons & IN_ATTACK)
    {
	    for (C_BaseEntity* entity : entitylist.get_entities())
	    {
		    if (localplayer != entity && !entity->is_dormant() && entity->is_alive() && entity->is_player())
		    {
			    const glm::vec3 rel_target_pos = entity->get_position() - localplayer->get_position();
			    const float pitch = glm::degrees(glm::atan(-rel_target_pos.z, hypot(rel_target_pos.x, rel_target_pos.y)));
			    const float yaw = glm::degrees(glm::atan(rel_target_pos.y, rel_target_pos.x));

			    cmd->viewangles.x = pitch;
			    cmd->viewangles.y = yaw;

			    break;
		    }
	    }
    }

    return original(player, input_sample_time, cmd);
}
