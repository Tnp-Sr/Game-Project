#pragma once
#include"Enemy.h"
#include"Bullet.h"
#include<map>


class Boss
{
private:
    //bullet
    std::vector < Bullet*> bullets;
    std::map<std::string, sf::Texture*> texture;
    //verible
    sf::Texture loadBoss;
    sf::Sprite boss;

    Boss* bosses;

    float speed;
    int random;

    float attackCooldown;
    float attackCooldownMax;

    int i;
    int damage;

    int hpMax;
    int hp;

    //Function
    void Varible();
    void iniwindow();
    void iniBackground();
    void setupHp(const int hp);

public:

    Boss();
    virtual ~Boss();
    //Function

    const  sf::Vector2f& getpos() const;
    const sf::FloatRect getBound() const;

    void update();

    const bool canAttack();
    void updateAttack();

    const  int& getDamage() const;
    const int& getHP() const;
    const int& getHPMax() const;
    void setHP(const int Velue);
    void loseHP(const int Velue);

    void render(sf::RenderTarget* target = NULL);
    void render2();
};

