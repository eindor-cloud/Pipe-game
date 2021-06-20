OOP ex 4
__Pipe_game__
//----------------------------------------------------------------------------
2. Creators:
a- Amit Ein-Dor   ID 208625681
b- Adi Gutman     ID 318166600
//----------------------------------------------------------------------------
3. General ideas and goals of ex.4:
A Pipe game which draw every pipe connected to the source
when the water get to the destination the level is over.
the problem is detecting all of the pipes connected to the source,
using the exception methods, iterator and sfml learned in class.
//----------------------------------------------------------------------------
4. Files:
Source files: 
all files with no description holds the ctrs and methods from headers
-CMakeLists.txt - Cmake file to all src files.
Classes:
-main -main c++
-Controller - the operative class
-Object - any kind of pipe\source\destination, all the objects printed
	on the screen inherit from the basic object.
-Board - read from the file and convert the data to an array of objects
-Graph - another databes, holds objects and for each object hold a list
	of his neighbors to represent a graph, needed for algorithms.
-Textures - singelton, holds all the textures needed for the game

*objects:
-Rotatable - all objects that can be rotated inherit from it
-Blank - just take a spot on the screen, water dont flow through (can't connect to anyone)
-Pipe\Curved_pipe\Trai_pipe - kind of objects. (water flow through them)
-Source - everything connected to this object get water
-destination - when water flow to the dest the level is over

//----------------------------------------------------------------------------
5. Data structures :
Board make a 2d vector of Objects, the controller hold this vector and
print it each round.
Graph - a graph of Objects, represented by unordered map, the key is the Object
and every object has its list of neighbors 
(which are other objects that connected to this object and water can flow through).

//----------------------------------------------------------------------------
6. Algorithems that are worth mentioning:
- DFS on the graph:
	*converting each valid route into a neighbor list (as stated before).
	*by using RTTI we start the DFS only from a source object.
	*the DFS will activate water flow through all of the objects that their 
     (graph)distance from the source isnt infinity (connect all object in route).
//----------------------------------------------------------------------------
7. Known bugs:
- none
//----------------------------------------------------------------------------
8. Other notes:
- the draw functions cannot be const because the tap_counter's draw cannot be const.
- you have to put a "map.txt" file that contain the maps, map size and list of neighbors is'nt needed. 
- the log.txt file incase of a failure will be opened inside the out file.