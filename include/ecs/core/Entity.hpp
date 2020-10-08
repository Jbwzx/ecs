#pragma once

#include <EASTL/hash_map.h>
#include "EntitySystemTypes.hpp"
#include "Component.hpp"

class Entity {
    EntityId m_id;
    eastl::hash_map<EntityId, Component*> m_components;

public:
    explicit Entity(EntityId id) : m_id(id) {}
    EntityId GetId() const { return m_id; }


    template<class CompType>
    CompType* GetComponent() const {
        auto findIt = m_components.find(CompType::ID);
        if (findIt != m_components.end())
            return findIt->second;
        return nullptr;
    }
};


