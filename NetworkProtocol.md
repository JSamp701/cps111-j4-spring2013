# Server to Client #

## When Communication will occur ##

At the beginning of the match.

50 times per second as long as the game is running.

At the end of the match.

## What communication will occur ##

For minions: minion information (at least ID, position, and state) will always be communicated.  If a minion is not communicated, delete it.

For Towers: communication will occur only when needed (at initialization and updates, such health / state).  Do not delete until end of game.

For Players: communication will always occur (at least ID, position, and state).  Do not delete until end of game session.

For Core: communication will occur only when needed (at initialization and update, such as health).  Do not delete until end of game.

## Suggested vectors on client ##


### Cores - clickable ###

> "static" vector

> do not update unless explicitly told to by server

## Towers - clickable ##

> "static" vector

> do not update unless explicitly told to by server

### Minions - clickable ###

> "dynamic" vector

> update from communication string - delete if not present in communication string.

### Players - clickable ###

> "static" vector

> update if present in string, leave as is if not present

> upon "dead" string, hide from map

> upon "alive" string, place at map on given coordinates

### Shots - NOT clickable ###

> "dynamic" vector

> update if present in string, delete if not



## Information strings ##

### KEY ###

> ENTVARIANT = a special number denoting both the type of entity as well as the variant (this parameter is more highly compressed than the original)

> FIRST TERM = the OBJECT type

> ID = int - Directly tied to objects on server side

> TEAM = 1 or 2

> PERCENT-HEALTH = int.  Use as value / 100

> STATE = will be an integer value, 1-8 for idle (1 = north), 11-18 for moving (11 for north), 21-28 for attacking (21 = north), and 99 for dying.

> XCOORD = int

> YCOORD = int

> Level = int

> PLAYERNAME = string to display


### Core information strings ###

ENTTYPE = 1x;

Variants: 2

**Variant 11: Creation**

Structure:  "ENTVARIANT ID TEAM PERCENT-HEALTH XCOORD YCOORD"

Example:   "11 2 2 97 2384 1838"

**Variant 15: Health Change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH"

Example:   "15 2 68"

**Variant 19: Death**

Structure:  "ENTVARIANT ID"

Example:    "19 9"

## Tower information strings ##

ENTTYPE = 2x;

Variants: 5

**Variant 21: Creation**

Structure:  "ENTVARIANT ID TEAM PERCENT-HEALTH STATE XCOORD YCOORD"

Example:    "21 9 1 100 7 1285 1234"

**Variant 23: State-change**

Structure:  "ENTVARIANT ID STATE"

Example:    "23 13 4"

**Variant 25: Health-change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH"

Example:    "25 11 63"

**Variant 27: State and Health changes**

Structure:  "ENTVARIANT ID PERCENT-HEALTH STATE"

Example:    "27 9 97 3"

**Variant 29: Death**

Structure:  "ENTVARIANT ID"

Example:    "29 9"

### Minion information ###

ENTTYPE = 3x;

Variants = 9

**Variant 31: Creation**

Structure:  "ENTVARIANT ID TEAM PERCENT-HEALTH STATE XCOORD YCOORD"

Example:    "31 86 2 100 15 2059 1003"

**Variant 32: Position change**

Structure:  "ENTVARIANT ID XCOORD YCOORD"

Example:    "32 21 1050 2901"

**Variant 33: State change**

Structure:  "ENTVARIANT ID STATE"

Example:    "33 45 19"

**Variant 34: State and position change**

Structure:  "ENTVARIANT ID STATE XCOORD YCOORD"

Example:    "34 23 21 550 2191"

**Variant 35: Health change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH"

Example:    "35 21 84"

**Variant 36: Health and position change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH XCOORD YCOORD"

Example:    "36 46 21 3750 2150"

**Variant 37: Health and state change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH STATE"

Example:    "37 11 78 28"

**Variant 38: Health, state, and position change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH STATE XCOORD YCOORD"

Example:    "38 24 87 38 2345 1245"

**Variant 39: Death**

Structure:  "ENTVARIANT ID"

Example:    "39 14"

### Player information ###

ENTTYPE = 4;

Variants = 9;

**Variant 41: Creation**

Structure = "ENTVARIANT ID TEAM PERCENT-HEALTH STATE XCOORD YCOORD PLAYERNAME"

Example =   "41 7 2 21 8 3479 2690 JOEL"

**Variant 42: Position change**

Structure:  "ENTVARIANT ID XCOORD YCOORD"

**Variant 43: State change**

Structure:  "ENTVARIANT ID STATE"

**Variant 44: State and Position change**

Structure:  "ENTVARIANT ID STATE XCOORD YCOORD"

**Variant 45: Health change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH"

**Variant 46: Health and Position change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH XCOORD YCOORD"

**Variant 47: Health and State change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH STATE"

**Variant 48: Health, State, and Position change**

Structure:  "ENTVARIANT ID PERCENT-HEALTH STATE XCOORD YCOORD"

**Variant 49: Death**

Structure:  "ENTVARIANT ID"

### Shot information ###

ENTTYPE = 5;

No Variants

Structure = "ENTTYPE XCOORD YCOORD"

Example =   "5 1018 654"

### Stats information ###

MESSAGE-TYPE = 50;

Structure = "(PLAYERINDICATOR PLAYERNAME TEAM TOWERKILLS MINIONKILLS PLAYERKILLS PLAYERDEATHS) TIME"

Where things in parenthesis will happen for each player

PLAYERINDICATOR = P;

time is in 20ms units

Example =   "50 P JonNeves 2 2 10 3 50000"

## Pause ##

MESSAGE-TYPE = 7

# Client - Server #


## When communication will occur ##

Before the game starts(username, screen resolution, difficulty[user](single.md))


Send information only when a button is pressed or released, or when a label is clicked.

## Communication Strings ##

### Label Click ###

MESSAGE-TYPE = 1;

EID = the ID of entity-object associated with the entity-label clicked (P.S. make your life easier, and institute a "clicked" event handler on the entityLabel class that sends a signal along the TCP Socket bound to your client)

Structure =  "MESSAGE-TYPE EID"

Example =    "1 25"

### Button Press ###

MESSAGE-TYPE = 2;

BUTTON# = 1 for W, 2 for D, 3 for S, and 4 for A;

Structure =  "MESSAGE-TYPE BUTTON"

Example =    "2 4"

### Button Release ###

MESSAGE-TYPE = 3;

BUTTON# = 1 for W, 2 for D, 3 for S, and 4 for A;

Structure =  "MESSAGE-TYPE BUTTON"

Example = "3 2"

### Save Game ###

MESSAGE-TYPE = 4
Structure = STRING FILENAME

### Load Game ###

MESSAGE-TYPE = 5
Structure = FILENAME USERNAME

### Pause Game ###

MESSAGE-TYPE = 7

### Start Network Game ###

MESSAGE-TYPE = 9
Structure = TEAM USERNAME