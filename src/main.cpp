#include <programs/hello_world/hello_world.h>

ProgramInterface* program = new HelloWorld();

void setup() {
  program->setup();
}

void loop() {
  program->loop();
}