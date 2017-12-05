//
//  FileLoader.cpp
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "FileLoader.h"

unique_ptr<Document> FileLoader::loadJSONFile(const string& path){
    
    ifstream inputFileStream (path);
    unique_ptr<Document> document(new Document());
    
    vector<string> textFile;
    
    if (inputFileStream.is_open())
    {
        document->ParseStream(inputFileStream);
        
        inputFileStream.close();
    }
    else {
        throw RayTracerException(std::string("File Load Error: Unable to open file: ") += path );
    }
    
    return document;

}