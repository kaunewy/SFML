#pragma once
#include "CoreMinimal.h"

struct TransformData
{
	Vector2f origin;
	Vector2f position;
	Angle rotation;
	Vector2f scale;
};

class Object
{
protected:
	TransformData transform;
	
public:
	FORCEINLINE virtual bool IsValid(Object* _object) const
	{
		return _object;
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		transform.origin = _origin;
	}
	FORCEINLINE TransformData GetTransform() const
	{
		return transform;
	}
	FORCEINLINE virtual Drawable* GetDrawable() const = 0;
	FORCEINLINE Vector2f GetPosition() const
	{
		return transform.position;
	}
	FORCEINLINE Vector2f GetScale() const
	{
		return transform.scale;
	}
	FORCEINLINE Angle GetRotation() const
	{
		return transform.rotation;
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		transform.position = _position;
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation)
	{
		transform.rotation = _rotation;
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		transform.scale = _scale;
	}
	FORCEINLINE virtual void SetTransform(const TransformData& _transformData)
	{
		transform = _transformData;
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		transform.position += _offset;
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		transform.rotation += _angle;
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		transform.scale += _factor;
	}

public:
	virtual ~Object() {};

public:
	
	template <typename T>
	T* Cast(Object* _object)
	{
		if (!_object) return nullptr;
		return dynamic_cast<T>(_object);
	}
};

