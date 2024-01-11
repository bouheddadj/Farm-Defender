

#ifndef VECT2_H
#define VECT2_H

#include <iostream>
#include <ostream>



class Vect2

{
    public:

        
        Vect2();

        
        ~Vect2();   

                
        
        
        Vect2(float a, float b);


        
        Vect2 operator+ (Vect2 a);

        
        Vect2 operator- (Vect2 a);

        
        Vect2 operator* (float a);

        
        Vect2 make_Vect2 (float a, float b);


        
        float distance (Vect2 a);

        
        float x,y;

        
        void normailiser();
        


    private:

};

#endif 