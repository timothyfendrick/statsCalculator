#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(const vector<int>& nums);
int maxUnorderedMap(unordered_map <int, int> &nums, const int firstNum);
int numberGreaterThanAverage(const vector<int>& nums);
int greatestCommonDivisor(const vector<int>& nums);
int gCDTwoInts(const int& larger, const int& smaller);
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
//Returns most frequent number of a vector
int findMostFrequentNumber(const vector<int>& nums)
{

    // TODO: Student 1
    
    // Map each int to its frequency
    unordered_map<int, int> frequency;

    for(int i = 0; i < nums.size(); i++){
        frequency[nums[i]] += 1;
    }

    return maxUnorderedMap(frequency, nums[0]);

}
//Returns -1 if map is empty
//New Helper Function max of unorderedMap for findMostFrequentNumber()
int maxUnorderedMap(unordered_map <int, int> &nums, const int firstNum){

    int firstNumMap = nums.begin() -> first;

    //Checks if list is empty, because then the iterator line fails and crashes program
    if(nums.empty()){
        return -1;
    }

    //gets first item in unordered_map and then accesses the second(value) item from the pair by dereferencing the pointer
    int maxNum = nums.begin() -> first;
    int maxFreq = nums.begin() -> second;


    //New piece of iterators I learned for this, next increments the iterator to the next spot
    //This is important because it skips the first index, making this slightly faster
    for(auto it = next(nums.begin()) ; it != nums.end(); it++){
        if(it -> second > maxFreq){
            maxFreq = it -> second;
            maxNum = it -> first;
        }
    }

    if(maxFreq == 1 && maxNum == firstNumMap){
        return firstNum;
    }

    return maxNum;
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
// returns the greatest common divisor (greatest common factor) between all ints in the given allNums vector
int greatestCommonDivisor(const vector<int>& allNums)
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
            gCD = gCDTwoInts(num1, num2);
        }
        else //if num2 is greater than num1
        {
            gCD = gCDTwoInts(num2, num1);
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
                    gCD = gCDTwoInts(allNums[i], allNums[i+1]);
                }
                else //if num2 is greater than num1
                {
                    gCD = gCDTwoInts(allNums[i+1], allNums[i]);
                }
            }
            else
            {
                if (allNums[i] > gCD)
                {
                    gCD = gCDTwoInts(allNums[i], gCD);
                }
                else //if num2 is greater than num1
                {
                    gCD = gCDTwoInts(gCD, allNums[i]);
                }
            }
        }
    }
    return gCD;
}
//-- Used in greatestCommonDivisor to find the gCD of two ints
int gCDTwoInts(const int& larger, const int& smaller)
{
    vector <int> divisorList = {larger, smaller};
    while (divisorList[divisorList.size()-1] != 0)
    {
        divisorList.push_back(divisorList[divisorList.size()-2] % divisorList[divisorList.size()-1]);
    }
    return divisorList[divisorList.size()-2];
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
