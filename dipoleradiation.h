/*
 * dipoleradiation.h
 *
 *  Created on: 2023/06/07
 *      Author: ando
 */

#ifndef DIPOLERADIATION_H_
#define DIPOLERADIATION_H_

#include <complex>

using Current_f = std::complex <double> (*)(double);

std::complex <double> Etheta(
    const double omega__Angular_frequency,
    std::complex <double> Idl__Current_filament,
//    Current_f Idl__Current_filament,
    const double r__Distance_from_current);


#endif /* DIPOLERADIATION_H_ */
