#pragma once

class C_BaseEntity;

class entitylist_t
{
	std::vector<C_BaseEntity*> entities{};

public:
	virtual void on_entity_created(C_BaseEntity* entity);
	virtual void on_entity_deleted(C_BaseEntity* entity);
};

inline entitylist_t entitylist{};
