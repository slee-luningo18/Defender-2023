#include "ResourceHolder.h"
#include <stdexcept>

template<typename Resource,typename Identifier>
void ResourceHolder<Resource,Identifier>::load(Identifier ID, const string& filename)
{
    unique_ptr<Resource> resource(new Resource());
    if(!resource->loadFromFile(filename))
        throw std::runtime_error(filename + " cannot be opened");
    ResourceMap.insert(make_pair(ID, move(resource)));
}
template<typename Resource,typename Identifier>
Resource& ResourceHolder<Resource,Identifier>::get(Identifier ID)
{
    auto found = ResourceMap.find(ID);
    return *found->second;
}
template class ResourceHolder<Texture,Textures>;
template class ResourceHolder<Font,Fonts>;

