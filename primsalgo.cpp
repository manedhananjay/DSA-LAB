#include <iostream>
using namespace std;
class Office
{
    int n;
    int data[10][10];
    string office[10];

public:
    void input();
    void display();
    void Prims();
};
void Office::input()
{
    cout << "Enter the no of office : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of offices : ";
        cin >> office[i];
    }
    cout << "Cost Input Data : \n";
    for (int i = 0; i < n; i++)

        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                data[i][j] = 0;
                continue;
            }
            cout << "Enter the cost to connect " + office[i] + " and " + office[j] + " : ";
            cin >> data[i][j];
            data[j][i] = data[i][j];
        }
}
void Office::display()
{
    cout << "Displaying the office connection and their cost : ";
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << data[i][j] << " ";
        }
    }
}
void Office::Prims()
{
    int minIndex;
    int count = 1;
    // Here these visited keep the track of element which has been visited during Prims algo so that the node doesnt get repeated
    int visited[n];
    int minCost = 0;
    int totalCost = 0;
    // These is just for making all the element of visited array to zero
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    cout << "Shortest path is : " << office[0] << "-->";
    while (1)
    {
        minCost = 1000;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i] == 1 && data[i][j] != 0 && data[i][j] < minCost && visited[j] == 0)
                {
                    minCost = data[i][j];
                    minIndex = j;
                }
            }
        }
        visited[minIndex] = 1;
        cout << office[minIndex] << "-->";
        totalCost += minCost;
        count++;
        if (count == n)
        {
            break;
        }
    }
    cout << "\nMinimum Cost : " << totalCost;
}
int main()
{
    Office o;
    o.input();

    o.display();
    o.Prims();
}