#include "Vect2.h"

#include <iostream>
#include <ostream>
#include <math.h>

using namespace std;

Vect2::Vect2()
{
    x = 0;
    y = 0;
}

Vect2::~Vect2()
{
}


Vect2::Vect2(float a, float b)
{ 	x=a;
	y=b;
}


Vect2 Vect2::operator+(Vect2 a)
{
    return make_Vect2(a.x+x , a.y+y);
}

Vect2 Vect2::operator-(Vect2 a)
{
    return make_Vect2(x-a.x ,y-a.y);
}

Vect2 Vect2::operator*(float a)
{
    return make_Vect2(a*x , a*y);
}

Vect2 Vect2::make_Vect2(float x, float y)
{
    Vect2 a;
    a.x=x;
    a.y=y;
    return a;
}

float Vect2::distance(Vect2 a)
{
    float d;
    int dx, dy;
    dx = a.x-x;
    dy = a.y-y;
    d = sqrt(dx*dx + dy*dy);
    return d;
}

void Vect2::normailiser(){
    float dist=sqrt(x*x + y*y);
    x=x/dist;
    y=y/dist;

    //cout<<sqrt(x*x + y*y)<<"    est la dist du vect normalisé"<<endl;
}