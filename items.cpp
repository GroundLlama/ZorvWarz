#include "entity.h" 

AmmoBox::AmmoBox(float x, float y){
	type = "box";
	drawable = true;
	collides = true;
	readyToUpdate = false;
	alive = true;

	this->x = x;
	this->y = y;

	ammoTex.loadFromFile("data/textures/ammo.png");
	box.setTexture(ammoTex);

	collisionBoxes.push_back(sf::FloatRect(x,y,20,20));
}

void AmmoBox::onCollision(Entity *object, sf::FloatRect otherbox){
	if(object->type == "player"){
		std::cout << "REMOVEING BOX" << std::endl;
		alive = false;
		collides = false;
	}
}

void AmmoBox::draw(sf::RenderWindow *screen, int screenx, int screeny){
	box.setPosition(x-screenx,y-screeny);
	screen->draw(box);
}