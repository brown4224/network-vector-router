#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

const int thisNode = 0;
const int size = 4;
int distance [size][size];
int minCost [size];

struct rtpkt {
    int source = thisNode;
    int destination;
    int payload [size];
} pkt;


rtinit0(){

    // Initialize values
    for(int i = 0; i < size; i++){
        minCost[i] = INT_MAX;
        for(int j = 0; j < size; j++){
            distance[i][j] = INT_MAX;
        }
    }

    // Given Info
    distance[thisNode][thisNode] = 0;
    distance[thisNode][1] = 1;
    distance[1][1] = 1;
    distance[thisNode][2] = 3;
    distance[2][2] = 3;
    distance[thisNode][3] = 7;
    distance[3][3] = 7;

    // Update min
    minCost[0] = 0;
    minCost[1] = 1;
    minCost[2] = 3;
    minCost[3] = 7;

    // To Layer 2
    tolayer2();
}

rtupdate0(struct rtpkt *rcvdpkt){
    bool flag = false;

    // cost to get their


    for(int i = 0; i < size; i++){
        // Update table with advertised
        distance[rcvdpkt->source][i] = rcvdpkt->payload[i];

        int cost = minCost[rcvdpkt->source];
        int min = cost + rcvdpkt->payload[i];
        if(min < minCost[i]){
            minCost[i] = min;
            flag = true;
        }
    }

    if(flag){
        // Update other nodes
    }


//        int costTo = minCost[rcvdpkt->source];
//    for(int i = 0; i < size; i++){
//        int temp = costTo + rcvdpkt->payload[i];
//        if(minCost[i] > temp){
//            minCost[i] = temp;
//            distance[i][rcvdpkt->source] = temp;
//            distance[rcvdpkt->source][i] = temp;
//            flag = true;
//        }
//    }


}