//
//  TGAWriter.cpp
//  RayTracer
//
//  Created by Alex Handby on 12/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "TGAWriter.h"

void TGAWriter::writeImage(const string& outputPath, const Image& image){
/*
    ofstream tgafile( filename.c_str(), ios::binary );
    if (!tgafile) return false;
    
    // The image header
    byte header[ 18 ] = { 0 };
    header[  2 ] = 1;  // truecolor
    header[ 12 ] =  width        & 0xFF;
    header[ 13 ] = (width  >> 8) & 0xFF;
    header[ 14 ] =  height       & 0xFF;
    header[ 15 ] = (height >> 8) & 0xFF;
    header[ 16 ] = 24;  // bits per pixel
    
    tgafile.write( (const char*)header, 18 );
    
    // The image data is stored bottom-to-top, left-to-right
    for (int y = height -1; y >= 0; y--)
        for (int x = 0; x < width; x++)
        {
            tgafile.put( (char)data[ (y * width) + x ].blue  );
            tgafile.put( (char)data[ (y * width) + x ].green );
            tgafile.put( (char)data[ (y * width) + x ].red   );
        }
    
    // The file footer. This part is totally optional.
    static const char footer[ 26 ] =
    "\0\0\0\0"  // no extension area
    "\0\0\0\0"  // no developer directory
    "TRUEVISION-XFILE"  // yep, this is a TGA file
    ".";
    tgafile.write( footer, 26 );
    
    tgafile.close();
    return true; */
    
}