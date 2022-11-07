# OOP pattern

This contains a template for creating classes (not complete) in the C language.

## The main rule when creating OOP classes in C:
1. **ONE CLASS DECLARATION - ONE FILE**

This rule will allow you to combine declarations of related entities (data and methods [xexexe]) at the code level, since the file is a separate unit of translation.

> Encapsulation can be recreated by establishing access rules at the user level (for example, specifying specific rules for naming entities that the user is denied access to).

There is one serious drawback in C: you cannot create separate scopes, and there is no way to distinguish between private, public, etc. scopes. This problem leads to the fact that at the code level it is impossible to combine two related entities: functions and data into one object. But at the user level, you can agree on certain usage rules that will regulate the level of access to entities (for example, by documenting each entity with a scope, as well as using a special style for naming entities). Thus, it is possible to artificially reproduce one of the main principles of OOP - ***ENCAPSULATION***.



2. **ONE IMPLEMENTATION - ONE FILE**

>

3. **ONE CLASS - ONE DIRECTORY**

>