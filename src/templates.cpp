#include "../include/templates.h"

Shapes::Shapes(){

}

Shapes::~Shapes(){

}

void PrintPoints(const Body *shape){
    for(int i = 0; i < sizeof(shape) ; ++i){
        float x_proj = shape[i][0] / -shape[i][2];
        float y_proj = shape[i][1] / -shape[i][2];
        printf("Projected corner %d: x:%f, y:%f\n", i, x_proj, y_proj);
    }
}

void PrintPoints(std::vector<std::vector<float>> shape){
    for(int i = 0; i < sizeof(shape) ; ++i){
        float x_proj = shape[i][0] / -shape[i][2];
        float y_proj = shape[i][1] / -shape[i][2];
        printf("Projected corner %d: x:%f, y:%f\n", i, x_proj, y_proj);
    }
}