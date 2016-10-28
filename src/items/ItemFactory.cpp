//
// Created by mafn on 10/27/16.
//

#include <items/useable_items/HealthPotion.hpp>
#include "ItemFactory.hpp"
#include "WeaponFileParser.hpp"

namespace Items {

    ItemFactory::ItemFactory()
    {

    }

    ItemFactory::~ItemFactory()
    {
        for (auto item_pair : this->_known_items) {
            delete item_pair.second;
        }
    }

    void ItemFactory::register_weapons(string weapon_file_path)
    {
        WeaponMap map = WeaponFileParser::parse_weapons_file(weapon_file_path);

        for (auto weapon_pair : map) {
            this->_register_item(weapon_pair.second.clone());
        }
    }

    void ItemFactory::register_useables()
    {
        // This is high binding and therefore dirty
        vector<Item*> useable_items = {
            new HealthPotion()
        };

        for (Item* item : useable_items) {
            this->_register_item(item);
        }
    }

    void ItemFactory::_register_item(Item *new_item)
    {
        this->_known_items[new_item->get_name()] = new_item;
    }

    Item *ItemFactory::create_item(string name)
    {
        return this->_known_items[name]->clone();
    }
}