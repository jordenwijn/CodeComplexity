#include <iostream>
#include <vector>
#include <string>

#include <winnt.h>

#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include<dirent.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/param.h>


#include <unistd.h>
#include <windef.h>
#include <windows.h>
#include <tchar.h>

#pragma comment(lib, "User32.lib")

//#define FILE_ATTRIBUTE_DIRECTORY		0x00000010

using namespace std;

void listFile() 
{
    DIR *pDIR;
    struct dirent *entry;
    struct stat file_info;
    std::string extension = ".cs";
    int pos = 0;
    bool folder = false;


    if( pDIR=opendir("/Users/JW_NUC1/Documents/Visual Studio 2015/Projects/App2/App2") )
    {
        while(entry = readdir(pDIR))
        {
            std::string file_name = entry->d_name;
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
            {
                folder = entry->d_type & FILE_ATTRIBUTE_DIRECTORY;

                if (folder)
                {
                    cout << "folder";
                    cout << entry->d_name  << "\n";
                }
              
                pos = file_name.length() - extension.length();

                if (pos < 4)
                {
                    continue;
                }

                std::string file_extension = file_name.substr(pos);
        
                if (strcmp(file_extension.c_str(), extension.c_str()) == 0 )
                {
                    cout << entry->d_name << "\n";
                }
            }
        }
            closedir(pDIR);
    }
}

int main()
{

    listFile();
    return 0;
}