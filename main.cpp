#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(vector<int> nums);
int numberGreaterThanAverage(vector<int> nums);
int greatestCommonDivisor(vector<int> nums);
bool isSorted(const vector<int>& nums);

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
//--
int greatestCommonDivisor(vector<int> nums)
{
    // TODO: Student 3
    return 1;
}
//--

// This function outputs true if a list is sorted in either ascending or descending order, and false otherwise.
bool isSorted(const vector<int>& nums)
{
    int sizeOfNums = nums.size();
    // if only two numbers (or less), the list is automatically considered sorted
    if(sizeOfNums > 2) {
        bool ascending = true, descending = true;

        // this loop checks each adjacent pair of numbers and flags when ascending or descending order is not preserved
        for(int i = 0; i < sizeOfNums - 1; i++) {
            // if previous number is greater, not ascending order
            if(nums[i] > nums[i+1]) {
                ascending = false;
            }
            // if previous number is less, not descending order
            if(nums[i] < nums[i+1]) {
                descending = false;
            }

            // if nums has been flagged as both not ascending and not descending, then it is definitely not sorted
            if(!ascending && !descending) return false;
        }
        // if we make it to the end of the loop, then either ascending or descending is still true, so nums is sorted
    }
    return true;
}
