#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(const vector<int>& nums);
int maxUnorderedMap(unordered_map <int, int> &nums);
int numberGreaterThanAverage(vector<int> nums);
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
//Returns most frequent number of a vector
int findMostFrequentNumber(const vector<int>& nums)
{

    // TODO: Student 1
    
    // Map each int to its frequency
    unordered_map<int, int> frequency;

    for(int i = 0; i < nums.size(); i++){
        frequency[nums[i]] += 1;
    }

    return maxUnorderedMap(frequency);

}
//Returns -1 if map is empty
//New Helper Function max of unorderedMap for findMostFrequentNumber()
int maxUnorderedMap(unordered_map <int, int> &nums){

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

    return maxNum;
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
bool isSorted(vector<int> nums)
{
    // TODO: Student 4
    return false;
}
