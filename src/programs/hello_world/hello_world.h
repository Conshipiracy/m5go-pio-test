#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include "programs/ProgramInterface.h"
#include <M5Stack.h>
#include <util/grid/grid.h>

class HelloWorld : public ProgramInterface {
    public:
    void setup() override;
    void loop() override;
};

#endif