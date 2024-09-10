from mijnlib import vector2
import time
import math

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def copy(self):
        return Vector2(self.x, self.y)

    def mag(self):
        return math.sqrt(self.x*self.x + self.y*self.y)
    
    def magSq(self):
        return self.x*self.x + self.y*self.y
    
    def setMag(self,speed):
        m = self.mag()
        self.x = (self.x / m) * speed
        self.y = (self.y / m) * speed
        return self
        
    def dist(self, v):
        return math.sqrt((self.x - v.x)*(self.x - v.x) + (self.y - v.y)*(self.y - v.y))

    def add(self,v):
        if type(v) == Vector2:
            self.x += v.x
            self.y += v.y
        else:
            self.x += v
            self.y += v
        return self
    
    def sub(self,v):
        if type(v) == Vector2:
            self.x -= v.x
            self.y -= v.y
        else:
            self.x -= v
            self.y -= v
        return self
            
    def mult(self,v):
        if type(v) == Vector2:
            self.x *= v.x
            self.y *= v.y
        else:
            self.x *= v
            self.y *= v
        return self
    
    def div(self,v):
        if type(v) == Vector2:
            self.x /= v.x
            self.y /= v.y
        else:
            self.x /= v
            self.y /= v
        return self

loops = 1000000

def test_het():
    start = time.time()
    v1 = Vector2(3,4)
    v2 = Vector2(4,3)
    i = []
    for _ in range(loops):
        fleop = v1.setMag(loops)
        i.append(fleop)
    end = time.time() - start
    print(f'test langzaam in {end}')

    start = time.time()
    v1 = vector2(3,4)
    v2 = vector2(4,3)
    j = []
    for _ in range(loops):
        fleop = v1.setmag(loops)
        j.append(fleop)
    end = time.time() - start
    print(f'test snel in {end}')

test_het()