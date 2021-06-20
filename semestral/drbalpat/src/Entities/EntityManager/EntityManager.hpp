#pragma once

#include "../Entity.hpp"

#include <map>
#include <list>
#include <memory>
#include <string>

class EntityManager {
public:
	static EntityManager * getInstance() { return entityManager = entityManager ? entityManager : new EntityManager(); }

	// add one entity with given id
	void addEntity( std::string id, std::shared_ptr<Entity> entity ) { entities[id].emplace_back( entity ); }
	
	// return all entities with given id
	std::list< std::shared_ptr<Entity> > & getEntities( std::string id ) { return entities[id]; }

	void update();
	void render();

private:
	EntityManager() {}
	static EntityManager * entityManager;

	// entities categorized by id
	std::map <
		std::string, // id
		std::list< std::shared_ptr<Entity> > // list of entities
	> entities;
};
