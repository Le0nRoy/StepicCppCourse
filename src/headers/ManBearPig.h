//
// Created by lap on 10/3/20.
//

#ifndef STEPICCPPCOURSE_MANBEARPIG_H
#define STEPICCPPCOURSE_MANBEARPIG_H

#include <cstddef>
#include <string>

// этот класс уже определён выше
struct Unit {
    explicit Unit(size_t id) :
            id_(id) {}

    size_t id() const {
        return id_;
    }

private:
    size_t id_;
};


// базовый класс для животных
struct Animal : virtual public Unit {
    // name хранит название животного
    // "bear" для медведя
    // "pig" для свиньи
    Animal(const std::string &name, size_t id) :
            Unit(id),
            name_(name) {}

    std::string const &name() const {
        return name_;
    }

private:
    std::string name_;
};

// класс для человека
struct Man : virtual public Unit {
    explicit Man(size_t id) :
            Unit(id) {}
};

// класс для медведя
struct Bear : public Animal, virtual public Unit {
    explicit Bear(size_t id) :
            Unit(id),
            Animal("bear", id) {}
};

// класс для свиньи
struct Pig : public Animal, virtual public Unit {
    explicit Pig(size_t id) :
            Unit(id),
            Animal("pig", id) {}
};

// класс для челмедведосвина
struct ManBearPig : public Man, Bear, Pig, virtual public Unit {
    ManBearPig(size_t id) :
            Unit(id),
            Man(id),
            Bear(id),
            Pig(id) {}
};

#endif //STEPICCPPCOURSE_MANBEARPIG_H
