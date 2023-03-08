//
// Created by Simone on 09/02/2023.
//

#ifndef PROGETTO_LISTA_SPESA_OBSERVER_H
#define PROGETTO_LISTA_SPESA_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;

protected:
    virtual ~Observer() = default;
};

#endif //PROGETTO_LISTA_SPESA_OBSERVER_H
