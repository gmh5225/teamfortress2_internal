#pragma once

class CUserCmd
{
	virtual void _0() = 0;

public:
	// For matching server and client commands for debugging
	int command_number{};

	// the tick the client created this command
	int tick_count{};

	// Player instantaneous view angles
	glm::vec3 viewangles{};

	// forward velocity
	float forwardmove{};
	// sideways velocity
	float sidemove{};
	// upward velocity
	float upmove{};

	// Attack button states
	int buttons{};

	// Impulse command issued
	std::byte impulse{};

	// Current weapon id
	int weaponselect{};
	int weaponsubtype{};

	// For shared random functions
	int random_seed{};
	// Only the server populates this seed
	int server_random_seed{};

	// mouse accum in x from create move
	short mousedx{};
	// mouse accum in y from create move
	short mousedy{};

	// Client only, tracks whether we've predicted this command at least once
	bool hasbeenpredicted{};
};

constexpr auto IN_ATTACK = 1 << 0;
constexpr auto IN_JUMP = 1 << 1;
constexpr auto IN_DUCK = 1 << 2;
constexpr auto IN_FORWARD = 1 << 3;
constexpr auto IN_BACK = 1 << 4;
constexpr auto IN_USE = 1 << 5;
constexpr auto IN_CANCEL = 1 << 6;
constexpr auto IN_LEFT = 1 << 7;
constexpr auto IN_RIGHT = 1 << 8;
constexpr auto IN_MOVELEFT = 1 << 9;
constexpr auto IN_MOVERIGHT = 1 << 10;
constexpr auto IN_ATTACK2 = 1 << 11;
constexpr auto IN_RUN = 1 << 12;
constexpr auto IN_RELOAD = 1 << 13;
constexpr auto IN_ALT1 = 1 << 14;
constexpr auto IN_ALT2 = 1 << 15;
// Used by client.dll for when scoreboard is held down
constexpr auto IN_SCORE = 1 << 16;
// Player is holding the speed key
constexpr auto IN_SPEED = 1 << 17;
// Player holding walk key
constexpr auto IN_WALK = 1 << 18;
// Zoom key for HUD zoom
constexpr auto IN_ZOOM = 1 << 19;
constexpr auto IN_WEAPON1 = 1 << 20;
constexpr auto IN_WEAPON2 = 1 << 21;
constexpr auto IN_BULLRUSH = 1 << 22;
constexpr auto IN_GRENADE1 = 1 << 23;
constexpr auto IN_GRENADE2 = 1 << 24;
constexpr auto IN_ATTACK3 = 1 << 25;
