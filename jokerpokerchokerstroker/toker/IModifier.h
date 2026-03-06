#ifndef IMODIFIER_H
#define IMODIFIER_H
#pragma once
#include <string>
struct Score;


class IModifier {
public:
virtual void apply(Score &score) = 0;
    virtual std::string getName() = 0;
    virtual ~IModifier() {}
    
};

#endif