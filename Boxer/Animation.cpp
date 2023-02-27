#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    //Pointers 
    this->imageCount = imageCount;
    this->switchTime = switchTime;
   
    totalTime = 0.0f;
    currentImage.x = 0;

    //Calculate each sprite size
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::setSwitchTime(float switchTime) {
    this->switchTime = switchTime;
}
void Animation::setImageCount(sf::Vector2u imageCount) {
    this->imageCount = imageCount;
}

void Animation::setTexture(sf::Texture* texture)
{
    this->texture = *texture;
}

void Animation::Update(int row, float deltatime, bool faceRight)
{
    //Declare the row of the animation
    currentImage.y = row; 
    totalTime += deltatime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        //Goes to next sprite
        currentImage.x++; 

        if (currentImage.x >= imageCount.x)
        {
            //Avoid drawing outside of the image
            currentImage.x = 0; 
        }
    }

    uvRect.top = currentImage.y * uvRect.height;

    //Mirror sprite in case of moving to another side
    if (faceRight)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}
