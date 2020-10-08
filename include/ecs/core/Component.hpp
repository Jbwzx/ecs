#pragma once

#include <EASTL/numeric_limits.h>
#include "EntitySystemTypes.hpp"

class Component {
    static constexpr size_t INVALID_POOL_INDEX = eastl::numeric_limits<size_t>::max();

    EntityId m_entityId;
    size_t m_poolIndex;

public:
    Component() : m_entityId(INVALID_ENTITY_ID), m_poolIndex(INVALID_POOL_INDEX) {};
    virtual ~Component() = default;
    virtual bool Init(void* pDescription) = 0; // TODO

    EntityId GetEntityId() const { return m_entityId; } // TODO private?
    void SetEntityId(EntityId id) { m_entityId = id; }

    size_t GetPoolIndex() const { return m_poolIndex; }
    void SetPoolIndex(size_t index) { m_poolIndex = index; }
};
