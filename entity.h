#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <enet/enet.h>
#include "ship.h"

extern int idCounter;

class Entity{
	public:
		std::string type;
		bool drawable,collides,readyToUpdate;
		bool alive;
		std::vector<sf::FloatRect> collisionBoxes;
		float x,y;
		float rot;
		int ID;

		Entity();
		//virtual ~Entity(){};

		virtual void update(int framecount){};
		virtual void onCollision(Entity *object, sf::FloatRect otherBox){};
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

class Mob : public Entity {
	public:
	sf::Sprite mobSprite;
	sf::Texture texture;
	ENetPeer *peer;

	Mob();
	Mob(std::string textureFile);
	void update(int framecount);
	void onCollision(Entity *object, sf::FloatRect otherBox){};
	void draw(sf::RenderWindow *window, int screenx,int screeny);
};

class Player : public Entity {
	public:
	float xVol;
	float yVol;
	float speed;
	sf::Sprite playerSprite;
	sf::Texture texture;
	
	Player(std::string playerTexture);
	void update(int framecount);
	void onCollision(Entity *object, sf::FloatRect otherBox);
	void draw(sf::RenderWindow *screen,int screenx,int screeny);
};

class ShipEntity : public Entity{
	public:
	Ship *map;
	
	ShipEntity(std::string tilesFile);
	~ShipEntity();

	void onCollision(Entity *object, sf::FloatRect otherBox){};
	void draw(sf::RenderWindow *screen, int screenx, int screeny);
	void getColBoxes();
	sf::Vector2i getRandomFloorTile();

};

#endif
