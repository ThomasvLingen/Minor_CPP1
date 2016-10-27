//
// Created by mafn on 10/27/16.
//

#ifndef MINOR_CPP1_ITEMFACTORY_HPP
#define MINOR_CPP1_ITEMFACTORY_HPP

#include <map>
#include "Item.hpp"

namespace Items {
    using std::string;
    using std::map;

    typedef map<string, Item*> ItemMap;

    class ItemFactory {
    public:
        ItemFactory();
        virtual ~ItemFactory();

        void register_weapons(string weapon_file_path);
        void register_useables();

        Item* create_item(string name);
    private:
        ItemMap _known_items;
        void _register_item(Item* new_item);
    };
}


#endif //MINOR_CPP1_ITEMFACTORY_HPP