//
// Created by mafn on 10/27/16.
//

#include <items/useable_items/HealthPotion.hpp>
#include <items/useable_items/HpStatPotion.hpp>
#include <items/useable_items/HitChancePotion.hpp>
#include <items/useable_items/DefencePotion.hpp>
#include <items/useable_items/Whetstone.hpp>
#include "ItemFactory.hpp"
#include "WeaponFileParser.hpp"
#include "util/RandomUtil.hpp"

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
            new HealthPotion(),
            new HpStatPotion(),
            new HitChancePotion(),
            new DefencePotion(),
            new WhetStone()
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

    Item* ItemFactory::get_random_item(){
        int random_index = RANDOM.get_random_int(0, this->_known_items.size() - 1);

        ItemMap::iterator random = this->_known_items.begin();
        advance(random, random_index);

        return create_item((*random).first);
    }
}