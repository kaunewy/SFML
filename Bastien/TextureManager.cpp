#include "TextureManager.h"


TextureManager::TextureManager()
{
    defaultTexturePath = "DefaultTexture";
    defaultTextureExtension = ".png";
    defaultTexture = nullptr;
}

TextureManager::~TextureManager()
{
    delete defaultTexture;
}

void TextureManager::Load(ShapeObject* _shapeObject, const string& _path,
    const IntRect& _rect, const bool _isRepeated, const bool _smooth)
{
    Texture& _texture = _shapeObject->GetTexture();

    if (_path == "")
    {
        cerr << "[Error] => Cannot open file with empty path"  << endl;
        _texture = GetDefaultTexture();
    }
    LoadTexture(_texture, _path, _rect);
    _texture.setRepeated(_isRepeated);
    _texture.setSmooth(_smooth);

    SetTexture(_shapeObject->GetDrawable(), &_texture);
}

void TextureManager::LoadTexture(Texture& _texture, const string& _path, const IntRect& _rect)
{
    const string& _finalPath = "Assets/Textures/" + _path + defaultTextureExtension;
    if (!_texture.loadFromFile(_finalPath, false, _rect))
    {
        cerr << "[Error] => Cannot open file with path : \'" << _finalPath << "\'" << endl;
        _texture = GetDefaultTexture();
    }
}

void TextureManager::LoadDefaultTexture()
{
    defaultTexture = new Texture();
    LoadTexture(*defaultTexture, defaultTexturePath, IntRect(Vector2i(0, 0), Vector2i(50, 50)));
}

void TextureManager::SetTexture(Shape* _shape, const Texture* _texture)
{
    _shape->setTexture(_texture);
}