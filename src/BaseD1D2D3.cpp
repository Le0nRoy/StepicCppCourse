//
// Created by lap on 9/30/20.
//

#include "headers/BaseD1D2D3.h"

namespace stepic {
Base const *D1BaseToD2Base(const Base *base) {
    const D1 *d1 = (const D1 *)(base);
    const D3 *d3 = (const D3 *)(d1);
    return (const D2 *)(d3);
}
}