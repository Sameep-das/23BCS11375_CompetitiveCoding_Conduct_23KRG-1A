class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    int n = points.size();
    if (n <= 2)
      return n;

    int maxPoints = 0;

    for (int i = 0; i < n; i++)
    {
      unordered_map<string, int> slopeMap;
      int currMax = 0;

      for (int j = i + 1; j < n; j++)
      {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];

        // Handle vertical line
        if (dx == 0)
        {
          dy = 1;
        }
        // Handle horizontal line
        else if (dy == 0)
        {
          dx = 1;
        }
        else
        {
          int g = gcd(dx, dy);
          dx /= g;
          dy /= g;

          // Normalize sign (keep dx positive)
          if (dx < 0)
          {
            dx *= -1;
            dy *= -1;
          }
        }

        string key = to_string(dx) + "," + to_string(dy);
        slopeMap[key]++;
        currMax = max(currMax, slopeMap[key]);
      }

      maxPoints = max(maxPoints, currMax + 1); // +1 for anchor
    }

    return maxPoints;
  }
};