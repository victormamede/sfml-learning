#pragma once

#include <map>
#include <memory>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
  void load(Identifier id, const std::string &filename);
  template <typename Parameter>
  void load(Identifier id, const std::string &filename,
            const Parameter &secondParam);

  Resource &get(Identifier id);
  const Resource &get(Identifier id) const;

private:
  std::map<Identifier, std::unique_ptr<Resource>> _resourceMap;
};

#include "ResourceHolder.inl"