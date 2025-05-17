#include <iostream>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int buildingHeights[10000];
    for (int i = 0; i < W; ++i)
    {
        cin >> buildingHeights[i];
    }

    int waterAmount = 0;
    for (int i = 1; i < W - 1; ++i)
    {
        int leftMax = 0, rightMax = 0;
        // Find the maximum height of the building to the left
        for (int j = i - 1; j >= 0; --j)
        {
            leftMax = max(leftMax, buildingHeights[j]);
        }
        // Find the maximum height of the building to the right
        for (int j = i + 1; j < W; ++j)
        {
            rightMax = max(rightMax, buildingHeights[j]);
        }
        // Calculate the amount of water above the current building
        int waterLevel = min(leftMax, rightMax);
        if (waterLevel > buildingHeights[i])
        {
            waterAmount += waterLevel - buildingHeights[i];
        }
    }
    cout << waterAmount << endl;
    return 0;
}