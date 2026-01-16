#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(vector<int> nums);
int numberGreaterThanAverage(const vector<int>& nums);
int greatestCommonDivisor(vector<int> nums);
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
int numberGreaterThanAverage(const vector<int>& nums)
{
    int numsTotal = 0;
    int average = 0;
    int totalnGTA = 0; // This tracks the total numbers greater than the average

    if (nums.size() > 0)
    {
        // add all the numbers together
        for (int i = 0; i < nums.size(); i++) 
        {
            numsTotal += nums.at(i);
        }
            
        // divide by size of the vector (gets average)
        if (nums.size() >= 1) 
        {
            average = numsTotal / nums.size();
        }

        // using average iterate through the initial vector and find the total numbers larger than the average
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums.at(j) > average)
            {
                totalnGTA++;
            }
        }
    }

    // output the count of numbers larger than the average
    return totalnGTA;
}
//--
int greatestCommonDivisor(vector<int> nums)
{
    // TODO: Student 3
    return 1;
}
//--
bool isSorted(vector<int> nums)
{
    // TODO: Student 4
    return false;
}
