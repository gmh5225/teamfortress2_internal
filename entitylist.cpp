#include "pch.h"
#include "entitylist.h"

void entitylist_t::on_entity_created(C_BaseEntity* entity)
{
	entities.emplace_back(entity);
}

void entitylist_t::on_entity_deleted(C_BaseEntity* entity)
{
	entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}
