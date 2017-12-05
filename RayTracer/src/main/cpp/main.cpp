//
//  main.cpp
//  RayTracer
//
//  Created by Alex Handby on 26/06/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include <iostream>
#include "program.h"


/*
 RayTracer Interface.
 
 - ./raytracer
	* if there is no scene.txt then we throw an error.
    * if the scene.txt data is incorrect then we throw an error.
	* if there is a scene.txt then we parse the scene, raytrace and write the data out to a tga file in the same directory.
 
 
 - ./raytracer -f some/path/scene.txt
    * if the path is wrong then we throw an error.
    * if scene.txt does not exist then we throw an error
    * if the scene.txt data is incorrect then we throw an error.
    * if there is a scene.txt then we parse the scene, raytrace and write the data out to a tga file in the same directory.
	
 
 - ./raytracer -o some/path/
	*if the path does not exist we will throw an error.
    *if we dont have permission to write to the folder then we throw an error.
    *if the argument provided is not a folder path then we throw an error.
    *if it is a valid path then we will output the image to that specified location.
 */

int main(int argc, const char * argv[]) {
    
    Program* program = new Program();
    
    program->run(argc, argv);
    
    delete program;
    
    return 0;
}
