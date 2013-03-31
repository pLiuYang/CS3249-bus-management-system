#ifndef SHARED_H
#define SHARED_H

#define TOTAL_STATION 21
#define ROUTE_A1 11
#define ROUTE_A2 13
#define ROUTE_B 11
#define ROUTE_C 8
#define ROUTE_D1 11
#define ROUTE_D2 9
#define BUS_SPACE 50

extern volatile int peopleAtStation[TOTAL_STATION];

extern volatile int stationA1[ROUTE_A1];
extern volatile int stationA2[ROUTE_A2];
extern volatile int stationB[ROUTE_B];
extern volatile int stationC[ROUTE_C];
extern volatile int stationD1[ROUTE_D1];
extern volatile int stationD2[ROUTE_D2];

#endif
