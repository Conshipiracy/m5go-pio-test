#pragma once

class ProgramInterface {
    public:
    virtual ~ProgramInterface() = default;
    
    virtual void setup() = 0;
    virtual void loop() = 0;
};
