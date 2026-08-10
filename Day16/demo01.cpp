/*
Hierarchy:

Type of hierarchy:
- Is a: Inheritance and polymorphism
    - Dog -> Animal
- Has a: Composition and aggregation
    - Car contains Engine
- Uses a: Dependency
    - Printer uses logger
- Creates a: Instantiation
    - orderfactory creates order
    - one object creates another object

Is a: Inheritance 
- Meanning 
    - Dog is an Animal
    - Car is a Vehicle
    - Circle is a Shape
- meaning : A specialized class inherihs properties and behavior from a more general class

Has a : Composition and aggregation
- Meaning: A class contains another class as a member variable
- Composition: A class contains another class as a member variable and is responsible for its lifetime
- Aggregation: A class contains another class as a member variable but is not responsible for its lifetime
- Example:
    - Car has an Engine, wheels , battery 
Computer has Mothroad and its has processor on it its multilevel composition
- Doe one object contains anaoher -> yes

Aggreation: A class contains another class as a member variable but is not responsible for its lifetime
- Example: A class contains a pointer to another class as a member variable but is not responsible for its lifetime
-> Meaning object can exist independently of each other

Composition: A class contains another class as a member variable and is responsible for its lifetime
- Child object cannot exist without parent object
- House has a Room, Room cannot exist without House
house collapse -> room will also collapse
- Strong ownership: A class contains another class as a member variable and is responsible for its lifetime
- Same life time: A class contains another class as a member variable and is responsible for its lifetime

Read notes

USE- A: Dependency

Modern Pesrcpetive on inheritance -> over composition

*/