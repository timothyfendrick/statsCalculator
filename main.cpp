#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(vector<int> nums);
int numberGreaterThanAverage(vector<int> nums);
int greatestCommonDivisor(vector<int>& nums);
bool isSorted(vector<int> nums);

int main()
{
    //get the numbers from the user
    vector<int> numbers = getNumbers();

    //process the numbers and print results
    cout<<"Most frequent number: "<<findMostFrequentNumber(numbers)<<endl;
    
    cout<<"There are "<<numberGreaterThanAverage(numbers)<<" numbers greater than the average."<<endl;
    
    cout<<"The greatest common divisor is: "<<greatestCommonDivisor(numbers)<<endl;
    
    if(isSorted(numbers))
    {
        cout<<"The numbers are sorted."<<endl;
    }
    else
    {
        cout<<"The numbers are not sorted."<<endl;
    }

    return 0;
}
//--
vector<int> getNumbers()
{
    vector<int> nums;
    int num;
    cout << "Enter numbers (0 to stop): ";
    while (cin >> num && num != 0)
    {
        nums.push_back(num);
    }
    return nums;
}
//--
int findMostFrequentNumber(vector<int> nums)
{
    // TODO: Student 1
    return -1;
}
//--
int numberGreaterThanAverage(vector<int> nums)
{
    // TODO: Student 2
    return 0;
}
// returns the greatest common divisor (greatest common factor) between all ints in the given allNums vector
int greatestCommonDivisor(vector<int>& allNums)
{
    //by default, the greatestCommonDivisor is 1
    int gCD = 1;

    if (allNums.size() == 1)
    {
        //returns itself
        gCD = allNums[0];
    }
    else if (allNums.size() < 3)
    {
        //find the gCD of two numbers
        int num1 = allNums[0];
        int num2 = allNums[1];

        if (num1 == num2) 
        {
            gCD = num1;
        }
        else if (num1 > num2) 
        {
            vector <int> divisorList = {num1, num2};
            while (divisorList[divisorList.size()-1] != 0)
            {
                divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
            }
            gCD = divisorList[divisorList.size()-2];
        }
        else //if num2 is greater than num1
        {
            vector <int> divisorList = {num2, num1};
            while (divisorList[divisorList.size()-1] != 0)
            {
                divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
            }
            gCD = divisorList[divisorList.size()-2];
        }

    }
    else 
    {
        //loop to find the gCD of all nums in the list
        for (int i = 0; i < allNums.size(); i++)
        {
            if (i == 0)
            {
                if (allNums[i] > allNums[i+1])
                {
                vector <int> divisorList = {allNums[i], allNums[i+1]};
                while (divisorList[divisorList.size()-1] != 0)
                {
                    divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
                }
                gCD = divisorList[divisorList.size()-2];
                }
                else //if num2 is greater than num1
                {
                vector <int> divisorList = {allNums[i+1], allNums[i]};
                while (divisorList[divisorList.size()-1] != 0)
                {
                    divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
                }
                gCD = divisorList[divisorList.size()-2];
                }
            }
            else
            {
                if (allNums[i] > allNums[i+1])
                {
                    vector <int> divisorList = {allNums[i], gCD};
                    while (divisorList[divisorList.size()-1] != 0)
                    {
                        divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
                    }
                    gCD = divisorList[divisorList.size()-2];
                }
                else //if num2 is greater than num1
                {
                    vector <int> divisorList = {gCD, allNums[i]};
                    while (divisorList[divisorList.size()-1] != 0)
                    {
                        divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
                    }
                    gCD = divisorList[divisorList.size()-2];
                }
            }
        }
    }

    return gCD;
}
//--
bool isSorted(vector<int> nums)
{
    // TODO: Student 4
    return false;
}
