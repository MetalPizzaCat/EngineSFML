#pragma once
#include "Actor.h"

//base class for the Charaters,that defines basic movement using Box2D's physics and LUA as well as basic collision
class Character : public CActor
{
protected:
	sf::Vector2f MaxVelocity = sf::Vector2f(1, 50);

	//LUA script file that will be used for movement
	//it is not obligatory to use LUA script
	std::string MovementScriptFileName="character.lua";

	sf::Vector2f Size;

	
public:

	bool IsMovingX = false;

	bool IsMovingY = false;

	
	//Shape that will be used for making shadows in game
	sf::ConvexShape ShadowShape;

	//Shape that will be used for the collision
	//THIS SHOULD BE USED ONLY IF POLYGON SHAPE IS NOT WORKING (If this can not be used it's better to use ShadowShape)
	//there is no way to properly check if collision is good for the polygon shape at runtime and change
	sf::FloatRect CollisionRectangle;

	//LUA script file that will be used for movement
	//it is not obligatory to use LUA script
	void SetMovementScriptFileName(std::string f) { MovementScriptFileName = f; }

	//LUA script file that will be used for movement
	//it is not obligatory to use LUA script
	std::string GetMovementScriptFileName()const { return MovementScriptFileName; }

	sf::Vector2f GetMaxVelocity()const { return MaxVelocity; }

	void SetMaxVelocity(sf::Vector2f v) { this->MaxVelocity = v; }

	
	inline void MoveX(float value);

	void Jump();

	//Forces body to stop x velocity
	void StopXMovement();

	DEPRECATED_ERROR inline void MoveY(float value);

	virtual void Init(std::string path);
	virtual void InitPhysBody(std::string path,cpSpace *&world);

	//Create LUA class from this for usage in LUA
	static void RegisterClassLUA(lua_State *&L);

	void Update(sf::Time dt);
	Character(sf::ConvexShape CollisionShape, sf::Vector2f Size, sf::Vector2f Location, std::string path="./../");
	~Character();
};

