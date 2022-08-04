#include <cassert>
#include "ResourceHolder.hpp"

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
  std::unique_ptr<Resource> resource(new Resource());

  if (!resource->loadFromFile(filename))
    throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

  auto inserted = _resourceMap.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename, const Parameter &secondParam)
{
  std::unique_ptr<Resource> resource(new Resource());

  if (!resource->loadFromFile(filename, secondParam))
    throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

  auto inserted = _resourceMap.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource &ResourceHolder<Resource, Identifier>::get(Identifier id)
{
  auto found = _resourceMap.find(id);
  assert(found != _resourceMap.end());

  return *found->second;
}

template <typename Resource, typename Identifier>
const Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
  auto found = _resourceMap.find(id);
  assert(found != _resourceMap.end());

  return *found->second;
}