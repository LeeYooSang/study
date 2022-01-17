#include <iostream>
#include "minimal_fighter.h"

int MinimalFighter::hp(){
	return mHp;
}

int MinimalFighter::power(){
	return mPower;
}

FighterStatus MinimalFighter::status(){
	if(mHp >0)
		mStatus = Alive;
	else
		mStatus = Dead;
	return mStatus;
}

void MinimalFighter::setHp(int _hp){
	mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter *_enemy){
	_enemy->mHp -= this->mPower;
	this->mHp -= _enemy->mPower;
}

void MinimalFighter::attack(MinimalFighter *_enemy){
	_enemy->mHp -= this->mPower;
	this->mPower = 0;

}

void MinimalFighter::fight(MinimalFighter *_enemy){
	while(this->mHp > 0 && _enemy->mHp > 0)
	{
		_enemy->mHp -= this->mPower;
		this->mHp -= _enemy->mPower;
	}
}
