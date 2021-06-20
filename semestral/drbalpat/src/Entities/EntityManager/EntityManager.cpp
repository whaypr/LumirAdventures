#include "EntityManager.hpp"

EntityManager * EntityManager::entityManager = nullptr;

void EntityManager::update() {
	for ( auto & e : entities )
		for ( auto ee = e.second.begin(); ee != e.second.end(); ee++ ) {
			(*ee)->update();
			if ( (*ee)->destroyed() ) {
				e.second.erase(ee++); // don't have to delete because of smart pointer
			}
		}
}

void EntityManager::render() {
	for ( auto & e : entities )
		for ( auto ee : e.second )
			ee->render();	
}
