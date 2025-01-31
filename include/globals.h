#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

const float PI = 3.14159265359;

void console(std::string msg);

typedef float Body[3];

/*const Body unitCube[8] = {
    {0,0,0},
    {1,0,0},
    {1,1,0},
    {0,1,0},
    {0,0,1},
    {1,0,1},
    {0,1,1},
    {1,1,1}
};*/

#endif