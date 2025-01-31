#include <globals.h>

template <typename T>

class Example{
    public:
        T var1;
        T var2;    
};

class Shapes {
    public:
        Shapes();
        ~Shapes();
        void PrintPoints(const Body *shape);
        void PrintPoints(std::vector<std::vector<float>> points);
};