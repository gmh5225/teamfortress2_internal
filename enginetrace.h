#pragma once

class C_BaseEntity;
enum TraceType_t;

class trace_filter_t
{
	virtual bool should_hit_entity(C_BaseEntity* entity, int contents_mask);
	virtual TraceType_t	get_trace_type();

	std::vector<void*> pass_through{};

public:
	trace_filter_t(std::vector<void*> pass_through_list) : pass_through{ pass_through_list } {}
};

class Ray_t
{
	__declspec(align(16)) glm::vec3 start{};
	__declspec(align(16)) glm::vec3 delta{};
	__declspec(align(16)) glm::vec3 start_offset{};
	__declspec(align(16)) glm::vec3 extents{};
	bool is_ray{};
	bool is_swept{};

public:
	Ray_t(glm::vec3 from, glm::vec3 to) : start{ from }, delta{ to - from }, is_ray{ true }, is_swept{ length(delta) != 0.f } {}
};

class trace_t
{
	std::byte _0[76]{};
public:
	C_BaseEntity* entity{};
	int hitbox{};
};

class engine_trace_t
{
public:
	void trace_ray(const Ray_t& ray, unsigned int mask, trace_filter_t* trace_filter, trace_t* trace) noexcept; // 4
};

inline engine_trace_t* enginetrace{ **reinterpret_cast<engine_trace_t***>(find_pattern(L"client", "A1 ? ? ? ? 8B 4D ? 8B 30 8D 85") + 1) };

// an eye is never valid in a solid
constexpr auto CONTENTS_SOLID = 0x1;
// translucent, but not watery (glass)
constexpr auto CONTENTS_WINDOW = 0x2;
// alpha-tested "grate" textures.  Bullets/sight pass through, but solids don't
constexpr auto CONTENTS_GRATE = 0x8;

// hits entities which are MOVETYPE_PUSH (doors, plats, etc.)
constexpr auto CONTENTS_MOVEABLE = 0x4000;

// should never be on a brush, only in game
constexpr auto CONTENTS_MONSTER = 0x2000000;
constexpr auto CONTENTS_DEBRIS = 0x4000000;
// use accurate hitboxes on trace
constexpr auto CONTENTS_HITBOX = 0x40000000;

// bullets see these as solid
constexpr auto MASK_SHOT = CONTENTS_SOLID | CONTENTS_MOVEABLE | CONTENTS_MONSTER | CONTENTS_WINDOW | CONTENTS_DEBRIS | CONTENTS_HITBOX;

