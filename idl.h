/*
 * idl.h
 *
 * Idl(t) = ( t - t0 ) / σ * exp( - ( t - t0 )^2 / (2*σ^2) )
 *
 * Idl(ω) = -j √(2π) * ωσ^2 exp( - σ^2 ω^2 / 2 ) exp(-jωt0)
 *
 *  Created on: 2023/06/07
 *      Author: ando
 */

#ifndef IDL_H_
#define IDL_H_

#include <complex>

#include <physical_constants.h>

constexpr double DX { 1.0e0 }; /* FDTDの電流源に用いた値(1) */
constexpr double tDx { 2.0*DX/C0 }; /* FDTDの電流源に用いた値(2) */
constexpr double sig { 5.0 * tDx };
constexpr double t0 { 6.0 * sig };

constexpr double dB_omega_max { -100.0 };
constexpr double omega_max { std::sqrt(-dB_omega_max/20.0 * 2.0/0.4343) / sig };

constexpr double t_max { 4.0 * t0 };

std::complex <double> Idl(double omega);

#endif /* IDL_H_ */
