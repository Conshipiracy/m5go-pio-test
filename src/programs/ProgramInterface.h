#ifndef PROGRAM_INTERFACE_H
#define PROGRAM_INTERFACE_H

class ProgramInterface {
    public:
    virtual ~ProgramInterface() = default;
    
    virtual void setup() = 0;
    virtual void loop() = 0;
};

#endif