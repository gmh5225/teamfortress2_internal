#pragma once

class C_TFPlayer;
class CUserCmd;

namespace hooks
{
	namespace tf_player
	{
		namespace create_move
		{
			inline bool(__thiscall* original)(C_TFPlayer* player_ptr, float input_sample_time, CUserCmd* cmd) {};
			bool __fastcall detour(C_TFPlayer* player_ptr, int32_t, float input_sample_time, CUserCmd* cmd);
		}
	}
}
