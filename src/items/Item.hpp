//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ITEM_HPP
#define MINOR_CPP1_ITEM_HPP

#include <string>

namespace Player {
    class Player;
}

namespace Items {
    using std::string;

    class Item {
    public:
        Item(string name, string description);
        virtual ~Item();

        string get_name();
        string get_description();
        int get_uses();

        bool is_usable();

        virtual void use(Player::Player* target)=0;
    protected:
        int _uses;
        string _name;
        string _description;
    };
}


#endif //MINOR_CPP1_ITEM_HPP
