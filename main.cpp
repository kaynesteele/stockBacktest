#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include "sObj.h"

using namespace std;

float *readFile(string fileName, StockClass *s, int x)
{
    float data, stoK, stoD,*stoDArr=new float[1101], *stoKArr=new float[1101];
    float *stockPrices = new float[1101];
    int *volArr = new int[1101];
    int i=0, vol;
    ifstream inFile;

    inFile.open(fileName);

    while(inFile.good())
    {
        inFile >> data >> stoK >> stoD >> vol;
        stockPrices[i] = data;
        stoKArr[i] = stoK;
        stoDArr[i] = stoD;
        volArr[i] = vol;
        s[x].setVol(volArr);
        s[x].setStoK(stoKArr);
        s[x].setStoD(stoDArr); 

        ++i;
    }
    inFile.close();
    return stockPrices;
}

int main(int argc, char **argv)
{
    StockClass s[argc];
    float *test, ma15=0.0, ma50=0.0, ma100=0,ma200=0, latest=0.0, stoK=0.0, stoD=0.0,overallPercent=0;
    int x=0, count=0,count1=0,count2=0, vol=0;
    float relativeVol=0;

    for(int i=1; i<argc; i++)
    {
        x=i-1;
        test = readFile(argv[i], s, x);
        string ticker = argv[i];

        s[x].setName(argv[i]);
        s[x].setData(test);

        for(int i =0; i < 1000; i++)
        {
            latest = s[x].getDataForDay(i); 
            ma15=s[x].calcMovingAvgForDay(i, 15);
            ma50=s[x].calcMovingAvgForDay(i, 50);
            ma100=s[x].calcMovingAvgForDay(i, 100);
            ma200=s[x].calcMovingAvgForDay(i, 200);
            stoK=s[x].getStoK(i);
            stoD=s[x].getStoD(i);
            vol=s[x].getVol(i);
            relativeVol=s[x].getRelativeVol(i);
            float highPer = ma200 + (ma200 * .08);
            float lowPer = ma200 - (ma200* .08);

            if(ma15 > ma50)
            {
                if(latest > ma100)
                {
                    if(ma50 > ma100)
                    {
                        if(latest > 10.0 && latest < 100.0)
                        {
                            if(stoK > stoD && stoK < 30)//if(latest < highPer && latest > lowPer)
                            {
                                if(vol > 300000 )
                                {
                                    float percentIncrease = 0, *percentIncrease1= new float[14];
                                    int z=0;
                                    cout << ticker << endl << endl;
                                    cout << "Price: " << s[x].getDataForDay(i) << endl;
                                    for(int y=i; y>(i-14); y--)
                                    {
                                        //cout << s[x].getDataForDay(y-1) << endl;
                                        percentIncrease1[z] =  s[x].getDataForDay(y);
                                        z++;
                                    } 
                                    float test= *max_element(percentIncrease1+1, percentIncrease1+14) ;
                                    cout << "Max Price: " << test << endl;
                                    percentIncrease = (((test - s[x].getDataForDay(i)) / s[x].getDataForDay(i))*100);
                                    overallPercent+=percentIncrease;
                                    cout << overallPercent << endl;
                                    cout << "%inc: " <<  percentIncrease << endl << endl;
                                    if(percentIncrease >= 3 )
                                        count++;
                                    if(percentIncrease >=10)
                                        count2++;
                                    if(percentIncrease<=0)
                                        count1++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Winning trades: " << count << endl;
    cout << "Big Winners: " << count2 << endl;
    cout << "Losing Trades: " << count1 << endl;
    cout << "Total %Gain: " << overallPercent << endl;
    return 0;
}
