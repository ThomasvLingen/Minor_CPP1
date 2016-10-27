//
// Created by jazula on 10/17/16.
//

#include "Item.hpp"

namespace Items {

    Item::Item(string name, string description, int uses)
    : _name(name)
    , _description(description)
    , _uses(uses)
    {

    }

    Item::~Item()
    {

    }

    string Item::get_name()
    {
        return this->_name;
    }

    string Item::get_description()
    {
        return this->_description;
    }

    bool Item::is_usable()
    {
        return this->get_uses() > 0;
    }

    int Item::get_uses()
    {
        return this->_uses;
    }
}