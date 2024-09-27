#pragma once

#include "cinder/app/App.h"
#include "cinder/CinderImGui.h"

class GShape {
public:
	const int mId;
	char name[32];
	bool isMoving;
	glm::vec2 location;
	ci::Color color;
	glm::vec2 velocity;
public:
	virtual void draw(ImDrawList* drawList) = 0;
	virtual bool isHovered(glm::vec2 point) = 0;
	char* getType() { return name; };
	
	void drawBase();
	virtual void drawInfo() = 0;

	virtual void moveShape(float width, float height) = 0;

	virtual ~GShape() = default;

	GShape(int id, glm::vec2 loc, ci::Color col, glm::vec2 vel);
};

class GCircle : public GShape {
public:
	float radius;
public:
	void draw(ImDrawList* drawList) override;
	bool isHovered(glm::vec2 point) override;
	void drawInfo() override;
	void moveShape(float width, float height) override;

	GCircle(int id, glm::vec2 loc, ci::Color col, glm::vec2 vel, float rad) : GShape(id, loc, col, vel), radius(rad) {};
};

class GSquare : public GShape {
public:
	float side;
	void draw(ImDrawList* drawList) override;
	bool isHovered(glm::vec2 point) override;
	void drawInfo() override;
	void moveShape(float width, float height) override;

	GSquare(int id, glm::vec2 loc, ci::Color col, glm::vec2 vel, float a) : GShape(id, loc, col, vel), side(a) { };
};
