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
        Item(string name, string description, int uses);
        Item(const Item& obj);
        virtual ~Item();
        virtual Item* clone()=0;

        string get_name();
        string get_description();
        int get_uses();

        bool is_usable();

        void use(Player::Player* target);
        virtual void use_handler(Player::Player *target)=0;
    protected:
        string _name;
        string _description;
        int _uses;
    };
}


#endif //MINOR_CPP1_ITEM_HPP
