#pragma once
#include "Object.h"

class ShapeObject : public Object
{
	Shape* shape;
	Texture texture;

public:
	FORCEINLINE Texture& GetTexture()
	{
		return texture;
	}
	FORCEINLINE virtual Shape* GetDrawable() const override
	{
		return shape;
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		Super::SetOrigin(_origin);
		shape->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		Super::SetPosition(_position);
		shape->setOrigin(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation)
	{
		Super::SetRotation(_rotation);
		shape->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		Super::SetScale(_scale);
		shape->setScale(_scale);
	}
	FORCEINLINE virtual void SetTransform(const TransformData& _transformData)
	{
		Super::SetTransform(_transformData);
		shape->setScale(transform.scale);
		shape->setRotation(transform.rotation);
		shape->setOrigin(transform.origin);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		Super::Move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		Super::Rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		Super::Scale(_factor);
	}

public:
	ShapeObject(const float _radius, const string& _path = "", const IntRect& _rect = IntRect(), const size_t& _pointCount = 30);
	ShapeObject(const Vector2f& _size, const string& _path = "", const IntRect& _rect = IntRect());
	~ShapeObject();
	
public:
	ShapeObject* operator = (const CircleShape* _circle);
	ShapeObject* operator = (const RectangleShape* _circle);

};

