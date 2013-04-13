#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ship.h"

extern int idCounter;

class Entity{
	public:
		std::string type;
		bool drawable,collides,readyToUpdate;
		bool alive;
		std::vector<sf::FloatRect> collisionBox;
		int x,y;
		int ID;

		Entity();
		//virtual ~Entity(){};

		virtual void update(int framecount){};
		virtual void onCollision(Entity object, sf::FloatRect otherBox){};
		virtual void draw(sf::RenderWindow *screen,int screenx,int screeny){};
};

class EntityManager{
	public:
	std::vector<Entity*> entityList;

	//~EntityManager();
	void updateEntities(int framecount);
	void collideEntities();
	void drawEntities(sf::RenderWindow *screen,int screenx,int screeny);
	void removeByID(int ID);
};

class Player : public Entity {
	public:
	int xVol;
	int yVol;
	int speed;
	sf::Sprite playerSprite;
	sf::Texture texture;
	
	Player(std::string playerTexture);
	void update(int framecount);
	void onCollision(Entity Object, sf::FloatRect otherBox);
	void draw(sf::RenderWindow *screen,int screenx,int screeny);
};

class ShipEntity : public Entity{
	public:
	Ship *map;
	
	ShipEntity(std::string tilesFile);
	~ShipEntity();

	void onCollision(Entity Object, sf::FloatRect otherBox);
	void draw(sf::RenderWindow *screen, int screenx, int screeny);

};

#endif
