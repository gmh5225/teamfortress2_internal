#include "pch.h"
#include "hooks.h"
#include "entity.h"
#include "entitylist.h"
#include "usercmd.h"
#include "modelinfo.h"

bool __fastcall hooks::tf_player::create_move::detour(C_TFPlayer* player_ptr, int32_t, float input_sample_time, CUserCmd* cmd)
{
	if (localplayer == player_ptr && cmd->buttons & IN_ATTACK)
	{
		std::vector<C_BaseEntity*> aim_targets{};
		for (C_BaseEntity* entity : entitylist.get_entities())
		{
			if (localplayer != entity && !entity->is_dormant() && entity->is_alive() && entity->is_player() && !entity->in_local_team())
			{
				aim_targets.push_back(entity);
			}
		}

		std::sort(aim_targets.begin(), aim_targets.end(), [cmd](C_BaseEntity* a, C_BaseEntity* b)
		{
			auto dist_to_crosshair = [cmd](C_BaseEntity* t_entity)
			{
				const glm::vec3 rel_target_pos = t_entity->get_center() - localplayer->get_eye_position();
				const float pitch = glm::degrees(glm::atan(-rel_target_pos.z, hypot(rel_target_pos.x, rel_target_pos.y)));
				const float yaw = glm::degrees(glm::atan(rel_target_pos.y, rel_target_pos.x));

				const float pitch_diff = pitch - cmd->viewangles.x;
				const float yaw_diff = std::remainderf(yaw - cmd->viewangles.y, 360.f);

				return length(glm::vec3{ pitch_diff, yaw_diff, 0.f });
			};

			const float a_dist = dist_to_crosshair(a);
			const float b_dist = dist_to_crosshair(b);

			return a_dist < b_dist;
		});

		for (C_BaseEntity* entity : aim_targets)
		{
			if (model_t* model = entity->get_model())
			{
				if (studiohdr_t* studiohdr = modelinfo->get_studio_model(model))
				{
					if (mstudiohitboxset_t* set = studiohdr->get_hitbox_set(0))
					{
						if (mstudiobbox_t* head_bbox = set->get_hitbox(0))
						{
							C_TFPlayer* player = static_cast<C_TFPlayer*>(entity);
							const glm::vec3 head_position = player->get_bone_position(head_bbox->bone);

							const glm::vec3 rel_target_pos = head_position - localplayer->get_eye_position();
							const float pitch = glm::degrees(glm::atan(-rel_target_pos.z, hypot(rel_target_pos.x, rel_target_pos.y)));
							const float yaw = glm::degrees(glm::atan(rel_target_pos.y, rel_target_pos.x));

							cmd->viewangles.x = pitch;
							cmd->viewangles.y = yaw;

							break;
						}
					}
				}
			}
		}
	}

	return original(player_ptr, input_sample_time, cmd);
}
