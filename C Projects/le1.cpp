#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Person {
    public:     
        string name;
        int age;
        Person() : Person({"3", 4}) {}
        Person(string n) : name(n) {} 
};

int main()
{
        Person p;
        
    return 0;
}
