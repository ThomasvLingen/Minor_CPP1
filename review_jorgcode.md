### General
Please namespace stuff.

### Floor

`Floor.cpp:10-11`
You can use an initialiser list for this

`Floor.cpp:13`
I'd personally use a `size_t` for the index.

`Floor.cpp:28`
This method does no bounds checking, setting a room outside of the map range means an exception

`Floor.cpp:33`
What does this return in case of an out of bounds location?

`Floor.cpp:42`
snake_case pls

`Floor.cpp:46`
See your own comment :p

`Floor.cpp:60`
What is the value of toPrint for a room of RoomType boss?

### Room
`Room.hpp`
Is there a reason Room does not have a constructor or destructor?

`Room.hpp:14`
Double `public:`

`Room.hpp:15-19`
Is there a reason the enums and structs are declared inside the class?
If you namespace it, it's not global  

`Room.hpp:29`
Nothing is done with `_decription`. You should generate this.

It surprises me that Room has 0 methods.

### RoomGenerator
Unused.

### DungeonGenerator
`DungeonGenerator.hpp:16`
Should be virtual

Wunderbar

### FloorGenerator
Lookin' good

### FloorPlan
`FloorPlan.hpp:16-17`
I don't find type very descriptive, reminds me of just a variable type!

`Floorplan.hpp:18`
Why?
you could also do
```
using Room::Location
```

`FloorPlan.cpp:20-21`
You can use an initialiser list.

`FloorPlan.cpp:24 & 26`
The indexes can be size_t's, getting rid of casts

`FloorPlan.cpp:35`
This method does no bounds checking, setting a room outside of the map range means an exception

`FloorPlan.cpp:45`
Why not use `this->set_room`?

`FloorPlan.cpp:49`
Quite a big function, listen to your own advice and split it ;p

`FloorPlan.cpp:62-63`
use `this->`

`FloorPlan.cpp:104-130`
Maybe this can be loopfied and mappified

`FloorPlan.cpp:133`
use `this->`

`FloorPlan.cpp:186`
docs are incomplete, only states what it does half the time

`FloorPlan.cpp:196-205`
Map this instead

`FloorPlan.cpp:65`
use `this->`

`FloorPlan.cpp:156`
This function should be a part of Location as an operator
see [this](http://stackoverflow.com/questions/14047191/overloading-operators-in-typedef-structs-c)

`FloorPlan.cpp:168`
Mappify

`FloorPlan`
This class makes a HUGE assumption, that RoomType is the only real thing to generate.
if in the future we want to generate more properties, big changes to FloorPlan are needed.
