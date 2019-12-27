// largefile.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <string>
#include <chrono>
#include <stdio.h>
#include <cstdint>


#include "binarydata.hpp"


int main()
{
    std::cout << "Beginning to write...\n";
   const std::string fileName = "C:\\all_files\\work\\junkyard\\insanely_largefile.bin";
   const long long FILE_SiZE = 30000000000; 

   //rawDataOne[4424] = '\0';

   FILE *pFile = nullptr;
   int errorCode = 0;
   if( (errorCode = fopen_s( &pFile, fileName.c_str(), "w"))) {
       std::cout << "Error in opening a file: " << errorCode;
   }
   auto begin = std::chrono::steady_clock::now();
   for (long long i = 0; i < FILE_SiZE; i++) {
       fprintf_s(pFile, rawDataOne,4000);
   }
     

   std::chrono::steady_clock::time_point end
        = std::chrono::steady_clock::now();
    std::cout << "Time for write = " << std::chrono::duration_cast<
        std::chrono::seconds>(end - begin).count() << "[ms] \n";
   fclose(pFile);

   system("pause");
   return 0;
}

