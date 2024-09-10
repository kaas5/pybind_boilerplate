#include <iostream>
#include <iomanip>
#include <cmath>
#include "mijnlib.h"

Vector2::Vector2(float x, float y){
	gx = x;
	gy = y;
}
Vector2 Vector2::Copy(){
	return Vector2(gx, gy);
}

float Vector2::Mag(){
	return (float)sqrt((gx * gx) + (gy * gy));
}

float Vector2::MagSq(){
	return (gx * gx) + (gy * gy);
}

Vector2* Vector2::SetMag(float mag){
	float curr_mag = Mag();
	gx = (gx / curr_mag) * mag;
	gy = (gy / curr_mag) * mag;
	return this;
}

float Vector2::Dist(Vector2 v){
	return (float)sqrt((gx - v.X()) * (gx - v.X()) + (gy - v.Y()) * (gy - v.Y()));
}

float Vector2::X(){
	return gx;
}
float Vector2::Y(){
	return gy;
}
void Vector2::SetX(float x){
	gx = x;
}
void Vector2::SetY(float y){
	gy = y;
}

Vector2* Vector2::Add(float c){
	gx += c;
	gy += c;
	return this;
}

Vector2* Vector2::Add(Vector2 v){
	gx += v.X();
	gy += v.Y();
	return this;
}

Vector2* Vector2::Sub(float c){
	gx -= c;
	gy -= c;
	return this;
}

Vector2* Vector2::Sub(Vector2 v){
	gx -= v.X();
	gy -= v.Y();
	return this;
}

Vector2* Vector2::Mul(float c){
	gx *= c;
	gy *= c;
	return this;
}

Vector2* Vector2::Mul(Vector2 v){
	gx *= v.X();
	gy *= v.Y();
	return this;
}

Vector2* Vector2::Div(float c){
	gx /= c;
	gy /= c;
	return this;
}

Vector2* Vector2::Div(Vector2 v){
	gx /= v.X();
	gy /= v.Y();
	return this;
}