//
// Created by lap on 9/30/20.
//

#ifndef STEPICCPPCOURSE_BASED1D2D3_H
#define STEPICCPPCOURSE_BASED1D2D3_H

namespace stepic {
struct Base {};

struct D1 : Base {};

struct D2 : Base {};

struct D3 : D1, D2 {};

/// \param base Pointer on instance of D3->D1 class
/// \return Pointer on D2 class
Base const *D1BaseToD2Base(Base const *base);
}

#endif //STEPICCPPCOURSE_BASED1D2D3_H
