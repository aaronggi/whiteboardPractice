#include "template.h"

bool urlify(char * url, int truelength){
        int lstchar = truelength - 2; // -1 to leave a null-terminator, and 1 because of 0-indexing
        int currentspot = truelength - 2; //index for the spot we are writing the next char to
        if(url == NULL || truelength == 0)
                return false;
        for(int i = lstchar; i >= 0; i--){
                if (url[i] == '\0')
                        continue;
                else if(url[i] != ' '){
                        url[currentspot--] = url[i];
                }
                else{
                        url[currentspot--] = '0';
                        url[currentspot--] = '2';
                        url[currentspot--] = '%';
                }
        }
        return true;

}

int main(int argc, char**argv){
        char url[16] = "this is url\0\0\0";
        urlify(url, 16);
        printf("%s", url);
}