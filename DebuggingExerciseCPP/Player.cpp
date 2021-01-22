#include "player.h"

Player::Player(const char* name, float health, float damage, float defense) :
    Character(name, health, damage, defense)
{

}

void Player::equipWeapon(Item item)
{
    m_weapon = item;
}

void Player::equipShield(Item item)
{
    m_shield = item;
}

float Player::takeDamage(float damage)
{
    float totalDamage = damage - m_shield.getStatusBoost();

    return Character::takeDamage(totalDamage);
}

float Player::attack(Character* other)
{
    return other->takeDamage(getDamage());
}

float Player::getDamage()
{
    return Character::getDamage() + m_weapon.getStatusBoost();
}

float Player::getDefense()
{
    return Character::getDefense() + m_shield.getStatusBoost();
}
