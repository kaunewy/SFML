#pragma once
#include "Core.h"
#include "ShapeObject.h"
#include "Component.h"

class Actor : public Core
{
	ShapeObject* shape;
	set<Component*> components;

public:
	FORCEINLINE void SetShape( ShapeObject* _shape)
	{
		shape = _shape;
	}

	FORCEINLINE ShapeObject* GetShape() const
	{
		return shape;
	}


public:
	Actor();
	Actor(const float _radius, const string& _path = "", const IntRect& _rect = IntRect(), const size_t& _pointCount = 30);
	Actor(const Vector2f& _size, const string& _path = "", const IntRect& _rect = IntRect());
	Actor(const int _size, const string& _path = "", const int _pointsCount = 3, const IntRect& _rect = IntRect());
	~Actor();

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;

public:
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	void Register();
	template <typename T>
	T* GetComponent()
	{
		for (Component* _component : components)
		{
			if(is_same_v<decltype(_component), T>)
			{
				return dynamic_cast<T>(_component);
			}
		}
		return nullptr;
	}
};

