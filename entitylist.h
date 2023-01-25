#pragma once

class C_BaseEntity;

class entitylist_t
{
	std::vector<C_BaseEntity*> entities{};

	virtual void on_entity_created(C_BaseEntity* entity);
	virtual void on_entity_deleted(C_BaseEntity* entity);

public:
	const std::vector<C_BaseEntity*>& get_entities() { return entities; }
};

inline entitylist_t entitylist{};
