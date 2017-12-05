//
//  CommandLineParserTest.cpp
//  RayTracer
//
//  Created by Alex Handby on 10/11/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

/*#include <stdio.h>
#include "gtest/gtest.h”*/

/*
 Specification:
 
 - ./raytracer. There needs to be a scene.txt file in the current directory where the program sits else it will through an error.
 
 - ./raytracer -f some/path/scene.txt then there needs to be a scene.txt file in the path that we have just provided else we will through an error.
 
 - ./raytracer -o some/path/ if this path does not exist then we create it. We also need permissions to write to the path else we will through an error.
 */

/* ./raytracer no commandline options
 assert that we are attempting to find the scene.txt in the current directory
 assert true that we have found it.
 assert that we are outputting to the default directory
 */

/*./raytracer no commandline options
 assert that we are attempting to find the scene.txt in the current directory
 assert that we are outputting to the default directory
 throw an error because we have not found it
 */

/*TEST (CommandLineParserTest, NoOptionsFilePresent) {
    Stack intStack;
    int a = 12;
    int b = 15;
    EXPECT_EQ (12, intStack.push(a));
    EXPECT_EQ (15, intStack.push(b));
    EXPECT_EQ (15, intStack.peek());
    EXPECT_EQ (15, intStack.peek());
}*/

/*./raytracer -f some/path/scene.txt 
 assert that we are finding the scene file in a provided path
 assert that we are outputting to the default directory
 assert true that we have found it.
 */

/*./raytracer -f some/path/scene.txt
assert that we are attempting to find the scene.txt in the current directory
assert that we are outputting to the default directory
throw an error because we cannot find it
 */

/*./raytracer -o some/path/
 assert that we are outputting to a specified location
 assert that we are looking for the scene.txt in the current directory
 assert true that we have found the output directory
 */

/*./raytracer -o some/path/
 assert that we are outputting to a specified location
 assert that we are looking for the scene.txt in the current directory
 assert true because we have not found the output directory and have created it
 */

/*./raytracer -o some/path/
 assert that we are outputting to a specified location
 assert that we are looking for the scene.txt in the current directory
 throw an error because we have tried to write to the output directory and we do not have the permissions to do so.
 */
