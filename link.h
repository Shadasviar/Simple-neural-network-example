#ifndef LINK_H
#define LINK_H

class Neuron;
class InputNeuron;

class Link
{
public:
    Neuron *neuron = nullptr;
    InputNeuron *inNeuron = nullptr;
    float weight = 1;
};

#endif // LINK_H
