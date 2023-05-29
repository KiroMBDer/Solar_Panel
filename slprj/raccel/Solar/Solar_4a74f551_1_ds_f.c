#include "ne_ds.h"
#include "Solar_4a74f551_1_ds_sys_struct.h"
#include "Solar_4a74f551_1_ds_f.h"
#include "Solar_4a74f551_1_ds.h"
#include "Solar_4a74f551_1_ds_externals.h"
#include "Solar_4a74f551_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Solar_4a74f551_1_ds_f ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t5 , NeDsMethodOutput * t6 ) { PmRealVector out ;
real_T Solar_Panel_Solar_Cell_CCS_i ; real_T U_idx_0 ; real_T U_idx_1 ;
real_T X_idx_0 ; real_T X_idx_1 ; int32_T M_idx_0 ; int32_T M_idx_1 ; M_idx_0
= t5 -> mM . mX [ 0 ] ; M_idx_1 = t5 -> mM . mX [ 1 ] ; U_idx_0 = t5 -> mU .
mX [ 0 ] ; U_idx_1 = t5 -> mU . mX [ 1 ] ; X_idx_0 = t5 -> mX . mX [ 0 ] ;
X_idx_1 = t5 -> mX . mX [ 1 ] ; out = t6 -> mF ; Solar_Panel_Solar_Cell_CCS_i
= X_idx_0 * 0.33333333333333331 + X_idx_1 ; X_idx_0 = U_idx_0 *
0.016666666666666718 * 1.602176487E-19 / 6.1746137514E-21 ; if ( M_idx_0 != 0
) { Solar_Panel_Solar_Cell_CCS_i -= U_idx_1 * 2.7266666666666666 / 1000.0 ; }
if ( X_idx_0 > 80.0 ) { X_idx_0 = X_idx_1 - ( ( X_idx_0 - 79.0 ) *
5.54062238439351E+34 - 1.0 ) * 3.48954275907586E-7 ; } else if ( M_idx_1 != 0
) { X_idx_0 = X_idx_1 - ( ( X_idx_0 + 80.0 ) * 4.9060947306492808E-35 - 1.0 )
* 3.48954275907586E-7 ; } else { X_idx_0 = X_idx_1 - ( pmf_exp ( X_idx_0 ) -
1.0 ) * 3.48954275907586E-7 ; } out . mX [ 0 ] = Solar_Panel_Solar_Cell_CCS_i
; out . mX [ 1 ] = X_idx_0 ; ( void ) sys ; ( void ) t6 ; return 0 ; }
