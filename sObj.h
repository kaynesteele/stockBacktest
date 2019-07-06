#include <string>
#include <iostream>

class StockClass
{
    private:
        std::string stockName;
        float *data;
        float maFifteen, maFifty,*stoArr, *stoD, *stoK;
        int *vol;

    public:
        StockClass() { stockName = "NULL"; data = NULL; stoD=new float[1101]; stoK=new float[1101]; };
        ~StockClass() { delete[] stoD; delete[] stoK; };
        void setName(std::string);
        std::string getName();
        void setData(float *);
        float getDataForDay(int);
        void getData(int);
        float calcMovingAvg(int);
        float calcMovingAvgForDay(int, int);
        void setMovingAvgFifteen(float);
        void setMovingAvgFifty(float);
        float displayMovingAvgFifteen();
        float displayMovingAvgFifty();
        float getLatestData();
        float getLowest(int, int);
        float getHighest(int, int);
        float calcStoK(int, int); 
        float calcStoD();
        void setStoK(float*);
        void setStoD(float*);
        float getStoK();
        float getStoD();
        float getStoK(int);
        float getStoD(int);
        void setVol(int*);
        int getVol();
        int getVol(int);
        float getRelativeVol();
        float getRelativeVol(int);

};
