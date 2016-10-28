//
// Created by mafn on 10/27/16.
//

#ifndef MINOR_CPP1_ITEMFACTORY_HPP
#define MINOR_CPP1_ITEMFACTORY_HPP

#include <map>
#include "Item.hpp"
#include <iterator>

namespace Items {
    using std::string;
    using std::map;
    using std::iterator;
    using std::advance;

    typedef map<string, Item*> ItemMap;

    class ItemFactory {
    public:
        ItemFactory();
        virtual ~ItemFactory();

        void register_weapons(string weapon_file_path);
        void register_useables();

        Item* create_item(string name);
        Item* get_random_item();
    private:
        ItemMap _known_items;
        void _register_item(Item* new_item);
    };
}


#endif //MINOR_CPP1_ITEMFACTORY_HPP