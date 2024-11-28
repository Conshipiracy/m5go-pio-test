#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include "programs/ProgramInterface.h"
#include <M5Stack.h>
#include <util/grid/grid.h>
#include <string>

#define WIDTH 100
#define HALF_WIDTH WIDTH / 2
#define QUART_WIDTH WIDTH / 4

#define HEIGHT 100
#define HALF_HEIGHT HEIGHT / 2
#define QUART_HEIGHT HEIGHT / 4

class HelloWorld : public ProgramInterface {
    public:
    void setup() override;
    void loop() override;
};

#endif