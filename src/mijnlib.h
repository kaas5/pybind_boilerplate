#pragma once

class Vector2{
    float gx;
    float gy;
    public:
        Vector2(float x, float y);

        Vector2 Copy();

        float X();
        float Y();
        void SetX(float x);
        void SetY(float y);

        float Mag();
        float MagSq();
        Vector2* SetMag(float mag);
        float Dist(Vector2 v);
        
        Vector2* Add(float c);
        Vector2* Add(Vector2 v);

        Vector2* Sub(float c);
        Vector2* Sub(Vector2 v);

        Vector2* Mul(float c);
        Vector2* Mul(Vector2 v);

        Vector2* Div(float c);
        Vector2* Div(Vector2 v);
};
