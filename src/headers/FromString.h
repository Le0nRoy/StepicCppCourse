//
// Created by lap on 10/20/20.
//

/**
*    Для того, чтобы учитывать пробельные символы, используйте std::noskipws
    (например, если строка с числом начинается с пробела или заканчивается пробелом,
    то это должно быть ошибкой).
*    Помните, что считывание std::string из потока означает считывание одного слова
    (т.е. без пробельных символов), а считывание char — одного символа.
*    Флаг eof() у потоков устанавливается только, если не удалось прочитать символ:
    если при чтении из потока с 5-ю символами прочли 5 символов, но при этом 6-ой
    (отсутствующий) символ прочесть не пытались, то eof() будет выдавать false.
*    Если Вы определили исключение с ключевым словом class, но не забудьте,
    что нужно унаследоваться от std::exception с ключевым словом public.
*    При переопределении метода what класса std::exception после сигнатуры метода нужно
    указывать ключевое слово noexcept (про него будет рассказано позже).
*    Не забудьте определить конструктор bad_from_string от char const * или от std::string.
 */

#ifndef STEPICCPPCOURSE_FROMSTRING_H
#define STEPICCPPCOURSE_FROMSTRING_H

#include <string>
#include <sstream>
#include <exception>
#include <utility>
#include <typeinfo>

namespace stepic {

struct bad_from_string : public std::exception {
    bad_from_string() = default;

    bad_from_string(std::string data) :
            data_(std::move(data)) {}

    const char *what() const noexcept override {
        return data_.data();
    }

private:
    std::string data_;
};

template <class T>
T from_string(std::string const &s) {
    T res;
    std::istringstream str(s);
    str >> std::noskipws >> res;
    if (str.fail() || str.peek() != EOF) {
        std::string message("Error while processing ");
        message.append(typeid(T).name());
        throw bad_from_string(message);
    }
    return res;
}
}

#endif //STEPICCPPCOURSE_FROMSTRING_H
