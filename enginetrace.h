#pragma once

class C_BaseEntity;
enum TraceType_t;

namespace trace_filter
{
	class bullet_t
	{
		virtual bool should_hit_entity(C_BaseEntity* entity, int contents_mask);
		virtual TraceType_t	get_trace_type();
	};
}


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
