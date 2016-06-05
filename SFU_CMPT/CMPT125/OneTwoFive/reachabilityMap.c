//
//  reachabilityMap.c
//  OneTwoFive
//
//  Created by June Kim on 2016-06-05.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct CoordinatesStruct {
    int x;
    int y;
};
typedef struct CoordinatesStruct Coordinates;

void traverse(int, int**, Coordinates, int**);

//precondition: elevationMap is a mapSize by mapSize matrix containing integers greater than zero
//the original elevation map is not modified
//postcondition: reachability indicates the possible places to travel from starting coordinates with 1's and 0's in a separate matrix
int** reachability(int mapSize,
                   //pass in the map by reference
                   int** elevationMap,
                   //coordinates enhance readability
                   Coordinates start) {
    //instantiate a map full of zeros
    int **reachableMap = (int **)malloc(mapSize * sizeof(int *));
    for (int row = 0; row < mapSize; row++) {
        reachableMap[row] = (int *)malloc(mapSize * sizeof(int));
        for (int column = 0; column < mapSize; column++) {
            reachableMap[row][column] = 0;
        }
    }
    
    //recursive helper
    traverse(mapSize, elevationMap, start, reachableMap);
    
    //return the map of all reachable places
    return reachableMap;
}

//Description: a recursive depth-first map traversal
//Params: elevationMap and reachableMap live in the heap, and passed by reference. step contains the coordinate being traversed.
void traverse(int mapSize,
              //pass in the map by reference
              int** elevationMap,
              Coordinates step,
              //also pass in the reachable map by reference
              int** reachableMap) {
    //No two places on the elevation map are traversed more than once
    assert(reachableMap[step.x][step.y] < 1);
    
    //leave breadcrumbs of bits at the current position.
    reachableMap[step.x][step.y] += 1;
    
    //attempt to traverse adjacent squares by checking and stepping
    
    //unless at the westmost edge of map.
    if (step.x > 0) {
        Coordinates west = (Coordinates){ .x = step.x - 1, .y = step.y };
        checkAndTraverse(west);
    }
    //unless at the eastmost edge of map.
    if (step.x < mapSize - 1) {
        Coordinates east = (Coordinates){ .x = step.x + 1, .y = step.y };
        checkAndTraverse(east);
    }
    //unless at the northmost edge of map.
    if (step.y > 0) {
        Coordinates north = (Coordinates){ .x = step.x, .y = step.y - 1 };
        checkAndTraverse(north);
    }
    //unless at the southmost edge of map.
    if (step.y < mapSize -1) {
        Coordinates south = (Coordinates){ .x = step.x, .y = step.y - 1 };
        checkAndTraverse(south);
    }
    
    //nested function to clean up code
    void checkAndTraverse(Coordinates nextStep) {
        int nextIsTraversed = reachableMap[nextStep.x][nextStep.y] > 0;
        int currentElevation = elevationMap[step.x][step.y];
        int nextStepElevation = elevationMap[nextStep.x][nextStep.y]
        //if the next step step has not yet been traversed,
        if (!nextIsTraversed &&
            //and the slope isn't to steep
            abs(currentElevation - nextStepElevation) <= 2) {
            //go there, and repeat traversal.
            traverse(mapSize, elevationMap, step, reachableMap);
        }
        //otherwise the next step should not be traversed
    }
}



/*
 __Runtime analysis__
 
 If the upper bound and the lower bound for the growth rate of f(n) are equal, then f ∈ O(lower and upper bound)
 
 Investigating an upper bound for f(n), we model the grid as a graph with coordinates as nodes and traversals as edges. For each additional node, there are at most two additional edges. 
 Proof by induction: 
 Base case: 
    For one coordinate, there are no possible traversals.
 Inductive case: 
    Consider the addition of a coordinate.
    In the case that there is one row on the map:
        there is only one traversal allowed in a single direction
    In the case that there are multiple rows on the map:
        there cannot be three or more directions in traversals, since all the previous coordinates have been arranged without concavity
 Thus, if there are at most two traversals per coordinate, and there are n^2 coordinates, then there are at most 2*n^2 possible traversals.
 
 A depth-first graph search algorithm runs in O(V+E), and there are n^2 vertices with 2*n^2 edges. Because the traversal algorithm shown above is a depth-first graph search with only constant-time additional comparisons per traversal, this puts an upper limit on the runtime of O(V+2V) == O(V) == O(n^2).
 
 For another upper limit (for the sake of exercise), we establish the runtime on the basis of the assertion provided at the beginning of traverse. No two places on the elevation map are traversed more than once, and this is guaranteed by the checking of nextIsTraversed in the nested function checkAndTraverse. This implies that given n^2 coordinates, the traverse function will run at most n^2 times. The number of comparisons and function calls are finite and constant for traverse.

 For the lower limit, the input size is n^2 and the worst-case input of a flat elevation map, all the coordinates will have to be traversed and recorded as valid, regardless of the algorithm's inherent complexity in order to ensure correctness. This implies Ω(n^2).
 
 So despite the fact that the recursive call to traverse makes it look like a divide-and-conquer algorithm suggesting a O(n^2*log(n^2)) runtime, the overlapping nature of coordinates and its graphlikeness limits the runtime to O(n^2). 

*/











