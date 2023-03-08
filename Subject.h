//
// Created by Simone on 09/02/2023.
//

#ifndef PROGETTO_LISTA_SPESA_SUBJECT_H
#define PROGETTO_LISTA_SPESA_SUBJECT_H

#include "Observer.h"
#include <memory>

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() = 0;

protected:
    virtual ~Subject() = default;
};

#endif //PROGETTO_LISTA_SPESA_SUBJECT_H
