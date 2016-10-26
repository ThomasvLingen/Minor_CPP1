### General
Please namespace stuff.

**yes**

### Floor

`Floor.cpp:10-11`
You can use an initialiser list for this

**yes**

`Floor.cpp:13`
I'd personally use a `size_t` for the index.

**yes**

`Floor.cpp:28`
This method does no bounds checking, setting a room outside of the map range means an exception

**very true yes**

`Floor.cpp:33`
What does this return in case of an out of bounds location?

**moet deze niet gebruikt worden in floorplan for example**

`Floor.cpp:42`
snake_case pls

**okie**

`Floor.cpp:46`
See your own comment :p

**yes**

`Floor.cpp:60`
What is the value of toPrint for a room of RoomType boss?

**yes**

### Room
`Room.hpp`
Is there a reason Room does not have a constructor or destructor?

**yes location in constructor for example + roomtype**

`Room.hpp:14`
Double `public:`

**yes**

`Room.hpp:15-19`
Is there a reason the enums and structs are declared inside the class?
If you namespace it, it's not global

**namespace that shit**

`Room.hpp:29`
Nothing is done with `_decription`. You should generate this.

**yes**

It surprises me that Room has 0 methods.

### RoomGenerator
Unused.

**yes**

### DungeonGenerator
`DungeonGenerator.hpp:16`
Should be virtual

**yes**

Wunderbar

### FloorGenerator
Lookin' good

### FloorPlan
`FloorPlan.hpp:16-17`
I don't find type very descriptive, reminds me of just a variable type!
Why double roomtype defs

**yes, very true, was a reason for, cant remember**


`Floorplan.hpp:18`
Why?
you could also do
```
using Room::Location
```

**yes**

`FloorPlan.cpp:20-21`
You can use an initialiser list.

**yes**

`FloorPlan.cpp:24 & 26`
The indexes can be size_t's, getting rid of casts

**yes**

`FloorPlan.cpp:35`
This method does no bounds checking, setting a room outside of the map range means an exception

**yes**

`FloorPlan.cpp:45`
Why not use `this->set_room`?

**yes**

`FloorPlan.cpp:49`
Quite a big function, listen to your own advice and split it ;p

**yes**

`FloorPlan.cpp:62-63`
use `this->`

**yes**

`FloorPlan.cpp:104-130`
Maybe this can be loopfied and mappified

**yes, eventueel mapping maken tussen left right etc naar een - en + val voor width en height**

`FloorPlan.cpp:133`
use `this->`

**yes**

`FloorPlan.cpp:186`
docs are incomplete, only states what it does half the time

**yes**

`FloorPlan.cpp:196-205`
Map this instead

**yes**

`FloorPlan.cpp:65`
use `this->`

**yes**

`FloorPlan.cpp:156`
This function should be a part of Location as an operator
see [this](http://stackoverflow.com/questions/14047191/overloading-operators-in-typedef-structs-c)

**yes, very good**

`FloorPlan.cpp:168`
Mappify

**yes**

`FloorPlan`
This class makes a HUGE assumption, that RoomType is the only real thing to generate.
if in the future we want to generate more properties, big changes to FloorPlan are needed.

**no changes needed to floorplan, this has to be done in floor generator**
