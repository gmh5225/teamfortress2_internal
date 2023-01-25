#include "pch.h"
#include "enginetrace.h"
#include "entity.h"

bool trace_filter::bullet_t::should_hit_entity(C_BaseEntity* entity, int contents_mask)
{
	return localplayer != entity;
}

enum TraceType_t
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,
	TRACE_ENTITIES_ONLY,
	TRACE_EVERYTHING_FILTER_PROPS,
};

TraceType_t trace_filter::bullet_t::get_trace_type()
{
	return TRACE_EVERYTHING;
}
