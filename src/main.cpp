#include <programs/hello_world/hello_world.h>
#include <programs/matrix/matrix.h>

ProgramInterface* program = new MatrixApp();

void setup() {
  program->setup();
}

void loop() {
  program->loop();
}
