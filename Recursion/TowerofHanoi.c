//
//  TowerofHanoi.c
//  recursion
//
//  Created by Ruize Zhang on 8/19/23.
//

#include "TowerofHanoi.h"
#include <stdio.h>
void towerofHanoi(int diskNum, int from, int other, int to){
    if(diskNum > 0){
        towerofHanoi(diskNum - 1, from, to, other);
        printf("(%d, %d)\n", from, to);
        towerofHanoi(diskNum - 1, other, from, to);
        
    }
}
int main(int argc, const char * argv[]) {
    int diskNum = 3;
    towerofHanoi(diskNum, 1, 2, 3);
    return 0;
}
