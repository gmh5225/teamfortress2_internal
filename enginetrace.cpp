#include "pch.h"
#include "enginetrace.h"
#include "entity.h"

bool trace_filter_t::should_hit_entity(C_BaseEntity* entity, int contents_mask)
{
	return std::find(pass_through.begin(), pass_through.end(), entity) == pass_through.end();
}

enum TraceType_t
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,
	TRACE_ENTITIES_ONLY,
	TRACE_EVERYTHING_FILTER_PROPS,
};

TraceType_t trace_filter_t::get_trace_type()
{
	return TRACE_EVERYTHING;
}

void engine_trace_t::trace_ray(const Ray_t& ray, unsigned int mask, trace_filter_t* trace_filter, trace_t* trace) noexcept
{
	call_vfunc(this, 4, &ray, mask, trace_filter, trace);
}
