#ifndef NEURON_H
#define NEURON_H
#include <vector>

class Neuron
{

public:

    class Akson{
    public:
        float getSignal();
        Neuron *ownerNeuron;
    };

    class Dendrit{
    public:
        float weight = 0.1;
        Akson *inputAkson;
    };


    Neuron();
    std::vector<Dendrit> dendrits;
    Akson akson;
    virtual float kernelFunction();
    float value;
};

#endif // NEURON_H
