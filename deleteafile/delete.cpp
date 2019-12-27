// delete.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <string>


int main()
{
    std::string fileToBeDeleted = "C:\\all_files\\work\\junkyard\\insanely_largefile.bin";
    auto begin = std::chrono::steady_clock::now();
    int errorCode = remove( fileToBeDeleted.c_str() );
    std::chrono::steady_clock::time_point end
        = std::chrono::steady_clock::now();
    std::cout << "Time for delete: " << std::chrono::duration_cast<
        std::chrono::milliseconds>(end - begin).count() << "[ms] \n";
    if( errorCode )
    perror( "Error deleting file" );
  else
    puts( "File successfully deleted" );
  
  system("pause");
  return 0;
}