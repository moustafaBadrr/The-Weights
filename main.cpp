#include <iostream>
#include <vector>


using namespace std;

bool isMeasureable(int target, vector<int> &weight);  /// Declaration of the Function

int main()
{
    vector <int> sampleWeights;  /// declaration of vector array which  will contains some of weights
    int n_weights,target;
    cout<<"Enter the numbers of Weights: ";
    cin>>n_weights;                         /// take the numbers of weights
    cout<<endl<<"Enter the weights: ";
    for (int i=0; i<n_weights;i++){
        int e_weights;
        cin>>e_weights;                     /// Entering the weights
        sampleWeights.push_back(e_weights); /// Full the array
    }
    cout<<"Enter the Target: ";
    cin>>target;                            /// take the target
    cout<< isMeasureable(target,sampleWeights);

    return 0;
}

bool isMeasureable(int target, vector<int> &weight)
{
    if (weight.empty())                /// check if the array is empty or not
    {
        if(target ==0)   /// check if the target equal zero or not
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int First_weight=weight[0];         /// take the first weight of array
        vector <int> reminder=weight;        /// put the array in new array to remove the first element
        reminder.erase(reminder.begin()+0);  /// Removing the first weight to take the other weights
        int x=target+First_weight, y=target-First_weight;  /// take the first weight which will take all weights by recursion
        return isMeasureable(x,reminder) || isMeasureable(y,reminder);
    }
}
