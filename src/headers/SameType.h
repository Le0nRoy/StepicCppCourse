//
// Created by lap on 9/30/20.
//

#ifndef STEPICCPPCOURSE_SAMETYPE_H
#define STEPICCPPCOURSE_SAMETYPE_H

namespace stepic {
template <class T, class U>
struct SameType {
    static const bool value = false;
};
template <class T>
struct SameType<T,T> {
    static const bool value = true;
};
}
#endif //STEPICCPPCOURSE_SAMETYPE_H
