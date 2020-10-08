#pragma once

#include <EASTL/type_traits.h>

#define COUNTER_READ_CRUMB( TAG, RANK, ACC ) counter_crumb( TAG(), constant_index< RANK >(), constant_index< ACC >() )
#define COUNTER_READ( TAG ) COUNTER_READ_CRUMB( TAG, 1, COUNTER_READ_CRUMB( TAG, 2, COUNTER_READ_CRUMB( TAG, 4, COUNTER_READ_CRUMB( TAG, 8, \
    COUNTER_READ_CRUMB( TAG, 16, COUNTER_READ_CRUMB( TAG, 32, COUNTER_READ_CRUMB( TAG, 64, COUNTER_READ_CRUMB( TAG, 128, 0 ) ) ) ) ) ) ) )

#define COUNTER_INC( TAG ) \
constexpr \
constant_index< COUNTER_READ( TAG ) + 1 > \
counter_crumb( TAG, constant_index< ( COUNTER_READ( TAG ) + 1 ) & ~ COUNTER_READ( TAG ) >, \
                                                constant_index< ( COUNTER_READ( TAG ) + 1 ) & COUNTER_READ( TAG ) > ) { return {}; }

#define COUNTER_LINK_NAMESPACE( NS ) using NS::counter_crumb;

template< size_t n >
struct constant_index : eastl::integral_constant< size_t, n > {};

template< typename id, size_t rank, size_t acc >
constexpr constant_index< acc > counter_crumb( id, constant_index< rank >, constant_index< acc > ) { return {}; } // found by ADL via constant_index