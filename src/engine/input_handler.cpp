#include "input_handler.h"

//std::list<Input>    InputMap::mapping;
std::map<std::string, std::list<const Uint8*>> InputMap::mapping;
const Uint8*                                   InputMap::keystate;

void InputMap::Handler()
{
    keystate = SDL_GetKeyboardState(NULL);
}

void InputMap::AddAction(std::string name, const Uint8* key)
{
    //std::list<const Uint8*> keyList;
    //keyList.push_front(key);
    mapping.insert({name, {key}});
}

void InputMap::AddKey(std::string name, const Uint8* key)
{
    //may have to make the input list static
    //auto search = mapping.find(name);
    //std::list<const Uint8*> val = search -> second;
    //val.push_front(key);
    mapping[name].push_front(key);
}

bool InputMap::IsPressed(std::string name)
{
    return false;
}