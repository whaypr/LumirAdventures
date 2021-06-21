/**
* \brief Class managing all the game entities, updating and rendering them.
*
* Entities are stored in a map, living in lists of shared pointers and categorized by string IDs.
*
* This class is a singleton.
*/

#pragma once

#include "../Entity.hpp"

#include <map>
#include <list>
#include <memory>
#include <string>

class EntityManager {
public:
	/**
	* Get class instance to access its public interface.
	* @return instance pointer
	*/
	static EntityManager * getInstance() { return entityManager = entityManager ? entityManager : new EntityManager(); }


	/**
	* Call *update()* method of all entities.
	*/
	void update();
	/**
	* Call *render()* method of all entities.
	*/
	void render() const;


	/**
	* Add one entity with given id.
	* @param id entity id
	* @param entity shared pointer to entity which will be added to the section by given id
	*/
	void addEntity( std::string id, std::shared_ptr<Entity> entity ) { entities[id].emplace_back( entity ); }	
	/**
	* Return all entities with given id.
	* @param id entity id
	* @return list of shared pointers to entities with given id
	*/
	std::list< std::shared_ptr<Entity> > & getEntities( std::string id ) { return entities[id]; }

private:
	EntityManager() {}
	static EntityManager * entityManager;

	// entities categorized by id
	std::map <
		std::string, // id
		std::list< std::shared_ptr<Entity> > // list of entities
	> entities;
};
