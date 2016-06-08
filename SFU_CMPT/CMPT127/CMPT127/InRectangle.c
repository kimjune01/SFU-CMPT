//
//  InRectangle.c
//  CMPT127
//
//  Created by June Kim on 2016-06-08.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "InRectangle.h"

// declaration of function to test
int InRectangle( float pt[2], float rect[4] ){
    //TODO:
    /*
     pt[0] is the x-coordinate, pt[1] is the y-coordinate.
     Argument rect[4] defines a rectangle on the same plane. 
     rect[0] and rect[1] define the x- and y- cordinates
     rect[2] and rect[3] define the opposite corner.
     Coordinates may be negative.
     returns int 0 (false) for outside the rectangle, 
     1 for points inside and on the boundary of the rectangle
     */
    float xPoint = pt[0];
    float yPoint = pt[1];
    
    float rectMinX = rect[0];
    float rectMinY = rect[1];
    float rectMaxX = rect[2];
    float rectMaxY = rect[3];
    
    //xPoint must be between, inclusive
    int xIsBetween = xPoint >= rectMinX && xPoint <= rectMaxX;
    //yPoint must be between, inclusive
    int yIsBetween = yPoint >= rectMinY && yPoint <= rectMaxY;
    
    return xIsBetween && yIsBetween;
}

int InRectangleTest( int argc, char* argv[] )
{
    // define a rectangle from (1,1) to (2,2)
    float rect[4] = {1.0, 1.0, 2.0, 2.0 };
    
    // define a point that is inside the rectangle
    float p_in[2] = { 1.5, 1.5 };
    
    // define a point that is outside the rectangle
    float p_out[2] = {2.5, 0.5};
    
    // define a point that is on the edge of the rectangle
    float p_edge[2] = {1.0, 1.0};
    
    // InRectangle() should return 0 (false) for points that are NOT in
    // the rectangle, and non-zero (true) for points that are in the
    // rectangle. Points on the edge are considered *in* the rectangle.
    
    // test 1
    if( InRectangle( p_in, rect ) == 0 )
    {
        puts( "error: should return true for p_in." );
        return 1; // indicate error
    }
    
    // test 2
    if( InRectangle( p_out, rect ) != 0 )
    {
        puts( "error: should return false for p_out." );
        return 1; // indicate error
    }
    
    // test 3
    if( InRectangle( p_edge, rect ) == 0 )
    {
        puts( "error: should return true for p_edge." );
        return 1; // indicate error
    }
    
    return 0; // all tests passed
}