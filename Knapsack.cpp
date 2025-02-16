#include <iostream>
using namespace std;
class item
{
    public:
    string item_name;
    float value;
    float weight;

    item(string name="", float val=0, float wt=0)
    {
        item_name = name;
        value = val;
        weight = wt;
    }

    float ratio()
    {
        return value/weight;
    }
};
void sortByRatio(item arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i].ratio()<arr[j].ratio())
            {
                item temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of items: "<<endl;
    cin>>n;
    cout<<"Enter name, value, weight of each item: "<<endl;
    item arr[n];
    for(int i=0;i<n;i++)
    {
        string item_name;
        float value, weight;
        cin>>item_name>>value>>weight;
        arr[i] = item(item_name, value, weight);
    }

    cout<<"Item name, value and weight: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].item_name<<" "<<arr[i].value<<" "<<arr[i].weight<<endl;
    }

    sortByRatio(arr,n);
    cout<<"Item name, value and weight sorted in descending order: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].item_name<<" "<<arr[i].value<<" "<<arr[i].weight<<endl;
    }    

    cout<<"Enter capacity of knapsack: ";
    int capacity;
    cin>>capacity;
    float totalValue = 0.0;

    for(int i=0;i<n;i++)
    {
        if(capacity>=arr[i].weight)
        {
            totalValue+=arr[i].value;
            capacity-=arr[i].weight;
            cout<<arr[i].item_name<<" taken\n";
            cout<<"Remaining capacity: "<<capacity<<endl;
        }
        else
        {
            float fractionLeft = float(capacity)/arr[i].weight;
            totalValue+=arr[i].value*fractionLeft;
            cout<<arr[i].item_name<<" partially taken ("<<fractionLeft*100<<"%)\n";
            capacity=0;
            break;
        }
    }
    cout<<"Maximum value in knapsack: "<<totalValue;

    return 0;
}
