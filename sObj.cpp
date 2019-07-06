#include "sObj.h"


void StockClass::setName(std::string name)
{
    stockName=name;
}

std::string StockClass::getName()
{
    return stockName;
}

void StockClass::setData(float *stockData)
{
    data = stockData;
}

void StockClass::getData(int x)
{
    for(int i=0; i<x; i++)
    {
        std::cout << i+1 << ": " << data[i] << std::endl;
    }
}

float StockClass::calcMovingAvg(int x)
{
    float movingAvg=0.0;

    for(int i=x-1; i>=0; i--)
    {
        movingAvg+=(data[i]);        
    } 
    
    return (movingAvg / float(x)); 
}

float StockClass::calcMovingAvgForDay(int x, int y)
{
    float movingAvg=0.0;
    for(int i=x; i<(x+y); i++)
    {
    movingAvg+=(data[i]);
    } 
    return (movingAvg / float(y));
}

void StockClass::setMovingAvgFifteen(float _ma)
{
    maFifteen = _ma;
}

void StockClass::setMovingAvgFifty(float _ma)
{
    maFifty = _ma;
}


float StockClass::displayMovingAvgFifteen()
{
    return maFifteen;
}

float StockClass::displayMovingAvgFifty()
{
    return maFifty;
}

float StockClass::getDataForDay(int x)
{
    return data[x];
}
float StockClass::getLatestData()
{
    return data[0];
}

float StockClass::getLowest(int x, int y)
{
    float lowest=100.0;
    for(int i=x; i<=y; i++)
    {
        if(data[i] < lowest) lowest=data[i];
    } 
    return lowest;
}

float StockClass::getHighest(int x, int y)
{
    float highest=0.0;
    for(int i=x; i<=y; i++)
    {
        if(data[i] > highest) highest=data[i];
    } 
    return highest;

}

float StockClass::calcStoK(int x, int y)
{
    return float((data[x] - getLowest(x, y) ) / ( getHighest(x, y) - getLowest(x,y)) * 100); 
}

float StockClass::calcStoD()
{
    stoArr = new float[3];    
    float stoD = 0.0;
    stoArr[0] = calcStoK(0, 13);
    stoArr[1] = calcStoK(1, 14);
    stoArr[2] = calcStoK(2, 15);
    for(int i = 0; i < 3; i++)
    {
        stoD+=stoArr[i];
    }
    return (stoD/3);
}

void StockClass::setStoK(float *_stoK)
{
    stoK = _stoK;
}

void StockClass::setStoD(float *_stoD)
{
    stoD = _stoD;
}

float StockClass::getStoK()
{
    return stoK[0];
}

float StockClass::getStoD()
{
    return stoD[0];
}
float StockClass::getStoK(int x)
{
    return stoK[x];
}
float StockClass::getStoD(int x)
{
    return stoD[x];
}

void StockClass::setVol(int *_vol)
{
    vol=_vol;

}
int StockClass::getVol()
{
    return vol[0];
}   
int StockClass::getVol(int x)
{
    return vol[x];
}

float StockClass::getRelativeVol()
{
    float relVol=0;

    for(int i=0; i<100; i++)
    {
        relVol += vol[i];    
    }
    relVol = relVol / 100;

    return (vol[0] / relVol);  
}

float StockClass::getRelativeVol(int x)
{
    float relVol=0;

    for(int i=x; i<x+100; i++)
    {
        relVol += vol[i];    
    }
    relVol = relVol / 100;

    return (vol[x] / relVol);  
}

