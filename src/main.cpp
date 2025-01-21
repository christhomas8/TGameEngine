#include "../include/engine.h"

int main(int argc, char const *argv[]){ 
    try{
        Engine engine;
        //engine.run();
        engine.runOpenGL();
    }
    catch (const std::exception& ex){
        console(ex.what());
        return -1;
    }

    return 0;
}